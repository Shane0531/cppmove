#include "menu.h"
#include "make.h"
#include "map.h"

// �޴� ���� ���� ǥ��
void Menu::menu_print()
{
	cout << endl;
	cout << endl;
	cout << "                             < < < ��  �� > > >     " << endl;
	cout << endl;
	cout << "                                                    " << endl;
	cout << "                                 �⺻  ����         " << endl;
	cout << "                                                    " << endl;
	cout << "                                                    " << endl;
	cout << "                               ����� �� ����       " << endl;
	cout << "                                                    " << endl;
	cout << "                                                    " << endl;
	cout << "                               ����� �� ����       " << endl;
	cout << "                                                    " << endl;
	cout << "                                                    " << endl;
	cout << "                                  �ڷΰ���          " << endl;
	cout << "                                                    " << endl;
}

// �޴� ȣ��
void Menu::menu_call()
{
	int line = 4;

	system("COLOR 1F");

	system("cls");
	menu_print();
	menu_show(line);

	while (1)
	{
		setInput(_getch());

		if (getInput() == 72)
		{
			if (getNow() != 1)
			{
				setNow(getNow() - 1);
				menu_hide(line);
				line -= 3;
				menu_show(line);
			}
			else
			{
				setNow(4);
				menu_hide(line);
				line = 13;
				menu_show(line);
			}
		}
		else if (getInput() == 80)
		{
			if (getNow() != 4)
			{
				setNow(getNow() + 1);
				menu_hide(line);
				line += 3;
				menu_show(line);
			}
			else
			{
				setNow(1);
				menu_hide(line);
				line = 4;
				menu_show(line);
			}
		}
		else if (getInput() == 13) // or 10
		{
			if (getNow() == 1)
				start1();
			else if (getNow() == 2)
				start2();
			else if (getNow() == 3)
				start3();
			else if (getNow() == 4)
			{
				gotoxy(0, 0);
				return;
			}

			system("cls");
			menu_print();
			menu_show(line);
		}
		else if (getInput() == 'z')
		{
			gotoxy(0, 0);
			return;
		}
	}
}

// ���� ����
void Menu::menu_show(int i)
{
	gotoxy(24, i);
	cout << "����������������������������" << endl;

	gotoxy(24, i+1);
	cout << "��";

	gotoxy(50, i + 1);
	cout << "��";

	gotoxy(24, i+2);
	cout << "����������������������������" << endl;
}

// ���� ����
void Menu::menu_hide(int i)
{
	gotoxy(24, i);
	cout << "                            " << endl;

	gotoxy(24, i + 1);
	cout << "  ";

	gotoxy(50, i + 1);
	cout << "  ";

	gotoxy(24, i + 2);
	cout << "                            " << endl;
}

// �⺻ ����
void Menu::start1()
{
	Menu_start_base base;
	base.menu_call();
}

// ����� �� ����
void Menu::start2()
{
	Make make;
	make.setMap_base();
	make.move(make);
}

// ����� �� ����
void Menu::start3()
{
	// �ҷ����� ��

	string_t open;
	int index = 0;

	open = GetMap();

	Base_map user(getUser_index());
	user.setNow(4);
	user.setMap_base();

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (open[index] == '1')
			{
				user.setMap_one(1 + (i * 2), 1 + (j * 2), "��");
				user.setX(1 + (i * 2));
				user.setY(1 + (j * 2));
			}
			else if (open[index] == '2')
				user.setMap_one(1 + (i * 2), 1 + (j * 2), "��");
			else if (open[index] == '3')
				user.setMap_one(1 + (i * 2), 1 + (j * 2), "��");

			index++;
		}
	}

	user.move(user);
}

// Ŀ�� �̵�
void Menu::gotoxy(int x, int y)
{
	COORD Cur;
	Cur.X = x;
	Cur.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}

// �޴� ���� ���� ǥ��
void Menu_start_base::menu_print()
{
	cout << endl;
	cout << endl;
	cout << "                             < < < ��  �� > > >     " << endl;
	cout << endl;
	cout << "                                                    " << endl;
	cout << "                                   1�� ��           " << endl;
	cout << "                                                    " << endl;
	cout << "                                                    " << endl;
	cout << "                                   2�� ��           " << endl;
	cout << "                                                    " << endl;
	cout << "                                                    " << endl;
	cout << "                                   3�� ��           " << endl;
	cout << "                                                    " << endl;
	cout << "                                                    " << endl;
	cout << "                                  �ڷΰ���          " << endl;
	cout << "                                                    " << endl;
}

// �޴� ȣ��
void Menu_start_base::menu_call()
{
	int line = 4;

	system("COLOR 1F");

	system("cls");
	menu_print();
	menu_show(line);

	while (1)
	{
		setInput(_getch());

		if (getInput() == 72)
		{
			if (getNow() != 1)
			{
				setNow(getNow()-1);
				menu_hide(line);
				line -= 3;
				menu_show(line);
			}
			else
			{
				setNow(4);
				menu_hide(line);
				line = 13;
				menu_show(line);
			}
		}
		else if (getInput() == 80)
		{
			if (getNow() != 4)
			{
				setNow(getNow()+1);
				menu_hide(line);
				line += 3;
				menu_show(line);
			}
			else
			{
				setNow(1);
				menu_hide(line);
				line = 4;
				menu_show(line);
			}
		}
		else if (getInput() == 13) // or 10
		{
			if (getNow() == 1)
				start1();
			else if (getNow() == 2)
				start2();
			else if (getNow() == 3)
				start3();
			else if (getNow() == 4)
			{
				gotoxy(0, 0);
				return;
			}

			system("cls");
			menu_print();
			menu_show(line);
		}
		else if (getInput() == 'z')
		{
			gotoxy(0, 0);
			return;
		}
	}
}

// 1�� �� ����
void Menu_start_base::start1()
{
	Base_map map;
	map.setNow(1);
	map.setMap_base();
	map.setMap_1();
	map.move(map);
}

// 2�� �� ����
void Menu_start_base::start2()
{
	Base_map map;
	map.setNow(2);
	map.setMap_base();
	map.setMap_2();
	map.move(map);
}

// 3�� �� ����
void Menu_start_base::start3()
{
	Base_map map;
	map.setNow(3);
	map.setMap_base();
	map.setMap_3();
	map.move(map);
}