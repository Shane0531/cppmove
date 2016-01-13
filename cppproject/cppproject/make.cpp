#include "make.h"
#include "map.h"

// 현재 맵 상태 출력
void Make::map_print()
{
	system("COLOR 1F");
	Sleep(10);
	system("cls");

	cout << endl;
	cout << endl;
	cout << "                         < < < 사용자 맵 생성 > > >" << endl;
	cout << endl;
	cout << "                        [ ＠ : 1 ][ □ : 2 ][ ※ : 3 ]" << endl;
	cout << endl;

	for (int i = 0; i < 13; i++)
	{
		cout << "                         ";
		for (int j = 0; j < 13; j++)
			cout << map[i][j];
		cout << endl;
	}

	gotoxy(0, 20);
	cout << "      	   이동 : ↑→↓← , 다시시작 : R , 저장 : S , 나가기 : Z" << endl;
}

// 캐릭터 이동
void Make::move(Make& map)
{
	char input;

	map.map_print();

	while (1)
	{
	

		cursor();

		cout << endl;
		
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
			else if (input == '1' || input == '2' || input == '3')
			{
				change(input);
				break;
			}
			else if (input == 'r')
			{
				map.setMap_base();
				map.map_print();
				break;
			}
			else if (input == 's')
			{
				int check = 0;

				for (int i = 0; i < 13; i++)
				{
					for (int j = 0; j < 13; j++)
					{
						if (map.map[i][j] == "＠")
						{
							check++;
							user_x = i;
							user_y = j;
						}
					}
				}

				if (check != 1)
				{
					gotoxy(23, 10);
					cout << "시작점이 1개가 아닙니다 !!!!";
					Sleep(1000);
					map.map_print();
					break;
				}

				if (test() == 1)
				{
					system("COLOR 1F");
					return;
				}

				map.map_print();
				break;
			}
			else if (input == 'z')
			{
				system("COLOR 1F");
				return;
			}
		}
	}

};

// ←키 눌렀을 때
void Make::move_left()
{
	if (user_y == 1)
		return;
	
	gotoxy(25 + (user_y * 2), 6 + user_x);
	system("COLOR 1F");
	cout << map[user_x][user_y];

	user_y -= 2;
}

// →키 눌렀을 때
void Make::move_right()
{
	if (user_y == 11)
		return;

	gotoxy(25 + (user_y * 2), 6 + user_x);
	system("COLOR 1F");
	cout << map[user_x][user_y];

	user_y += 2;
}

// ↑키 눌렀을 때
void Make::move_up()
{
	if (user_x == 1)
		return;

	gotoxy(25 + (user_y * 2), 6 + user_x);
	system("COLOR 1F");
	cout << map[user_x][user_y];

	user_x -= 2;
}

// ↓키 눌렀을 때
void Make::move_down()
{
	if (user_x == 11)
		return;

	gotoxy(25 + (user_y * 2), 6 + user_x);
	system("COLOR 1F");
	cout << map[user_x][user_y];

	user_x += 2;
}

