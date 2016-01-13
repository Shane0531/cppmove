#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <conio.h>
#include "User.h"
#include"data.h"
#define sleep_time 100

using namespace std;

class Base_map {
	char input; // �Է�
	int now = 0; // �������� �� ��ȣ ( 0 : �׽�Ʈ )
	int user_x, user_y; // ���� ĳ���� ��ġ
	string map[13][13]; // �� ���� �迭
	wint_t user_index;
public:
	void setInput(int i) { input = i; }
	int getInput() { return input; }
	void setNow(int n) { now = n; }
	int getNow() { return now; }
	void setX(int a) { user_x = a; }
	int getX() { return user_x; }
	void setY(int b) { user_y = b; }
	int getY() { return user_y; }
	void setUser_index(wint_t t) { user_index = t; }
	wint_t getUser_index() { return user_index; }
	Base_map()
	{
	}
	Base_map(wint_t i)
	{
		setUser_index(i);
	}

	void map_print(); // ���� �� ���� ���
	int move(Base_map& map); // �̵�
	void move_left(); // ��Ű ������ ��
	void move_right(); // ��Ű ������ ��
	void move_up(); // ��Ű ������ ��
	void move_down(); // ��Ű ������ ��
	void setMap_one(int i, int j, string s); // �� �ѱ��� ����
	void setMap_base(); // �⺻ �� ����
	void gotoxy(int x, int y); // Ŀ�� �̵�
	void setMap_1(); // 1�� �� ����
	void setMap_2(); // 2�� �� ����
	void setMap_3(); // 3�� �� ����
	int check(); // �����ߴ��� üũ
};