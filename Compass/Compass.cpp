//�����, ���Ǽ�, �ѽ³�
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int PID=0;

class Package
{
protected:
	string searchloc; //���� ���� ���� �Է�
	string searchmin; //�ּ� ����
	string searchmax; //�ִ� ����
	string searchdate; //�����
	int searchvia; //���� ����
	string searchfree; //�������� ����
	string Pname[100]; //��Ű�� �̸�
	string location[100]; //����
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
		int offset;
		string search;
		string line;
		ifstream FileCheck;
		FileCheck.open("packagelist.txt");
		search = "PID >>"+PID;
		if(FileCheck.is_open())
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
		//���ϳ� PID ���Ͽ� PID �� �����ҽ� +1 �ݺ�
		

		cout << "��Ű�� �̸�: ";
		getline(cin, Pname[PID]); //getline �ݺ� �ߺ� ���� �ذ��ʿ�
		fflush(stdin);
		cout << "���� : ";
		getline(cin, location[PID]);
		fflush(stdin);
		cout << "����(��ȭ): ";
		cin >> price[PID];
		cout << "���� �����: ";
		cin >> trav_start_date[PID];
		cout << "���� ��� �ð�:(�� ��) ";
		cin >> trav_start_hour[PID];
		cout << "����Ⱓ: ";
		cin >> how_long_trav[PID];

		ofstream os;
		os.open("packagelist.txt");
		os << "PID >>" << PID <<  endl;
		os << "��Ű�� >>" << Pname[PID] << endl;
		os << "���� >>"<<location[PID] << endl;
		os << "���� >>"<<price[PID] << endl;
		os << "����� >>"<<trav_start_date[PID] << endl;
		os << "��߽ð� >>"<<trav_start_hour[PID] << endl;
		os << "����Ⱓ >>"<<how_long_trav[PID] << endl;
		os.close();
	}

	void searchPackage()
	{
		int option;
		int offset;
		string line; 
		ifstream MyFile;
		MyFile.open("packagelist.txt");
		cout << "�˻� �ɼ� : " << endl;
		cout << "1.����\t2.�ּҰ���\t3.�ִ밡��\t4.�����\t5.����\t6.��������" << endl;
		cin >> option;
		switch (option)
		{
		case 1:
			cout << "���� ���� ������ �Է��ϼ���>> ";
			cin >> searchloc;
			break;
		case 2:
			cout << "�ּҰ����� �Է��ϼ���>> ";
			cin >> searchmin;
			break;
		case 3:
			cout << "�ִ밡���� �Է��ϼ���>> ";
			cin >> searchmax;
			break;
		case 4:
			cout << "������� �Է��ϼ���>> ";
			cin >> searchdate;
			break;
		case 5:
			cout << "������ �Ͻǰǰ���? 0. �ƴϿ� / 1. �� >> ";
			cin >> searchvia;
			break;
		case 6:
			cout << "�������� 0. �ƴϿ� / 1. �� >> ";
			cin >> searchfree;
			break;
		}

		if (MyFile.is_open()) //������ �ʿ�
		{
			while (!MyFile.eof())
			{
				getline(MyFile, line);
				if ((offset = line.find(searchloc, 0)) != string::npos)
					cout << "�ش� ������ �´� ��Ű���� ã�ҽ��ϴ� : " << searchloc << endl;
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
				if ((offset = line.find(searchmin, 0)) != string::npos)
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
				if ((offset = line.find(searchmax, 0)) != string::npos)
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
				if ((offset = line.find(searchdate, 0)) != string::npos)
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
				if ((offset = line.find(searchvia, 0)) != string::npos)
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
				if ((offset = line.find(searchfree, 0)) != string::npos)
					cout << "���������� ��Ű���� ã�ҽ��ϴ� : " << searchfree << endl;
			}
			MyFile.close();
		}
		else
			cout << "������ �� �� �����ϴ�." << endl;
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