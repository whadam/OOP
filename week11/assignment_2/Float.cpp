#include "Float.h"
#include "Integer.h"
#include "Complex.h"
#include <iostream>

using namespace std;

double Float::parse_string(std::string str) {
    double result = atof(str.c_str());
    return result;
}

Float::Float() {
	this->value = 0;
}

Float::Float(double _value) {
	this->value = _value;
}

Float::Float(const std::string& str) {
	this->value = this->parse_string(str);
}

Number *Float::add(Number * num) {
	if (num->types() == INTEGER) {
		Integer* num_i = dynamic_cast<Integer*>(num);
		this->set_val(this->value + num_i->val());
		delete num_i;
		return this;
	} else if (num->types() == FLOAT) {
		Float* num_f = dynamic_cast<Float*>(num);
		this->set_val(this->value + num_f->val());
		delete num_f;
		return this;
	} else if (num->types() == COMPLEX) {
		Complex* num_c = dynamic_cast<Complex*>(num);
		num_c->set_val(this->value + num_c->real(), num_c->imag());
		delete this;
		return num_c;
	} else {
		cout << "else" << endl;
		return this;
	}
}

Number *Float::sub(Number * num) {
	if (num->types() == INTEGER) {
		Integer* num_i = dynamic_cast<Integer*>(num);
		this->set_val(this->value - num_i->val());
		delete num_i;
		return this;
	} else if (num->types() == FLOAT) {
		Float* num_f = dynamic_cast<Float*>(num);
		this->set_val(this->value - num_f->val());
		delete num_f;
		return this;
	} else if (num->types() == COMPLEX) {
		Complex* num_c = dynamic_cast<Complex*>(num);
		num_c->set_val(this->value - num_c->real(), -1 * num_c->imag());
		delete this;
		return num_c;
	} else {
		cout << "else" << endl;
		return this;
	}
}

Number *Float::mul(Number *num) {
	if (num->types() == INTEGER) {
		Integer* num_i = dynamic_cast<Integer*>(num);
		this->set_val(this->value * num_i->val());
		delete num_i;
		return this;
	} else if (num->types() == FLOAT) {
		Float* num_f = dynamic_cast<Float*>(num);
		this->set_val(this->value * num_f->val());
		delete num_f;
		return this;
	} else if (num->types() == COMPLEX) {
		Complex* num_c = dynamic_cast<Complex*>(num);
		num_c->set_val(this->value * num_c->real(), this->value * num_c->imag());
		delete this;
		return num_c;
	} else {
		cout << "else" << endl;
		return this;
	}
}

Number *Float::div(Number *num) {
	if (num->types() == INTEGER) {
		Integer* num_i = dynamic_cast<Integer*>(num);
		if (num_i->val() == 0) {
			cout << "div zero" << endl;
			return this;
		}
		this->set_val(this->value / num_i->val());
		delete num_i;
		return this;
	} else if (num->types() == FLOAT) {
		Float* num_f = dynamic_cast<Float*>(num);
		if (num_f->val() == 0) {
			cout << "div zero" << endl;
			return this;
		}
		this->set_val(this->value / num_f->val());
		delete num_f;
		return this;
	} else if (num->types() == COMPLEX) {
		return nullptr;
	} else {
		cout << "else" << endl;
		return this;
	}
}

void Float::set_val(double val) {
	this->value = val;
}

double Float::val() const {
    return this->value;
}

Number::type Float::types() const {
    return FLOAT;
}

std::string Float::to_string() const {
    return std::to_string(value);
}
