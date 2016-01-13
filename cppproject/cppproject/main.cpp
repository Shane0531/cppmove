#include "make.h"
#include "map.h"
#include "data.h"
#include"mainmenu.h"

void CursorView(char show)
{
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);




	ConsoleCursor.bVisible = show;

	ConsoleCursor.dwSize = 1;




	SetConsoleCursorInfo(hConsole, &ConsoleCursor);

}

void main()
{
	wcout.imbue(locale("kor"));
	CursorView(0);
	LogoPrint();
	MainMenu m;
	m.menu_call();
}