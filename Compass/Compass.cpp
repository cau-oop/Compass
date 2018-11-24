//김경태, 이의섭, 한승남
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
cout<< "hello"<<endl;
}

class Package
{
protected:
	int PID;
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
		ofstream out("packagelist.txt");
			cin >> Pname;
			out << Pname << endl;
		out.close();
	}
};