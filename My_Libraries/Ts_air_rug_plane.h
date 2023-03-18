#pragma once
#include "Ts_air.h"
class Ts_air_rug_plane : public Ts_air
{
public:
	My_Libraries_API Ts_air_rug_plane(int length, int coefficient = 0, std::string name = "Ковёр-самолёт", int speed = 10);
	My_Libraries_API void set_coefficient(const int& length);
};

