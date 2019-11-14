#include "Complex.h"
#include "Integer.h"
#include "Float.h"
#include <iostream>

using namespace std;

Complex::Complex() {
	this->value = std::make_pair(0,0);
}

Complex::Complex(double _val1, double _val2) {
	this->value = std::make_pair(_val1, _val2);
}

Number *Complex::add(Number * num) {
	if (num->types() == INTEGER) {
		Integer* num_i = dynamic_cast<Integer*>(num);
		this->set_val(this->real() + num_i->val(), this->imag());
		delete num_i;
		return this;
	} else if (num->types() == FLOAT) {
		Float* num_f = dynamic_cast<Float*>(num);
		this->set_val(this->real() + num_f->val(), this->imag());
		delete num_f;
		return this;
	} else if (num->types() == COMPLEX) {
		Complex* num_c = dynamic_cast<Complex*>(num);
		this->set_val(this->real() + num_c->real(), this->imag() + num_c->imag());
		delete num_c;
		return this;
	} else {
		cout << "else" << endl;
		return this;
	}
}

Number *Complex::sub(Number * num) {
	if (num->types() == INTEGER) {
		Integer* num_i = dynamic_cast<Integer*>(num);
		this->set_val(this->real() - num_i->val(), this->imag());
		delete num_i;
		return this;
	} else if (num->types() == FLOAT) {
		Float* num_f = dynamic_cast<Float*>(num);
		this->set_val(this->real() - num_f->val(), this->imag());
		delete num_f;
		return this;
	} else if (num->types() == COMPLEX) {
		Complex* num_c = dynamic_cast<Complex*>(num);
		this->set_val(this->real() - num_c->real(), this->imag() - num_c->imag());
		delete num_c;
		return this;
	} else {
		cout << "else" << endl;
		return this;
	}
}

Number *Complex::mul(Number * num) {
	if (num->types() == INTEGER) {
		Integer* num_i = dynamic_cast<Integer*>(num);
		this->set_val(this->real() * num_i->val(), this->imag() * num_i->val());
		delete num_i;
		return this;
	} else if (num->types() == FLOAT) {
		Float* num_f = dynamic_cast<Float*>(num);
		this->set_val(this->real() * num_f->val(), this->imag() * num_f->val());
		delete num_f;
		return this;
	} else if (num->types() == COMPLEX) {
		Complex* num_c = dynamic_cast<Complex*>(num);
		this->set_val(this->real() * num_c->real() - this->imag() * num_c->imag()
					, this->real() * num_c->imag() + this->imag() * num_c->real());
		delete num_c;
		return this;
	} else {
		cout << "else" << endl;
		return this;
	}
}

Number *Complex::div(Number * num) {
	if (num->types() == INTEGER) {
		Integer* num_i = dynamic_cast<Integer*>(num);
		if (num_i->val() == 0) {
			cout << "div zero" << endl;
			return this;
		}
		this->set_val(this->real() / num_i->val(), this->imag() / num_i->val());
		delete num_i;
		return this;
	} else if (num->types() == FLOAT) {
		Float* num_f = dynamic_cast<Float*>(num);
		if (num_f->val() == 0) {
			cout << "div zero" << endl;
			return this;
		}
		this->set_val(this->real() / num_f->val(), this->imag() / num_f->val());
		delete num_f;
		return this;
	} else if (num->types() == COMPLEX) {
		return nullptr;
	} else {
		cout << "eles" << endl;
		return this;
	}
}

double Complex::real() const {
    return std::get<0>(value);
}
double Complex::imag() const {
    return std::get<1>(value);
}

void Complex::set_val(std::pair<double, double> val) {
	this->value = val;
}

void Complex::set_val(double real, double imag) {
	this->value = std::make_pair(real, imag);
}

std::pair<double, double> Complex::val() const {
    return this->value;
}

Number::type Complex::types() const {
    return COMPLEX;
}

std::string Complex::to_string() const {
    std::string real = std::to_string(std::get<0>(value));
    std::string imag;
    if (std::get<1>(value) >= 0) {
        imag = std::to_string(std::get<1>(value));
        std::string op(" + ");
        real.append(op);
    } else {
        imag = std::to_string(-std::get<1>(value));
        std::string op(" - ");
        real.append(op);
    }
    real.append(imag);
    std::string im("i");
    real.append(im);
    return real;
}
