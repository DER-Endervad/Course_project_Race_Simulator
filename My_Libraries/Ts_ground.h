#pragma once
#include "Transport.h"
class Ts_ground : public Transport
{
private:
	int time_before_rest;
	int rest1;
	double rest2;
	int rest_all;
public:
	My_Libraries_API Ts_ground(std::string name, int speed, int time_before_rest, int rest1, double rest2, int rest_all, std::string type_ts = "ground");
	My_Libraries_API int time(const int& length);
	My_Libraries_API int get_rest1();
	My_Libraries_API int get_rest2();
	My_Libraries_API int get_rest_all();
};

