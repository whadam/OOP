#ifndef INTEGER_H
#define INTEGER_H

#include "Object.h"

class Integer : public Object<int> {
private:
    int _val;
public:
    explicit Integer(int value);

    int val() override ;
    void set_val(const int& value) override ;

    static json_object* parse(const char *, int length);
    _type type() override ;
    std::string to_string() override ;
};

#endif //INTEGER_H
