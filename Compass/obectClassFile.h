// ConsoleApplication5.cpp : �� ���Ͽ��� 'main' �Լ��� ���Ե˴ϴ�. �ű⼭ ���α׷� ������ ���۵ǰ� ����˴ϴ�.
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;


class User
{
private:
	string password;
	string name;
	string sex;
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
		strcat_s(idtxt, ".txt");
		strcat_s(pack, ".txt");
		strcat_s(review, ".txt");
		strcat_s(guide, ".txt");
		strcat_s(rank, ".txt");
		string s;
	}
	void GetInfo()
	{

		fstream fs(idtxt);
		getline(fs, password);
		getline(fs, name);
		getline(fs, sex);
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
		int num, k;
		char packname[50];
		cout << "��Ű�� ��ȣ�� �Է����ּ���" << endl;
		cin >> packname;
		strcat_s(packname, ".");
		strcat_s(packname, rank);
		fstream fs2(packname);
		cout << "��Ű���� ������ �Է����ּ���" << endl;
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
		cout << "���̵��� ������ �Է����ּ���" << endl;
		cin >> rankAfter;
		fs5 >> rankBefore;
		fs5 >> num;
		fs5.close();
		rankBefore *= num;
		num++;
		rankBefore += rankAfter;
		ofstream fs3(pack, ios::ate);
		fs3 << rankBefore / num << " " << num << endl;
		fs3.close();
	}
	void PackReview()
	{
		string a;
		char packname[50];
		cout << "��Ű�� ��ȣ�� �Է����ּ���" << endl;
		cin >> packname;
		strcat_s(packname, ".");
		strcat_s(packname, review);
		cout << "��Ű���� ���並 �Է����ּ���" << endl;
		cin >> a;
		ofstream fs(packname, ios::app);
		fs << "\n" << a << " - " << id;
		fs.close();
	}
	void ChangeInfo()
	{
		int a;
		cout << "�����ϰ��� �ϴ� ��Ҹ� �������ּ���" << endl;
		cin >> a;
		switch (a) {
		case 1:
			cout << "��й�ȣ ����" << endl;
			cout << "���泻�� :" << endl;
			cin >> password;
			break;
		case 2:
			cout << "��ȭ��ȣ ����" << endl;
			cout << "���泻�� :" << endl;
			cin >> phone;
			break;
		case 3:
			cout << "���Կ��� ����(�����ϸ� 1, �ƴϸ� 0)" << endl;
			cout << "���泻�� :" << endl;
			cin >> spam;
			break;
		case 4:
			cout << "���ɳ��� ����" << endl;
			cout << "���泻�� :" << endl;
			cin >> country;
			break;
		case 5:
			cout << "���ɵ��� ����" << endl;
			cout << "���泻�� :" << endl;
			cin >> city;
			break;
		}
		ofstream fs4(idtxt, ios::ate);
		fs4 << password;
		fs4 << "\n" << name;
		fs4 << "\n" << sex;
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

};