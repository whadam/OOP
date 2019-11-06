#include <iostream>
#include "vehicle.h"

class bike : public vehicle {
private:
	char* bike_name;
	int bike_number;
public:
	bike();
	bike(int num, int speed);
	bike(int num, int speed, char* name);
	bike(int num, int speed, char* name, int bnum);
	bike(int num, int speed, char* name, int bnum, bool has_name);

	int get_bike_number();
	char* get_bike_name();
	const char* get_class_name();
	int get_wheel_number();
	int get_max_speed();
	bool get_has_name();

	void set_bike_name(char* name);
	void set_bike_number(int num);
	void set_wheel_number(int number);
	void set_max_speed(int speed);
	void set_has_name(bool name);
};
