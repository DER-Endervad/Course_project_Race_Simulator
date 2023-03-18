#pragma once

#include "Import.h"

class Transport
{
private:
	std::string name;
	std::string type_ts;
	int speed;

public:
	My_Libraries_API Transport(std::string name, std::string type_ts, int speed);
	My_Libraries_API int get_speed();
	My_Libraries_API std::string get_name();
};

