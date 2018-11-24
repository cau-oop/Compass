//김경태, 이의섭, 한승남
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

	void main()
	{
		char id[] = "Lee";
		char * fileName = strcat(id, ".txt");
		fstream fs(fileName);
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