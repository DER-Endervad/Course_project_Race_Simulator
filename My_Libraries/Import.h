#pragma once
#ifdef My_Libraries_EXPORTS
#define My_Libraries_API __declspec(dllexport)
#else
#define My_Libraries_API __declspec(dllimport)
#endif
#include <iostream>
#include <array>
#include <Windows.h>
#include <sstream>
