#include"mainmenu.h"
#include"menu.h"
#include"User.h"
#include"data.h"
#include<list>
#include<iomanip>

// 메뉴 현재 상태 표시
void MainMenu::menu_print(){
	cout << endl;
	cout << endl;
	cout << "                             < < < 메  뉴 > > >     " << endl;
	cout << endl;
	cout << "                                                    " << endl;
	cout << "                                 새로  하기         " << endl;
	cout << "                                                    " << endl;
	cout << "                                                    " << endl;
	cout << "                                 이어  하기         " << endl;
	cout << "                                                    " << endl;
	cout << "                                                    " << endl;
	cout << "                                 랭킹  보기         " << endl;
	cout << "                                                    " << endl;
	cout << "                                                    " << endl;
	cout << "                                   종  료           " << endl;
	cout << "                                                    " << endl;
}

// 메뉴 호출
void MainMenu::menu_call(){
	int line = 4;

	system("COLOR 1F");
	system("cls");
	menu_print();
	menu_show(line);

	while (1){
		json::value v = GetUser();
		setInput(_getch());
		if (getInput() == 72){
			if (getNow() != 1){
				setNow(getNow() - 1);
				menu_hide(line);
				line -= 3;
				menu_show(line);
			}
			else{
				setNow(4);
				menu_hide(line);
				line = 13;
				menu_show(line);
			}
		}
		else if (getInput() == 80){
			if (getNow() != 4){
				setNow(getNow() + 1);
				menu_hide(line);
				line += 3;
				menu_show(line);
			}
			else{
				setNow(1);
				menu_hide(line);
				line = 4;
				menu_show(line);
			}
		}
		else if (getInput() == 13){
			if (getNow() == 1)
				start1(v);
			else if (getNow() == 2)
				start2(v);
			else if (getNow() == 3)
				start3();
			else if (getNow() == 4){
				gotoxy(0, 0);
				return;
			}

			system("cls");
			menu_print();
			menu_show(line);
		}
		else if (getInput() == 'z'){
			gotoxy(0, 0);
			string end = { "□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□■□□□■□□■■□□■■■□□■■■■□□□□■■■□□■□□□■□□□□□□■■□■■□■□□■□■□□■□■□□□□□□□■□□■□□■□■□□□□□□□■□■□■□■■■■□■□□■□■■■■□□□□■■■□□□□■□□□□□□□□■□□□■□■□□■□■□□■□■□□□□□□□■□□■□□□■□□□□□□□□■□□□■□■□□■□■■■□□■■■■□□□□■■■□□□□■□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□■□□■□□■■■□■□□■□□□□□■□□□□□■■■□■■■■□□□□□□□■□■□□■□□□□■□□■□□□□□■□□□□■□□□□□□■□□□□□□□□■■□□□□■■□□■■■■□□□□□■□□□□□■■□□□□■□□□□□□□□■□■□□□□□■□■□□■□□□□□■□□□□□□□■□■□■□□□□□□□□■□□■□■■■□□■□□■□□□□□■■■■□■■■□□■■□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□■□□□□■□□□■□■□□□■□□□□□□□□□□□□□□□□□□□□□□□□■□□□□■■□□■□■□□□■□□□□□□□□□□□□□□□□□□□□□□□□■□□□□■□■□■□■■■■■□□□□□□□□□□□□□□□□□□□□□□□□■□□□□■□□■■□■□□□■□□□□□□□□□□□□□□□□□□□□□□□□■■■■□■□□□■□■□□□■□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□" };
			cout << end;
			gotoxy(0, 0);
			Sleep(500);
			
			gotoxy(0, 0);
			return;
		}
	}
}

// 상자 생성
void MainMenu::menu_show(int i){
	gotoxy(24, i);
	cout << "┏━━━━━━━━━━━━┓" << endl;

	gotoxy(24, i + 1);
	cout << "┃";

	gotoxy(50, i + 1);
	cout << "┃";

	gotoxy(24, i + 2);
	cout << "┗━━━━━━━━━━━━┛" << endl;
}

