//김경태, 이의섭, 한승남
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


class User
{
private:
	char password;
	char name;
	char sex;
	int birth;
	int phone;
	bool spam;
	char place;

public:
	User()
	{
		
	}
	void GetInfo()
	{
		char idOnLogin[50] = "kkt752";
		char *fileName = strcat(idOnLogin, ".txt");
		cout << fileName << endl;
	}

	
};
/*
class Licensee
{
private:
	char password;
	char name;
	char agency;
	int phone;
	int license;
	int grade;
	int packgrade;
	bool spam;
	bool on;
public:


};
class Guide
{
private:

public:


};
*/
int main()
{
	cout << "das";
}