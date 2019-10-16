#ifndef SMART_PTR_SMART_OBJ_H
#define SMART_PTR_SMART_OBJ_H

#include "object.h"

namespace ptr {
class smart_obj {
protected:
    struct mgr {
        mgr() {
            ptr = nullptr;
            count = 0;
        }
        explicit mgr(int val) {
            ptr = new Object(val);
            count = 1;
        }
        explicit mgr(Object* _ptr) {
            ptr = _ptr;
            count = 1;
        }
        ~mgr() {
            delete(ptr);
            ptr = nullptr;
        }
        Object* ptr;
        int count;
    };
public:
    smart_obj();
	explicit smart_obj(int _val);
    ~smart_obj();
}; // end of class smart_obj
} // end of namespace ptr

#endif //SMART_PTR_SMART_OBJ_H
