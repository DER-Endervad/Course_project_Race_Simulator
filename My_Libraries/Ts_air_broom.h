#pragma once
#include "Ts_air.h"
class Ts_air_broom : public Ts_air
{
public:
	My_Libraries_API Ts_air_broom(int length, int coefficient = 0, std::string name = "Метла", int speed = 20);
	My_Libraries_API void set_coefficient(const int& length);
};

