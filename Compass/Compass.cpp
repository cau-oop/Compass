//�����, ���Ǽ�, �ѽ³�
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
	string searchvia; //���� ����
	string searchfree; //�������� ����
	string searchppl; //�����ο�
	string reviewstr;

	float rank;
	int buyer;

	int reviewbuyer;
	string Pname[100]; //��Ű�� �̸�
	string location[100]; //����
	string tag[100]; //�ؽ��±�
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
	void addPackage() //�µθ� �ϼ�
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
			cout << "������ ã�� �� �����ϴ�!" << endl;
		}

		cout << "Package ID :" << PID << endl;
		cout << "��Ű�� �̸�: ";
		//cin.ignore();
		getline(cin, Pname[PID]);
		cout << "���� : ";
		getline(cin, location[PID]);
		cout << "�±�: ";
		getline(cin, tag[PID]);
		cout << "����(��ȭ): ";
		cin >> price[PID];
		cout << "���� ���� (1. YES 0. NO): ";
		cin >> via[PID];
		cout << "���� �����: ";
		cin >> trav_start_date[PID];
		cout << "���� ��� �ð�:(�� ��) ";
		cin >> trav_start_hour[PID];
		cout << "����Ⱓ: ";
		cin >> how_long_trav[PID];
		cout << "�������� (1. YES 0. NO) : ";
		cin >> free_trav[PID];
		cout << "�ּ��ο� :";
		cin >> minppl[PID];
		cout << "�ִ��ο� :";
		cin >> maxppl[PID];

		ofstream os;
		os.open("packagelist.txt", ios::app);
		os << "PID >>" << PID;
		os << " || ��Ű�� >>" << Pname[PID];
		os << " || ���� >>" << location[PID];
		os << " || �±� >>" << tag[PID];
		os << " || ���� >>" << price[PID];
		os << " || ���� >>" << via[PID];
		os << " || ����� >>" << trav_start_date[PID];
		os << " || ��߽ð� >>" << trav_start_hour[PID];
		os << " || ����Ⱓ >>" << how_long_trav[PID];
		os << " || �������� >>" << free_trav[PID];
		os << " || �ּ��ο� >>" << minppl[PID];
		os << " || �ִ��ο� >>" << maxppl[PID] << endl;

		os.close();
	}

	void fileRead(ifstream& spack, vector<string>& v)
	{
		string line;

		while (getline(spack, line))
			v.push_back(line);

	}

	// ���Ϳ��� word�� ã�Ƽ� ����Ѵ�
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

		cout << "�˻� �ɼ� : " << endl;
		cout << "1.���� 1. Yes  2. No" << endl;
		cin >> option[0];
		if (option[0] == 1)
		{
			cout << "���� ���� ������ �Է��ϼ���>> ";
			cin >> searchloc;
			comparedata[0] = searchloc;
		}
		cout << "2.�ּҰ��� 1. Yes  2. No" << endl;
		cin >> option[1];
		if (option[1] == 1)
		{
			cout << "�ּҰ����� �Է��ϼ���>> ";
			cin >> searchmin;
			comparedata[1] = searchmin;
		}
		cout << "3.�ִ밡�� 1. Yes  2. No" << endl;
		cin >> option[2];
		if (option[2] == 1)
		{
			cout << "�ִ밡���� �Է��ϼ���>> ";
			cin >> searchmax;
			comparedata[2] = searchmax;
		}
		cout << "4.����� 1. Yes  2. No" << endl;
		cin >> option[3];
		if (option[3] == 1)
		{
			cout << "������� �Է��ϼ���>> ";
			cin >> searchdate;
			comparedata[3] = searchdate;
		}
		cout << "5.���� 1. Yes  2. No" << endl;
		cin >> option[4];
		if (option[4] == 1)
		{
			cout << "������ �Ͻǰǰ���? 0. �ƴϿ� / 1. �� >> ";
			cin >> searchvia;
			comparedata[4] = "���� >>" + searchvia;
		}

		cout << "6.�������� 1. Yes  2. No" << endl;
		cin >> option[5];
		if (option[5] == 1)
		{
			cout << "�������� 0. �ƴϿ� / 1. �� >> ";
			cin >> searchfree;
			comparedata[5] = "�������� >>" + searchfree;
		}
		cout << "7.�����ο� 1. Yes  2. No" << endl;
		cin >> option[6];
		if (option[6] == 1)
		{
			cout << "�����ο� >> ";
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
		cout << "��Ű�� ����" << endl;
		cout << "���� ��� : 1.ī��\t2.�������Ա�\t3.Payco\t4.īī������"<<endl;
	}

};
int main()
{
	Package p;
	//p.addPackage();
	p.searchPackage();

}