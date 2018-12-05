//김경태, 이의섭, 한승남
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



int PID = 0;

class Package
{
public:
	string searchloc; //가고 싶은 지역 입력
	int searchmin=0; //최소 가격
	int searchmax=0; //최대 가격
	string searchdate; //출발일
	string searchvia; //경유 유무
	string searchfree; //자유일정 유무
	int searchppl=0; //여행인원
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
				if ((offset == s.find(search, 0)) != string::npos)
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
		os << " || 태그(띄어쓰기 없이) >>" << tag[PID];
		os << " || 가격 >> " << price[PID];
		os << " || 경유 >>" << via[PID];
		os << " || 출발일 >>" << trav_start_date[PID];
		os << " || 출발시간 >>" << trav_start_hour[PID];
		os << " || 여행기간 >>" << how_long_trav[PID];
		os << " || 자유여행 >>" << free_trav[PID];
		os << " || 최소인원 >> " << minppl[PID];
		os << " || 최대인원 >> " << maxppl[PID] << endl;

		os.close();
	}

	void fileRead(ifstream& spack, vector<string>& v)
	{
		string line;

		while (getline(spack, line))
			v.push_back(line);

	}

	void searchPackage()
	{
		vector<string> v;
		int option[7] = { 0 };
		string comparedata[7];
		int findpackagecount = 0;
		int buypacknumber=0; //상품번호
		int buynum; //입력받을 상품번호
		int condition[100] = { 0, };

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
			comparedata[1] = "가격 >> ";
		}
		cout << "3.최대가격 1. Yes  2. No" << endl;
		cin >> option[2];
		if (option[2] == 1)
		{
			cout << "최대가격을 입력하세요>> ";
			cin >> searchmax;
			comparedata[2] = "가격 >> ";
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
			comparedata[6] = "인원 >>";
		}

		ifstream spack;
		spack.open("packagelist.txt");
		fileRead(spack, v);
		for (int i = 0; i < v.size(); i++)
		{
			char *str_buff = new char[1000];
			char *str_buff2 = new char[1000];
			int findloc = 0, findmin = 0, findmax = 0, finddate = 0, findvia = 0, findfree = 0, findppl = 0;
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
					tok2 = strtok(nullptr, ">>"); //가격 저장
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
					tok3 = strtok(nullptr, ">>"); //최소인원 저장
					int convertpplmin = atoi(tok3); //int 변환

					strcpy(comp2, str_arr[11].c_str());
					tok4 = strtok(comp2, ">>");
					str_arr2[0] = string(tok4);
					tok4 = strtok(nullptr, ">>"); //최대인원 저장
					int convertpplmax = atoi(tok4); //int 변환

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
							cout << "상품 : "<< buypacknumber << "-> "<< v[i] << endl;
							findpackagecount++;
							buypacknumber++;
							condition[i] = 1;
						}
					}
					else 
					{
						if (pricetrue == 1)
						{
							cout << "상품 : " << buypacknumber << "-> " << v[i] << endl;
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
						cout << "상품 : " << buypacknumber << "-> " << v[i] << endl;
						findpackagecount++;
						buypacknumber++;
						condition[i] = 1;

					}

				}
				else
				{
					cout << "상품 : " << buypacknumber << "-> " << v[i] << endl;
					findpackagecount++;
					buypacknumber++;
					condition[i] = 1;

				}
		
			}
			

			free(str_buff);
			free(str_buff2);
		}
		if (findpackagecount == 0)
			cout << "검색하신 조건에 맞는 패키지를 찾지 못했습니다" << endl;
		else
		{
			cout << "\n구매 하실 패키지 상품번호를 입력해주세요 >>";
			cin >> buynum;
			if (condition[buynum] == 1)
			{
				cout << "\n\n" << v[buynum] << endl;
				buyPackage();
			}
			else
			{
				cout << "잘못 입력하셨습니다" << endl;
			}


		}

		spack.close();

		


	}


	void buyPackage()
	{
		int paymentopt;
		cout << "패키지 구매" << endl;
		cout << "구매 방법 : 1.카드\t2.무통장입금\t3.Payco\t4.카카오페이" << endl;
		cin >> paymentopt;

	}

};

class User
{
private:
	string password;
	string name;
	string sex;
	string birth;
	string phone;
	string spam;
	string country;
	string city;
	char id[50] = "abc";
	char pack[50] = "pack";
	char review[50] = "review";
	char guide[50] = "guide";
	char rank[50] = "rank";
	char packname[50];
	char idtxt[50] = "abc";

};

class Advertise : public User, public Package
{
	void advertisement()
	{
		int ad;
		Package pack;
		string uname = User::GetInfo(); //이렇게 
		string country = User::getCount();
		
		ad = rand() % pack.v.size();
		cout << pack.v[ad] <<endl;
		
	}
};

