#include "Ts_ground.h"

Ts_ground::Ts_ground(std::string name, int speed, int time_before_rest, int rest1, double rest2, int rest_all, std::string type_ts) : Transport(name, type_ts, speed) {
	this->time_before_rest = time_before_rest;
	this->rest1 = rest1;
	this->rest2 = rest2;
	this->rest_all = rest_all;
}

int Ts_ground::time(const int& length) {
	int time = length / get_speed();
	int count_rest = 0;
	if (time % time_before_rest == 0) {
		count_rest = time / time_before_rest - 1;
	}
	else {
		count_rest = time / time_before_rest;
	}
	for (int i = 1; i <= count_rest; ++i) {
		if (i == 1) {
			time = time + rest1;
		}
		else if (i == 2) {
			time = time + rest2;
		}
		else {
			time = time + rest_all;
		}
	}
	return time;
}

int Ts_ground::get_rest1() {
	return rest1;
}

int Ts_ground::get_rest2() {
	return rest_all;
}

int Ts_ground::get_rest_all() {
	return rest_all;
}