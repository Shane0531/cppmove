#include<iostream>
#include<string>
#include <windows.h>
#include <conio.h>
#include<cpprest/http_client.h>

using namespace utility;
using namespace std;
class User{
private:
	string_t Id;
	string_t Pw;
	wint_t score;
	wint_t index;
public:
	User();//�⺻ ������
	User(string_t id, string_t pw, wint_t clear, wint_t index);//�Ű����� �ִ� ������
	string_t getPw();//��й�ȣ �ҷ�����
	void SetId(string_t s);//���̵� �ֱ�
	void SetPw(string_t s);//��й�ȣ �ֱ�
	void NewId();//���̵����
	void NewPw();//��й�ȣ ����
	void SetScore(wint_t a);//���� ���� ����
	wint_t getScore();//���� ���� ��������
	wint_t getIndex();//�ε����� �ҷ�����
	string_t getId();//���̵� �ҷ�����
	string_t Encryption(string_t s);//��ȣȭ
	string_t UnEncryption(string_t s);//��ȣȭ
};