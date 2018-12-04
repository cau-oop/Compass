//김경태, 이의섭, 한승남
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

int PID;

class Package
{
protected:
	string searchloc; //가고 싶은 지역 입력
	string searchmin; //최소 가격
	string searchmax; //최대 가격
	string searchdate; //출발일
	string searchvia; //경유 유무
	string searchfree; //자유일정 유무
	string searchppl; //여행인원
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
		os << " || 패키지 >>" << Pname[PID];
		os << " || 지역 >>" << location[PID];
		os << " || 태그 >>" << tag[PID];
		os << " || 가격 >>" << price[PID];
		os << " || 경유 >>" << via[PID];
		os << " || 출발일 >>" << trav_start_date[PID];
		os << " || 출발시간 >>" << trav_start_hour[PID];
		os << " || 여행기간 >>" << how_long_trav[PID];
		os << " || 자유여행 >>" << free_trav[PID];
		os << " || 최소인원 >>" << minppl[PID];
		os << " || 최대인원 >>" << maxppl[PID] << endl;

		os.close();
	}

	void fileRead(ifstream& spack, vector<string>& v)
	{
		string line;

		while (getline(spack, line))
			v.push_back(line);

	}

	// 벡터에서 word를 찾아서 출력한다
	void search(vector<string>& v, string& word)
	{
		for (int i = 0; i < v.size(); i++)
		{
			int index = v[i].find(word);
			if (index != -1)
				cout << v[i] << endl;

		}
	}

	void searchPackage()
	{
		vector<string> v;
		int option[7] = { 0 };
		int offset[7] = { 0 };
		string comparedata[7] = { 0 };
		int count = 0;
		string line;

		cout << "검색 옵션 : " << endl;
		cout << "1.지역 1. Yes  2. No" << endl;
		cin >> option[0];
		if (option[0] == 1)
		{
			cout << "가고 싶은 지역을 입력하세요>> ";
			cin >> searchloc;
			comparedata[0] = searchloc;
		}
		cout << "2.최소가격 1. Yes  2. No" << endl;
		cin >> option[1];
		if (option[1] == 1)
		{
			cout << "최소가격을 입력하세요>> ";
			cin >> searchmin;
			comparedata[1] = searchmin;
		}
		cout << "3.최대가격 1. Yes  2. No" << endl;
		cin >> option[2];
		if (option[2] == 1)
		{
			cout << "최대가격을 입력하세요>> ";
			cin >> searchmax;
			comparedata[2] = searchmax;
		}
		cout << "4.출발일 1. Yes  2. No" << endl;
		cin >> option[3];
		if (option[3] == 1)
		{
			cout << "출발일을 입력하세요>> ";
			cin >> searchdate;
			comparedata[3] = searchdate;
		}
		cout << "5.경유 1. Yes  2. No" << endl;
		cin >> option[4];
		if (option[4] == 1)
		{
			cout << "경유를 하실건가요? 0. 아니요 / 1. 예 >> ";
			cin >> searchvia;
			comparedata[4] = "경유 >>" + searchvia;
		}

		cout << "6.자유일정 1. Yes  2. No" << endl;
		cin >> option[5];
		if (option[5] == 1)
		{
			cout << "자유일정 0. 아니요 / 1. 예 >> ";
			cin >> searchfree;
			comparedata[5] = "자유여행 >>" + searchfree;
		}
		cout << "7.여행인원 1. Yes  2. No" << endl;
		cin >> option[6];
		if (option[6] == 1)
		{
			cout << "여행인원 >> ";
			cin >> searchppl;
			comparedata[6] = searchppl;
		}

		int ppl[5];
		ifstream spack;
		spack.open("packagelist.txt");
		spack >> ppl[0];
		spack >> ppl[1];
		cout << ppl[0] << endl;
		cout << ppl[1] << endl;
		/*
		fileRead(spack, v);
		search(v, searchloc);
		search(v, searchmin);
		search(v, searchmax);
		search(v, searchdate);
		search(v, comparedata[5);
		search(v, comparedata[4]);
		search(v, searchppl);
		*/
		spack.close();

	}

	void buyPackage()
	{
		cout << "패키지 구매" << endl;
		cout << "구매 방법 : 1.카드\t2.무통장입금\t3.Payco\t4.카카오페이"<<endl;
	}

};
int main()
{
	Package p;
	//p.addPackage();
	p.searchPackage();

}