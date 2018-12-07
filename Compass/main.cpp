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
	
	// ���� �۵�.
	if (success == true) {
		return 0;
	}

	// ������ �۵�.
	if (success == false) {
		return 1;
	}
}

int work() {
	LoginSystem loginSystem;
	int login_or_join_option;
	int login_optionNum; // �α��� ���� �� optionNum(�Ϲ� ȸ�� : 1, ����� : 2, ���̵� : 3) ����.  �α��� ���� �� -1 ����.

	while(1){

		Greeter::initialMessage();
		scanf("%d", &login_or_join_option);
		

		login_optionNum = selectFirstOption(login_or_join_option, loginSystem); 
		// �α��� ���� �� ���α׷� ����.
		if(login_optionNum == -1)
			exit(0); // gui ������ �ѹ� �� ���� ����.


		// �α��� ���� ��
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

// login ���������� ���� �� ���� ȭ������ ������ true ��ȯ.
int selectFirstOption(int login_or_join_option, LoginSystem & loginSystem) {
	int loginSuccess = -1; // ���� �� optionNum(�Ϲ� ȸ�� : 1, ����� : 2, ���̵� : 3) ����.  ���� �� -1 ����.

	do {
		// ȸ������ ���ý�.
		if (login_or_join_option == 1) {
			loginSystem.createMember();
		}

		// login ���ý�.
		else if (login_or_join_option == 2) {
			loginSuccess = loginSystem.login();
		}

		// exit ���ý�.
		else if (login_or_join_option == 3) {
			return -1;
		}

		// ���� option ���� ��. gui ������ ��� ���ص� ��.
		else {
			printf("�߸� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���. \n\n");
		}
	} while (loginSuccess == -1);

	return loginSuccess;
}

void operation_UserOption() {
	int user_optionNum; // User�� �α��� �� �� �ȿ��� �������� �޴� ������ �� �Է� ���� �ɼ� ��ȣ.
	Greeter::availGeneralUserOption();

	switch (user_optionNum) {

	}
}

void operation_AgencyOption() {

}

void operation_GuideOption() {

}