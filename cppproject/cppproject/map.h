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
	char input; // 입력
	int now = 0; // 실행중인 맵 번호 ( 0 : 테스트 )
	int user_x, user_y; // 현재 캐릭터 위치
	string map[13][13]; // 맵 저장 배열
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

	void map_print(); // 현재 맵 상태 출력
	int move(Base_map& map); // 이동
	void move_left(); // ←키 눌렀을 때
	void move_right(); // →키 눌렀을 때
	void move_up(); // ↑키 눌렀을 때
	void move_down(); // ↓키 눌렀을 때
	void setMap_one(int i, int j, string s); // 맵 한군데 수정
	void setMap_base(); // 기본 맵 셋팅
	void gotoxy(int x, int y); // 커서 이동
	void setMap_1(); // 1번 맵 셋팅
	void setMap_2(); // 2번 맵 셋팅
	void setMap_3(); // 3번 맵 셋팅
	int check(); // 성공했는지 체크
};