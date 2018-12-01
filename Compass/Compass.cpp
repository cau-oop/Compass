//김경태, 이의섭, 한승남
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int PID;

class Package
{
protected:
	string searchloc; //가고 싶은 지역 입력
	string searchmin; //최소 가격
	string searchmax; //최대 가격
	string searchdate; //출발일
	int searchvia; //경유 유무
	string searchfree; //자유일정 유무
	string reviewstr;
	
	float rank;
	int buyer;
	
	int reviewbuyer;
	string Pname[100]; //패키지 이름
	string location[100]; //지역
	string tag[100]; //해시태그
	int price[100];
	int via[100];

	int trav_start_date[100];
	int trav_start_hour[100];

	int how_long_trav[100];
	int free_trav[100];
	int minppl[100];
	int maxppl[100];
 public:
	Package()
	{

	}
	void addPackage() //태두리 완성
	{
		PID = 0;
		int offset;
		string search;
		ifstream FileCheck("packagelist.txt");
		string s;
		
		if (FileCheck.is_open()) {
			while (!FileCheck.eof()) {
				search = "PID >>" + to_string(PID);
				getline(FileCheck, s);
				if ((offset = s.find(search, 0)) != string::npos)
				{
					PID++;
				}
			}
				FileCheck.close();
			
		}
		else {
			cout << "파일을 찾을 수 없습니다!" << endl;
		}
		
		cout << "Package ID :" << PID << endl;
		cout << "패키지 이름: ";
		//cin.ignore();
		getline(cin, Pname[PID]);
		cout << "지역 : ";
		getline(cin, location[PID]);
		cout << "태그: ";
		getline(cin, tag[PID]);
		cout << "가격(원화): ";
		cin >> price[PID];
		cout << "경유 유무 (1. YES 0. NO): ";
		cin >> via[PID];
		cout << "여행 출발일: ";
		cin >> trav_start_date[PID];
		cout << "여행 출발 시간:(시 분) ";
		cin >> trav_start_hour[PID];
		cout << "여행기간: ";
		cin >> how_long_trav[PID];
		cout << "자유여행 (1. YES 0. NO) : ";
		cin >> free_trav[PID];
		cout << "최소인원 :";
		cin >> minppl[PID];
		cout << "최대인원 :";
		cin >> maxppl[PID];

		ofstream os;
		os.open("packagelist.txt", ios::app);
		os << "PID >>" << PID;
		os << "패키지 >>" << Pname[PID];
		os << "지역 >>"<<location[PID];
		os << "태그 >>" << tag[PID];
		os << "가격 >>"<<price[PID];
		os << "경유 >>" << via[PID];
		os << "출발일 >>"<<trav_start_date[PID];
		os << "출발시간 >>"<<trav_start_hour[PID];
		os << "여행기간 >>"<<how_long_trav[PID];
		os << "자유여행 >>" << free_trav[PID] << endl;;

		os.close();
	}

	void searchPackage()
	{
		int option[6] = { 0 };
		int offset[6] = { 0 };
		string comparedata[6] = { 0 };
		int foundpackage[100] = { 0 };
		int count = 0;
		int pidcount = 0;
		string str;
		string line; 
		
		cout << "검색 옵션 : " << endl;
		cout << "1.지역 1. Yes  2. No" << endl;
		cin >> option[0];
		if (option[0] == 1)
		{
			cout << "가고 싶은 지역을 입력하세요>> ";
			cin >> searchloc;
		}
		cout << "2.최소가격 1. Yes  2. No" << endl;
		cin >> option[1];
		if (option[1] == 1)
		{
			cout << "최소가격을 입력하세요>> ";
			cin >> searchmin;
		}
		cout << "3.최대가격 1. Yes  2. No" << endl;
		cin >> option[2];
		if (option[2] == 1)
		{
			cout << "최대가격을 입력하세요>> ";
			cin >> searchmax;
		}
		cout << "4.출발일 1. Yes  2. No" << endl;
		cin >> option[3];
		if (option[3] == 1)
		{
			cout << "출발일을 입력하세요>> ";
			cin >> searchdate;
		}
		cout << "5.경유 1. Yes  2. No" << endl;
		cin >> option[4];
		if (option[4] == 1)
		{
			cout << "경유를 하실건가요? 0. 아니요 / 1. 예 >> ";
			cin >> searchvia;
		}

		cout << "6.자유일정 1. Yes  2. No" << endl;
		cin >> option[5];
		if (option[5] == 1)
		{
			cout << "자유일정 0. 아니요 / 1. 예 >> ";
			cin >> searchfree;
		}
		ifstream MyFile;
		MyFile.open("packagelist.txt");
			if (MyFile.is_open()) //마무리 필요
			{
				pidcount = 0;
				while (!MyFile.eof())
				{
					getline(MyFile, line);
					if (option[0] == 1)
					{
						if ((offset[0] = line.find(searchloc, 0)) != string::npos)
						{
							comparedata[0] = line;
							foundpackage[count] = 1;
							count++;
						}
					}
					if (option[1] == 1)
					{
						if ((offset[1] = line.find("가격 >>" + searchmin, 0)) != string::npos)
						{
							comparedata[1] = line;
							foundpackage[count] = 1;
							count++;
						}
							
					}
					if (option[2] == 1)
					{
						if ((offset[2] = line.find("가격 >>" + searchmax, 0)) != string::npos)
						{
							comparedata[2] = line;
							foundpackage[count] = 1;
							count++;
						}
					}
					if (option[3] == 1)
					{
						if ((offset[3] = line.find("출발일 >>" + searchdate, 0)) != string::npos)
						{
							comparedata[3] = line;
							foundpackage[count] = 1;
							count++;
						}
					}
					if (option[4] == 1)
					{
						if ((offset[4] = line.find("경유 >>" + searchvia, 0)) != string::npos)
						{
							comparedata[4] = line;
							foundpackage[count] = 1;
							count++;
						}
					}
					if (option[5] == 1)
					{
						if ((offset[5] = line.find("자유여행 >>" + searchfree, 0)) != string::npos)
						{
							comparedata[5] = line;
							foundpackage[count] = 1;
							count++;
						}
					}
						pidcount++;
					}
				if (comparedata[0] != comparedata[1] /*!= comparedata[2] != comparedata[3] != comparedata[4] != comparedata[5]*/)
				{

				}
				else
				{
					for (int i = 0; i < 6; i++)
					{
						if(comparedata[i]!=0)
						cout << comparedata[i] << endl;
					}
					}
				MyFile.close();
			}
			else
				cout << "파일을 열 수 없습니다." << endl;
		
		
			/*if (MyFile.is_open()) //마무리 필요
			{
				while (!MyFile.eof())
				{
					getline(MyFile, line);
					if ((offset[1] = line.find("가격 >>" + searchmin, 0)) != string::npos)
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
					if ((offset[2] = line.find(searchmax, 0)) != string::npos)
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
					if ((offset[3] = line.find("출발일 >>" + searchdate, 0)) != string::npos)
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
					if ((offset[4] = line.find("경유 >>" + searchvia, 0)) != string::npos)
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
					if ((offset[5] = line.find("자유여행 >>" + searchfree, 0)) != string::npos)
						cout << "자유여행인 패키지를 찾았습니다 : " << searchfree << endl;
				}
				MyFile.close();
			}
			else
				cout << "파일을 열 수 없습니다." << endl;*/
		
	}
	void advertisement()
	{

	}
};

int main()
{
	Package p;
		//p.addPackage();
		p.searchPackage();
		
}