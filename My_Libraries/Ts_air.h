#pragma once
#include "Transport.h"
class Ts_air : public Transport
{
private:
	int coefficient;
protected:
	My_Libraries_API void set_coefficient2(const int& coefficient);
public:
	My_Libraries_API Ts_air(std::string name, int speed, int coefficient, std::string type_ts = "air");
	My_Libraries_API int time(const int& length);
};

