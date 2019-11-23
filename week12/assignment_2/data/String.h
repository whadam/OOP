#ifndef STRING_H
#define STRING_H

#include "Object.h"

class String : public Object<std::string> {
private:
    std::string _val;
public:
    explicit String(const std::string& str);

    std::string val() override ;
    void set_val(const std::string& str) override ;

    static json_object* parse(const char *, int length, char base);

    _type type() override ;
    std::string to_string() override ;
};


#endif //STRING_H
