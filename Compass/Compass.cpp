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
					cout << "�ش� ������ �´� ��Ű���� ã�ҽ��ϴ� : " << searchloc << endl;
			}
			MyFile.close();
		}
		���ϳ� PID ���Ͽ� PID �� �����ҽ� +1 �ݺ�
		*/

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
		cout << "�˻� �ɼ� : " << endl;
		cout << "";
		cout << "���� ���� ������ �Է��ϼ���>> ";
		cin >> searchloc;
		cout << "�ּҰ����� �Է��ϼ���>> ";
		cin >> searchmin;
		cout << "�ִ밡���� �Է��ϼ���>> ";
		cin >> searchmax;
		cout << "������� �Է��ϼ���>> ";
		cin >> searchdate;
		cout << "������ �Ͻǰǰ���? 0. �ƴϿ� / 1. �� >> ";
		cin >> searchmin;
		cout << "�������� 0. �ƴϿ� / 1. �� >> ";
		cin >> searchfree;
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