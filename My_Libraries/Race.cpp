#include "Race.h"
Race::Race(int length, std::string name, std::string type_race) {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	this->name = name;
	this->length = length;
	this->type_race = type_race;
	transport.fill(0);
	time.fill(0);
	count_ts = 0;
}

bool Race::add_transport(const int& number, bool& already, bool& another, std::string& name_ts) {
	if (transport[number-1] == 0) {
		if (number > 0 && number < 5 && (type_race == "ground" || type_race == "all")) {
			Ts_ground* ts;
			if (number == 1) {
				ts = new Ts_ground_camel;
			}
			else if (number == 2) {
				ts = new Ts_ground_speed_camel;
			}
			else if (number == 3) {
				ts = new Ts_ground_centaur;
			}
			else {
				ts = new Ts_ground_all_terrain_boots;
			}
			transport[number-1] = 1; count_ts++;
			time[number-1] = ts->time(length);
			name_transport[number-1] = ts->get_name();
			name_ts = this->name_transport[number-1];
			delete ts;
			return true;
		}
		else if (number > 4 && number < 8 && (type_race == "air" || type_race == "all")) {
			Ts_air* ts;
			if (number == 5) {
				ts = new Ts_air_rug_plane(length);
			}
			else if (number == 6) {
				ts = new Ts_air_eagle;
			}
			else {
				ts = new Ts_air_broom(length);
			}
			transport[number-1] = 1; count_ts++;
			time[number-1] = ts->time(length);
			name_transport[number-1] = ts->get_name();
			name_ts = this->name_transport[number-1];
			delete ts;
			return true;
		}
		else {
			another = true;
			return false;
		}
	}
	else {
		name_ts = this->name_transport[number-1];
		already = true;
		return false;
	}
}

void Race::result_race() {
	int count = 0;
	for (int i = count_ts; i > 0; --i) {
		int min = 0; int number = 0;
		for (int j = 0; j < 7; ++j) {
			if (transport[j] == 1 && min == 0) {
				min = time[j]; number = j;
			}
			else if (transport[j] == 1 && min > time[j]) {
				min = time[j]; number = j;
			}
		}
		result[count] = std::to_string(count+1) + ". " + name_transport[number] + ". Время: " + std::to_string(time[number]);
		++count; transport[number] = 0;
	}
}

std::string Race::get_result(const int& number) {
	return result[number];
}


std::string Race::info() {
	std::string output;
	output = name + ". Расстояние: " + std::to_string(length);
	return output;
}

int Race::get_count_ts() {
	return count_ts;
}

std::string Race::get_name_transport() {
	std::string output; int first = 0;
	for (int i = 0; i < 7; ++i) {
		if (transport[i] == 1 && first == 0) {
			output = name_transport[i];
			first++;
		}
		else if (transport[i] == 1) {
			output = output + ", " + name_transport[i];
		}
	}
	return output;
}

std::string Race::get_name() {
	return name;
}