// 기본 맵 셋팅
void Make::setMap_base()
{
	map[0][0] = "┏";
	map[0][1] = "━";
	map[0][2] = "┳";
	map[0][3] = "━";
	map[0][4] = "┳";
	map[0][5] = "━";
	map[0][6] = "┳";
	map[0][7] = "━";
	map[0][8] = "┳";
	map[0][9] = "━";
	map[0][10] = "┳";
	map[0][11] = "━";
	map[0][12] = "┓";

	map[1][0] = "┃";
	map[1][1] = "□";
	map[1][2] = "┃";
	map[1][3] = "□";
	map[1][4] = "┃";
	map[1][5] = "□";
	map[1][6] = "┃";
	map[1][7] = "□";
	map[1][8] = "┃";
	map[1][9] = "□";
	map[1][10] = "┃";
	map[1][11] = "□";
	map[1][12] = "┃";

	map[2][0] = "┣";
	map[2][1] = "━";
	map[2][2] = "╋";
	map[2][3] = "━";
	map[2][4] = "╋";
	map[2][5] = "━";
	map[2][6] = "╋";
	map[2][7] = "━";
	map[2][8] = "╋";
	map[2][9] = "━";
	map[2][10] = "╋";
	map[2][11] = "━";
	map[2][12] = "┫";

	map[3][0] = "┃";
	map[3][1] = "□";
	map[3][2] = "┃";
	map[3][3] = "□";
	map[3][4] = "┃";
	map[3][5] = "□";
	map[3][6] = "┃";
	map[3][7] = "□";
	map[3][8] = "┃";
	map[3][9] = "□";
	map[3][10] = "┃";
	map[3][11] = "□";
	map[3][12] = "┃";

	map[4][0] = "┣";
	map[4][1] = "━";
	map[4][2] = "╋";
	map[4][3] = "━";
	map[4][4] = "╋";
	map[4][5] = "━";
	map[4][6] = "╋";
	map[4][7] = "━";
	map[4][8] = "╋";
	map[4][9] = "━";
	map[4][10] = "╋";
	map[4][11] = "━";
	map[4][12] = "┫";

	map[5][0] = "┃";
	map[5][1] = "□";
	map[5][2] = "┃";
	map[5][3] = "□";
	map[5][4] = "┃";
	map[5][5] = "□";
	map[5][6] = "┃";
	map[5][7] = "□";
	map[5][8] = "┃";
	map[5][9] = "□";
	map[5][10] = "┃";
	map[5][11] = "□";
	map[5][12] = "┃";

	map[6][0] = "┣";
	map[6][1] = "━";
	map[6][2] = "╋";
	map[6][3] = "━";
	map[6][4] = "╋";
	map[6][5] = "━";
	map[6][6] = "╋";
	map[6][7] = "━";
	map[6][8] = "╋";
	map[6][9] = "━";
	map[6][10] = "╋";
	map[6][11] = "━";
	map[6][12] = "┫";

	map[7][0] = "┃";
	map[7][1] = "□";
	map[7][2] = "┃";
	map[7][3] = "□";
	map[7][4] = "┃";
	map[7][5] = "□";
	map[7][6] = "┃";
	map[7][7] = "□";
	map[7][8] = "┃";
	map[7][9] = "□";
	map[7][10] = "┃";
	map[7][11] = "□";
	map[7][12] = "┃";

	map[8][0] = "┣";
	map[8][1] = "━";
	map[8][2] = "╋";
	map[8][3] = "━";
	map[8][4] = "╋";
	map[8][5] = "━";
	map[8][6] = "╋";
	map[8][7] = "━";
	map[8][8] = "╋";
	map[8][9] = "━";
	map[8][10] = "╋";
	map[8][11] = "━";
	map[8][12] = "┫";

	map[9][0] = "┃";
	map[9][1] = "□";
	map[9][2] = "┃";
	map[9][3] = "□";
	map[9][4] = "┃";
	map[9][5] = "□";
	map[9][6] = "┃";
	map[9][7] = "□";
	map[9][8] = "┃";
	map[9][9] = "□";
	map[9][10] = "┃";
	map[9][11] = "□";
	map[9][12] = "┃";

	map[10][0] = "┣";
	map[10][1] = "━";
	map[10][2] = "╋";
	map[10][3] = "━";
	map[10][4] = "╋";
	map[10][5] = "━";
	map[10][6] = "╋";
	map[10][7] = "━";
	map[10][8] = "╋";
	map[10][9] = "━";
	map[10][10] = "╋";
	map[10][11] = "━";
	map[10][12] = "┫";

	map[11][0] = "┃";
	map[11][1] = "□";
	map[11][2] = "┃";
	map[11][3] = "□";
	map[11][4] = "┃";
	map[11][5] = "□";
	map[11][6] = "┃";
	map[11][7] = "□";
	map[11][8] = "┃";
	map[11][9] = "□";
	map[11][10] = "┃";
	map[11][11] = "□";
	map[11][12] = "┃";

	map[12][0] = "┗";
	map[12][1] = "━";
	map[12][2] = "┻";
	map[12][3] = "━";
	map[12][4] = "┻";
	map[12][5] = "━";
	map[12][6] = "┻";
	map[12][7] = "━";
	map[12][8] = "┻";
	map[12][9] = "━";
	map[12][10] = "┻";
	map[12][11] = "━";
	map[12][12] = "┛";
}

// 맵 한군데 수정
void Make::setMap_one(int i, int j, string s)
{
	map[i][j] = s;
}

// 커서 이동
void Make::gotoxy(int x, int y)
{
	COORD Cur;
	Cur.X = x;
	Cur.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}

// 커서 표시
void Make::cursor()
{
	gotoxy(25 + (user_y * 2), 6 + user_x);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cout << map[user_x][user_y];
}

// 커서위치 변경
void Make::change(char i)
{
	if (i == '1')
		setMap_one(user_x, user_y, "＠");
	else if (i == '2')
		setMap_one(user_x, user_y, "□");
	else if (i == '3')
		setMap_one(user_x, user_y, "※");
}

// 클리어 가능한 맵인지 테스트
int Make::test()
{
	Base_map test;

	for (int i = 0; i < 13; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			test.setMap_one(i, j, map[i][j]);
		}
	}

	test.setX(user_x);
	test.setY(user_y);

	if (test.move(test) == 1)
	{
		save();
		return 1;
	}

	return 0;
}

void Make::change_to_server()
{
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++ )
		{
			if (map[1 + (i * 2)][1 + (j * 2)] == "＠")
				Makemap.push_back('1');
			else if (map[1 + (i * 2)][1 + (j * 2)] == "□")
				Makemap.push_back('2');
			else if (map[1 + (i * 2)][1 + (j * 2)] == "※")
				Makemap.push_back('3');
		}
	}
}

// 서버에 저장
void Make::save()
{
	
	system("cls");
	change_to_server();
	PostMap(Makemap);
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "                              서버에 저장되었습니다. ";
	
	Sleep(1000);
}