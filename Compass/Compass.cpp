//�����, ���Ǽ�, �ѽ³�
#include <iostream>
#include <fstream>
#include <string>
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
		os << "��Ű�� >>" << Pname[PID];
		os << "���� >>"<<location[PID];
		os << "�±� >>" << tag[PID];
		os << "���� >>"<<price[PID];
		os << "���� >>" << via[PID];
		os << "����� >>"<<trav_start_date[PID];
		os << "��߽ð� >>"<<trav_start_hour[PID];
		os << "����Ⱓ >>"<<how_long_trav[PID];
		os << "�������� >>" << free_trav[PID] << endl;;

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
		
		cout << "�˻� �ɼ� : " << endl;
		cout << "1.���� 1. Yes  2. No" << endl;
		cin >> option[0];
		if (option[0] == 1)
		{
			cout << "���� ���� ������ �Է��ϼ���>> ";
			cin >> searchloc;
		}
		cout << "2.�ּҰ��� 1. Yes  2. No" << endl;
		cin >> option[1];
		if (option[1] == 1)
		{
			cout << "�ּҰ����� �Է��ϼ���>> ";
			cin >> searchmin;
		}
		cout << "3.�ִ밡�� 1. Yes  2. No" << endl;
		cin >> option[2];
		if (option[2] == 1)
		{
			cout << "�ִ밡���� �Է��ϼ���>> ";
			cin >> searchmax;
		}
		cout << "4.����� 1. Yes  2. No" << endl;
		cin >> option[3];
		if (option[3] == 1)
		{
			cout << "������� �Է��ϼ���>> ";
			cin >> searchdate;
		}
		cout << "5.���� 1. Yes  2. No" << endl;
		cin >> option[4];
		if (option[4] == 1)
		{
			cout << "������ �Ͻǰǰ���? 0. �ƴϿ� / 1. �� >> ";
			cin >> searchvia;
		}

		cout << "6.�������� 1. Yes  2. No" << endl;
		cin >> option[5];
		if (option[5] == 1)
		{
			cout << "�������� 0. �ƴϿ� / 1. �� >> ";
			cin >> searchfree;
		}
		ifstream MyFile;
		MyFile.open("packagelist.txt");
			if (MyFile.is_open()) //������ �ʿ�
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
						if ((offset[1] = line.find("���� >>" + searchmin, 0)) != string::npos)
						{
							comparedata[1] = line;
							foundpackage[count] = 1;
							count++;
						}
							
					}
					if (option[2] == 1)
					{
						if ((offset[2] = line.find("���� >>" + searchmax, 0)) != string::npos)
						{
							comparedata[2] = line;
							foundpackage[count] = 1;
							count++;
						}
					}
					if (option[3] == 1)
					{
						if ((offset[3] = line.find("����� >>" + searchdate, 0)) != string::npos)
						{
							comparedata[3] = line;
							foundpackage[count] = 1;
							count++;
						}
					}
					if (option[4] == 1)
					{
						if ((offset[4] = line.find("���� >>" + searchvia, 0)) != string::npos)
						{
							comparedata[4] = line;
							foundpackage[count] = 1;
							count++;
						}
					}
					if (option[5] == 1)
					{
						if ((offset[5] = line.find("�������� >>" + searchfree, 0)) != string::npos)
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
				cout << "������ �� �� �����ϴ�." << endl;
		
		
			/*if (MyFile.is_open()) //������ �ʿ�
			{
				while (!MyFile.eof())
				{
					getline(MyFile, line);
					if ((offset[1] = line.find("���� >>" + searchmin, 0)) != string::npos)
						cout << "�ּҰ��ݿ� �´� ��Ű���� ã�ҽ��ϴ� : " << searchmin << endl;
				}
				MyFile.close();
			}
			else
				cout << "������ �� �� �����ϴ�." << endl;
		
			if (MyFile.is_open()) //������ �ʿ�
			{
				while (!MyFile.eof())
				{
					getline(MyFile, line);
					if ((offset[2] = line.find(searchmax, 0)) != string::npos)
						cout << "�ִ밡�ݿ� �´� ��Ű���� ã�ҽ��ϴ� : " << searchmax << endl;
				}
				MyFile.close();
			}
			else
				cout << "������ �� �� �����ϴ�." << endl;
	
			if (MyFile.is_open()) //������ �ʿ�
			{
				while (!MyFile.eof())
				{
					getline(MyFile, line);
					if ((offset[3] = line.find("����� >>" + searchdate, 0)) != string::npos)
						cout << "���� ��¥�� �´� ��Ű���� ã�ҽ��ϴ� : " << searchdate << endl;
				}
				MyFile.close();
			}
			else
				cout << "������ �� �� �����ϴ�." << endl;
		
			if (MyFile.is_open()) //������ �ʿ�
			{
				while (!MyFile.eof())
				{
					getline(MyFile, line);
					if ((offset[4] = line.find("���� >>" + searchvia, 0)) != string::npos)
						cout << "������ ���Ե� ��Ű���� ã�ҽ��ϴ� : " << searchvia << endl;
				}
				MyFile.close();
			}
			else
				cout << "������ �� �� �����ϴ�." << endl;
		
			if (MyFile.is_open()) //������ �ʿ�
			{
				while (!MyFile.eof())
				{
					getline(MyFile, line);
					if ((offset[5] = line.find("�������� >>" + searchfree, 0)) != string::npos)
						cout << "���������� ��Ű���� ã�ҽ��ϴ� : " << searchfree << endl;
				}
				MyFile.close();
			}
			else
				cout << "������ �� �� �����ϴ�." << endl;*/
		
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