#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>
#include <locale.h>

#define MY_COLOR_BLACK			0
#define MY_COLOR_DARK_BLUE		1
#define MY_COLOR_SOFT_GREEN		2
#define MY_COLOR_SOFT_BLUE		3
#define MY_COLOR_DARK_RED		4
#define MY_COLOR_PURPLE			5
#define MY_COLOR_DARK_YELLOW	6
#define MY_COLOR_GRAY			7
#define MY_COLOR_DARK_GRAY		8
#define MY_COLOR_CYAN			9
#define MY_COLOR_LIGTH_GREEN	10
#define MY_COLOR_LIGTH_BLUE		11
#define MY_COLOR_LIGTH_RED		12
#define MY_COLOR_PINK			13
#define MY_COLOR_LIGTH_YELLOW	14
#define MY_COLOR_WHITE			15


class lab
{
public:

	lab() {};
	~lab() {};


	void setColor(int foreGround, int backGround) 
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), backGround * 16 + foreGround);
	}

	void resetColor() 
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), MY_COLOR_BLACK * 16 + MY_COLOR_WHITE);
	}
};

