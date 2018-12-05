#pragma once
//�����, ���Ǽ�, �ѽ³�

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstring>
#include <array>
#include <iomanip>
#include <ctime>

#define MAX_STR_LEN 4000


using namespace std;




class Package
{
public:
	string searchloc; //���� ���� ���� �Է�
	int searchmin = 0; //�ּ� ����
	int searchmax = 0; //�ִ� ����
	string searchdate; //�����
	string searchvia; //���� ����
	string searchfree; //�������� ����
	int searchppl = 0; //�����ο�
	string reviewstr;
	vector<string> v; //��Ű�� ã�Ƽ� ��¿�
	string filename;
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
		int PID=0;
		size_t offset=0;
		string search;
		ifstream FileCheck("packagelist.txt");
		string s;

		if (FileCheck.is_open())
		{
			while (!FileCheck.eof())
			{
				search = "PID >>" + to_string(PID);
				getline(FileCheck, s);
				if ((offset == s.find(search, 0)) != string::npos)
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

		filename = to_string(PID) + ".rank.txt";
		ifstream newfile(filename.c_str(), ios::out);	
		ofstream nf(filename, ios::app);
		nf << "0 0";
		nf.close();
	}

	void fileRead(ifstream& spack, vector<string>& v)
	{
		string line;

		while (getline(spack, line))
			v.push_back(line);

	}

	void searchPackage()
	{
		int option[7] = { 0 };
		string comparedata[7];
		int findpackagecount = 0;
		int buypacknumber = 0; //��ǰ��ȣ
		int buynum; //�Է¹��� ��ǰ��ȣ
		int condition[100] = { 0, };

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

		ifstream spack;
		spack.open("packagelist.txt");
		fileRead(spack, v);
		for (int i = 0; i < v.size(); i++)
		{
			char *str_buff = new char[1000];
			char *str_buff2 = new char[1000];
			size_t findloc = 0, findmin = 0, findmax = 0, finddate = 0, findvia = 0, findfree = 0, findppl = 0;
			int pricetrue = 0, ppltrue = 0;
			int str_cnt = 0;
			char *tok = NULL;
			char *tok2 = NULL;
			char *tok3 = NULL;
			char *tok4 = NULL;
			string str_arr[1000];
			string str_arr2[100];

			if (option[0] == 1)
				findloc = v[i].find(comparedata[0]);
			if (option[1] == 1 || option[2] == 1)
			{
				findmin = v[i].find(comparedata[1]);
				findmax = v[i].find(comparedata[2]);

				if ((findmin != -1) || (findmax != -1))
				{
					strcpy(str_buff, v[i].c_str());
					tok = strtok(str_buff, "||");
					while (tok != nullptr)
					{
						str_arr[str_cnt++] = string(tok);
						tok = strtok(nullptr, "||");
					}

					char *comp = new char[1000];
					strcpy(comp, str_arr[4].c_str());
					tok2 = strtok(comp, ">>");
					str_arr2[0] = string(tok2);
					tok2 = strtok(nullptr, ">>"); //���� ����
					int convertstr = atoi(tok2);
					if (option[1] == 1)
					{
						if (option[2] == 1)
						{
							if (convertstr >= searchmin && convertstr <= searchmax)
							{
								pricetrue = 1;
							}
						}
						else
						{
							if (convertstr >= searchmin)
							{
								pricetrue = 1;
							}
						}

					}
					else if (option[2] == 1)
					{
						if (convertstr <= searchmax)
						{
							pricetrue = 1;
						}
					}
					free(comp);
				}
			}
			if (option[3] == 1)
				finddate = v[i].find(comparedata[3]);
			if (option[4] == 1)
				findvia = v[i].find(comparedata[4]);
			if (option[5] == 1)
				findfree = v[i].find(comparedata[5]);
			if (option[6] == 1)
			{
				tok = NULL;
				findppl = v[i].find(comparedata[6]);
				if (findppl != -1)
				{
					strcpy(str_buff2, v[i].c_str());
					str_cnt = 0;
					tok = strtok(str_buff2, "||");
					while (tok != nullptr)
					{
						str_arr[str_cnt++] = string(tok);
						tok = strtok(nullptr, "||");
					}

					char *comp2 = new char[1000];
					strcpy(comp2, str_arr[10].c_str());
					tok3 = strtok(comp2, ">>");
					str_arr2[0] = string(tok3);
					tok3 = strtok(nullptr, ">>"); //�ּ��ο� ����
					int convertpplmin = atoi(tok3); //int ��ȯ

					strcpy(comp2, str_arr[11].c_str());
					tok4 = strtok(comp2, ">>");
					str_arr2[0] = string(tok4);
					tok4 = strtok(nullptr, ">>"); //�ִ��ο� ����
					int convertpplmax = atoi(tok4); //int ��ȯ

					if (convertpplmin <= searchppl && convertpplmax >= searchppl)
					{
						ppltrue = 1;
					}
					free(comp2);
				}
			}
			if ((findloc != -1) && (findmin != -1) && (findmax != -1) && (finddate != -1) && (findvia != -1) && (findfree != -1) && (findppl != -1))
			{
				if (option[1] == 1 || option[2] == 1)
				{
					if (option[6] == 1)
					{
						if (ppltrue == 1 && pricetrue == 1)
						{
							cout << "��ǰ : " << buypacknumber << "-> " << v[i] << endl;
							findpackagecount++;
							buypacknumber++;
							condition[i] = 1;
						}
					}
					else
					{
						if (pricetrue == 1)
						{
							cout << "��ǰ : " << buypacknumber << "-> " << v[i] << endl;
							findpackagecount++;
							buypacknumber++;
							condition[i] = 1;
						}

					}
				}
				else if (option[6] == 1)
				{
					if (ppltrue == 1)
					{
						cout << "��ǰ : " << buypacknumber << "-> " << v[i] << endl;
						findpackagecount++;
						buypacknumber++;
						condition[i] = 1;

					}

				}
				else
				{
					cout << "��ǰ : " << buypacknumber << "-> " << v[i] << endl;
					findpackagecount++;
					buypacknumber++;
					condition[i] = 1;

				}

			}


			free(str_buff);
			free(str_buff2);
		}
		if (findpackagecount == 0)
			cout << "�˻��Ͻ� ���ǿ� �´� ��Ű���� ã�� ���߽��ϴ�" << endl;
		else
		{
			cout << "\n���� �Ͻ� ��Ű�� ��ǰ��ȣ�� �Է����ּ��� >>";
			cin >> buynum;
			if (condition[buynum] == 1)
			{
				cout << "\n\n" << v[buynum] << endl;
				buyPackage();
			}
			else
			{
				cout << "�߸� �Է��ϼ̽��ϴ�" << endl;
			}


		}

		spack.close();




	}


	void buyPackage()
	{
		int paymentopt;
		cout << "��Ű�� ����" << endl;
		cout << "���� ��� : 1.ī��\t2.�������Ա�\t3.Payco\t4.īī������" << endl;
		cin >> paymentopt;

	}

};
