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
		cout << "뒤로가기 : 숫자입력" << endl;
		cout << "ID를 입력하세요 (3~12자) : ";
		wcin >> temp;
		if (temp[0] < 48 || temp[0] > 57){
			if (temp.length() > 12){
				system("cls");
				cout << "ID가 " << temp.length() << "자 입니다. ID는 12자 이하입니다. " << endl;
				Sleep(1500);
				system("cls");
			}
			else if (temp.length() < 3){
				system("cls");
				cout << "ID가 " << temp.length() << "자 입니다. ID는 3자 이상입니다. " << endl;
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
	cout << "패스워드를 입력하세요 : ";
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
void User::SetScore(wint_t a){//유저 점수 설정
	score = a;
}
wint_t User::getIndex(){//인덱스값 불러오기
	return index;
}
wint_t User::getScore(){
	return score;
}