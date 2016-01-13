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
	User();//기본 생성자
	User(string_t id, string_t pw, wint_t clear, wint_t index);//매개변수 있는 생성자
	string_t getPw();//비밀번호 불러오기
	void SetId(string_t s);//아이디 넣기
	void SetPw(string_t s);//비밀번호 넣기
	void NewId();//아이디생성
	void NewPw();//비밀번호 생성
	void SetScore(wint_t a);//유저 점수 설정
	wint_t getScore();//유저 점수 가져오기
	wint_t getIndex();//인덱스값 불러오기
	string_t getId();//아이디 불러오기
	string_t Encryption(string_t s);//암호화
	string_t UnEncryption(string_t s);//복호화
};