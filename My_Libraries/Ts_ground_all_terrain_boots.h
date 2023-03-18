#pragma once
#include "Ts_ground.h"
class Ts_ground_all_terrain_boots : public Ts_ground
{
public:
	My_Libraries_API Ts_ground_all_terrain_boots(std::string name = "Ботинки-вездеходы", int speed = 6, int time_before_rest = 60, int rest1 = 10, double rest2 = 5, int rest_all = 5);
};

