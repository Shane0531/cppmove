#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <conio.h>

using namespace std;

// ���� �޴�
class Menu{
	char input; // �޴�����
	int now = 1; // ���õ� �޴�
	wint_t user_index;
public:
	void setInput(int i) { input = i; }
	int getInput() { return input; }
	void setNow(int n) { now = n; }
	int getNow() { return now; }
	virtual void menu_print(); // �޴� ���� ���� ǥ��
	virtual void menu_call(); // �޴� ȣ��
	void menu_show(int i); // ���� ����
	void menu_hide(int i); // ���� ����
	virtual void start1(); // �⺻ ����
	virtual void start2(); // ����� �� ����
	virtual void start3(); // ����� �� ����
	void gotoxy(int x, int y); // Ŀ�� �̵�
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

// �⺻ ���� �޴�
class Menu_start_base : public Menu {
public:
	void menu_print(); // �޴� ���� ���� ǥ��
	void menu_call(); // �޴� ȣ��
	void start1(); // 1�� �� ����
	void start2(); // 2�� �� ����
	void start3(); // 3�� �� ����
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