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
// ���� �޴�

class MainMenu {
	char input; // �޴�����
	int now = 1; // ���õ� �޴�
public:
	void setInput(int i) { input = i; }
	int getInput() { return input; }
	void setNow(int n) { now = n; }
	int getNow() { return now; }

	virtual void menu_print(); // �޴� ���� ���� ǥ��
	virtual void menu_call(); // �޴� ȣ��
	void menu_show(int i); // ���� ����
	void menu_hide(int i); // ���� ����
	virtual void start1(json::value v); // ���ν���
	virtual void start2(json::value v); // �̾��ϱ�
	virtual void start3(); // ��ŷ����
	void gotoxy(int x, int y); // Ŀ�� �̵�
};