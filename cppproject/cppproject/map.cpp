#include "map.h"

// ⑷營 裘 鼻鷓 轎溘
void Base_map::map_print()
{
	system("cls");

	cout << endl;
	cout << endl;

	if (now == 0)
		cout << "                            < < < 纔蝶お醞 > > >" << endl;
	else if (now == 1)
		cout << "                             < < < 1廓 裘 > > >" << endl;
	else if (now == 2)
		cout << "                             < < < 2廓 裘 > > >" << endl;
	else if (now == 3)
		cout << "                             < < < 3廓 裘 > > >" << endl;
	else if (now == 4)
		cout << "                           < < < 餌辨濠  裘 > > >" << endl;

	cout << endl;

	for (int i = 0; i < 13; i++)
	{
		cout << "                         ";
		for (int j = 0; j < 13; j++)
			cout << map[i][j];
		cout << endl;
	}

	gotoxy(0, 18);
	cout << "             	檜翕 : ∟⊥⊿∠ , 棻衛衛濛 : R , 釭陛晦 : Z" << endl;
}

// 議葛攪 檜翕
int Base_map::move(Base_map& map)
{
	char input;
	string temp[13][13];
	int tempX, tempY;

	if (now == 0 || now == 4)
	{
		for (int i = 0; i < 13; i++)
		{
			for (int j = 0; j < 13; j++)
			{
				temp[i][j] = map.map[i][j];
			}
		}

		tempX = user_x;
		tempY = user_y;
	}

	map.map_print();

	while (1)
	{
		if (check() == 1)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			gotoxy(35, 10);
			cout << "Success";
			
			if (now == 4)
			{
				UpScore(user_index);

				gotoxy(30, 12);
				cout << "5薄檜 螢嫉蝗棲棻.";
			}

			Sleep(1000);
			system("COLOR 1F");
			return 1;
		}

		while (1)
		{
			input = _getch();

			if (input == 75)
			{
				map.move_left();
				break;
			}
			else if (input == 77)
			{
				map.move_right();
				break;
			}
			else if (input == 72)
			{
				map.move_up();
				break;
			}
			else if (input == 80)
			{
				map.move_down();
				break;
			}
			else if (input == 'r')
			{
				if (now == 0 || now == 4)
				{
					for (int i = 0; i < 13; i++)
					{
						for (int j = 0; j < 13; j++)
						{
							map.map[i][j] = temp[i][j];
						}
					}

					user_x = tempX;
					user_y = tempY;
				}
				if (now == 1)
				{
					map.setMap_base();
					map.setMap_1();
				}
				else if (now == 2)
				{
					map.setMap_base();
					map.setMap_2();
				}
				else if (now == 3)
				{
					map.setMap_base();
					map.setMap_3();
				}

				map.map_print();
				break;
			}
			else if (input == 'z')
				return 0;
		}
	}

};

// ∠酈 揚毓擊 陽
void Base_map::move_left()
{
	if (user_y == 1)
		return;

	while (map[user_x][user_y - 2] == "﹤")
	{
		map[user_x][user_y] = "﹥";
		map[user_x][user_y - 2] = "��";


		gotoxy(25 + (user_y * 2), 4 + user_x);
		cout << map[user_x][user_y];

		user_y -= 2;

		gotoxy(25 + (user_y * 2), 4 + user_x);
		cout << map[user_x][user_y];

		if (user_y == 1)
			return;

		Sleep(sleep_time);
	}
}

// ⊥酈 揚毓擊 陽
void Base_map::move_right()
{
	if (user_y == 11)
		return;

	while (map[user_x][user_y + 2] == "﹤")
	{
		map[user_x][user_y] = "﹥";
		map[user_x][user_y + 2] = "��";

		gotoxy(25 + (user_y * 2), 4 + user_x);
		cout << map[user_x][user_y];

		user_y += 2;

		gotoxy(25 + (user_y * 2), 4 + user_x);
		cout << map[user_x][user_y];

		if (user_y == 11)
			return;

		Sleep(sleep_time);
	}
}

// ∟酈 揚毓擊 陽
void Base_map::move_up()
{
	if (user_x == 1)
		return;

	while (map[user_x - 2][user_y] == "﹤")
	{
		map[user_x][user_y] = "﹥";
		map[user_x - 2][user_y] = "��";

		gotoxy(25 + (user_y * 2), 4 + user_x);
		cout << map[user_x][user_y];

		user_x -= 2;

		gotoxy(25 + (user_y * 2), 4 + user_x);
		cout << map[user_x][user_y];

		if (user_x == 1)
			return;

		Sleep(sleep_time);
	}
}

