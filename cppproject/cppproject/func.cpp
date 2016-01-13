#include"data.h"
#include"make.h"

//유저정보 호출
json::value GetUser()
{
	http_client client(U("http://168.131.35.110:8080/user"));
	auto resp = client.request(U("GET")).get();
	json::value v = resp.extract_json(true).get();
	return v;
}

void PostUser(string_t a,string_t b){
	http_client client(U("http://168.131.35.110:8080/user"));
	uri_builder builder;
	builder.append_path(L"/save");
	json::value v;
	v[U("name")] = json::value::string(a);
	v[U("password")] = json::value::string(b);
	client.request(methods::POST, builder.to_string(), v.serialize(), L"application/json");
}

//맵 저장
void PostMap(string_t map){
	http_client client(U("http://168.131.35.110:8080/map"));
	uri_builder builder;
	builder.append_path(L"/save");
	json::value v;
	v[L"map"] = json::value::string(map);
	auto resp = client.request(methods::POST, builder.to_string(), v.serialize(), L"application/json").get();
}

//랜덤으로 맵 불러오기
string_t GetMap(){
	http_client client(U("http://168.131.35.110:8080/map"));
	auto resp = client.request(U("GET")).get();
	json::value v = resp.extract_json(true).get();
	string_t map = v.at(L"map").as_string();
	return map;
}

//점수올리기
void UpScore(wint_t idx){
	http_client client(U("http://168.131.35.110:8080"));
	uri_builder builder;
	string a = std::to_string(idx);
	builder.append_path(L"/score");
	builder.append_query(string_t(L"idx"),utility::conversions::to_string_t(a));
	wcout << client.request(U("PUT"), builder.to_string()).get().extract_string(true).get() << endl;
}

void LogoPrint(){
	string logo = "□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□■□□□■□□□■■■□□□■□□□■□□■■■■■□□□□□□□□□□□□□□■■□■■□□■□□□■□□■□□□■□□■□□□□□□□□□□□□□□□□□□■□■□■□□■□□□■□□□■□■□□□■■■■■□□□□□□□□□□□□□□■□□□■□□■□□□■□□□■□■□□□■□□□□□□□□□□□□□□□□□□■□□□■□□□■■■□□□□□■□□□□■■■■■□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□■□□□■□□□■■■□□□■□□□■□□■■■■■□□□□□□□□□□□□□□■■□■■□□■□□□■□□■□□□■□□■□□□□□□□□□□□□□□□□□□■□■□■□□■□□□■□□□■□■□□□■■■■■□□□□□□□□□□□□□□■□□□■□□■□□□■□□□■□■□□□■□□□□□□□□□□□□□□□□□□■□□□■□□□■■■□□□□□■□□□□■■■■■□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□";
	int i = 0;
	Make m;

	cout << logo;
	m.gotoxy(0, 0);

	while (i < 4){
		Sleep(200);
		system("Color 1F");
		Sleep(200);
		system("Color F1");
		i++;
	}
	for (int i = 0; i < 25; i++){
		m.gotoxy(0, i);
		cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■";
		Sleep(50);
	}
	system("cls");
}