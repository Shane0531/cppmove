#include<iostream>
#include <windows.h>
#include <conio.h>
#include"User.h"
using namespace std;

User::User(){
	score = 0;
}
User::User(string_t id, string_t pw, wint_t clear, wint_t index){
	Id = id;
	Pw = pw;
	score = clear;
	this->index = index;
}
string_t User::getPw(){
	return Pw;
}
void User::NewId(){
	string_t temp;

	while (temp.length() > 12 || temp.length() < 3)
	{
		cout << "�ڷΰ��� : �����Է�" << endl;
		cout << "ID�� �Է��ϼ��� (3~12��) : ";
		wcin >> temp;
		if (temp[0] < 48 || temp[0] > 57){
			if (temp.length() > 12){
				system("cls");
				cout << "ID�� " << temp.length() << "�� �Դϴ�. ID�� 12�� �����Դϴ�. " << endl;
				Sleep(1500);
				system("cls");
			}
			else if (temp.length() < 3){
				system("cls");
				cout << "ID�� " << temp.length() << "�� �Դϴ�. ID�� 3�� �̻��Դϴ�. " << endl;
				Sleep(1500);
				system("cls");
			}
		}
	}
	Id = temp;
}
void User::NewPw(){

	string_t pass = L"";
	char ch;
	cout << "�н����带 �Է��ϼ��� : ";
	ch = _getch();
	while (ch != 13){//character 13 is enter
		if (ch != 8){
			pass.push_back(ch);
			cout << '*';
		}
		else{
			if (pass.length() > 0){
				pass.pop_back();
				cout << "\b \b";
			}
		}
		ch = _getch();
	}
	cout << endl;
	Pw = Encryption(pass);
}
string_t User::Encryption(string_t s){
	int i;
	if (s.length() % 2 == 0){
		for (i = 0; i < s.length(); i++){
			s[i] += 3;
		}
	}
	else{
		for (i = 0; i < s.length(); i++){
			s[i] += 2;
		}
	}
	return s;
}
string_t User::UnEncryption(string_t s){
	int i;
	if (s.length() % 2 == 0){
		for (i = 0; i < s.length(); i++){
			s[i] -= 3;
		}
	}
	else{
		for (i = 0; i < s.length(); i++){
			s[i] -= 2;
		}
	}
	return s;
}
void User::SetId(string_t s){
	Id = s;
}
void User::SetPw(string_t s){
	Pw = s;
}
string_t User::getId(){
	return Id;
}
void User::SetScore(wint_t a){//���� ���� ����
	score = a;
}
wint_t User::getIndex(){//�ε����� �ҷ�����
	return index;
}
wint_t User::getScore(){
	return score;
}