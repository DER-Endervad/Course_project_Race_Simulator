#include "Main_lib.h"
namespace Main_lib {
	Race* reg_race(const int& number,const int& length) {
		if (number == 1) {
			Race* r = new Race_ground(length); return r;
		}
		else if (number == 2) {
			Race* r = new Race_air(length); return r;
		}
		else {
			Race* r = new Race_all(length); return r;
		}
	}
}