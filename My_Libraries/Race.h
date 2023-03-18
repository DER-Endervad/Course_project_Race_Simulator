#pragma once

#include "Import.h"
#include "Transport.h"

#include "Ts_ground.h"
#include "Ts_ground_camel.h"
#include "Ts_ground_speed_camel.h"
#include "Ts_ground_centaur.h"
#include "Ts_ground_all_terrain_boots.h"

#include "Ts_air.h"
#include "Ts_air_rug_plane.h"
#include "Ts_air_eagle.h"
#include "Ts_air_broom.h"

class Race
{
private:
	std::string name;
	std::string type_race;
	int length;
	int count_ts;
	std::array<std::string, 7> name_transport;
	std::array<int, 7> transport;
	std::array<int, 7> time;
	std::array<std::string, 7> result;
public:
	My_Libraries_API Race(int length, std::string name, std::string type_race);
	My_Libraries_API bool add_transport(const int& number, bool& already, bool& another, std::string& name_ts);
	My_Libraries_API void result_race();
	My_Libraries_API std::string get_result(const int& number);
	My_Libraries_API std::string info();
	My_Libraries_API int get_count_ts();
	My_Libraries_API std::string get_name_transport();
	My_Libraries_API std::string get_name();
};

