//ÍπÄÍ≤ΩÌÉú, ?¥Ïùò?? ?úÏäπ??
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

	string searchloc; //∞°∞Ì ΩÕ¿∫ ¡ˆø™ ¿‘∑¬
	string searchmin; //√÷º“ ∞°∞›
	string searchmax; //√÷¥Î ∞°∞›
	string searchdate; //√‚πﬂ¿œ
	int searchvia; //∞Ê¿Ø ¿Øπ´
	string searchfree; //¿⁄¿Ø¿œ¡§ ¿Øπ´
	string searchppl; //ø©«‡¿Œø¯
=======
	string searchloc; //Í∞ÄÍ≥??∂Ï? ÏßÄ???ÖÎ†•
	string searchmin; //ÏµúÏÜå Í∞ÄÍ≤?
	string searchmax; //ÏµúÎ? Í∞ÄÍ≤?
	string searchdate; //Ï∂úÎ∞ú??
	int searchvia; //Í≤ΩÏú† ?†Î¨¥
	string searchfree; //?êÏú†?ºÏ†ï ?†Î¨¥

	string reviewstr;
	
	float rank;
	int buyer;
	
	int reviewbuyer;
	string Pname[100]; //?®ÌÇ§ÏßÄ ?¥Î¶Ñ
	string location[100]; //ÏßÄ??
	string tag[100]; //?¥Ïãú?úÍ∑∏
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
	void addPackage() //?úÎëêÎ¶??ÑÏÑ±
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
			cout << "?åÏùº??Ï∞æÏùÑ ???ÜÏäµ?àÎã§!" << endl;
		}
		
		cout << "Package ID :" << PID << endl;
		cout << "?®ÌÇ§ÏßÄ ?¥Î¶Ñ: ";
		//cin.ignore();
		getline(cin, Pname[PID]);
		cout << "ÏßÄ??: ";
		getline(cin, location[PID]);
		cout << "?úÍ∑∏: ";
		getline(cin, tag[PID]);
		cout << "Í∞ÄÍ≤??êÌôî): ";
		cin >> price[PID];
		cout << "Í≤ΩÏú† ?†Î¨¥ (1. YES 0. NO): ";
		cin >> via[PID];
		cout << "?¨Ìñâ Ï∂úÎ∞ú?? ";
		cin >> trav_start_date[PID];
		cout << "?¨Ìñâ Ï∂úÎ∞ú ?úÍ∞Ñ:(??Î∂? ";
		cin >> trav_start_hour[PID];
		cout << "?¨ÌñâÍ∏∞Í∞Ñ: ";
		cin >> how_long_trav[PID];
		cout << "?êÏú†?¨Ìñâ (1. YES 0. NO) : ";
		cin >> free_trav[PID];
		cout << "ÏµúÏÜå?∏Ïõê :";
		cin >> minppl[PID];
		cout << "ÏµúÎ??∏Ïõê :";
		cin >> maxppl[PID];

		ofstream os;
		os.open("packagelist.txt", ios::app);
		os << "PID >>" << PID;
<<<<<<< HEAD
		os << " || ∆–≈∞¡ˆ >>" << Pname[PID];
		os << " || ¡ˆø™ >>"<<location[PID];
		os << " || ≈¬±◊ >>" << tag[PID];
		os << " || ∞°∞› >>"<<price[PID];
		os << " || ∞Ê¿Ø >>" << via[PID];
		os << " || √‚πﬂ¿œ >>"<<trav_start_date[PID];
		os << " || √‚πﬂΩ√∞£ >>"<<trav_start_hour[PID];
		os << " || ø©«‡±‚∞£ >>"<<how_long_trav[PID];
		os << " || ¿⁄¿Øø©«‡ >>" << free_trav[PID];
		os << " || √÷º“¿Œø¯ >>" << minppl[PID];
		os << " || √÷¥Î¿Œø¯ >>" << maxppl[PID] << endl;
=======
		os << "?®ÌÇ§ÏßÄ >>" << Pname[PID];
		os << "ÏßÄ??>>"<<location[PID];
		os << "?úÍ∑∏ >>" << tag[PID];
		os << "Í∞ÄÍ≤?>>"<<price[PID];
		os << "Í≤ΩÏú† >>" << via[PID];
		os << "Ï∂úÎ∞ú??>>"<<trav_start_date[PID];
		os << "Ï∂úÎ∞ú?úÍ∞Ñ >>"<<trav_start_hour[PID];
		os << "?¨ÌñâÍ∏∞Í∞Ñ >>"<<how_long_trav[PID];
		os << "?êÏú†?¨Ìñâ >>" << free_trav[PID] << endl;;
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
	// ∫§≈Õø°º≠ word∏¶ √£æ∆º≠ √‚∑¬«—¥Ÿ
	void search(vector<string>& v, string& word)
