//김경태, ?�의?? ?�승??
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

	string searchloc; //���� ���� ���� �Է�
	string searchmin; //�ּ� ����
	string searchmax; //�ִ� ����
	string searchdate; //�����
	int searchvia; //���� ����
	string searchfree; //�������� ����
	string searchppl; //�����ο�
=======
	string searchloc; //가�??��? 지???�력
	string searchmin; //최소 가�?
	string searchmax; //최�? 가�?
	string searchdate; //출발??
	int searchvia; //경유 ?�무
	string searchfree; //?�유?�정 ?�무

	string reviewstr;
	
	float rank;
	int buyer;
	
	int reviewbuyer;
	string Pname[100]; //?�키지 ?�름
	string location[100]; //지??
	string tag[100]; //?�시?�그
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
	void addPackage() //?�두�??�성
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
			cout << "?�일??찾을 ???�습?�다!" << endl;
		}
		
		cout << "Package ID :" << PID << endl;
		cout << "?�키지 ?�름: ";
		//cin.ignore();
		getline(cin, Pname[PID]);
		cout << "지??: ";
		getline(cin, location[PID]);
		cout << "?�그: ";
		getline(cin, tag[PID]);
		cout << "가�??�화): ";
		cin >> price[PID];
		cout << "경유 ?�무 (1. YES 0. NO): ";
		cin >> via[PID];
		cout << "?�행 출발?? ";
		cin >> trav_start_date[PID];
		cout << "?�행 출발 ?�간:(??�? ";
		cin >> trav_start_hour[PID];
		cout << "?�행기간: ";
		cin >> how_long_trav[PID];
		cout << "?�유?�행 (1. YES 0. NO) : ";
		cin >> free_trav[PID];
		cout << "최소?�원 :";
		cin >> minppl[PID];
		cout << "최�??�원 :";
		cin >> maxppl[PID];

		ofstream os;
		os.open("packagelist.txt", ios::app);
		os << "PID >>" << PID;
<<<<<<< HEAD
		os << " || ��Ű�� >>" << Pname[PID];
		os << " || ���� >>"<<location[PID];
		os << " || �±� >>" << tag[PID];
		os << " || ���� >>"<<price[PID];
		os << " || ���� >>" << via[PID];
		os << " || ����� >>"<<trav_start_date[PID];
		os << " || ��߽ð� >>"<<trav_start_hour[PID];
		os << " || ����Ⱓ >>"<<how_long_trav[PID];
		os << " || �������� >>" << free_trav[PID];
		os << " || �ּ��ο� >>" << minppl[PID];
		os << " || �ִ��ο� >>" << maxppl[PID] << endl;
=======
		os << "?�키지 >>" << Pname[PID];
		os << "지??>>"<<location[PID];
		os << "?�그 >>" << tag[PID];
		os << "가�?>>"<<price[PID];
		os << "경유 >>" << via[PID];
		os << "출발??>>"<<trav_start_date[PID];
		os << "출발?�간 >>"<<trav_start_hour[PID];
		os << "?�행기간 >>"<<how_long_trav[PID];
		os << "?�유?�행 >>" << free_trav[PID] << endl;;
>>>>>>> bf294570f9e63b23006481db293a0d520a7d40f5

		os.close();
	}

	void fileRead(ifstream& spack, vector<string>& v)
	{
		string line;

		while (getline(spack, line))
			v.push_back(line);
		
	}

<<<<<<< HEAD
	// ���Ϳ��� word�� ã�Ƽ� ����Ѵ�
	void search(vector<string>& v, string& word)
=======
	// 벡터?�서 word�?찾아??출력?�다
	void search(vector<string>& v, vector<string>& word)
