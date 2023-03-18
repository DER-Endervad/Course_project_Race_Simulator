#pragma once
#include "Ts_ground.h"
class Ts_ground_centaur : public Ts_ground
{
public:
	My_Libraries_API Ts_ground_centaur(std::string name = "Кентавр", int speed = 15, int time_before_rest = 8, int rest1 = 2, double rest2 = 2, int rest_all = 2);
};
