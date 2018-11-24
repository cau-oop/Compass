//김경태, 이의섭, 한승남
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int PID;


class Package
{
protected:
	string Pname;
	string location;
	int price;
	int trav_start_date;
	int trav_start_hour;
	int how_long_trav;

public:
	Package()
	{

	}
	void addPackage()
	{
		cout << "패키지 이름: ";
		getline(cin, Pname);
		cout << "지역 : ";
		getline(cin, location);
		cout << "가격(원화): ";
		cin >> price;
		cout << "여행 출발일: ";
		cin >> trav_start_date;
		cout << "여행 출발 시간:(시 분) ";
		cin >> trav_start_hour;
		cout << "여행기간: ";
		cin >> how_long_trav;
		ofstream os;
		os.open("packagelist.txt");
		os << Pname << endl;
		os << location << endl;
		os << price << endl;
		os << trav_start_date << endl;
		os << trav_start_hour << endl;
		os << how_long_trav << endl;
		os.close();
	}
};

int main()
{
	Package p;
	p.addPackage();
}