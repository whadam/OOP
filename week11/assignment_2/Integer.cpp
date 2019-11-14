#include "Integer.h"
#include "Float.h"
#include "Complex.h"
#include <iostream>

using namespace std;

int Integer::parse_string(const std::string& str) {
    int result = atoi(str.c_str());
    return result;
}

Integer::Integer() {
	this->value = 0;
}

Integer::Integer(int _value) {
	this->value = _value;
}

Integer::Integer(const std::string& str) {
	this->value = parse_string(str);
}

Number *Integer::add(Number * num) {
    if (num->types() == INTEGER) {
		Integer* num_i = dynamic_cast<Integer*>(num);
		this->set_val(this->value + num_i->val());
		delete num_i;
		return this;
    } else if (num->types() == FLOAT) {
		Float* num_f = dynamic_cast<Float*>(num);
		num_f->set_val(this->value + num_f->val());
		delete this;
		return num_f;
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

Number *Integer::sub(Number * num) {
	if (num->types() == INTEGER) {
		Integer* num_i = dynamic_cast<Integer*>(num);
		this->set_val(this->value - num_i->val());
		delete num_i;
		return this;
    } else if (num->types() == FLOAT) {
		Float* num_f = dynamic_cast<Float*>(num);
		num_f->set_val(this->value - num_f->val());
		delete this;
		return num_f;
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

Number *Integer::mul(Number * num) {
	if (num->types() == INTEGER) {
		Integer* num_i = dynamic_cast<Integer*>(num);
		this->set_val(this->value * num_i->val());
		delete num_i;
		return this;
    } else if (num->types() == FLOAT) {
		Float* num_f = dynamic_cast<Float*>(num);
		num_f->set_val(this->value * num_f->val());
		delete this;
		return num_f;
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

Number *Integer::div(Number * num) {
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
		num_f->set_val(this->value / num_f->val());
		delete this;
		return num_f;
    } else if (num->types() == COMPLEX) {
		return nullptr;
    } else {
		cout << "else" << endl;
		return this;
    }

}

void Integer::set_val(int val) {
	this->value = val;
}

int Integer::val() const {
    return this->value;
}

Number::type Integer::types() const {
    return INTEGER;
}

std::string Integer::to_string() const {
    return std::to_string(value);
}
