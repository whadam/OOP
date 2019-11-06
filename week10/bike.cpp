#include "bike.h"

bike::bike() {

}

bike::bike(int num, int speed) {
	this->wheel_number = num;
	this->max_speed = speed;
}

bike::bike(int num, int speed, char* name) {
	this->wheel_number = num;
	this->max_speed = speed;
	this->bike_name = name;
}

bike::bike(int num, int speed, char* name, int bnum) {
	this->wheel_number = num;
	this->max_speed = speed;
	this->bike_name = name;
	this->bike_number = bnum;
}

bike::bike(int num, int speed, char* name, int bnum, bool has_name) {
	this->wheel_number = num;
	this->max_speed = speed;
	this->bike_name = name;
	this->bike_number = bnum;
	this->has_name = has_name;
}

int bike::get_bike_number() {
	return this->bike_number;
}

char* bike::get_bike_name() {
	return this->bike_name;
}

const char* bike::get_class_name() {
	return "bike";
}

int bike::get_wheel_number() {
	return this->wheel_number;
}

int bike::get_max_speed() {
	return this->max_speed;
}

bool bike::get_has_name() {
	return this->has_name;
}


void bike::set_bike_name(char* name) {
	this->bike_name = name;
}

void bike::set_bike_number(int num) {
	this->bike_number = num;
}

void bike::set_wheel_number(int number) {
	this->wheel_number = number;
}

void bike::set_max_speed(int speed) {
	this->max_speed = speed;
}

void bike::set_has_name(bool name) {
	this->has_name = name;
}

