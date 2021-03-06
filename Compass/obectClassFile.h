#pragma once
// ConsoleApplication5.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Login.h"
using namespace std;

extern LoginSystem loginSystem;

class User
{
private:
	string password;
	string isPremium;
	string name;
	string gender;
	string birth;
	string phone;
	string spam;
	string country;
	string city;
	char id[50] = "abc";
	char pack[50] = "pack";
	char review[50] = "review";
	char guide[50] = "guide";
	char rank[50] = "rank";
	char packname[50];
	char idtxt[50] = "abc";

public:
	User()
	{
		
		strcat_s(pack, ".txt");
		strcat_s(review, ".txt");
		strcat_s(guide, ".txt");
		strcat_s(rank, ".txt");
		string s;
	}
	string getPassword()
	{
		return password;
	}
	string getName()
	{
		return name;
	}
	string getGender()
	{
		return gender;
	}
	string getBirth()
	{
		return birth;
	}
	string getPhone()
	{
		return phone;
	}
	string getSpam()
	{
		return spam;
	}
	string getCountry()
	{
		return country;
	}
	string getCity()
	{
		return city;
	}

	void GetInfo()
	{
		/*LoginSystem log1;*/
		//strcpy(idtxt,log1.getCurrentID());
		strcat_s(idtxt, ".txt");
		fstream fs(idtxt);
		getline(fs, password);
		getline(fs, isPremium);
		getline(fs, name);
		getline(fs, gender);
		getline(fs, birth);
		getline(fs, phone);
		getline(fs, spam);
		getline(fs, country);
		getline(fs, city);
		fs.close();
	}

	void PackRank()
	{
		double rankBefore, rankAfter;
		int num;
		cout << "패키지 번호를 입력해주세요" << endl;
		cin >> packname;
		strcat_s(packname, ".");
		strcat_s(packname, rank);
		fstream fs2(packname);
		cout << "패키지의 평점을 입력해주세요" << endl;
		cin >> rankAfter;
		fs2 >> rankBefore;
		fs2 >> num;
		fs2.close();
		rankBefore *= num;
		num++;
		rankBefore += rankAfter;
		ofstream fs3(packname, ios::ate);
		fs3 << rankBefore / num << " " << num << endl;
		fs3.close();
	}
	void GuideRank()
	{
		double rankBefore, rankAfter;
		int num;
		fstream fs5(pack);
		cout << "가이드의 평점을 입력해주세요" << endl;
		cin >> rankAfter;
		fs5 >> rankBefore;
		fs5 >> num;
		fs5.close();
		rankBefore *= num;
		num++;
		rankBefore += rankAfter;
		ofstream fs3(pack, ios::ate);
		if (fs3.is_open()) {
		}
		else {
			cout << "파일을 찾을 수 없습니다!" << endl;
		}
		fs3 << rankBefore / num << " " << num << endl;
		fs3.close();
	}
	void PackReview()
	{
		string a;
		char packname[50];
		cout << "패키지 번호를 입력해주세요" << endl;
		cin >> packname;
		strcat_s(packname, ".");
		strcat_s(packname, review);
		cout << "패키지의 리뷰를 입력해주세요" << endl;
		cin >> a;
		ofstream fs(packname, ios::app);
		if (fs.is_open()) {
		}
		else {
			cout << "파일을 찾을 수 없습니다!" << endl;
		}
		fs << "\n" << a << " - " << id;
		fs.close();
	}
	void ChangeInfo()
	{
		int a;
		cout << "수정하고자 하는 요소를 선택해주세요" << endl;
		cin >> a;
		switch (a) {
		case 1:
			cout << "비밀번호 변경" << endl;
			cout << "변경내용 :" << endl;
			cin >> password;
			break;
		case 2:
			cout << "전화번호 변경" << endl;
			cout << "변경내용 :" << endl;
			cin >> phone;
			break;
		case 3:
			cout << "스팸여부 변경(동의하면 1, 아니면 0)" << endl;
			cout << "변경내용 :" << endl;
			cin >> spam;
			break;
		case 4:
			cout << "관심나라 변경" << endl;
			cout << "변경내용 :" << endl;
			cin >> country;
			break;
		case 5:
			cout << "관심도시 변경" << endl;
			cout << "변경내용 :" << endl;
			cin >> city;
			break;
		}
		ofstream fs4(idtxt, ios::ate);
		fs4 << password;
		fs4 << "\n" << name;
		fs4 << "\n" << gender;
		fs4 << "\n" << birth;
		fs4 << "\n" << phone;
		fs4 << "\n" << spam;
		fs4 << "\n" << city;
		fs4 << "\n" << country;
		fs4.close();
	}

};

class Licensee
{
private:
	string password;
	string name;
	string agency;
	string phone;
	string license;
	string city;
	string country;
public:
	void GetInfo()
	{
		string s;
		char id[50] = "abc";
		strcat_s(id, ".txt");
		fstream fs(id);
		getline(fs, password);
		getline(fs, name);
		getline(fs, agency);
		getline(fs, phone);
		getline(fs, license);
		getline(fs, city);
		getline(fs, country);
	}

};
class Guide
{
private:
	string password;
	string name;
	string phone;
	string license;
	string city;
	string country;
	string online;
public:
	void GetInfo()
	{
		string s;
		char id[50] = "";
		strcat_s(id, ".txt");
		fstream fs(id);
		getline(fs, password);
		getline(fs, name);
		getline(fs, phone);
		getline(fs, license);
		getline(fs, city);
		getline(fs, country);
		getline(fs, online);
	}

	//char * getOnline(char * ID) {
	//	const char *fileName = NULL;
	//	int exist;
	//	fileName = strcat(ID, ".txt");
	//	exist = _access(fileName, 0); // 존재하면 exist : 0, 존재하지 않으면 exist : -1.
	//	
	//	if (exist == 0) {
	//		FILE * fileRead = fopen(fileName, "r");
	//		fgets(user_PWD, sizeof(user_PWD), fileRead);
	//		fclose(reader_UserInfo);

	//		// 파일로부터 읽어들인 user_PWD에서 띄어쓰기 문자 제거.
	//		user_PWD[strlen(user_PWD) - 1] = '\0';
	//	}

	//	else {
	//		return NULL;
	//	}

	//}
};