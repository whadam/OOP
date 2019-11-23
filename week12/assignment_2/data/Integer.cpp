#include "Integer.h"
#include "../json_list.h"
#include "../json_dict.h"
#include "../json_object.h"
#include "String.h"

Integer::Integer(int value) {
    this->_val = value;
}

int Integer::val() {
	return this->_val;
}

void Integer::set_val(const int &value) {
    this->_val = value;
}

json_object *Integer::parse(const char * str, int length) {
	std::string s;

	while (true) {
		if (47 < str[_index] && str[_index] < 58) {
			s += str[_index];
		}
		else {
			break;
		}
		_index++;
	}

	json_object* temp = new Integer(std::stoi(s));
    return temp;
}

json_object::_type Integer::type() {
    return INT;
}

std::string Integer::to_string() {
    return std::to_string(this->_val);
}