// 상자 삭제
void MainMenu::menu_hide(int i){
	gotoxy(24, i);
	cout << "                            " << endl;
	gotoxy(24, i + 1);
	cout << "  ";
	gotoxy(50, i + 1);
	cout << "  ";
	gotoxy(24, i + 2);
	cout << "                            " << endl;
}

// 아이디 새로만들기
void MainMenu::start1(json::value v){
	User a;
	system("cls");
	a.NewId();
	if (a.getId()[0] < 48 || a.getId()[0] > 57){
		for (int i = 0; i < v.size(); i++){
			if (a.getId().compare(v[i].at(L"name").as_string()) == 0/*서버에서 중복아이디 검사후 중복아이디 있을때*/){
				cout << "중복된 아이디가 있습니다." << endl;
				Sleep(1500);
				system("cls");
				start1(v);
				return;
			}
		}
		
		a.NewPw();
		//서버에 아이디 저장
		PostUser(a.getId(), a.getPw());
	}
}

// 기존아이디 로그인하기
void MainMenu::start2(json::value v){
	string_t id = L"", pw = L"";
	char ch;
	User b;
	system("cls");
	cout << "뒤로가기 : 숫자 입력" << endl;
	cout << "ID	: ";
	wcin >> id;
	if (id[0] < 48 || id[0] > 57){
		cout << "PassWord	: ";
		ch = _getch();
		while (ch != 13){//character 13 is enter
			if (ch != 8){
				pw.push_back(ch);
				cout << '*';
			}
			else{
				if (pw.length() > 0){
					pw.pop_back();
					cout << "\b \b";
				}
			}
			ch = _getch();
		}
		cout << endl;
		pw = b.Encryption(pw);
		for (int i = 0; i < v.size(); i++){
			if (id.compare(v[i].at(L"name").as_string()) == 0){
				if (pw.compare(v[i].at(L"password").as_string()) == 0){/*서버에서 찾아와*/
					User a(id, pw, v[i].at(L"point").as_integer(), v[i].at(L"idx").as_integer());
					Menu menu(a.getIndex());
					menu.menu_call();
					break;
				}
				else{
					system("cls");
					cout << "비밀번호가 맞지 않습니다. " << endl;
					Sleep(2000);
					start2(v);
				}
			}
			else if (i == v.size() - 1){
				system("cls");
				cout << "입력하신 아이디가 존재하지 않습니다. 다시한번 확인하세요" << endl;
				Sleep(1500);
				system("cls");
				start2(v);
			}
		}
	}
}
void MainMenu::start3(){
	system("cls");
	int j = 1;
	char ch = NULL;
	json::value v = GetUser();
	list<pair<wint_t, string_t>> user;
	pair<wint_t, string_t> mpair;
	//서버에서 불러와서 하나씩 넣어용
	for (int i = 0; i < v.size(); i++){
		mpair.first = v[i].at(L"point").as_integer();
		mpair.second = v[i].at(L"name").as_string();
		user.push_back(pair<wint_t, string_t>(mpair));
	}
	user.sort();
	list<pair<wint_t, string_t>>::reverse_iterator it;
	for (it = user.rbegin(); it != user.rend(); ++it){
		if (j == 1)
			wcout << setw(8) << j << L"st\t" << setw(12) << (*it).second << setw(8) << (*it).first << L"점" << endl;
		else if (j == 2)
			wcout << setw(8) << j << L"nd\t" << setw(12) << (*it).second << setw(8) << (*it).first << L"점" << endl;
		else if (j == 3)
			wcout << setw(8) << j << L"rd\t" << setw(12) << (*it).second << setw(8) << (*it).first << L"점" << endl << endl << endl;
		else
			wcout << setw(8) << j << L"위\t" << setw(12) << (*it).second << setw(8) << (*it).first << L"점" << endl;
		j++;
	}
	while (ch == NULL){
		ch = _getch();
	}
}

// 커서 이동
void MainMenu::gotoxy(int x, int y){
	COORD Cur;
	Cur.X = x;
	Cur.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}
