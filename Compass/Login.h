/*#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<string>
#include<ctime>
#include<io.h>
#include "WorkFlow_Greeter.h"
 
#define ID_MAX_LENGTH 30
#define PWD_MAX_LENGTH 30
#define NAME_MAX_LEGTH 30
#define BIRTH_MAX_LEGTH 6
#define PHONE_NUMBER_MAX_LEGTH 11
#define INTEREST_COUNTRY_MAX_LEGTH 50
#define INTEREST_REGION_MAX_LEGTH 50 // ���� ����(�Ǵ� ���� ���� �̸�)(�ټ� ���� ����)

#define AGENCY_NAME_MAX_LENGTH 30
#define BUSYNESS_LICENSE_MAX_LENGTH 10
#define MAIN_COUNTRY_MAX_LENGTH 50
#define MAIN_REGION_MAX_LENGTH 50

#define GUIDE_LICENSE_MAX_LENGTH 30

#define MAX_LOGIN_NUM 5
#define MAX_USER_TYPE_LENGTH 30
using namespace std;

// ���� ���� �� �� ���� ����� ����. lock �ɾ�� �Ҽ��� �ְ� �ƴϸ� ���� ���½� �� �Լ����� file ������ �����ؼ� ���� close ���� ���� ����� �� ���� �ִ�.

class LoginSystem {
private:
	char * currentLogID;
	char * currentUserType;
	static FILE * writer_UserInfo;
	static FILE * reader_UserInfo;

public:
	LoginSystem(char * input_ID) {
		currentLogID = (char*)malloc((ID_MAX_LENGTH + 1) * sizeof(char));
		currentLogID = input_ID;
	}

	static void createMember() {
		int optionNum; // �޴� �ɼ� �� ���� ��ȣ.
		char isSuccess; // ȸ������ ����, ���� ����.

		// general member, one-man travel agency, guide �� ��������� ȸ������ �ϴ��� �������� �Է¹��� ���.
		char ID[ID_MAX_LENGTH + 1], PWD[PWD_MAX_LENGTH + 1],
			name[NAME_MAX_LEGTH + 1], phoneNumber[PHONE_NUMBER_MAX_LEGTH + 1]; 
		
		// general member�� ȸ������ �� �Է¹��� ���.
		bool isPremium;
		char birthDate[BIRTH_MAX_LEGTH + 1], interestCountry[INTEREST_COUNTRY_MAX_LEGTH + 1],
			interestRegion[INTEREST_REGION_MAX_LEGTH + 1];
		char legalGender, advertise_AcceptOrNot;
		
		// one-man travel agency, guide �� ��������� ȸ������ �ϴ��� �������� �Է¹��� ���.
		char mainCountry[MAIN_COUNTRY_MAX_LENGTH + 1], mainRegion[MAIN_REGION_MAX_LENGTH + 1];

		// one-man travel agency�� ȸ������ �� �Է¹��� ���.
		char AgencyName[AGENCY_NAME_MAX_LENGTH + 1], travelBusinessLicenseNumber[BUSYNESS_LICENSE_MAX_LENGTH + 1];

		// guide�� ȸ������ �� �Է¹��� ���.
		char guideLicenseNumber[GUIDE_LICENSE_MAX_LENGTH + 1];


		// ȸ������ â�� ȸ������ �޴�(�ɼ�).
		cout << "\/\/\/ Join Membership \/\/\/" << endl;

		cout << "1 : General Member\n" << endl;
		cout << "2 : One-man Travel Agency\n" << endl;
		cout << "3 : Guide except for Travel Agency\n" << endl;
		cout << "4 : Exit" << endl;


		// �޴�(�ɼ�) �� ����.
		cout << "�Է� : ";
		cin >> optionNum;


		// �� �޴�(1~4) ���� �� operation.
		switch (optionNum) {

		// �Ϲ� ȸ�� ȸ������
		case1:

			isSuccess = getUserInfo(ID, PWD, name, legalGender,
				 birthDate, phoneNumber, advertise_AcceptOrNot,
				 interestCountry, interestRegion); // ����ڷκ��� ������ �Է� ����. ȸ������ ���� ���θ� ��ȯ(true, false).
			
			// ȸ������ ���� ��.
			if (isSuccess) {
				cout << "\n���������� ��ϵǼ̽��ϴ�." << endl;

				isPremium = convertToPremiumMemberOrNot();

				// �Է� ���� ������ ����(�ý���)�� ����.
				addUserInfo(ID, PWD, isPremium, name, legalGender,
					birthDate, phoneNumber, advertise_AcceptOrNot,
					interestCountry, interestRegion); 
			}

			// ȸ������ ���� ��(���� : ����ϴ� ��� �ۿ� ����).
			else {
				cout << "ȸ�������� ����ϼ̽��ϴ�." << endl;
			}

			break;
			
		// 1�� �����(�����) ȸ������
		case2:


			isSuccess = getUserInfo(ID, PWD, name, AgencyName, phoneNumber, travelBusinessLicenseNumber, 
			mainCountry, mainRegion); // ����ڷκ��� ������ �Է� ����. ȸ������ ���� ���θ� ��ȯ(true, false).

		    // ȸ������ ���� ��.
			if (isSuccess) {
				cout << "\n���������� ��ϵǼ̽��ϴ�." << endl;


				// �Է� ���� ������ ����(�ý���)�� ����.
				addUserInfo(ID, PWD, name, AgencyName, phoneNumber,
					travelBusinessLicenseNumber, mainCountry, mainRegion);
			}

			// ȸ������ ���� ��(���� : ����ϴ� ��� �ۿ� ����).
			else {
				cout << "ȸ�������� ����ϼ̽��ϴ�." << endl;
			}

			break;

		// ���̵� ȸ������
		case3:
			
			isSuccess = getUserInfo(ID, PWD, name, phoneNumber, 
				guideLicenseNumber, mainCountry, mainRegion); // ����ڷκ��� ������ �Է� ����. ȸ������ ���� ���θ� ��ȯ(true, false).

			// ȸ������ ���� ��.
			if (isSuccess) {
				cout << "\n���������� ��ϵǼ̽��ϴ�." << endl;


				// �Է� ���� ������ ����(�ý���)�� ����.
				addUserInfo(ID, PWD, name, phoneNumber, 
					guideLicenseNumber, mainCountry, mainRegion);
			}

			// ȸ������ ���� ��(���� : ����ϴ� ��� �ۿ� ����).
			else {
				cout << "ȸ�������� ����ϼ̽��ϴ�." << endl;
			}


			break;
			
		default:
			exit(0);
		}


	}

	//// �Ϲ� ȸ���� ��, ����� �� ��, ���̵� �� �� �ݺ��Ǵ�(������) �κ� ����ϰ� ���� �ϱ�.
	// ��ĥ�� strcpy(currentUserType, "one-man travel agency"); <- �������� �� ���� �ϳ��� ��ġ�� �ɵ�.
	// optionNum �޾ƿͼ� switch �ؼ� ���� ���� strcpy(currentUserType, "one-man travel agency"); �̰� �ֱ�.
	void login() {
		int optionNum, loginNum = 0;
		bool isSuccess = false; // �α��� ����, ����. �ʱⰪ : false
		char inputID[ID_MAX_LENGTH + 1], inputPWD[PWD_MAX_LENGTH + 1];
		Greeter::loginOptionMessage();

		cout << "\n�Է� : ";
		cin >> optionNum;

		// �޴�(�ɼ�) �� ����.
		cout << "�Է� : ";
		cin >> optionNum;


		// �� �޴�(1~4) ���� �� operation.
		switch (optionNum) {

		// �Ϲ� ȸ�� �α���.
		case1:
			do {

				printf("\n���̵� �Է��ϼ���.(�α��� ��� : ID : 0 )\n");
				printf("ID : ");
				scanf("%s", inputID);

				if (!strcmp(inputID, "0"))
					break;
			
				printf("\n��й�ȣ�� �Է��ϼ���.(�α��� ��� : PWD : 0)\n");
				printf("PWD : ");
				scanf("%s", inputPWD);

				if (!strcmp(inputPWD, "0"))
					break;

				// �������� 5�� Ʋ���� ���α׷� ��������.
				loginNum++;
				if (loginNum > MAX_LOGIN_NUM)
					exit(0);

				isSuccess = checkIsUser(optionNum, inputID, inputPWD);

			} while (!isSuccess);


			//�α��� ���� �� ���� �α��� ���� ���̵� �� user type(�Ϲ�ȸ������, ��������� ���̵�����) ����.
			if (isSuccess) {
				currentLogID = (char *)malloc(sizeof(char)*ID_MAX_LENGTH);  // �α׾ƿ� �� ���� �Ҵ� free�����.
				currentUserType = (char *)malloc(sizeof(char)*MAX_USER_TYPE_LENGTH);

				strcpy(currentLogID, inputID);
				strcpy(currentUserType, "general member");
			}
			break;

			// 1�� �����(�����) ȸ������
		case2:
			do {

				printf("\n���̵� �Է��ϼ���.(�α��� ��� : ID : 0 )\n");
				printf("ID : ");
				scanf("%s", inputID);

				if (!strcmp(inputID, "0"))
					break;

				printf("\n��й�ȣ�� �Է��ϼ���.(�α��� ��� : PWD : 0)\n");
				printf("PWD : ");
				scanf("%s", inputPWD);

				if (!strcmp(inputPWD, "0"))
					break;

				// �������� 5�� Ʋ���� ���α׷� ��������.
				loginNum++;
				if (loginNum > MAX_LOGIN_NUM)
					exit(0);

				isSuccess = checkIsUser(optionNum, inputID, inputPWD);

			} while (!isSuccess);


			//�α��� ���� �� ���� �α��� ���� ���̵� �� user type(�Ϲ�ȸ������, ��������� ���̵�����) ����.
			if (isSuccess) {
				currentLogID = (char *)malloc(sizeof(char)*ID_MAX_LENGTH);  // �α׾ƿ� �� ���� �Ҵ� free�����.
				currentUserType = (char *)malloc(sizeof(char)*MAX_USER_TYPE_LENGTH);

				strcpy(currentLogID, inputID);
				strcpy(currentUserType, "one-man travel agency"); 
			}
			break;

			// ���̵� ȸ������
		case3:
			do {

				printf("\n���̵� �Է��ϼ���.(�α��� ��� : ID : 0 )\n");
				printf("ID : ");
				scanf("%s", inputID);

				if (!strcmp(inputID, "0"))
					break;

				printf("\n��й�ȣ�� �Է��ϼ���.(�α��� ��� : PWD : 0)\n");
				printf("PWD : ");
				scanf("%s", inputPWD);

				if (!strcmp(inputPWD, "0"))
					break;

				// �������� 5�� Ʋ���� ���α׷� ��������.
				loginNum++;
				if (loginNum > MAX_LOGIN_NUM)
					exit(0);

				isSuccess = checkIsUser(optionNum, inputID, inputPWD);

			} while (!isSuccess);


			//�α��� ���� �� ���� �α��� ���� ���̵� �� user type(�Ϲ�ȸ������, ��������� ���̵�����) ����.
			if (isSuccess) {
				currentLogID = (char *)malloc(sizeof(char)*ID_MAX_LENGTH);  // �α׾ƿ� �� ���� �Ҵ� free�����.
				currentUserType = (char *)malloc(sizeof(char)*MAX_USER_TYPE_LENGTH);

				strcpy(currentLogID, inputID);
				strcpy(currentUserType, "guide");
			}
			break;

		default:
			exit(0);
		}

	}

	//// ����� ������ �Է� ����.


	// General Member�� ȸ������ �� �ʿ��� ����� ������ �Է� ����.
	// ���̵�(���ڼ� ����), ��й�ȣ(���ڼ� ����), �̸�(���ڼ� ����), ����(M, W��), �������(6�ڸ�, ��ȿ��(���� ����)), ��ȭ��ȣ(11�ڸ�) ��
	// ��ȿ���� Ȯ���ϴ� �Լ� �����ؼ� �ֱ�.
	// ����, ������� �� ��ȿ���� Ȯ���ؾ� ���߿� ���Ͽ��� �ٽ� �����ͼ� �̿��� �� ���� �ȳ�(���� ����� �� ����).
	static bool getUserInfo(char * input_ID, char * input_PWD, char * input_name, char & input_gender,
		char * input_birth, char * input_phoneNumber, char & input_advertiseAcceptOrNot,
		char * input_interestCountry, char * input_interestRegion) {
		
		cout << "ȸ������ ������ �Է¹޾� '�Ϲ� ȸ��' ȸ�������� �����մϴ�(ȸ�������� ����ϰ� ���� ��� �� �Է°����� �� �ϳ����� 0�� �Է�.)\n" << endl;
		cout << "\nȸ�� ���̵�� ��й�ȣ�� �����մϴ�" << endl;

		// ���̵�.
		do {
			cout << "���̵� �Է����ּ���(���� ��� x, ȸ������ ��� : 0, �ٽ� �Է� : 1) : ";
			cin >> input_ID;
			return !isCancelJoinMember(input_ID);
		} while (atoi(input_ID) == 1);

		// ��й�ȣ.
		do {
			cout << "��й�ȣ�� �Է����ּ���(���� ��� x, ȸ������ ��� : 0, �ٽ� �Է� : 1) : ";
			cin >> input_PWD;
			return !isCancelJoinMember(input_PWD);
		} while (atoi(input_PWD) == 1);

		// �̸�.
		do {
			cout << "�̸��� �Է����ּ���(ȸ������ ��� : 0, �ٽ� �Է� : 1) : ";
			cin >> input_name;
			return !isCancelJoinMember(input_name);
		} while (atoi(input_name) == 1);


		do {
			cout << "������ �Է����ּ���(���� : M, ���� : W, ȸ������ ��� : 0, �ٽ� �Է� : 1) : ";
			cin >> input_gender;
			return !isCancelJoinMember(input_gender);
		} while (input_gender == '1');


		do {
			cout << "��������� �Է����ּ���(ex 180528, ȸ������ ��� : 0, �ٽ� �Է� : 1) : ";
			cin >> input_birth;
			return !isCancelJoinMember(input_birth);
		} while (atoi(input_birth) == 1);


		do {
			cout << "��ȭ��ȣ�� �Է����ּ���(ex 01067891234, ȸ������ ��� : 0, �ٽ� �Է� : 1) : ";
			cin >> input_phoneNumber;
			return !isCancelJoinMember(input_phoneNumber);
		} while (atoi(input_phoneNumber) == 1);


		do {
			cout << "������ſ��θ� �Է����ּ���(��� : Y, �ź� : N, ȸ������ ��� : 0, �ٽ� �Է� : 1) : ";
			cin >> input_advertiseAcceptOrNot;
			return !isCancelJoinMember(input_advertiseAcceptOrNot);
		} while (input_advertiseAcceptOrNot == '1');


		do {
			cout << "���� ���� �Է����ּ���(ex �ѱ�, �̱�, ȸ������ ��� : 0, �ٽ� �Է� : 1, ������ �Է� �� ';'�� ����.) : ";
			cin >> input_interestCountry;
			return !isCancelJoinMember(input_interestCountry);
		} while (atoi(input_interestCountry) == 1);


		do {
			cout << "���� ����(�Ǵ� ���� ����, �������)�� �Է����ּ���(ex ����, ����, ������, ������, ȸ������ ��� : 0, �ٽ� �Է� : 1, ������ �Է� �� ';'�� ����.) : ";
			cin >> input_interestRegion;
			return !isCancelJoinMember(input_interestRegion);
		} while (atoi(input_interestRegion) == 1);

		
		return true;
	}
	 
	// One-Man Travel Agency�� ȸ������ �� �ʿ��� ����� ������ �Է� ����.
	// ��ȿ���� Ȯ���ϴ� �Լ� �����ؼ� �ֱ�.
	// ��ȿ���� Ȯ���ؾ� ���߿� ���Ͽ��� �ٽ� �����ͼ� �̿��� �� ���� �ȳ�(���� ����� �� ����).
	static bool getUserInfo(char * input_ID, char * input_PWD, char * input_name, char * input_agencyName, char * input_phoneNumber,
		char * input_LicenseNumber, char * input_mainCountry, char * input_mainRegion) {

		cout << "ȸ������ ������ �Է¹޾� '�����' ȸ�������� �����մϴ�(ȸ�������� ����ϰ� ���� ��� �� �Է°����� �� �ϳ����� 0�� �Է�.)\n" << endl;
		cout << "\nȸ�� ���̵�� ��й�ȣ�� �����մϴ�" << endl;

		// ���̵�.
		do {
			cout << "���̵� �Է����ּ���(���� ��� x, ȸ������ ��� : 0, �ٽ� �Է� : 1) : ";
			cin >> input_ID;
			return !isCancelJoinMember(input_ID);
		} while (atoi(input_ID) == 1);

		// ��й�ȣ.
		do {
			cout << "��й�ȣ�� �Է����ּ���(���� ��� x, ȸ������ ��� : 0, �ٽ� �Է� : 1) : ";
			cin >> input_PWD;
			return !isCancelJoinMember(input_PWD);
		} while (atoi(input_PWD) == 1);

		// ����� �̸�.
		do {
			cout << "����� �̸��� �Է����ּ���(ȸ������ ��� : 0, �ٽ� �Է� : 1) : ";
			cin >> input_name;
			return !isCancelJoinMember(input_name);
		} while (atoi(input_name) == 1);

		// ����� �̸�.
		do {
			cout << "����� �̸��� �Է����ּ���(ȸ������ ��� : 0, �ٽ� �Է� : 1) : ";
			cin >> input_agencyName;
			return !isCancelJoinMember(input_agencyName);
		} while (atoi(input_agencyName) == 1);

		// ��ȭ��ȣ.
		do {
			cout << "��ȭ��ȣ�� �Է����ּ���(ex 01067891234, ȸ������ ��� : 0, �ٽ� �Է� : 1) : ";
			cin >> input_phoneNumber;
			return !isCancelJoinMember(input_phoneNumber);
		} while (atoi(input_phoneNumber) == 1);

		// ����� ����� ��Ϲ�ȣ.
		do {
			cout << "����� ����� ��Ϲ�ȣ(10�ڸ�, '-' ����)�� �Է����ּ���(ȸ������ ��� : 0, �ٽ� �Է� : 1) : ";
			cin >> input_LicenseNumber;
			return !isCancelJoinMember(input_LicenseNumber);
		} while (atoi(input_LicenseNumber) == '1');

		// ���� ����
		do {
			cout << "�ش� �����(��Ű��)���� �ַ� ����ϴ� ���� �Է����ּ���(ex �ѱ�, �̱�, ȸ������ ��� : 0, �ٽ� �Է� : 1, ������ �Է� �� ';'�� ����.) : ";
			cin >> input_mainCountry;
			return !isCancelJoinMember(input_mainCountry);
		} while (atoi(input_mainCountry) == 1);

		// ���� ����(�Ǵ� ���� ���� �̸� �Ǵ� ���� ���)
		do {
			cout << "�ش� �����(��Ű��)���� �ַ� ����ϴ� ����(�Ǵ� ���� ����, �������)�� �Է����ּ���(ex ����, ����, ������, ������, ȸ������ ��� : 0, �ٽ� �Է� : 1, ������ �Է� �� ';'�� ����.) : ";
			cin >> input_mainRegion;
			return !isCancelJoinMember(input_mainRegion);
		} while (atoi(input_mainRegion) == 1);


		return true;
	}

	// Guide�� ȸ������ �� �ʿ��� ����� ������ �Է¹���.
	// ��ȿ���� Ȯ���ϴ� �Լ� �����ؼ� �ֱ�.
	// ��ȿ���� Ȯ���ؾ� ���߿� ���Ͽ��� �ٽ� �����ͼ� �̿��� �� ���� �ȳ�(���� ����� �� ����).
	static bool getUserInfo(char * input_ID, char * input_PWD, char * input_name, char * input_phoneNumber,
		char * input_LicenseNumber, char * input_mainCountry, char * input_mainRegion) {

		cout << "ȸ������ ������ �Է¹޾� '�����' ȸ�������� �����մϴ�(ȸ�������� ����ϰ� ���� ��� �� �Է°����� �� �ϳ����� 0�� �Է�.)\n" << endl;
		cout << "\nȸ�� ���̵�� ��й�ȣ�� �����մϴ�" << endl;

		// ���̵�.
		do {
			cout << "���̵� �Է����ּ���(���� ��� x, ȸ������ ��� : 0, �ٽ� �Է� : 1) : ";
			cin >> input_ID;
			return !isCancelJoinMember(input_ID);
		} while (atoi(input_ID) == 1);

		// ��й�ȣ.
		do {
			cout << "��й�ȣ�� �Է����ּ���(���� ��� x, ȸ������ ��� : 0, �ٽ� �Է� : 1) : ";
			cin >> input_PWD;
			return !isCancelJoinMember(input_PWD);
		} while (atoi(input_PWD) == 1);

		// ����� �̸�.
		do {
			cout << "����� �̸��� �Է����ּ���(ȸ������ ��� : 0, �ٽ� �Է� : 1) : ";
			cin >> input_name;
			return !isCancelJoinMember(input_name);
		} while (atoi(input_name) == 1);

		// ��ȭ��ȣ.
		do {
			cout << "��ȭ��ȣ�� �Է����ּ���(ex 01067891234, ȸ������ ��� : 0, �ٽ� �Է� : 1) : ";
			cin >> input_phoneNumber;
			return !isCancelJoinMember(input_phoneNumber);
		} while (atoi(input_phoneNumber) == 1);

		// ���� ���̵� �ڰ��� ��ȣ.
		do {
			cout << "���� ���̵� �ڰ��� ��ȣ('-' ����)�� �Է����ּ���(ȸ������ ��� : 0, �ٽ� �Է� : 1) : ";
			cin >> input_LicenseNumber;
			return !isCancelJoinMember(input_LicenseNumber);
		} while (atoi(input_LicenseNumber) == '1');

		// ���� ����
		do {
			cout << "�ش� �����(��Ű��)���� �ַ� ����ϴ� ���� �Է����ּ���(ex �ѱ�, �̱�, ȸ������ ��� : 0, �ٽ� �Է� : 1, ������ �Է� �� ';'�� ����.) : ";
			cin >> input_mainCountry;
			return !isCancelJoinMember(input_mainCountry);
		} while (atoi(input_mainCountry) == 1);

		// ���� ����(�Ǵ� ���� ���� �̸� �Ǵ� ���� ���)
		do {
			cout << "�ش� �����(��Ű��)���� �ַ� ����ϴ� ����(�Ǵ� ���� ����, �������)�� �Է����ּ���(ex ����, ����, ������, ������, ȸ������ ��� : 0, �ٽ� �Է� : 1, ������ �Է� �� ';'�� ����.) : ";
			cin >> input_mainRegion;
			return !isCancelJoinMember(input_mainRegion);
		} while (atoi(input_mainRegion) == 1);


		return true;
	}

	// ȸ������ ���
	static bool isCancelJoinMember(const char * input) {
		if (atoi(input) == 0) {
			return true;
		}
	}

	static bool isCancelJoinMember(const char input) {
		if (input == '0') {
			return false;
		}
	}

	static bool convertToPremiumMemberOrNot() {
		char yesOrNo;
		char cardNumber[21];
		char * registerTime = getCurrentTime(); //�����̾� ������ ������ ��¥�� �ð��� ��Ÿ���� ���ڿ�

		
		do {
			// ���� ������ ȸ��(�����̾� ȸ��) ���ο�� ���� ������ �ʾ���.
			cout << "������ ȸ�� ��Ͻ� �� 3000���� ����� ���� ���̵� ������ ����(���̵���� ä��)�� �̿��Ͻ� �� �ֽ��ϴ�. ";
			cout << "�����Ͻðڽ��ϱ�?(Y,N)" << endl;
			cin >> yesOrNo;

			if (yesOrNo == 'Y') {
				cout << "ī���ȣ�� �Է����ּ���(16�ڸ�, 4�ڸ��� '-'�� �������ּ���)." << endl;
				cin >> cardNumber;

				cout << "\n" << endl;

				cout << "ȯ���մϴ� ����" << endl << registerTime << "�� �����̾� ����� �Ǽ̽��ϴ�.\n\n";

				return true;
			}

			else if (yesOrNo == 'N') {
				cout << "�����մϴ�. ������ �������ּ���.\n" << endl;
				return false;
			}

			else {
				cout << "��Ȯ�� �ٽ� �Է����ּ���.\n" << endl;
			}
		} while (yesOrNo != 'Y' && yesOrNo != 'N');
		
	}


	// ���� ��¥�� �ð��� ����ϱ� ���� �Լ�.
	// �����̾� ������ ������ ��¥�� �ð��� ����ϱ� ���� �Լ�.
	static char * getCurrentTime() {
		time_t now;
		time(&now);
		return ctime(&now);
	}

	// �Ϲ� ȸ������ ȸ������ �� �Է¹��� ����� ������ ���� �ý��ۿ� �����ϴ� �Լ�.
	// DB ���� �ý��� Ŭ���� ���� ���� ������� ���� �����ұ�?
	static void addUserInfo(char * input_ID, const char * input_PWD, const bool input_isPremium, const char * input_name, const char input_gender,
		const char * input_birth, const char * input_phoneNumber, const char input_advertiseAcceptOrNot,
		const char * input_interestCountry, const char * input_interestRegion) {

		const char *fileName = strcat(input_ID, ".txt");
		
		
		//�� ��ҵ��� �ٹٲ����� ����.

		// pwd ����.
		writer_UserInfo = fopen(fileName, "w");
		fputs(input_PWD, writer_UserInfo);
		fputs("\n", writer_UserInfo);

		// premium ȸ������ �ƴ��� ����.(true, false).
		fputs((input_isPremium ? "true" : "false"), writer_UserInfo);
		fputs("\n", writer_UserInfo);

		// name ����.
		fputs(input_name, writer_UserInfo);
		fputs("\n", writer_UserInfo);

		// legal gender ����.
		fputc(input_gender, writer_UserInfo);
		fputs("\n", writer_UserInfo);

		// birth ����.
		fputs(input_birth, writer_UserInfo);
		fputs("\n", writer_UserInfo);

		// phone number ����.
		fputs(input_phoneNumber, writer_UserInfo);
		fputs("\n", writer_UserInfo);

		// ���� ���� ���� ����.
		fputc(input_advertiseAcceptOrNot, writer_UserInfo);
		fputs("\n", writer_UserInfo);

		// ���� ���� ����.
		fputs(input_interestCountry, writer_UserInfo);
		fputs("\n", writer_UserInfo);

		// ���� ����(�Ǵ� ���� ���� �Ǵ� ���� ���) ����.
		fputs(input_interestRegion, writer_UserInfo);
		fputs("\n", writer_UserInfo);
		
	}

	// ������ ȸ������ �� �Է� ���� ����� ������ ���� �ý��ۿ� �����ϴ� �Լ�.
	static void addUserInfo(char * input_ID, char * input_PWD, char * input_name, char * input_agencyName, char * input_phoneNumber,
		char * input_LicenseNumber, char * input_mainCountry, char * input_mainRegion) {

		const char *fileName = strcat(input_ID, ".txt");


		// �� ��ҵ��� �� �ٿ� �� ��Ұ� ������ ����.

		// pwd ����.
		writer_UserInfo = fopen(fileName, "w");
		fputs(input_PWD, writer_UserInfo);
		fputs("\n", writer_UserInfo);

		// ����� �̸� ����.
		fputs(input_name, writer_UserInfo);
		fputs("\n", writer_UserInfo);

		// ����� �̸� ����.
		fputs(input_agencyName, writer_UserInfo);
		fputs("\n", writer_UserInfo);

		// phone number ����.
		fputs(input_phoneNumber, writer_UserInfo);
		fputs("\n", writer_UserInfo);

		// ����� ����� ��Ϲ�ȣ ����.
		fputs(input_LicenseNumber, writer_UserInfo);
		fputs("\n", writer_UserInfo);

		// ���� ���� ����.
		fputs(input_mainCountry, writer_UserInfo);
		fputs("\n", writer_UserInfo);

		// ���� ����(�Ǵ� ���� ���� �̸� �Ǵ� ���� ���) ����.
		fputs(input_mainRegion, writer_UserInfo);
		fputs("\n", writer_UserInfo);

		fclose(writer_UserInfo);
	}

	// ���̵�� ȸ������ �� �Է� ���� ����� ������ ���� �ý��ۿ� �����ϴ� �Լ�.
	static void addUserInfo(char * input_ID, char * input_PWD, char * input_name, char * input_phoneNumber,
		char * input_LicenseNumber, char * input_mainCountry, char * input_mainRegion) {

		const char *fileName = strcat(input_ID, ".txt");


		// �� ��ҵ��� �� �ٿ� �� ��Ұ� ������ ����.

		// pwd ����.
		writer_UserInfo = fopen(fileName, "w");
		fputs(input_PWD, writer_UserInfo);
		fputs("\n", writer_UserInfo);

		// ����� �̸� ����.
		fputs(input_name, writer_UserInfo);
		fputs("\n", writer_UserInfo);

		// phone number ����.
		fputs(input_phoneNumber, writer_UserInfo);
		fputs("\n", writer_UserInfo);

		// ���̵� �ڰ��� ��ȣ ����.
		fputs(input_LicenseNumber, writer_UserInfo);
		fputs("\n", writer_UserInfo);

		// ���� ���� ����.
		fputs(input_mainCountry, writer_UserInfo);
		fputs("\n", writer_UserInfo);

		// ���� ����(�Ǵ� ���� ���� �̸� �Ǵ� ���� ���) ����.
		fputs(input_mainRegion, writer_UserInfo);
		fputs("\n", writer_UserInfo);

		fclose(writer_UserInfo);
	}

	// �α��� �� �α��� ������ ���� ���θ� ��ȯ.
	// �α��� �� �Է��� ���̵�� ��й�ȣ�� ��ġ�ϴ� ����� ��������� �ִ��� Ȯ��.
	bool checkIsUser(int optionNum, char * input_ID, char * input_PWD) {
		char user_ID[ID_MAX_LENGTH + 1], user_PWD[PWD_MAX_LENGTH + 1];
		bool exist;
		const char *fileName;
		int exist;

		switch (optionNum)
		{

		// �Ϲ� ȸ������ �α��� ��
		case1:
			fileName = strcat(input_ID, ".txt"); 
			break;

		// 1�� ������ �α��� �� 
		case2:
			fileName = strcat(input_ID, ".txt");
			break;

		// ���̵�� �α��� ��
		case3:
			fileName = strcat(input_ID, ".txt");
			break;

		default:
			break;
		}

		exist = _access("test.txt", 0); // �����ϸ� exist : 0, �������� ������ exist : -1.
		
		// �ش� ���̵� ����(input_ID.txt)�� �����ϸ�
		if (!exist) {
			reader_UserInfo = fopen(fileName, "r");
			
			fgets(user_PWD, PWD_MAX_LENGTH, reader_UserInfo);
			fclose(reader_UserInfo);

			if (strcmp(input_PWD, user_PWD)) {
				printf("��й�ȣ�� �߸��Ǿ����ϴ�.\n");
				return false;
			}

			else
				return true;
		}

		// �ش� ���̵� ����(input_ID.txt)�� �������� ������
		else {
			printf("���̵� �߸��Ǿ����ϴ�.\n");
			return false;
		}

	}


};*/