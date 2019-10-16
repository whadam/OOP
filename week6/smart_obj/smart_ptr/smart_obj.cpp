#include "smart_obj.h"

namespace ptr {
smart_obj::smart_obj() {
    std::cout << "Smart pointer Creation" << std::endl;
};

smart_obj::smart_obj(int _val) {
	std::cout << "Smart pointer Creation" << std::endl;
}

smart_obj::~smart_obj() {
    std::cout << "Smart pointer Deletion" << std::endl;
};
} // end of namespace ptr
