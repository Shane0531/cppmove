#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <conio.h>
#include "data.h"
using namespace std;
using namespace utility;
class Make {
	char input; // �޴�����
	int user_x = 1, user_y = 1; // ���� Ŀ�� ��ġ
	string map[13][13]; // �� ���� �迭
	string_t Makemap;
public:
	void setInput(int i) { input = i; }
	int getInput() { return input; }
	void setX(int a) { user_x = a; }
	int getX() { return user_x; }
	void setY(int b) { user_y = b; }
	int getY() { return user_y; }

	void map_print(); // ���� �� ���� ���
	void move(Make& map); // �̵�
	void move_left(); // ��Ű ������ ��
	void move_right(); // ��Ű ������ ��
	void move_up(); // ��Ű ������ ��
	void move_down(); // ��Ű ������ ��
	void setMap_one(int i, int j, string s); // �� �ѱ��� ����
	void setMap_base(); // �⺻ �� ����
	void gotoxy(int x, int y); // Ŀ�� �̵�
	void cursor(); // Ŀ�� ǥ��
	void change(char i); // Ŀ����ġ ����
	int test(); // Ŭ���� ������ ������ �׽�Ʈ
	void save(); // ������ ����
	void change_to_server();
};