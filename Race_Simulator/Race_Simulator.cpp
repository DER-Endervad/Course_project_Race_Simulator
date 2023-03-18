#include <iostream>
#include <Windows.h>

#include "Main_lib.h"

Race* reg_race();
void reg_transport(Race* race);
void reg_transport2(Race* race);
void transport_list();
void result_race(Race* race);
bool end();

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::cout << "Добро пожаловать в гоночный симулятор!" << std::endl;
	bool true_false = true;
	do {
		true_false = true;
		auto race = reg_race();
		reg_transport(race);
		result_race(race);
		true_false = end();
	} while (true_false);
	system("pause");
	return 0;
}

Race* reg_race() {
	int input;
	while (true) {
		std::cout << "1. Гонка для наземного транспорта" << std::endl;
		std::cout << "2. Гонка для воздушного транспорта" << std::endl;
		std::cout << "3. Гонка для наземного и воздушного транспорта" << std::endl;
		std::cout << "Выберите тип гонки, введя ее номер: ";
		if ((std::cin >> input).good() && input == 1 || input == 2 || input == 3) {
			std::cout << "\n" << std::endl;
			while (true) {
				int input_length = 0;
				std::cout << "Укажите длину дистанции (должна быть положительна): ";
				if ((std::cin >> input_length).good() && input_length > 0) {
					std::cout << "\n" << std::endl;
					return Main_lib::reg_race(input, input_length);
				}
				std::cin.clear();
				std::cin.ignore();
				std::cout << "\nВы ввели неверную длину дистанции\n" << std::endl;
			}
		}
		std::cin.clear();
		std::cin.ignore();
		std::cout << "\nВы ввели неверный тип гонки, попробуйте еще раз\n" << std::endl;
	}
}

void reg_transport(Race* race) {
	bool true_false = true; int input = 0;
	while (true_false) {
		int number_ts = race->get_count_ts();
		if (number_ts < 2) {
			std::cout << "Должно быть зарегистрировано хотя бы 2 транспортных средства" << std::endl;
		}
		std::cout << "1. Зарегистрировать транспорт" << std::endl;
		if (number_ts >= 2) {
			std::cout << "2. Начать гонку" << std::endl;
		}
		std::cout << "Ваш выбор: ";
		while (true) {
			if ((std::cin >> input).good() && input == 1 || input == 2) {
				std::cout << "\n" << std::endl;
				if (input == 1) {
					reg_transport2(race); break;
				}
				else if (number_ts >= 2) {
					true_false = false; break;
				}
				else {
					std::cout << "\nВы ввели неверный символ\n" << std::endl;
				}
			}
			else {
				std::cout << "\nВы ввели неверный символ\n" << std::endl;
			}
			std::cin.clear();
			std::cin.ignore();
		}
	}
}

void reg_transport2(Race* race) {
	while (true) {
		std::cout << race->info() << std::endl;
		int number_ts = race->get_count_ts();
		if (number_ts > 0) {
			std::cout << "Зарегистрированные транспортные средства: ";
			std::cout << race->get_name_transport() << std::endl;
		}
		transport_list();
			int input = 0;
			if ((std::cin >> input).good() && input > -1 && input < 8) {
				if (input == 0) {
					std::cout << "\n" << std::endl;
					break;
				}
				bool already = false, another = false; std::string name;
				std::cout << std::endl;
				if (!(race->add_transport(input, already, another, name))) {
					if (already) {
						std::cout << name << " уже зарегистрирован!\n" << std::endl;
					}
					if (another) {
						std::cout << "Попытка зарегистрировать неправильный тип транспортного средства!\n" << std::endl;
					}
				}
				else {
					std::cout << name << " успешно зарегистрирован!\n" << std::endl;
				}
			}
			else {
				std::cout << "\nВы ввели неверный символ\n" << std::endl;
			}
			std::cin.clear();
			std::cin.ignore();
	}
}

void transport_list() {
	std::cout << "1. Верблюд" << std::endl;
	std::cout << "2. Верблюд - быстроход" << std::endl;
	std::cout << "3. Кентавр" << std::endl;
	std::cout << "4. Ботинки - вездеходы" << std::endl;
	std::cout << "5. Ковёр - самолёт" << std::endl;
	std::cout << "6. Орёл" << std::endl;
	std::cout << "7. Метла" << std::endl;
	std::cout << "0. Закончить регистрацию" << std::endl;
	std::cout << "Выберите номер транспорта или 0 для окончания процесса регистрации: ";
}

void result_race(Race* race) {
	race->result_race();
	std::cout << "Результаты гонки: " << std::endl;
	for (int i = 0; i < race->get_count_ts(); ++i) {
		std::cout << race->get_result(i) << std::endl;
	}
	std::cout << "\n" << std::endl;
}

bool end() {
	while (true) {
		bool check_true = false;
		std::cout << "1. Провести ещё одну гонку \n2. Выйти \nВаш выбор: ";
		int input = 0;
		if ((std::cin >> input).good() && input == 1 || input == 2) {

			if (input == 2) { return false; }
			else { std::cout << "\n" << std::endl; return true; }
		}
		std::cin.clear();
		std::cin.ignore();
		std::cout << "\nВы ввели неверный символ\n" << std::endl;
	}
}