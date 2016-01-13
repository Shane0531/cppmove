#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <conio.h>

using namespace std;

// 메인 메뉴
class Menu{
	char input; // 메뉴선택
	int now = 1; // 선택된 메뉴
	wint_t user_index;
public:
	void setInput(int i) { input = i; }
	int getInput() { return input; }
	void setNow(int n) { now = n; }
	int getNow() { return now; }
	virtual void menu_print(); // 메뉴 현재 상태 표시
	virtual void menu_call(); // 메뉴 호출
	void menu_show(int i); // 상자 생성
	void menu_hide(int i); // 상자 삭제
	virtual void start1(); // 기본 시작
	virtual void start2(); // 사용자 맵 생성
	virtual void start3(); // 사용자 맵 시작
	void gotoxy(int x, int y); // 커서 이동
	void setUser_index(wint_t t) { user_index = t; }
	wint_t getUser_index() { return user_index; }
	Menu()
	{
	}
	Menu(wint_t i)
	{
		setUser_index(i);
	}
};

// 기본 시작 메뉴
class Menu_start_base : public Menu {
public:
	void menu_print(); // 메뉴 현재 상태 표시
	void menu_call(); // 메뉴 호출
	void start1(); // 1번 맵 시작
	void start2(); // 2번 맵 시작
	void start3(); // 3번 맵 시작
	Menu_start_base()
	{
	}
	Menu_start_base(wint_t i)
	{
		setUser_index(i);
	}
};

class Menu_start_user : public Menu_start_base {
public:
	void start();
};