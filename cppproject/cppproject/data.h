#include<cpprest/http_client.h>
#include<iostream>
#include<string>

using namespace std;
using namespace utility;
using namespace web;
using namespace web::http;
using namespace web::http::client;
using namespace web::json;

json::value GetUser();
//회원가입
void PostUser(string_t a, string_t b);
//맵 저장하기
void PostMap(string_t map);
//맵 불러오기
string_t GetMap();
//포인트올리기
void UpScore(wint_t idx);

void LogoPrint();