#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <conio.h>
#include "data.h"
using namespace std;
using namespace utility;
class Make {
	char input; // 메뉴선택
	int user_x = 1, user_y = 1; // 현재 커서 위치
	string map[13][13]; // 맵 저장 배열
	string_t Makemap;
public:
	void setInput(int i) { input = i; }
	int getInput() { return input; }
	void setX(int a) { user_x = a; }
	int getX() { return user_x; }
	void setY(int b) { user_y = b; }
	int getY() { return user_y; }

	void map_print(); // 현재 맵 상태 출력
	void move(Make& map); // 이동
	void move_left(); // ←키 눌렀을 때
	void move_right(); // →키 눌렀을 때
	void move_up(); // ↑키 눌렀을 때
	void move_down(); // ↓키 눌렀을 때
	void setMap_one(int i, int j, string s); // 맵 한군데 수정
	void setMap_base(); // 기본 맵 셋팅
	void gotoxy(int x, int y); // 커서 이동
	void cursor(); // 커서 표시
	void change(char i); // 커서위치 변경
	int test(); // 클리어 가능한 맵인지 테스트
	void save(); // 서버에 저장
	void change_to_server();
};