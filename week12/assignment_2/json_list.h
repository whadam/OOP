#ifndef JSON_LIST_H
#define JSON_LIST_H

#include "json_object.h"
#include <vector>

class json_list : public json_object {
private:
    std::vector<json_object*> v;
public:
    json_list();
    static json_object* parse(const char *, int length);
    json_object* operator[](int key) const;
    _type type() override;
    std::string to_string() override;
};

#endif // JSON_LIST_H