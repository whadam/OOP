#include "shared_mut.h"

namespace ptr {
shared_mut::shared_mut() {
    _mgr = new mgr();
}

shared_mut::shared_mut(Object* _obj) {
    _mgr = new mgr(_obj);
}

shared_mut::~shared_mut() {
    release();
}

void shared_mut::increase() {
	_mgr->count++;
}

Object* shared_mut::get() const {
	if (this->_mgr->ptr != nullptr) return this->_mgr->ptr;
	else return nullptr;
}

void shared_mut::release() {
	_mgr->count--;
	if (_mgr->count == 0) this->_mgr->~mgr();
}

int shared_mut::count() {
	return _mgr->count;
}

shared_mut shared_mut::operator+(const shared_mut& shared) {
	int newval = this->_mgr->ptr->get() + shared._mgr->ptr->get();
	return shared_mut(new Object(newval));
}

shared_mut shared_mut::operator-(const shared_mut& shared) {
	int newval = this->_mgr->ptr->get() - shared._mgr->ptr->get();
	return shared_mut(new Object(newval));
}

shared_mut shared_mut::operator*(const shared_mut& shared) {
	int newval = this->_mgr->ptr->get() * shared._mgr->ptr->get();
	return shared_mut(new Object(newval));
}

shared_mut shared_mut::operator/(const shared_mut& shared) {
	int newval = this->_mgr->ptr->get() / shared._mgr->ptr->get();
	return shared_mut(new Object(newval));
}

Object* shared_mut::operator->() {
	return this->_mgr->ptr;
}

shared_mut& shared_mut::operator=(const shared_mut& r) {
	this->release();
	this->_mgr = r._mgr;
	this->increase();
	return *this;
}
} // end of namespace ptr