// ⊿酈 揚毓擊 陽
void Base_map::move_down()
{
	if (user_x == 11)
		return;

	while (map[user_x + 2][user_y] == "﹤")
	{
		map[user_x][user_y] = "﹥";
		map[user_x + 2][user_y] = "��";

		gotoxy(25 + (user_y * 2), 4 + user_x);
		cout << map[user_x][user_y];

		user_x += 2;

		gotoxy(25 + (user_y * 2), 4 + user_x);
		cout << map[user_x][user_y];

		if (user_x == 11)
			return;

		Sleep(sleep_time);
	}
}

// 晦獄 裘 撢た
void Base_map::setMap_base()
{
	map[0][0] = "旨";
	map[0][1] = "收";
	map[0][2] = "有";
	map[0][3] = "收";
	map[0][4] = "有";
	map[0][5] = "收";
	map[0][6] = "有";
	map[0][7] = "收";
	map[0][8] = "有";
	map[0][9] = "收";
	map[0][10] = "有";
	map[0][11] = "收";
	map[0][12] = "旬";

	map[1][0] = "早";
	map[1][1] = "﹤";
	map[1][2] = "早";
	map[1][3] = "﹤";
	map[1][4] = "早";
	map[1][5] = "﹤";
	map[1][6] = "早";
	map[1][7] = "﹤";
	map[1][8] = "早";
	map[1][9] = "﹤";
	map[1][10] = "早";
	map[1][11] = "﹤";
	map[1][12] = "早";

	map[2][0] = "曳";
	map[2][1] = "收";
	map[2][2] = "朱";
	map[2][3] = "收";
	map[2][4] = "朱";
	map[2][5] = "收";
	map[2][6] = "朱";
	map[2][7] = "收";
	map[2][8] = "朱";
	map[2][9] = "收";
	map[2][10] = "朱";
	map[2][11] = "收";
	map[2][12] = "朽";

	map[3][0] = "早";
	map[3][1] = "﹤";
	map[3][2] = "早";
	map[3][3] = "﹤";
	map[3][4] = "早";
	map[3][5] = "﹤";
	map[3][6] = "早";
	map[3][7] = "﹤";
	map[3][8] = "早";
	map[3][9] = "﹤";
	map[3][10] = "早";
	map[3][11] = "﹤";
	map[3][12] = "早";

	map[4][0] = "曳";
	map[4][1] = "收";
	map[4][2] = "朱";
	map[4][3] = "收";
	map[4][4] = "朱";
	map[4][5] = "收";
	map[4][6] = "朱";
	map[4][7] = "收";
	map[4][8] = "朱";
	map[4][9] = "收";
	map[4][10] = "朱";
	map[4][11] = "收";
	map[4][12] = "朽";

	map[5][0] = "早";
	map[5][1] = "﹤";
	map[5][2] = "早";
	map[5][3] = "﹤";
	map[5][4] = "早";
	map[5][5] = "﹤";
	map[5][6] = "早";
	map[5][7] = "﹤";
	map[5][8] = "早";
	map[5][9] = "﹤";
	map[5][10] = "早";
	map[5][11] = "﹤";
	map[5][12] = "早";

	map[6][0] = "曳";
	map[6][1] = "收";
	map[6][2] = "朱";
	map[6][3] = "收";
	map[6][4] = "朱";
	map[6][5] = "收";
	map[6][6] = "朱";
	map[6][7] = "收";
	map[6][8] = "朱";
	map[6][9] = "收";
	map[6][10] = "朱";
	map[6][11] = "收";
	map[6][12] = "朽";

	map[7][0] = "早";
	map[7][1] = "﹤";
	map[7][2] = "早";
	map[7][3] = "﹤";
	map[7][4] = "早";
	map[7][5] = "﹤";
	map[7][6] = "早";
	map[7][7] = "﹤";
	map[7][8] = "早";
	map[7][9] = "﹤";
	map[7][10] = "早";
	map[7][11] = "﹤";
	map[7][12] = "早";

	map[8][0] = "曳";
	map[8][1] = "收";
	map[8][2] = "朱";
	map[8][3] = "收";
	map[8][4] = "朱";
	map[8][5] = "收";
	map[8][6] = "朱";
	map[8][7] = "收";
	map[8][8] = "朱";
	map[8][9] = "收";
	map[8][10] = "朱";
	map[8][11] = "收";
	map[8][12] = "朽";

	map[9][0] = "早";
	map[9][1] = "﹤";
	map[9][2] = "早";
	map[9][3] = "﹤";
	map[9][4] = "早";
	map[9][5] = "﹤";
	map[9][6] = "早";
	map[9][7] = "﹤";
	map[9][8] = "早";
	map[9][9] = "﹤";
	map[9][10] = "早";
	map[9][11] = "﹤";
	map[9][12] = "早";

	map[10][0] = "曳";
	map[10][1] = "收";
	map[10][2] = "朱";
	map[10][3] = "收";
	map[10][4] = "朱";
	map[10][5] = "收";
	map[10][6] = "朱";
	map[10][7] = "收";
	map[10][8] = "朱";
	map[10][9] = "收";
	map[10][10] = "朱";
	map[10][11] = "收";
	map[10][12] = "朽";

	map[11][0] = "早";
	map[11][1] = "﹤";
	map[11][2] = "早";
	map[11][3] = "﹤";
	map[11][4] = "早";
	map[11][5] = "﹤";
	map[11][6] = "早";
	map[11][7] = "﹤";
	map[11][8] = "早";
	map[11][9] = "﹤";
	map[11][10] = "早";
	map[11][11] = "﹤";
	map[11][12] = "早";

	map[12][0] = "曲";
	map[12][1] = "收";
	map[12][2] = "朴";
	map[12][3] = "收";
	map[12][4] = "朴";
	map[12][5] = "收";
	map[12][6] = "朴";
	map[12][7] = "收";
	map[12][8] = "朴";
	map[12][9] = "收";
	map[12][10] = "朴";
	map[12][11] = "收";
	map[12][12] = "旭";
}

