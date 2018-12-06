#pragma once
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
		int randomxm; //비회원
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
		AD.close();
		randomxm = rand() % numLines;
		ifstream printAD("packagelist.txt");
		while (getline(printAD, adline))
		{
			if (findline == randomxm)
			{
				cout << adline;
			}
			findline++;
		}	
	}
	void advertisement_member() //회원
	{
		string locationad[100];
		int i = 0;
		string mline;
		size_t findpersonal=0;
		int countnum=0;
		int randomm; //회원
		string country = getCountry();
		ifstream ADMem("packagelist.txt");
		while (!ADMem.eof())
		{
			getline(ADMem, mline);
			if ((findpersonal == mline.find(country, 0)) != string::npos)
			{
				countnum++;
				locationad[i] = mline;
				i++;
			}

		}
		ADMem.close();
		randomm = rand() % countnum;
		cout << locationad[randomm] << endl;
	}
};
