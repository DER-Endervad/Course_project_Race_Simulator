#pragma once
#include "Ts_ground.h"
class Ts_ground_camel : public Ts_ground
{
public:
	My_Libraries_API Ts_ground_camel(std::string name = "Верблюд", int speed = 10, int time_before_rest = 30, int rest1 = 5, double rest2 = 8, int rest_all = 8);
};

