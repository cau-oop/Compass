#include<iostream>
#include<cstring>
#include<string>
#define ID_MAX_LENGTH 30
#define PWD_MAX_LENGTH 30

using namespace std;

class LoginSystem {
private:
	char *currentLogID;
	FILE * writeUserInfo;
	FILE * readUserInfo;

public:
	LoginSystem(char * input_ID) {
		currentLogID = (char*)malloc(ID_MAX_LENGTH * sizeof(char));
		currentLogID = input_ID;
	}

	static void createMember() {
		cout<< "\/\/\/ 회원가입 \/\/\/" <<endl;

	}

	static void login() {

	}



};