=======
	// Î≤°ÌÑ∞?êÏÑú wordÎ•?Ï∞æÏïÑ??Ï∂úÎ†•?úÎã§
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

		cout << "Í≤Ä???µÏÖò : " << endl;
		cout << "1.ÏßÄ??1. Yes  2. No" << endl;
		cin >> option[0];
		if (option[0] == 1)
		{
			cout << "Í∞ÄÍ≥??∂Ï? ÏßÄ??ùÑ ?ÖÎ†•?òÏÑ∏??> ";
			cin >> searchloc;
			comparedata[0] = searchloc;
		}
		cout << "2.ÏµúÏÜåÍ∞ÄÍ≤?1. Yes  2. No" << endl;
		cin >> option[1];
		if (option[1] == 1)
		{
			cout << "ÏµúÏÜåÍ∞ÄÍ≤©ÏùÑ ?ÖÎ†•?òÏÑ∏??> ";
			cin >> searchmin;
			comparedata[1] = searchmin;
		}
		cout << "3.ÏµúÎ?Í∞ÄÍ≤?1. Yes  2. No" << endl;
		cin >> option[2];
		if (option[2] == 1)
		{
			cout << "ÏµúÎ?Í∞ÄÍ≤©ÏùÑ ?ÖÎ†•?òÏÑ∏??> ";
			cin >> searchmax;
			comparedata[2] = searchmax;
		}
		cout << "4.Ï∂úÎ∞ú??1. Yes  2. No" << endl;
		cin >> option[3];
		if (option[3] == 1)
		{
			cout << "Ï∂úÎ∞ú?ºÏùÑ ?ÖÎ†•?òÏÑ∏??> ";
			cin >> searchdate;
			comparedata[3] = searchdate;
		}
<<<<<<< HEAD
		cout << "5.∞Ê¿Ø 1. Yes  2. No" << endl;
=======
		cout << "5.Í≤ΩÏú† 1. Yes  2. No" << endl;

>>>>>>> bf294570f9e63b23006481db293a0d520a7d40f5
		cin >> option[4];
		if (option[4] == 1)
		{
			cout << "Í≤ΩÏú†Î•??òÏã§Í±¥Í??? 0. ?ÑÎãà??/ 1. ??>> ";
			cin >> searchvia;
			comparedata[4] = searchvia;
		}

		cout << "6.?êÏú†?ºÏ†ï 1. Yes  2. No" << endl;
		cin >> option[5];
		if (option[5] == 1)
		{
			cout << "?êÏú†?ºÏ†ï 0. ?ÑÎãà??/ 1. ??>> ";
			cin >> searchfree;
			comparedata[5] = searchfree;
		}
		cout << "7.ø©«‡¿Œø¯ 1. Yes  2. No" << endl;
		cin >> option[6];
		if (option[6] == 1)
		{
			cout << "ø©«‡¿Œø¯ >> ";
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

		/*if (spack.is_open()) //ÎßàÎ¨¥Î¶??ÑÏöî
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

						if ((offset[1] = line.find("Í∞ÄÍ≤?>>" + searchmin, 0)) != string::npos)
						{
							comparedata[1] = line;
							count++;
						}
				}
				if (option[2] == 1)
				{
					if ((offset[2] = line.find("Í∞ÄÍ≤?>>" + searchmax, 0)) != string::npos)
						{
							comparedata[2] = line;
							count++;
						}
				}
				if (option[3] == 1)
				{
						if ((offset[3] = line.find("Ï∂úÎ∞ú??>>" + searchdate, 0)) != string::npos)
						{
							comparedata[3] = line;
							count++;
						}
						
				}
				if (option[4] == 1)
				{
					
						if ((offset[4] = line.find("Í≤ΩÏú† >>" + searchvia, 0)) != string::npos)
						{
							comparedata[4] = line;
							count++;
						}
				}
				if (option[5] == 1)
				{
						if ((offset[5] = line.find("?êÏú†?¨Ìñâ >>" + searchfree, 0)) != string::npos)
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
		cout << "?®ÌÇ§ÏßÄ Íµ¨Îß§" << endl;
		cout << "Íµ¨Îß§ Î∞©Î≤ï : 1.Ïπ¥Îìú\t2.Î¨¥ÌÜµ?•ÏûÖÍ∏?t3.Payco\t4.Ïπ¥Ïπ¥?§Ìéò??<endl;

	}
	
};



int main()
{
	Package p;
		//p.addPackage();
		p.searchPackage();
		
}
