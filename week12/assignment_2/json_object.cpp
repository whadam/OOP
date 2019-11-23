#include "json_object.h"
#include "json_dict.h"
#include "json_list.h"
#include "data/Integer.h"
#include "data/String.h"

int json_object::_index = 0;

json_object* json_object::parse(const char * str, int length) {
    json_object * temp = nullptr;
    while (_index < length) {
        switch (str[_index]) {
            case '{':
				temp = json_dict::parse(str, length);
				break;
            case '[':
				temp = json_list::parse(str, length);
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
                temp = Integer::parse(str, length);
                break;
            case '"':
            case '\'':
                temp = String::parse(str, length, *str+_index);
                break;
			case ':':
				_index++;
				break;
			case '}':
			case ']':
			case ',':
			case ' ':
				_index++;
				break;
            default:
                _index++;
                std::cout << "default" << std::endl;
                break;
        }
    }

    return temp;
}

json_object* json_object::parse(const std::string& str) {
    json_object::_index = 0;
    return parse(str.c_str(), str.length());
}

