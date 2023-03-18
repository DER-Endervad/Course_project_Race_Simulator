#pragma once
#include "Ts_ground.h"
class Ts_ground_speed_camel : public Ts_ground
{
public:
	My_Libraries_API Ts_ground_speed_camel(std::string name = "Верблюд-быстроход", int speed = 40, int time_before_rest = 10, int rest1 = 5, double rest2 = 6.5, int rest_all = 8);
};

