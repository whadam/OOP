#include "json_dict.h"
#include "json_list.h"
#include "data/Integer.h"
#include "data/String.h"

void json_dict::put(json_object *key, json_object *val) {
    //key가 있으면 덮어 씌우고, 없으면 push_back
    int i = find(key);
    if (i == -1) {
		v.emplace_back(std::make_pair(key, val));
    }
    else {
		v[i].second = val;
    }
}

int json_dict::find(json_object *key) {
	for (int i = 0; i < v.size(); i++) {
		if (v[i].first->to_string() == key->to_string()) {
			return i;
		}
    }
    return -1;
}

json_dict::json_dict() = default;

json_object *json_dict::parse(const char * str, int length) {
    _index++;
	bool check = false;
	json_dict* temp = new json_dict();
	json_object* first = nullptr;
	json_object* second = nullptr;

	while (_index < length) {
		switch (str[_index]) {
		case '{':
			second = json_dict::parse(str, length);
			break;
		case '[':
			second = json_list::parse(str, length);
			break;
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
			if (check) second = Integer::parse(str, length);
			else first = Integer::parse(str, length);
			break;
		case '}':
			_index++;
			temp->put(first, second);
			return temp;
		case ']':
		case ' ':
			_index++;
			break;
		case ',':
			check = false;
			temp->put(first, second);
			_index++;
			break;
		case '"':
		case '\'':
			if (check) {
				second = String::parse(str, length, str[_index]);
			}
			else {
				first = String::parse(str, length, str[_index]);
			}
			break;
		case ':':
			check = true;
			_index++;
			break;
		default:
			_index++;
			std::cout << "default" << std::endl;
			break;
		}
	}

	temp->put(first, second);

    return temp;
}

json_object *json_dict::operator[](json_object *key) const {
    int i = 0;
    for (; i < v.size(); i++) {
        if (v[i].first->to_string() == key->to_string()) {
            return v[i].second;
        }
    }
    return nullptr;
}

json_object *json_dict::operator[](const std::string &key) const {
    int i = 0;
	std::string str;
    for (; i < v.size(); i++) {
		if (v[i].first->type() == 3) {
			str = dynamic_cast<String*>(v[i].first)->val();
        	if (str == key) {
            	return v[i].second;
        	}
		}
    }
    return nullptr;
}

json_object *json_dict::operator[](int key) const {
    int i = 0;
	int temp;
    for (; i < v.size(); i++) {
		if (v[i].first->type() == 2) {
			temp = dynamic_cast<Integer*>(v[i].first)->val();
        	if (temp== key) {
            	return v[i].second;
        	}
		}
    }
    return nullptr;
}

json_object::_type json_dict::type() {
    return DICT;
}

std::string json_dict::to_string() {
	std::string s = "{";
	for (auto& iter : this->v) {
		s += iter.first->to_string();
		s += ": ";
		s += iter.second->to_string();
		s += ", ";
	}
	if (s.length() >= 2) {
		s.pop_back();
		s.pop_back();
	}
	s += "}";

    return s;
}

