//김경태, 이의섭, 한승남
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstring>
#include <array>
#include <iomanip>
#include <ctime>

#define MAX_STR_LEN 4000


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

};

class Advertise : public User, public Package
{
	void advertisement()
	{
		int ad;
		Package pack;
		string uname = User::GetInfo(); //이렇게 
		string country = User::getCount();
		
		ad = rand() % pack.v.size();
		cout << pack.v[ad] <<endl;
		
	}
};
