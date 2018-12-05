//김경태, 이의섭, 한승남

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstring>
#include <array>
#include <iomanip>
#include <ctime>
#include "obectClassFile.h"
#include "Package.h"



using namespace std;


class Advertise : public User, public Package
{
public:
	void advertisement_xmemeber()		//비회원일시
	{
		int random;
		string adline;
		int numLines = 0;
		int findline=0;
		string line;

		ifstream AD("packagelist.txt");
		while (!AD.eof())
		{
			getline(AD, line);
			numLines++;
		}
		numLines--;
		cout << numLines << endl;
		random = rand() % numLines;
		cout << random << endl;
		AD.close();
		ifstream printAD("packagelist.txt");
		while (getline(printAD, adline))
		{
			if (findline == random)
			{
				cout << adline;
			}
			findline++;
		}	
	}
	/*void advertisement_member()
	{
		string locationad;
		string mline;
		size_t findpersonal=0;
		User::getCountry;
		ifstream ADMem("packagelist.txt");
		while (!ADMem.eof())
		{
			getline(ADMem, mline);
			if((findpersonal == ADMem.find( ))
		}
	}*/
};
