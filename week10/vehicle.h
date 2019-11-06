#include <iostream>

#ifndef h
#define h

class vehicle {
protected:
	bool has_name;
	int wheel_number;
	int max_speed;
public:
	vehicle();
	vehicle(int wheel_number, int max_speed);
	vehicle(int wheel_number, int max_speed, bool has_name);

	virtual int get_wheel_number();
	virtual int get_max_speed();
	virtual bool get_has_name();
	const char* get_class_name();
	
	virtual void set_wheel_number(int number);
	virtual void set_max_speed(int speed);
	virtual void set_has_name(bool name);
};

#endif
