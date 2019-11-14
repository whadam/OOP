#ifndef COMPLEX_H
#define COMPLEX_H

#include "Number.h"
#include <iostream>

class Complex : public Number {
private:
    std::pair<double, double> value;
public:
    Complex();
    explicit Complex(double _val1, double _val2);

    Number* add(Number* num);
    Number* sub(Number* num);
    Number* mul(Number* num);
    Number* div(Number* num);

    double real() const;
    double imag() const;
    void set_val(std::pair<double, double> val);
    void set_val(double real, double imag);
    std::pair<double, double> val() const;
    type types() const;
    std::string to_string() const;
};

#endif // COMPLEX_H