int main()
{
	Package p;
	srand((unsigned int)time(NULL));
	//p.addPackage();
	p.searchPackage();

}
#include <fstream>
#include <string>
#include <sstream>
using namespace std;


class User
{
private:
	string password;
	string name;
	string sex;
	string birth;
	string phone;
	string spam;
	string country;
	string city;
	char id[50] = "abc";
	char pack[50] = "pack";
	char review[50] = "review";
	char guide[50] = "guide";
	char rank[50] = "rank";
	char packname[50];
	char idtxt[50] = "abc";
public:
	User()
	{
		strcat_s(idtxt, ".txt");
		strcat_s(pack, ".txt");
		strcat_s(review, ".txt");
		strcat_s(guide, ".txt");
		strcat_s(rank, ".txt");
		string s;
	}
	void GetInfo()
	{

		fstream fs(idtxt);
		getline(fs, password);
		getline(fs, name);
		getline(fs, sex);
		getline(fs, birth);
		getline(fs, phone);
		getline(fs, spam);
		getline(fs, country);
		getline(fs, city);
		fs.close();
	}

	void PackRank()
	{
		double rankBefore, rankAfter;
		int num, k;
		char packname[50];
		cout << "패키지 번호를 입력해주세요" << endl;
		cin >> packname;
		strcat_s(packname, ".");
		strcat_s(packname, rank);
		fstream fs2(packname);
		cout << "패키지의 평점을 입력해주세요" << endl;
		cin >> rankAfter;
		fs2 >> rankBefore;
		fs2 >> num;
		fs2.close();
		rankBefore *= num;
		num++;
		rankBefore += rankAfter;
		ofstream fs3(packname, ios::ate);
		fs3 << rankBefore / num << " " << num << endl;
		fs3.close();
	}
	void GuideRank()
	{
		double rankBefore, rankAfter;
		int num;
		fstream fs5(pack);
		cout << "가이드의 평점을 입력해주세요" << endl;
		cin >> rankAfter;
		fs5 >> rankBefore;
		fs5 >> num;
		fs5.close();
		rankBefore *= num;
		num++;
		rankBefore += rankAfter;
		ofstream fs3(pack, ios::ate);
		fs3 << rankBefore / num << " " << num << endl;
		fs3.close();
	}
	void PackReview()
	{
		string a;
		char packname[50];
		cout << "패키지 번호를 입력해주세요" << endl;
		cin >> packname;
		strcat_s(packname, ".");
		strcat_s(packname, review);
		cout << "패키지의 리뷰를 입력해주세요" << endl;
		cin >> a;
		ofstream fs(packname, ios::app);
		fs << "\n" << a << " - " << id;
		fs.close();
	}
	void ChangeInfo()
	{
		int a;
		cout << "수정하고자 하는 요소를 선택해주세요" << endl;
		cin >> a;
		switch (a) {
		case 1:
			cout << "비밀번호 변경" << endl;
			cout << "변경내용 :" << endl;
			cin >> password;
			break;
		case 2:
			cout << "전화번호 변경" << endl;
			cout << "변경내용 :" << endl;
			cin >> phone;
			break;
		case 3:
			cout << "스팸여부 변경(동의하면 1, 아니면 0)" << endl;
			cout << "변경내용 :" << endl;
			cin >> spam;
			break;
		case 4:
			cout << "관심나라 변경" << endl;
			cout << "변경내용 :" << endl;
			cin >> country;
			break;
		case 5:
			cout << "관심도시 변경" << endl;
			cout << "변경내용 :" << endl;
			cin >> city;
			break;
		}
		ofstream fs4(idtxt, ios::ate);
		fs4 << password;
		fs4 << "\n" << name;
		fs4 << "\n" << sex;
		fs4 << "\n" << birth;
		fs4 << "\n" << phone;
		fs4 << "\n" << spam;
		fs4 << "\n" << city;
		fs4 << "\n" << country;
		fs4.close();
	}

};

class Licensee
{
private:
	string password;
	string name;
	string agency;
	string phone;
	string license;
	string city;
	string country;
public:
	void GetInfo()
	{
		string s;
		char id[50] = "abc";
		strcat_s(id, ".txt");
		fstream fs(id);
		getline(fs, password);
		getline(fs, name);
		getline(fs, agency);
		getline(fs, phone);
		getline(fs, license);
		getline(fs, city);
		getline(fs, country);
	}

};
class Guide
{
private:
	string password;
	string name;
	string phone;
	string license;
	string city;
	string country;
	string online;
public:
	void GetInfo()
	{
		string s;
		char id[50] = "";
		strcat_s(id, ".txt");
		fstream fs(id);
		getline(fs, password);
		getline(fs, name);
		getline(fs, phone);
		getline(fs, license);
		getline(fs, city);
		getline(fs, country);
		getline(fs, online);
	}

};

int main()
{
	User user;
	user.GetInfo();
	//	user.PackRank();
	//	user.PackReview();
	//	user.ChangeInfo();
	user.PackReview();
}