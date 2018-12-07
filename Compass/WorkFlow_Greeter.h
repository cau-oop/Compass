#pragma once
#include<iostream>

using namespace std;

class Greeter {

public:
 
	static void initialMessage() {
		printf("////////////////////   Welcome to Compass!!!   ////////////////////\n\n");

		printf("1. Join Membership(회원가입)\n");
		printf("2. Login\n");
		printf("3. Exit\n\n");
	}

	// 회원가입 창과 회원가입 메뉴(옵션).
	static void joinMembershipMessage() {	
		cout << "/// Join Membership ///\n\n" << endl;

		cout << "1 : General Member\n" << endl;
		cout << "2 : One-man Travel Agency\n" << endl;
		cout << "3 : Guide except for Travel Agency\n" << endl;
		cout << "4 : Exit\n\n" << endl;
	}

	static void loginOptionMessage() {
		printf("\nWho are you?\n");
		printf("1 : General User\n");
		printf("2 : One-man Travel Agency\n");
		printf("3 : Guide\n");
		printf("4 : Exit\n");
	}

	static void exitMessage() {
		printf("\n\n////////////////////   Have a nice day!!!   ////////////////////\n\n");
	}

	static void greet(const char * id, const int loginOption) {
		if (loginOption == 1)
			printf("\nHello General User %s sir.\n", id);

		else if (loginOption == 2)
			printf("\nHello Travel Agency %s sir.\n", id);

		else if (loginOption == 3)
			printf("\nHello Guide %s sir.\n", id);
	}

	static void availGeneralUserOption() {
		printf("\nGeneralUser Sir. What are you supposed to do?\n\n");
		printf("1. change info\n");
		printf("2. chat with Guide\n");
		printf("3. purchase package\n");
		printf("4. logout\n\n");
	}

	static void availTravelAgencyOption() {
		printf("\nTravel Agency Sir. What are you supposed to do?\n\n");
		printf("1. register package\n");
		printf("2. logout\n\n");
	}

	static void availGuideOption() {
		printf("\nGuide Sir. What are you supposed to do?\n\n");
		printf("1. chat with user\n");
		printf("2. alarm\n");
		printf("3. logout\n\n");
	}

};