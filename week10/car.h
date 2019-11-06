#include <iostream>
#include "vehicle.h"

class car : public vehicle {
private:
	char* car_name;
public:
	car();
	car(int wheel_number, int max_speed);
	car(int wheel_number, int max_speed, char* car_name);
	car(int wheel_number, int max_speed, char* car_name, bool has_name);

	char* get_car_name();
	const char* get_class_name();
	int get_wheel_number();
	int get_max_speed();
	bool get_has_name();

	void set_car_name(char* name);
	void set_wheel_number(int number);
	void set_max_speed(int speed);
	void set_has_name(bool name);
};
