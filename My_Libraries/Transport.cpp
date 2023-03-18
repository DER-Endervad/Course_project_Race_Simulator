#include "Transport.h"

Transport::Transport(std::string name, std::string type_ts, int speed) {
	this->name = name;
	this->type_ts = type_ts;
	this->speed = speed;
}

int Transport::get_speed() {
	return speed;
}

std::string Transport::get_name() {
	return name;
}