// 1廓 裘 撢た
void Base_map::setMap_1()
{
	setX(7);
	setY(5);
	setMap_one(7, 5, "��");
	setMap_one(5, 1, "≦");
	setMap_one(3, 9, "≦");
	setMap_one(9, 3, "≦");
	setMap_one(7, 11, "≦");
}

// 2廓 裘 撢た
void Base_map::setMap_2()
{
	setX(5);
	setY(3);
	setMap_one(5, 3, "��");
	setMap_one(1, 1, "≦");
	setMap_one(1, 3, "≦");
	setMap_one(3, 7, "≦");
	setMap_one(7, 3, "≦");
	setMap_one(7, 3, "≦");
	setMap_one(9, 7, "≦");
	setMap_one(11, 1, "≦");

	setMap_one(0, 10, "旬");
	setMap_one(1, 10, "早");
	setMap_one(2, 10, "朽");
	setMap_one(3, 10, "早");
	setMap_one(4, 10, "朽");
	setMap_one(5, 10, "早");
	setMap_one(6, 10, "朽");
	setMap_one(7, 10, "早");
	setMap_one(8, 10, "朽");
	setMap_one(9, 10, "早");
	setMap_one(10, 10, "朽");
	setMap_one(11, 10, "早");
	setMap_one(12, 10, "旭");

	setMap_one(0, 11, "");
	setMap_one(1, 11, "");
	setMap_one(2, 11, "");
	setMap_one(3, 11, "");
	setMap_one(4, 11, "");
	setMap_one(5, 11, "");
	setMap_one(6, 11, "");
	setMap_one(7, 11, "");
	setMap_one(8, 11, "");
	setMap_one(9, 11, "");
	setMap_one(10, 11, "");
	setMap_one(11, 11, "");
	setMap_one(12, 11, "");

	setMap_one(0, 12, "");
	setMap_one(1, 12, "");
	setMap_one(2, 12, "");
	setMap_one(3, 12, "");
	setMap_one(4, 12, "");
	setMap_one(5, 12, "");
	setMap_one(6, 12, "");
	setMap_one(7, 12, "");
	setMap_one(8, 12, "");
	setMap_one(9, 12, "");
	setMap_one(10, 12, "");
	setMap_one(11, 12, "");
	setMap_one(12, 12, "");

}

// 3廓 裘 撢た
void Base_map::setMap_3()
{
	setX(7);
	setY(7);
	setMap_one(7, 7, "��");
	setMap_one(1, 1, "≦");
	setMap_one(1, 3, "≦");
	setMap_one(1, 5, "≦");
	setMap_one(3, 5, "≦");
	setMap_one(3, 9, "≦");
	setMap_one(5, 9, "≦");
	setMap_one(9, 7, "≦");
	setMap_one(9, 11, "≦");
	setMap_one(11, 3, "≦");
	setMap_one(11, 11, "≦");
}

// 裘 и捱等 熱薑
void Base_map::setMap_one(int i, int j, string s)
{
	map[i][j] = s;
}

// 撩奢ц朝雖 羹觼
int Base_map::check()
{
	for (int i = 0; i < 13; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			if (map[i][j] == "﹤")
				return 0;
		}
	}
	return 1;
}

// 醴憮 檜翕
void Base_map::gotoxy(int x, int y)
{
	COORD Cur;
	Cur.X = x;
	Cur.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}