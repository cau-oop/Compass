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
