//김경태, 이의섭, 한승남
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int PID=0;

class Package
{
protected:
	string searchloc; //가고 싶은 지역 입력
	string searchmin; //최소 가격
	string searchmax; //최대 가격
	string searchdate; //출발일
	int searchvia; //경유 유무
	string searchfree; //자유일정 유무
	string Pname[100]; //패키지 이름
	string location[100]; //지역
	int price[100];
	int trav_start_date[100];
	int trav_start_hour[100];
	int how_long_trav[100];

public:
	Package()
	{

	}
	void addPackage()
	{
		/*int offset;
		string line;
		ifstream MyFile;
		MyFile.open("packagelist.txt");
		if(MyFile.is_open())
		{
			while (!MyFile.eof())
			{
				getline(MyFile, line);
				if ((offset = PID != string::npos)
					cout << "해당 지역에 맞는 패키지를 찾았습니다 : " << searchloc << endl;
			}
			MyFile.close();
		}
		파일내 PID 비교하여 PID 값 존재할시 +1 반복
		*/

		cout << "패키지 이름: ";
		getline(cin, Pname[PID]); //getline 반복 중복 문제 해결필요
		fflush(stdin);
		cout << "지역 : ";
		getline(cin, location[PID]);
		fflush(stdin);
		cout << "가격(원화): ";
		cin >> price[PID];
		cout << "여행 출발일: ";
		cin >> trav_start_date[PID];
		cout << "여행 출발 시간:(시 분) ";
		cin >> trav_start_hour[PID];
		cout << "여행기간: ";
		cin >> how_long_trav[PID];

		ofstream os;
		os.open("packagelist.txt");
		os << PID << endl;
		os << Pname[PID] << endl;
		os << location[PID] << endl;
		os << price[PID] << endl;
		os << trav_start_date[PID] << endl;
		os << trav_start_hour[PID] << endl;
		os << how_long_trav[PID] << endl;
		os.close();
	}

	void searchPackage()
	{
		int offset;
		string line; 
		ifstream MyFile;
		MyFile.open("packagelist.txt");
		cout << "검색 옵션 : " << endl;
		cout << "";
		cout << "가고 싶은 지역을 입력하세요>> ";
		cin >> searchloc;
		cout << "최소가격을 입력하세요>> ";
		cin >> searchmin;
		cout << "최대가격을 입력하세요>> ";
		cin >> searchmax;
		cout << "출발일을 입력하세요>> ";
		cin >> searchdate;
		cout << "경유를 하실건가요? 0. 아니요 / 1. 예 >> ";
		cin >> searchmin;
		cout << "자유일정 0. 아니요 / 1. 예 >> ";
		cin >> searchfree;
		if (MyFile.is_open()) //마무리 필요
		{
			while (!MyFile.eof())
			{
				getline(MyFile, line);
				if ((offset = line.find(searchloc, 0)) != string::npos)
					cout << "해당 지역에 맞는 패키지를 찾았습니다 : " << searchloc << endl;
			}
			MyFile.close();
		}
		else
			cout << "파일을 열 수 없습니다." << endl;

	}
	void advertisement()
	{

	}
};

int main()
{
	Package p;
	for (int i = 0; i < 5; i++)
	{
		p.addPackage();
		PID++;
	}
}