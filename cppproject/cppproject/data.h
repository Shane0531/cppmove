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
//ȸ������
void PostUser(string_t a, string_t b);
//�� �����ϱ�
void PostMap(string_t map);
//�� �ҷ�����
string_t GetMap();
//����Ʈ�ø���
void UpScore(wint_t idx);

void LogoPrint();