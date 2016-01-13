#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <conio.h>
#include "cpprest\http_client.h"
using namespace web;
using namespace web::http;
using namespace web::http::client;
using namespace web::json;
using namespace std;
using namespace utility;
// 메인 메뉴

class MainMenu {
	char input; // 메뉴선택
	int now = 1; // 선택된 메뉴
public:
	void setInput(int i) { input = i; }
	int getInput() { return input; }
	void setNow(int n) { now = n; }
	int getNow() { return now; }

	virtual void menu_print(); // 메뉴 현재 상태 표시
	virtual void menu_call(); // 메뉴 호출
	void menu_show(int i); // 상자 생성
	void menu_hide(int i); // 상자 삭제
	virtual void start1(json::value v); // 새로시작
	virtual void start2(json::value v); // 이어하기
	virtual void start3(); // 랭킹보기
	void gotoxy(int x, int y); // 커서 이동
};