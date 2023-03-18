#include "Ts_air_rug_plane.h"
Ts_air_rug_plane::Ts_air_rug_plane(int length, int coefficient, std::string name, int speed) : Ts_air(name, speed, coefficient) {
	if (length < 1000) {
		this->set_coefficient2(0);
	}
	else if (length < 5000) {
		this->set_coefficient2(3);
	}
	else if (length < 10000) {
		this->set_coefficient2(10);
	}
	else {
		this->set_coefficient2(5);
	}
}

void Ts_air_rug_plane::set_coefficient(const int& length) {
	if (length < 1000) {
		this->set_coefficient(0);
	}
	else if (length < 5000) {
		this->set_coefficient(3);
	}
	else if (length < 10000) {
		this->set_coefficient(10);
	}
	else {
		this->set_coefficient(5);
	}
}