#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "WorkFlow_Greeter.h"
#include "Login.h"
#include "obectClassFile.h"
#include "Package.h"
#include "Advertise.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstring>
#include <array>
#include <iomanip>
#include <ctime>

using namespace std;

// system work flow
int work();


int main()
{
	bool success;
	success = work();
	
	// 정상 작동.
	if (success == true) {
		return 0;
	}

	// 비정상 작동.
	if (success == false) {
		return 1;
	}
}

int work() {
	LoginSystem loginSystem;
	int login_or_join_option;
	int login_optionNum; // 로그인 성공 시 optionNum(일반 회원 : 1, 여행사 : 2, 가이드 : 3) 저장.  로그인 실패 시 -1 저장.

	while(1){

		Greeter::initialMessage();
		scanf("%d", &login_or_join_option);
		

		login_optionNum = selectFirstOption(login_or_join_option, loginSystem); 
		// 로그인 실패 시 프로그램 종료.
		if(login_optionNum == -1)
			exit(0); // gui 구현시 한번 더 묻고 끄기.


		// 로그인 성공 시
		switch (login_optionNum) {
		case 1:
			Greeter::greet(loginSystem.getCurrentID(), login_optionNum);
			Greeter::availGeneralUserOption();
			operation_UserOption();
			break;

		case 2:
			Greeter::greet(loginSystem.getCurrentID(), login_optionNum);
			Greeter::availTravelAgencyOption();
			operation_AgencyOption();
			break;
		case 3:
			Greeter::greet(loginSystem.getCurrentID(), login_optionNum);
			Greeter::availGuideOption();
			operation_GuideOption();
			break;
		}

		
		

	}

	return 1;
}

// login 정상적으로 성공 시 다음 화면으로 가도록 true 반환.
int selectFirstOption(int login_or_join_option, LoginSystem & loginSystem) {
	int loginSuccess = -1; // 성공 시 optionNum(일반 회원 : 1, 여행사 : 2, 가이드 : 3) 저장.  실패 시 -1 저장.

	do {
		// 회원가입 선택시.
		if (login_or_join_option == 1) {
			loginSystem.createMember();
		}

		// login 선택시.
		else if (login_or_join_option == 2) {
			loginSuccess = loginSystem.login();
		}

		// exit 선택시.
		else if (login_or_join_option == 3) {
			return -1;
		}

		// 없는 option 선택 시. gui 구현시 고려 안해도 됨.
		else {
			printf("잘못 입력하셨습니다. 다시 입력해주세요. \n\n");
		}
	} while (loginSuccess == -1);

	return loginSuccess;
}

void operation_UserOption() {
	int user_optionNum; // User로 로그인 시 그 안에서 세부적인 메뉴 선택할 때 입력 받을 옵션 번호.
	Greeter::availGeneralUserOption();

	switch (user_optionNum) {

	}
}

void operation_AgencyOption() {

}

void operation_GuideOption() {

}