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
	string tag[100]; //해시태그
	int price[100];
	int via[100];
	int trav_start_date[100];
	int trav_start_hour[100];
	int how_long_trav[100];
	int free_trav[100];
public:
	Package()
	{

	}
	void addPackage() //태두리 완성
	{
		int offset;
		string search;
		string line;
		string PIDconv;
		ifstream FileCheck("packagelist.txt");
		string s;
		search = "PID >>"; //+ to_string(PID);
		if (FileCheck.is_open()) {
			while (!FileCheck.eof()) {
				getline(FileCheck, s);
				cout << s << endl;
				if ((offset = line.find(search, 0)) != string::npos)
				{
					++PID;
					cout << "yes" << endl;

				}
			}
				FileCheck.close();
			
		}
		else {
			cout << "파일을 찾을 수 없습니다!" << endl;
		}

		cout << search << endl;
		
		/*if(FileCheck.is_open())
		{
			while (!FileCheck.eof())
			{
				
				getline(FileCheck, line);
				if ((offset = line.find(search, 0)) != string::npos)
					PID++;
				else
					break;
			}
			FileCheck.close();
		}
		//파일내 PID 비교하여 PID 값 존재할시 +1 반복
		*/

		cout << "패키지 이름: ";
		cin.ignore();
		getline(cin, Pname[PID]);
		fflush(stdin);
		cout << "지역 : ";
		getline(cin, location[PID]);
		fflush(stdin);
		cout << "태그: ";
		getline(cin, tag[PID]);
		cout << "가격(원화): ";
		cin >> price[PID];
		cout << "경유 유무 (1. YES 2. NO): ";
		cin >> via[PID];
		cout << "여행 출발일: ";
		cin >> trav_start_date[PID];
		cout << "여행 출발 시간:(시 분) ";
		cin >> trav_start_hour[PID];
		cout << "여행기간: ";
		cin >> how_long_trav[PID];
		cout << "자유여행 (1. YES 2. NO) : ";
		cin >> free_trav[PID];

		ofstream os;
		os.open("packagelist.txt", ios::app);
		os << "PID >>" << PID <<  endl;
		os << "패키지 >>" << Pname[PID] << endl;
		os << "지역 >>"<<location[PID] << endl;
		os << "태그 >>" << tag[PID] << endl;
		os << "가격 >>"<<price[PID] << endl;
		os << "경유 >>" << via[PID] << endl;
		os << "출발일 >>"<<trav_start_date[PID] << endl;
		os << "출발시간 >>"<<trav_start_hour[PID] << endl;
		os << "여행기간 >>"<<how_long_trav[PID] << endl;
		os << "자유여행 >>" << free_trav[PID] << endl;

		os.close();
	}

	void searchPackage()
	{
		int option;
		int offset;
		string line; 
		ifstream MyFile;
		MyFile.open("packagelist.txt");
		cout << "검색 옵션 : " << endl;
		cout << "1.지역\t2.최소가격\t3.최대가격\t4.출발일\t5.경유\t6.자유일정" << endl;
	
			cout << "가고 싶은 지역을 입력하세요>> ";
			cin >> searchloc;
		
			cout << "최소가격을 입력하세요>> ";
			cin >> searchmin;
		
			cout << "최대가격을 입력하세요>> ";
			cin >> searchmax;
		
			cout << "출발일을 입력하세요>> ";
			cin >> searchdate;
		
			cout << "경유를 하실건가요? 0. 아니요 / 1. 예 >> ";
			cin >> searchvia;
		
			cout << "자유일정 0. 아니요 / 1. 예 >> ";
			cin >> searchfree;
		
			if (MyFile.is_open()) //마무리 필요
			{
				while (!MyFile.eof())
				{
					getline(MyFile, line);
					if ((offset = line.find("지역 >>"+searchloc, 0)) != string::npos)
						cout << "해당 지역에 맞는 패키지를 찾았습니다 : " << searchloc << endl;
				}
				MyFile.close();
			}
			else
				cout << "파일을 열 수 없습니다." << endl;
		
		
			if (MyFile.is_open()) //마무리 필요
			{
				while (!MyFile.eof())
				{
					getline(MyFile, line);
					if ((offset = line.find("가격 >>" + searchmin, 0)) != string::npos)
						cout << "최소가격에 맞는 패키지를 찾았습니다 : " << searchmin << endl;
				}
				MyFile.close();
			}
			else
				cout << "파일을 열 수 없습니다." << endl;
		
			if (MyFile.is_open()) //마무리 필요
			{
				while (!MyFile.eof())
				{
					getline(MyFile, line);
					if ((offset = line.find(searchmax, 0)) != string::npos)
						cout << "최대가격에 맞는 패키지를 찾았습니다 : " << searchmax << endl;
				}
				MyFile.close();
			}
			else
				cout << "파일을 열 수 없습니다." << endl;
	
			if (MyFile.is_open()) //마무리 필요
			{
				while (!MyFile.eof())
				{
					getline(MyFile, line);
					if ((offset = line.find("출발일 >>" + searchdate, 0)) != string::npos)
						cout << "시작 날짜가 맞는 패키지를 찾았습니다 : " << searchdate << endl;
				}
				MyFile.close();
			}
			else
				cout << "파일을 열 수 없습니다." << endl;
		
			if (MyFile.is_open()) //마무리 필요
			{
				while (!MyFile.eof())
				{
					getline(MyFile, line);
					if ((offset = line.find("경유 >>" + searchvia, 0)) != string::npos)
						cout << "경유가 포함된 패키지를 찾았습니다 : " << searchvia << endl;
				}
				MyFile.close();
			}
			else
				cout << "파일을 열 수 없습니다." << endl;
		
			if (MyFile.is_open()) //마무리 필요
			{
				while (!MyFile.eof())
				{
					getline(MyFile, line);
					if ((offset = line.find("자유여행 >>" + searchfree, 0)) != string::npos)
						cout << "자유여행인 패키지를 찾았습니다 : " << searchfree << endl;
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
		p.addPackage();
		
}