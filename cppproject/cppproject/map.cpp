#include "map.h"

// ���� �� ���� ���
void Base_map::map_print()
{
	system("cls");

	cout << endl;
	cout << endl;

	if (now == 0)
		cout << "                            < < < �׽�Ʈ�� > > >" << endl;
	else if (now == 1)
		cout << "                             < < < 1�� �� > > >" << endl;
	else if (now == 2)
		cout << "                             < < < 2�� �� > > >" << endl;
	else if (now == 3)
		cout << "                             < < < 3�� �� > > >" << endl;
	else if (now == 4)
		cout << "                           < < < �����  �� > > >" << endl;

	cout << endl;

	for (int i = 0; i < 13; i++)
	{
		cout << "                         ";
		for (int j = 0; j < 13; j++)
			cout << map[i][j];
		cout << endl;
	}

	gotoxy(0, 18);
	cout << "             	�̵� : ����� , �ٽý��� : R , ������ : Z" << endl;
}

// ĳ���� �̵�
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
				cout << "5���� �ö����ϴ�.";
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

// ��Ű ������ ��
void Base_map::move_left()
{
	if (user_y == 1)
		return;

	while (map[user_x][user_y - 2] == "��")
	{
		map[user_x][user_y] = "��";
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

// ��Ű ������ ��
void Base_map::move_right()
{
	if (user_y == 11)
		return;

	while (map[user_x][user_y + 2] == "��")
	{
		map[user_x][user_y] = "��";
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

// ��Ű ������ ��
void Base_map::move_up()
{
	if (user_x == 1)
		return;

	while (map[user_x - 2][user_y] == "��")
	{
		map[user_x][user_y] = "��";
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

// ��Ű ������ ��
void Base_map::move_down()
{
	if (user_x == 11)
		return;

	while (map[user_x + 2][user_y] == "��")
	{
		map[user_x][user_y] = "��";
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

// �⺻ �� ����
void Base_map::setMap_base()
{
	map[0][0] = "��";
	map[0][1] = "��";
	map[0][2] = "��";
	map[0][3] = "��";
	map[0][4] = "��";
	map[0][5] = "��";
	map[0][6] = "��";
	map[0][7] = "��";
	map[0][8] = "��";
	map[0][9] = "��";
	map[0][10] = "��";
	map[0][11] = "��";
	map[0][12] = "��";

	map[1][0] = "��";
	map[1][1] = "��";
	map[1][2] = "��";
	map[1][3] = "��";
	map[1][4] = "��";
	map[1][5] = "��";
	map[1][6] = "��";
	map[1][7] = "��";
	map[1][8] = "��";
	map[1][9] = "��";
	map[1][10] = "��";
	map[1][11] = "��";
	map[1][12] = "��";

	map[2][0] = "��";
	map[2][1] = "��";
	map[2][2] = "��";
	map[2][3] = "��";
	map[2][4] = "��";
	map[2][5] = "��";
	map[2][6] = "��";
	map[2][7] = "��";
	map[2][8] = "��";
	map[2][9] = "��";
	map[2][10] = "��";
	map[2][11] = "��";
	map[2][12] = "��";

	map[3][0] = "��";
	map[3][1] = "��";
	map[3][2] = "��";
	map[3][3] = "��";
	map[3][4] = "��";
	map[3][5] = "��";
	map[3][6] = "��";
	map[3][7] = "��";
	map[3][8] = "��";
	map[3][9] = "��";
	map[3][10] = "��";
	map[3][11] = "��";
	map[3][12] = "��";

	map[4][0] = "��";
	map[4][1] = "��";
	map[4][2] = "��";
	map[4][3] = "��";
	map[4][4] = "��";
	map[4][5] = "��";
	map[4][6] = "��";
	map[4][7] = "��";
	map[4][8] = "��";
	map[4][9] = "��";
	map[4][10] = "��";
	map[4][11] = "��";
	map[4][12] = "��";

	map[5][0] = "��";
	map[5][1] = "��";
	map[5][2] = "��";
	map[5][3] = "��";
	map[5][4] = "��";
	map[5][5] = "��";
	map[5][6] = "��";
	map[5][7] = "��";
	map[5][8] = "��";
	map[5][9] = "��";
	map[5][10] = "��";
	map[5][11] = "��";
	map[5][12] = "��";

	map[6][0] = "��";
	map[6][1] = "��";
	map[6][2] = "��";
	map[6][3] = "��";
	map[6][4] = "��";
	map[6][5] = "��";
	map[6][6] = "��";
	map[6][7] = "��";
	map[6][8] = "��";
	map[6][9] = "��";
	map[6][10] = "��";
	map[6][11] = "��";
	map[6][12] = "��";

	map[7][0] = "��";
	map[7][1] = "��";
	map[7][2] = "��";
	map[7][3] = "��";
	map[7][4] = "��";
	map[7][5] = "��";
	map[7][6] = "��";
	map[7][7] = "��";
	map[7][8] = "��";
	map[7][9] = "��";
	map[7][10] = "��";
	map[7][11] = "��";
	map[7][12] = "��";

	map[8][0] = "��";
	map[8][1] = "��";
	map[8][2] = "��";
	map[8][3] = "��";
	map[8][4] = "��";
	map[8][5] = "��";
	map[8][6] = "��";
	map[8][7] = "��";
	map[8][8] = "��";
	map[8][9] = "��";
	map[8][10] = "��";
	map[8][11] = "��";
	map[8][12] = "��";

	map[9][0] = "��";
	map[9][1] = "��";
	map[9][2] = "��";
	map[9][3] = "��";
	map[9][4] = "��";
	map[9][5] = "��";
	map[9][6] = "��";
	map[9][7] = "��";
	map[9][8] = "��";
	map[9][9] = "��";
	map[9][10] = "��";
	map[9][11] = "��";
	map[9][12] = "��";

	map[10][0] = "��";
	map[10][1] = "��";
	map[10][2] = "��";
	map[10][3] = "��";
	map[10][4] = "��";
	map[10][5] = "��";
	map[10][6] = "��";
	map[10][7] = "��";
	map[10][8] = "��";
	map[10][9] = "��";
	map[10][10] = "��";
	map[10][11] = "��";
	map[10][12] = "��";

	map[11][0] = "��";
	map[11][1] = "��";
	map[11][2] = "��";
	map[11][3] = "��";
	map[11][4] = "��";
	map[11][5] = "��";
	map[11][6] = "��";
	map[11][7] = "��";
	map[11][8] = "��";
	map[11][9] = "��";
	map[11][10] = "��";
	map[11][11] = "��";
	map[11][12] = "��";

	map[12][0] = "��";
	map[12][1] = "��";
	map[12][2] = "��";
	map[12][3] = "��";
	map[12][4] = "��";
	map[12][5] = "��";
	map[12][6] = "��";
	map[12][7] = "��";
	map[12][8] = "��";
	map[12][9] = "��";
	map[12][10] = "��";
	map[12][11] = "��";
	map[12][12] = "��";
}

// 1�� �� ����
void Base_map::setMap_1()
{
	setX(7);
	setY(5);
	setMap_one(7, 5, "��");
	setMap_one(5, 1, "��");
	setMap_one(3, 9, "��");
	setMap_one(9, 3, "��");
	setMap_one(7, 11, "��");
}

// 2�� �� ����
void Base_map::setMap_2()
{
	setX(5);
	setY(3);
	setMap_one(5, 3, "��");
	setMap_one(1, 1, "��");
	setMap_one(1, 3, "��");
	setMap_one(3, 7, "��");
	setMap_one(7, 3, "��");
	setMap_one(7, 3, "��");
	setMap_one(9, 7, "��");
	setMap_one(11, 1, "��");

	setMap_one(0, 10, "��");
	setMap_one(1, 10, "��");
	setMap_one(2, 10, "��");
	setMap_one(3, 10, "��");
	setMap_one(4, 10, "��");
	setMap_one(5, 10, "��");
	setMap_one(6, 10, "��");
	setMap_one(7, 10, "��");
	setMap_one(8, 10, "��");
	setMap_one(9, 10, "��");
	setMap_one(10, 10, "��");
	setMap_one(11, 10, "��");
	setMap_one(12, 10, "��");

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

// 3�� �� ����
void Base_map::setMap_3()
{
	setX(7);
	setY(7);
	setMap_one(7, 7, "��");
	setMap_one(1, 1, "��");
	setMap_one(1, 3, "��");
	setMap_one(1, 5, "��");
	setMap_one(3, 5, "��");
	setMap_one(3, 9, "��");
	setMap_one(5, 9, "��");
	setMap_one(9, 7, "��");
	setMap_one(9, 11, "��");
	setMap_one(11, 3, "��");
	setMap_one(11, 11, "��");
}

// �� �ѱ��� ����
void Base_map::setMap_one(int i, int j, string s)
{
	map[i][j] = s;
}

// �����ߴ��� üũ
int Base_map::check()
{
	for (int i = 0; i < 13; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			if (map[i][j] == "��")
				return 0;
		}
	}
	return 1;
}

// Ŀ�� �̵�
void Base_map::gotoxy(int x, int y)
{
	COORD Cur;
	Cur.X = x;
	Cur.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}