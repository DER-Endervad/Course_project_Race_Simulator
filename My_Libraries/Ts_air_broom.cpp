#include "Ts_air_broom.h"
Ts_air_broom::Ts_air_broom(int length, int coefficient, std::string name, int speed) : Ts_air(name, speed, coefficient) {
	int coef = length / 1000;
	this->set_coefficient2(coef);
}

void Ts_air_broom::set_coefficient(const int& length) {
	int coef = length / 1000;
	this->set_coefficient(coef);
}