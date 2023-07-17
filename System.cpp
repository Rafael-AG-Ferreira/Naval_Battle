#include "System.h"

System::System()
{
}

System::~System()
{
}

void System::Pausa()
{
	cin.clear();
	cin.sync();
	cin.get();
}

void System::Clear_S()
{
	DWORD n;                        
	DWORD size;                   
	COORD coord = { 0 };             
	CONSOLE_SCREEN_BUFFER_INFO csbi;

	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

	GetConsoleScreenBufferInfo(h, &csbi);

	size = csbi.dwSize.X * csbi.dwSize.Y;

	FillConsoleOutputCharacter(h, TEXT(' '), size, coord, &n);
	GetConsoleScreenBufferInfo(h, &csbi);
	FillConsoleOutputAttribute(h, csbi.wAttributes, size, coord, &n);

	SetConsoleCursorPosition(h, coord);
}


