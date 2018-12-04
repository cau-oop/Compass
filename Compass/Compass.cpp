//�����, ���Ǽ�, �ѽ³�
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstring>
#include <array>
#include <iomanip>

using namespace std;
string str_arr[1000];
string str_arr2[100];

char *str_buff = new char[1000];
int str_cnt = 0;
int PID = 0;

class Package
{
protected:
	string searchloc; //���� ���� ���� �Է�
	int searchmin; //�ּ� ����
	int searchmax; //�ִ� ����
	string searchdate; //�����
	string searchvia; //���� ����
	string searchfree; //�������� ����
	int searchppl; //�����ο�
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
		os << " || �±�(���� ����) >>" << tag[PID];
		os << " || ���� >> " << price[PID];
		os << " || ���� >>" << via[PID];
		os << " || ����� >>" << trav_start_date[PID];
		os << " || ��߽ð� >>" << trav_start_hour[PID];
		os << " || ����Ⱓ >>" << how_long_trav[PID];
		os << " || �������� >>" << free_trav[PID];
		os << " || �ּ��ο� >> " << minppl[PID];
		os << " || �ִ��ο� >> " << maxppl[PID] << endl;

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
			{
				strcpy(str_buff, v[i].c_str());
			}
		}
	}

	void searchPackage()
	{
		vector<string> v;
		vector<string> printlocation;
		vector<string> printpricemin;
		vector<string> printpricemax;
		vector<string> printdate;
		vector<string> printvia;
		vector<string> printfree;
		vector<string> printppl;
		int option[7] = { 0 };
		int offset[7] = { 0 };
		string comparedata[7];
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
			comparedata[1] = "���� >> ";
		}
		cout << "3.�ִ밡�� 1. Yes  2. No" << endl;
		cin >> option[2];
		if (option[2] == 1)
		{
			cout << "�ִ밡���� �Է��ϼ���>> ";
			cin >> searchmax;
			comparedata[2] = "���� >> ";
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
			comparedata[6] = "�ο� >>";
		}
		array<string, 7> compareoption;
		ifstream spack;
		spack.open("packagelist.txt");
		fileRead(spack, v);
		for (int i = 0; i < v.size(); i++)
		{
			int findloc = 0, findmin = 0, findmax = 0, finddate = 0,findvia= 0, findfree = 0, findppl = 0;
			if(option[0] ==1)
			 findloc = v[i].find(comparedata[0]);
			if (option[1] == 1 || option[2] == 1)
			{
				findmin = v[i].find(comparedata[1]);

				findmax = v[i].find(comparedata[2]);
				if ((findmin != -1)||(findmax!=-1))
				{
					strcpy(str_buff, v[i].c_str());
					char *tok = strtok(str_buff, "||");
					while (tok != nullptr)
					{
						str_arr[str_cnt++] = string(tok);
						tok = strtok(nullptr, "||");
					}

					char *comp = new char[1000];
					strcpy(comp, str_arr[4].c_str());
					cout << comp << endl;
					char *tok2 = strtok(comp, ">>");
					cout << tok2 << endl;
					str_arr2[0] = string(tok2);
					tok2 = strtok(nullptr, ">>"); //���� ����
					int convertstr = atoi(tok2);
					if (option[1] == 1)
					{
						if (option[2] == 1)
						{
							if (convertstr >= searchmin && convertstr <= searchmax)
							{
								printpricemin.push_back(v[i]);
								printpricemax.push_back(v[i]);
								for (int n = 0; n < str_cnt; n++)
								{
									cout << str_arr[n] << endl;
								}
							}
						}
						else
						{
							if (convertstr >= searchmin)
							{
								printpricemin.push_back(v[i]);
								for (int n = 0; n < str_cnt; n++)
								{

								}
							}
						}

					}
					else if (option[2] == 1)
					{
						if (convertstr <= searchmin)
						{
							printpricemax.push_back(v[i]);
							for (int n = 0; n < str_cnt; n++)
							{
								cout << str_arr[n] << endl;
							}
						}
					}
				}
			}
			if(option[3]==1)
			 finddate = v[i].find(comparedata[3]);
			if(option[4]==1)
			 findvia = v[i].find(comparedata[4]);
			if(option[5]==1)
			 findfree = v[i].find(comparedata[5]);
			if (option[6] == 1)
				findppl = v[i].find(comparedata[6]);
			if ((findloc != -1)&&(findmin !=-1)&&(findmax!=-1)&&(finddate!=-1) && (findvia != -1) && (findfree != -1) && (findppl != -1))
			{
				cout << v[i] << endl;
			}
		}

		/*if (option[0] == 1)
		{
			str_cnt = 0;
			for (int i = 0; i < v.size(); i++)
			{
				int index = v[i].find(searchloc);
				if (index != -1)
				{
					printlocation.push_back(v[i]);
				}
			}
			
		}
		if (option[1] == 1 || option[2] == 1)
		{
			for (int i = 0; i < v.size(); i++)
			{
				int index = v[i].find(comparedata[1]);
				if (index != -1)
				{
					strcpy(str_buff, v[i].c_str());
					char *tok = strtok(str_buff, "||");
					while (tok != nullptr)
					{
						str_arr[str_cnt++] = string(tok);
						tok = strtok(nullptr, "||");
					}

					char *comp = new char[1000];
					strcpy(comp, str_arr[4].c_str());
					cout << comp << endl;
					char *tok2 = strtok(comp, ">>");
					cout << tok2 << endl;
					str_arr2[0] = string(tok2);
					tok2 = strtok(nullptr, ">>"); //���� ����
					int convertstr = atoi(tok2);
					if (option[1] == 1)
					{
						if (option[2] == 1)
						{
							if (convertstr >= searchmin && convertstr <= searchmax)
							{
								printpricemin.push_back(v[i]);
								printpricemax.push_back(v[i]);
								for (int n = 0; n < str_cnt; n++)
								{
									cout << str_arr[n] << endl;
								}
							}
						}
						else
						{
							if (convertstr >= searchmin)
							{
								printpricemin.push_back(v[i]);
								for (int n = 0; n < str_cnt; n++)
								{
									cout << str_arr[n] << endl;
								}
							}
						}

					}
					else if (option[2] == 1)
					{
						if (convertstr <= searchmin)
						{
							printpricemax.push_back(v[i]);	
							for (int n = 0; n < str_cnt; n++)
							{
								cout << str_arr[n] << endl;
							}
						}
					}
				}
			}
			str_cnt = 0;
			
			


		}
		if (option[3] == 1)
		{
			search(v, searchdate);
			for (int i = 0; i < v.size(); i++)
			{
				int index = v[i].find(searchdate);
				if (index != -1)
				{
					printdate.push_back(v[i]);
				}
			}
		}
		if (option[4] == 1)
		{
			for (int i = 0; i < v.size(); i++)
			{
				int index = v[i].find(comparedata[4]);
				if (index != -1)
				{
					printvia.push_back(v[i]);
				}
			}
		}
		if (option[5] == 1)
		{
			for (int i = 0; i < v.size(); i++)
			{
				int index = v[i].find(comparedata[5]);
				if (index != -1)
				{
					printfree.push_back(v[i]);
				}
			}
		}

		if (option[6] == 1)
		{
			search(v, comparedata[6]);
			for (int i = 0; i < v.size(); i++)
			{
				int index = v[i].find(comparedata[6]);
				if (index != -1)
				{
					strcpy(str_buff, v[i].c_str());
					str_cnt = 0;
					char *tok = strtok(str_buff, "||");
					while (tok != nullptr)
					{
						str_arr[str_cnt++] = string(tok);
						tok = strtok(nullptr, "||");
					}

					char *comp = new char[1000];
					strcpy(comp, str_arr[10].c_str());
					char *tok3 = strtok(comp, ">>");
					str_arr2[0] = string(tok3);
					tok3 = strtok(nullptr, ">>"); //�ּ��ο� ����
					int convertpplmin = atoi(tok3); //int ��ȯ

					strcpy(comp, str_arr[11].c_str());
					char *tok4 = strtok(comp, ">>");
					str_arr2[0] = string(tok4);
					tok4 = strtok(nullptr, ">>"); //�ִ��ο� ����
					int convertpplmax = atoi(tok4); //int ��ȯ

					if (convertpplmin <= searchppl && convertpplmax >= searchppl)
					{
						for (int n = 0; n < str_cnt; n++)
						{
							printppl.push_back(v[i]);
						}
					}

				}
			}
		
		}*/
		cout << "���� 1 ���� :" << endl;
		for (int i = 0; i < printlocation.size(); i++)
			cout << printlocation[i]<<endl;
		for (int i = 0; i < 7; i++)
		{
			for (int j = 0; j < 7; j++)
			{
				if (j < i)
				{}
				else
				{
					compareoption[i] == compareoption[j];
				}
			}

		}

		spack.close();

	}

	void buyPackage()
	{
		cout << "��Ű�� ����" << endl;
		cout << "���� ��� : 1.ī��\t2.�������Ա�\t3.Payco\t4.īī������" << endl;
	}

};



int main()
{
	Package p;
	//p.addPackage();
	p.searchPackage();

}