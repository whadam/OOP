#include "json_list.h"
#include "json_dict.h"
#include "data/Integer.h"
#include "data/String.h"

json_list::json_list() = default;

json_object* json_list::parse(const char* str, int length) {
	_index++;
	int* index_check = &_index;
	json_list* temp = new json_list();
	int comma = 0;
    
	while (_index < length) {
		switch (str[_index]) {
		case '{':
			temp->v.emplace_back(json_dict::parse(str, length));
			break;
		case '[':
			temp->v.emplace_back(json_list::parse(str, length));
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
			temp->v.emplace_back(Integer::parse(str, length));
			break;
		case '}':
		case ' ':
			_index++;
			break;
		case ']':
			_index++;
			if (comma == temp->v.size() && comma != 0) {
				temp->v.emplace_back(nullptr);
			}
			if (temp->v.empty()) {
				temp->v.emplace_back(nullptr);
			}
			return temp;
		case ',':
			comma++;
			_index++;
			break;
		case '"':
		case '\'':
			temp->v.emplace_back(String::parse(str, length, str[_index]));
			break;
		default:
			_index++;
			std::cout << "default " << str[_index-1] << str[_index] << str[_index+1] << std::endl;
			break;
		}
	}

    return temp;
}

json_object *json_list::operator[](int key) const {
	return this->v[key];
}

json_object::_type json_list::type() {
    return LIST;
}

std::string json_list::to_string() {
	if (v[0] == nullptr) return "[]";
	std::string s = "[";
	for (auto& iter : v) {
		if (iter != nullptr) {
			s += iter->to_string();
			s += ", ";
		}
		else {
			s += " ";
		}
	}
	s.pop_back();
	s.pop_back();
	s += "]";

    return s;
}
