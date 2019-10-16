#include "unique_immut.h"

namespace ptr {
unique_immut::unique_immut() {
    _mgr = new mgr();
}

unique_immut::unique_immut(Object *obj) {
    _mgr = new mgr(obj);
}

unique_immut::unique_immut(const unique_immut &immut) {
    if (immut._mgr) {
        int val = immut._mgr->ptr->get();
        _mgr = new mgr(val);
    }
}

unique_immut::~unique_immut() {
    release();
}

Object* unique_immut::get() const {
	if (this->_mgr->ptr != nullptr) return this->_mgr->ptr;
	else return nullptr;
}

void unique_immut::release() {
	if (this->_mgr->ptr != nullptr) this->_mgr->~mgr();
}

unique_immut unique_immut::operator+(unique_immut& unique) {
	int newval = this->_mgr->ptr->get() + unique._mgr->ptr->get();
	this->release();
	unique.release();
	return unique_immut(new Object(newval));
}

unique_immut unique_immut::operator-(unique_immut& unique) {
	int newval = this->_mgr->ptr->get() - unique._mgr->ptr->get();
	this->release();
	unique.release();
	return unique_immut(new Object(newval));
}

unique_immut unique_immut::operator*(unique_immut& unique) {
	int newval = this->_mgr->ptr->get() * unique._mgr->ptr->get();
	this->release();
	unique.release();
	return unique_immut(new Object(newval));
}

unique_immut unique_immut::operator/(unique_immut& unique) {
	int newval = this->_mgr->ptr->get() / unique._mgr->ptr->get();
	this->release();
	unique.release();
	return unique_immut(new Object(newval));
}

Object* unique_immut::operator->() {
	return this->_mgr->ptr;
}

unique_immut& unique_immut::operator=(unique_immut& r) {
	this->release();
	this->_mgr = r._mgr;
	return *this;
}
} // end of namespace ptr
