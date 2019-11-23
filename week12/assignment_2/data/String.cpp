#include "String.h"

String::String(const std::string &str) {
    this->_val = str;
}

std::string String::val() {
    return this->_val;
}

void String::set_val(const std::string &str) {
    this->_val = str;
}

json_object *String::parse(const char * str, int length, char base) {
	_index++;

	std::string s;
	while (str[_index] != base) {
		s += str[_index++];
	}
	_index++;

	json_object* temp = new String(s);

    return temp;
}

json_object::_type String::type() {
    return STRING;
}

std::string String::to_string() {
	std::string s = "'";
	s += this->_val;
	s += "'";
    return s;
}
