#include <iostream>
#include <fstream>
#include <string>
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
	string place;
	char id[50] = "abc";
	char pack[50] = "pack";
	char review[50] = "review";

public:
	User()
	{
		strcat_s(id, ".txt");
		strcat_s(pack, ".txt");
		strcat_s(review, ".txt");
		string s;
	}
	void GetInfo()
	{

		fstream fs(id);
		getline(fs, password);
		getline(fs, name);
		getline(fs, sex);
		getline(fs, birth);
		getline(fs, phone);
		getline(fs, spam);
		getline(fs, place);
		fs.close();
	}

	void PackRank()
	{
		double rankBefore, rankAfter;
		int num;
		fstream fs2(pack);
		cout << "패키지의 평점을 입력해주세요" << endl;
		cin >> rankAfter;
		fs2 >> rankBefore;
		fs2 >> num;
		fs2.close();
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
		cout << "패키지의 리뷰를 입력해주세요" << endl;
		cin >> a;
		ofstream fs(review, ios::app);
		fs << "\n" << a;
		fs.close();
	}
	void ChangeInfo()
	{
		ofstream fs4(id, ios::ate);
		fs4 << password;
		fs4 << "\n" << name;
		fs4 << "\n" << sex;
		fs4 << "\n" << birth;
		fs4 << "\n" << phone;
		fs4 << "\n" << spam;
		fs4 << "\n" << place;
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
	string grade;
	string packgrade;
	string spam;
	string online;
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
		getline(fs, grade);
		getline(fs, packgrade);
		getline(fs, spam);
		getline(fs, online);
	}

	void EnterPackage()
	{

	}

};
class Guide
{
private:

public:


};

int main()
{
	User user;
	user.GetInfo();
	user.PackRank();
	user.PackReview();
	user.ChangeInfo();
}