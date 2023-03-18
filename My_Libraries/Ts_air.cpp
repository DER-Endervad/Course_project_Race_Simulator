#include "Ts_air.h"

Ts_air::Ts_air(std::string name, int speed, int coefficient, std::string type_ts) : Transport(name, type_ts, speed) {
	this->coefficient = coefficient;
}

int Ts_air::time(const int& length) {
	int length_s = length - (length / 100 * coefficient);
	return length_s / get_speed();
}

void Ts_air::set_coefficient2(const int& coefficient) {
	this->coefficient = coefficient;
}