>>>>>>> bf294570f9e63b23006481db293a0d520a7d40f5
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

		cout << "검???�션 : " << endl;
		cout << "1.지??1. Yes  2. No" << endl;
		cin >> option[0];
		if (option[0] == 1)
		{
			cout << "가�??��? 지??�� ?�력?�세??> ";
			cin >> searchloc;
			comparedata[0] = searchloc;
		}
		cout << "2.최소가�?1. Yes  2. No" << endl;
		cin >> option[1];
		if (option[1] == 1)
		{
			cout << "최소가격을 ?�력?�세??> ";
			cin >> searchmin;
			comparedata[1] = searchmin;
		}
		cout << "3.최�?가�?1. Yes  2. No" << endl;
		cin >> option[2];
		if (option[2] == 1)
		{
			cout << "최�?가격을 ?�력?�세??> ";
			cin >> searchmax;
			comparedata[2] = searchmax;
		}
		cout << "4.출발??1. Yes  2. No" << endl;
		cin >> option[3];
		if (option[3] == 1)
		{
			cout << "출발?�을 ?�력?�세??> ";
			cin >> searchdate;
			comparedata[3] = searchdate;
		}
<<<<<<< HEAD
		cout << "5.���� 1. Yes  2. No" << endl;
=======
		cout << "5.경유 1. Yes  2. No" << endl;

>>>>>>> bf294570f9e63b23006481db293a0d520a7d40f5
		cin >> option[4];
		if (option[4] == 1)
		{
			cout << "경유�??�실건�??? 0. ?�니??/ 1. ??>> ";
			cin >> searchvia;
			comparedata[4] = searchvia;
		}

		cout << "6.?�유?�정 1. Yes  2. No" << endl;
		cin >> option[5];
		if (option[5] == 1)
		{
			cout << "?�유?�정 0. ?�니??/ 1. ??>> ";
			cin >> searchfree;
			comparedata[5] = searchfree;
		}
		cout << "7.�����ο� 1. Yes  2. No" << endl;
		cin >> option[6];
		if (option[6] == 1)
		{
			cout << "�����ο� >> ";
			cin >> searchppl;
			comparedata[6] = searchppl;
		}
		ifstream spack;
		spack.open("packagelist.txt");
		fileRead(spack, v);
<<<<<<< HEAD
		search(v, searchloc);
		spack.close();
=======
		string word;
		vector<string> searchtotal;
		for (int i = 0; i < 6; i++)
		{
			if (option[i] == 1)
			{
				searchtotal.push_back(comparedata[i]);
			}
		}	
		search(v, searchtotal);

		/*if (spack.is_open()) //마무�??�요
		{
			pidcount = 0;
			while (!spack.eof())
			{
				getline(spack, line);
				if (option[0] == 1)
				{	
					if ((offset[0] = line.find(searchloc, 0)) != string::npos)
					{
					comparedata[0] = line;
					count++;
					}		
				}
				if (option[1] == 1)
				{

						if ((offset[1] = line.find("가�?>>" + searchmin, 0)) != string::npos)
						{
							comparedata[1] = line;
							count++;
						}
				}
				if (option[2] == 1)
				{
					if ((offset[2] = line.find("가�?>>" + searchmax, 0)) != string::npos)
						{
							comparedata[2] = line;
							count++;
						}
				}
				if (option[3] == 1)
				{
						if ((offset[3] = line.find("출발??>>" + searchdate, 0)) != string::npos)
						{
							comparedata[3] = line;
							count++;
						}
						
				}
				if (option[4] == 1)
				{
					
						if ((offset[4] = line.find("경유 >>" + searchvia, 0)) != string::npos)
						{
							comparedata[4] = line;
							count++;
						}
				}
				if (option[5] == 1)
				{
						if ((offset[5] = line.find("?�유?�행 >>" + searchfree, 0)) != string::npos)
						{
							comparedata[5] = line;
							count++;
						}
				}
			}
			
			/*for (int j = 0; j < 6; j++)
			{
				//for (int i = 0; i < 6; i++)
				//{
					for (int k = 0; k < 100; k++)
					{
						if ((comparedata[j][k] != "0") && (comparedata[j][k].compare(comparedata[i][k]) == 0))
						{
							cout << comparedata[j][k] << endl;
						}
					}
				//}
			}
				spack.close();
			
			
>>>>>>> bf294570f9e63b23006481db293a0d520a7d40f5

	}

	void buyPackage()
	{
		cout << "?�키지 구매" << endl;
		cout << "구매 방법 : 1.카드\t2.무통?�입�?t3.Payco\t4.카카?�페??<endl;

	}
	
};



int main()
{
	Package p;
		//p.addPackage();
		p.searchPackage();
		
}
