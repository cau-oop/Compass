#pragma once
#define _CRT_SECURE_NO_WARNINGS
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
	FILE * writer_UserInfo;
	FILE * reader_UserInfo;

public:

	char * getCurrentID() {
		return currentLogID;
	}

	void createMember() {
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
		Greeter::joinMembershipMessage();


		// �޴�(�ɼ�) �� ����.
		cout << "�Է� : ";
		cin >> optionNum;


		// �� �޴�(1~4) ���� �� operation.
		switch (optionNum) {

		// �Ϲ� ȸ�� ȸ������
		case 1:

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
		case 2:


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
		case 3:
			
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
	// login ���� �� true ��ȯ, ���н� false ��ȯ.
	int login() {
		int optionNum, loginNum = 0;
		bool isSuccess = false; // �α��� ����, ����. �ʱⰪ : false
		char inputID[ID_MAX_LENGTH + 1], inputPWD[PWD_MAX_LENGTH + 1];
		Greeter::loginOptionMessage();

		// �޴�(�ɼ�) �� ����.
		cout << "�Է� : ";
		cin >> optionNum;


		// �� �޴�(1~4) ���� �� operation.
		switch (optionNum) {

		// �Ϲ� ȸ�� �α���.
			case 1:

				do {

					printf("\n���̵� �Է��ϼ���.(�α��� ��� : ID : 0 )\n");
					printf("ID : ");
					scanf("%s", inputID);
						
					if (!strcmp(inputID, "0"))
						return -1; // �α��� ��� �� -1 ��ȯ.
			
					printf("\n��й�ȣ�� �Է��ϼ���.(�α��� ��� : PWD : 0)\n");
					printf("PWD : ");
					scanf("%s", inputPWD);

					if (!strcmp(inputPWD, "0"))
						return -1; // �α��� ��� �� -1 ��ȯ.

					// �������� 5�� Ʋ���� ���α׷� ��������.
					loginNum++;
					if (loginNum > MAX_LOGIN_NUM)
						exit(0);

					isSuccess = checkIsUser(optionNum, inputID, inputPWD);
	
				} while (!isSuccess);


				//�α��� ���� �� ���� �α��� ���� ���̵� �� user type(�Ϲ�ȸ������, ��������� ���̵�����) ����.
				if (isSuccess) {
					currentLogID = (char *)malloc(sizeof(char)*(ID_MAX_LENGTH+1));  // �α׾ƿ� �� ���� �Ҵ� free�����.
					currentUserType = (char *)malloc(sizeof(char)*(MAX_USER_TYPE_LENGTH+1));
						
					strcpy(currentLogID, inputID);
					strcpy(currentUserType, "general member");
				}
				break;

				// 1�� �����(�����) ȸ������
			case 2:
				do {
						
					printf("\n���̵� �Է��ϼ���.(�α��� ��� : ID : 0 )\n");
					printf("ID : ");
					scanf("%s", inputID);
	
					if (!strcmp(inputID, "0"))
						return -1; // �α��� ��� �� -1 ��ȯ.
	
					printf("\n��й�ȣ�� �Է��ϼ���.(�α��� ��� : PWD : 0)\n");
					printf("PWD : ");
					scanf("%s", inputPWD);

					if (!strcmp(inputPWD, "0"))
						return -1; // �α��� ��� �� -1 ��ȯ.

					// �������� 5�� Ʋ���� ���α׷� ��������.
					loginNum++;
					if (loginNum > MAX_LOGIN_NUM)
						exit(0);
	
					isSuccess = checkIsUser(optionNum, inputID, inputPWD);

				} while (!isSuccess);


				//�α��� ���� �� ���� �α��� ���� ���̵� �� user type(�Ϲ�ȸ������, ��������� ���̵�����) ����.
				if (isSuccess) {
					currentLogID = (char *)malloc(sizeof(char)*(ID_MAX_LENGTH+1));  // �α׾ƿ� �� ���� �Ҵ� free�����.
					currentUserType = (char *)malloc(sizeof(char)*(MAX_USER_TYPE_LENGTH+1));
	
					strcpy(currentLogID, inputID);
					strcpy(currentUserType, "one-man travel agency"); 
				}
				break;

				// ���̵� ȸ������
			case 3:
				do {
	
					printf("\n���̵� �Է��ϼ���.(�α��� ��� : ID : 0 )\n");
					printf("ID : ");
					scanf("%s", inputID);
						
					if (!strcmp(inputID, "0"))
						return -1; // �α��� ��� �� -1 ��ȯ.

					printf("\n��й�ȣ�� �Է��ϼ���.(�α��� ��� : PWD : 0)\n");
					printf("PWD : ");
					scanf("%s", inputPWD);
	
					if (!strcmp(inputPWD, "0"))
						return -1; // �α��� ��� �� -1 ��ȯ.

					// �������� 5�� Ʋ���� ���α׷� ��������.
					loginNum++;
					if (loginNum > MAX_LOGIN_NUM)
						exit(0);

					isSuccess = checkIsUser(optionNum, inputID, inputPWD);

				} while (!isSuccess);


				//�α��� ���� �� ���� �α��� ���� ���̵� �� user type(�Ϲ�ȸ������, ��������� ���̵�����) ����.
				if (isSuccess) {
					currentLogID = (char *)malloc(sizeof(char)*(ID_MAX_LENGTH+1));  // �α׾ƿ� �� ���� �Ҵ� free�����.
					currentUserType = (char *)malloc(sizeof(char)*(MAX_USER_TYPE_LENGTH+1));
		
					strcpy(currentLogID, inputID);
					strcpy(currentUserType, "guide");
				}
				break;

			default:
				cout << "�߸� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���.\n\n";
		}

		return optionNum;

	}

	//// ����� ������ �Է� ����.


	// General Member�� ȸ������ �� �ʿ��� ����� ������ �Է� ����.
	// ���̵�(���ڼ� ����), ��й�ȣ(���ڼ� ����), �̸�(���ڼ� ����), ����(M, W��), �������(6�ڸ�, ��ȿ��(���� ����)), ��ȭ��ȣ(11�ڸ�) ��
	// ��ȿ���� Ȯ���ϴ� �Լ� �����ؼ� �ֱ�.
	// ����, ������� �� ��ȿ���� Ȯ���ؾ� ���߿� ���Ͽ��� �ٽ� �����ͼ� �̿��� �� ���� �ȳ�(���� ����� �� ����).
	bool getUserInfo(char * input_ID, char * input_PWD, char * input_name, char & input_gender,
		char * input_birth, char * input_phoneNumber, char & input_advertiseAcceptOrNot,
		char * input_interestCountry, char * input_interestRegion) {

		cout << "ȸ������ ������ �Է¹޾� '�Ϲ� ȸ��' ȸ�������� �����մϴ�(ȸ�������� ����ϰ� ���� ��� �� �Է°����� �� �ϳ����� 0�� �Է�.)\n" << endl;
		cout << "\nȸ�� ���̵�� ��й�ȣ�� �����մϴ�" << endl;

		// ���̵�.
		do {
			cout << "���̵� �Է����ּ���(���� ��� x, ȸ������ ��� : 0, �ٽ� �Է� : 1) : ";
			cin >> input_ID;
			if (isCancelJoinMember(input_ID))
				return false;
		} while (atoi(input_ID) == 1);

		// ��й�ȣ.
		do {
			cout << "��й�ȣ�� �Է����ּ���(���� ��� x, ȸ������ ��� : 0, �ٽ� �Է� : 1) : ";
			cin >> input_PWD;
			if (isCancelJoinMember(input_PWD))
				return false;
		} while (atoi(input_PWD) == 1);

		// �̸�.
		do {
			cout << "�̸��� �Է����ּ���(ȸ������ ��� : 0, �ٽ� �Է� : 1) : ";
			cin >> input_name;
			if (isCancelJoinMember(input_name))
				return false;
		} while (atoi(input_name) == 1);


		do {
			cout << "������ �Է����ּ���(���� : M, ���� : W, ȸ������ ��� : 0, �ٽ� �Է� : 1) : ";
			cin >> input_gender;
			if (isCancelJoinMember(input_gender))
				return false;
		} while (input_gender == '1');


		do {
			cout << "��������� �Է����ּ���(ex 180528, ȸ������ ��� : 0, �ٽ� �Է� : 1) : ";
			cin >> input_birth;
			if (isCancelJoinMember(input_birth))
				return false;
		} while (atoi(input_birth) == 1);


		do {
			cout << "��ȭ��ȣ�� �Է����ּ���(ex 01067891234, ȸ������ ��� : 0, �ٽ� �Է� : 1) : ";
			cin >> input_phoneNumber;
			if (isCancelJoinMember(input_phoneNumber))
				return false;
		} while (atoi(input_phoneNumber) == 1);


		do {
			cout << "������ſ��θ� �Է����ּ���(��� : Y, �ź� : N, ȸ������ ��� : 0, �ٽ� �Է� : 1) : ";
			cin >> input_advertiseAcceptOrNot;
			if (isCancelJoinMember(input_advertiseAcceptOrNot))
				return false;
		} while (input_advertiseAcceptOrNot == '1');


		do {
			cout << "���� ���� �Է����ּ���(ex �ѱ�, �̱�, ȸ������ ��� : 0, �ٽ� �Է� : 1, ������ �Է� �� ';'�� ����.) : ";
			cin >> input_interestCountry;
			if (isCancelJoinMember(input_interestCountry))
				return false;
		} while (atoi(input_interestCountry) == 1);


		do {
			cout << "���� ����(�Ǵ� ���� ����, �������)�� �Է����ּ���(ex ����, ����, ������, ������, ȸ������ ��� : 0, �ٽ� �Է� : 1, ������ �Է� �� ';'�� ����.) : ";
			cin >> input_interestRegion;
			if (isCancelJoinMember(input_interestRegion))
				return false;
		} while (atoi(input_interestRegion) == 1);

		
		return true;
	}
	 
	// One-Man Travel Agency�� ȸ������ �� �ʿ��� ����� ������ �Է� ����.
	// ��ȿ���� Ȯ���ϴ� �Լ� �����ؼ� �ֱ�.
	// ��ȿ���� Ȯ���ؾ� ���߿� ���Ͽ��� �ٽ� �����ͼ� �̿��� �� ���� �ȳ�(���� ����� �� ����).
	bool getUserInfo(char * input_ID, char * input_PWD, char * input_name, char * input_agencyName, char * input_phoneNumber,
		char * input_LicenseNumber, char * input_mainCountry, char * input_mainRegion) {

		cout << "ȸ������ ������ �Է¹޾� '�����' ȸ�������� �����մϴ�(ȸ�������� ����ϰ� ���� ��� �� �Է°����� �� �ϳ����� 0�� �Է�.)\n" << endl;
		cout << "\nȸ�� ���̵�� ��й�ȣ�� �����մϴ�" << endl;

		// ���̵�.
		do {
			cout << "���̵� �Է����ּ���(���� ��� x, ȸ������ ��� : 0, �ٽ� �Է� : 1) : ";
			cin >> input_ID;
			if (isCancelJoinMember(input_ID))
				return false;
		} while (atoi(input_ID) == 1);

		// ��й�ȣ.
		do {
			cout << "��й�ȣ�� �Է����ּ���(���� ��� x, ȸ������ ��� : 0, �ٽ� �Է� : 1) : ";
			cin >> input_PWD;
			if (isCancelJoinMember(input_PWD))
				return false;
		} while (atoi(input_PWD) == 1);

		// ����� �̸�.
		do {
			cout << "����� �̸��� �Է����ּ���(ȸ������ ��� : 0, �ٽ� �Է� : 1) : ";
			cin >> input_name;
			if (isCancelJoinMember(input_name))
				return false;
		} while (atoi(input_name) == 1);

		// ����� �̸�.
		do {
			cout << "����� �̸��� �Է����ּ���(ȸ������ ��� : 0, �ٽ� �Է� : 1) : ";
			cin >> input_agencyName;
			if (isCancelJoinMember(input_agencyName))
				return false;
		} while (atoi(input_agencyName) == 1);

		// ��ȭ��ȣ.
		do {
			cout << "��ȭ��ȣ�� �Է����ּ���(ex 01067891234, ȸ������ ��� : 0, �ٽ� �Է� : 1) : ";
			cin >> input_phoneNumber;
			if (isCancelJoinMember(input_phoneNumber))
				return false;
		} while (atoi(input_phoneNumber) == 1);

		// ����� ����� ��Ϲ�ȣ.
		do {
			cout << "����� ����� ��Ϲ�ȣ(10�ڸ�, '-' ����)�� �Է����ּ���(ȸ������ ��� : 0, �ٽ� �Է� : 1) : ";
			cin >> input_LicenseNumber;
			if (isCancelJoinMember(input_LicenseNumber))
				return false;
		} while (atoi(input_LicenseNumber) == '1');

		// ���� ����
		do {
			cout << "�ش� �����(��Ű��)���� �ַ� ����ϴ� ���� �Է����ּ���(ex �ѱ�, �̱�, ȸ������ ��� : 0, �ٽ� �Է� : 1, ������ �Է� �� ';'�� ����.) : ";
			cin >> input_mainCountry;
			if (isCancelJoinMember(input_mainCountry))
				return false;
		} while (atoi(input_mainCountry) == 1);

		// ���� ����(�Ǵ� ���� ���� �̸� �Ǵ� ���� ���)
		do {
			cout << "�ش� �����(��Ű��)���� �ַ� ����ϴ� ����(�Ǵ� ���� ����, �������)�� �Է����ּ���(ex ����, ����, ������, ������, ȸ������ ��� : 0, �ٽ� �Է� : 1, ������ �Է� �� ';'�� ����.) : ";
			cin >> input_mainRegion;
			if (isCancelJoinMember(input_mainRegion))
				return false;
		} while (atoi(input_mainRegion) == 1);


		return true;
	}

	// Guide�� ȸ������ �� �ʿ��� ����� ������ �Է¹���.
	// ��ȿ���� Ȯ���ϴ� �Լ� �����ؼ� �ֱ�.
	// ��ȿ���� Ȯ���ؾ� ���߿� ���Ͽ��� �ٽ� �����ͼ� �̿��� �� ���� �ȳ�(���� ����� �� ����).
	bool getUserInfo(char * input_ID, char * input_PWD, char * input_name, char * input_phoneNumber,
		char * input_LicenseNumber, char * input_mainCountry, char * input_mainRegion) {

		cout << "ȸ������ ������ �Է¹޾� '�����' ȸ�������� �����մϴ�(ȸ�������� ����ϰ� ���� ��� �� �Է°����� �� �ϳ����� 0�� �Է�.)\n" << endl;
		cout << "\nȸ�� ���̵�� ��й�ȣ�� �����մϴ�" << endl;

		// ���̵�.
		do {
			cout << "���̵� �Է����ּ���(���� ��� x, ȸ������ ��� : 0, �ٽ� �Է� : 1) : ";
			cin >> input_ID;
			if (isCancelJoinMember(input_ID))
				return false;
		} while (atoi(input_ID) == 1);

		// ��й�ȣ.
		do {
			cout << "��й�ȣ�� �Է����ּ���(���� ��� x, ȸ������ ��� : 0, �ٽ� �Է� : 1) : ";
			cin >> input_PWD;
			if (isCancelJoinMember(input_PWD))
				return false;
		} while (atoi(input_PWD) == 1);

		// ����� �̸�.
		do {
			cout << "����� �̸��� �Է����ּ���(ȸ������ ��� : 0, �ٽ� �Է� : 1) : ";
			cin >> input_name;
			if (isCancelJoinMember(input_name))
				return false;
		} while (atoi(input_name) == 1);

		// ��ȭ��ȣ.
		do {
			cout << "��ȭ��ȣ�� �Է����ּ���(ex 01067891234, ȸ������ ��� : 0, �ٽ� �Է� : 1) : ";
			cin >> input_phoneNumber;
			if (isCancelJoinMember(input_phoneNumber))
				return false;
		} while (atoi(input_phoneNumber) == 1);

		// ���� ���̵� �ڰ��� ��ȣ.
		do {
			cout << "���� ���̵� �ڰ��� ��ȣ('-' ����)�� �Է����ּ���(ȸ������ ��� : 0, �ٽ� �Է� : 1) : ";
			cin >> input_LicenseNumber;
			if (isCancelJoinMember(input_LicenseNumber))
				return false;
		} while (atoi(input_LicenseNumber) == '1');

		// ���� ����
		do {
			cout << "�ش� �����(��Ű��)���� �ַ� ����ϴ� ���� �Է����ּ���(ex �ѱ�, �̱�, ȸ������ ��� : 0, �ٽ� �Է� : 1, ������ �Է� �� ';'�� ����.) : ";
			cin >> input_mainCountry;
			if (isCancelJoinMember(input_mainCountry))
				return false;
		} while (atoi(input_mainCountry) == 1);

		// ���� ����(�Ǵ� ���� ���� �̸� �Ǵ� ���� ���)
		do {
			cout << "�ش� �����(��Ű��)���� �ַ� ����ϴ� ����(�Ǵ� ���� ����, �������)�� �Է����ּ���(ex ����, ����, ������, ������, ȸ������ ��� : 0, �ٽ� �Է� : 1, ������ �Է� �� ';'�� ����.) : ";
			cin >> input_mainRegion;
			if (isCancelJoinMember(input_mainRegion))
				return false;
		} while (atoi(input_mainRegion) == 1);


		return true;
	}

	// ȸ������ ���
	bool isCancelJoinMember(const char * input) {
		if (!strcmp(input, "0")) {
			return true;
		}
		return false;
	}

	static bool isCancelJoinMember(const char input) {
		if (input == '0') {
			return true;
		}
		return false;
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
	void addUserInfo(char * input_ID, const char * input_PWD, const bool input_isPremium, const char * input_name, const char input_gender,
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
		
		fclose(writer_UserInfo);
	}

	// ������ ȸ������ �� �Է� ���� ����� ������ ���� �ý��ۿ� �����ϴ� �Լ�.
	void addUserInfo(char * input_ID, char * input_PWD, char * input_name, char * input_agencyName, char * input_phoneNumber,
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
	void addUserInfo(char * input_ID, char * input_PWD, char * input_name, char * input_phoneNumber,
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
		char user_PWD[PWD_MAX_LENGTH + 1];
		//char user_ID[ID_MAX_LENGTH + 1];
		const char *fileName=NULL;
		int exist;

		switch (optionNum)
		{

		// �Ϲ� ȸ������ �α��� ��
		case 1:
			fileName = strcat(input_ID, ".txt"); 
			break;

		// 1�� ������ �α��� �� 
		case 2:
			fileName = strcat(input_ID, ".txt");
			break;

		// ���̵�� �α��� ��
		case 3:
			fileName = strcat(input_ID, ".txt");
			break;

		default:
			break;
		}

		exist = _access(fileName, 0); // �����ϸ� exist : 0, �������� ������ exist : -1.
		
		// �ش� ���̵� ����(input_ID.txt)�� �����ϸ�
		if (!exist) {
			reader_UserInfo = fopen(fileName, "r");
			
			fgets(user_PWD, sizeof(user_PWD), reader_UserInfo);
			fclose(reader_UserInfo);

			// ���Ϸκ��� �о���� user_PWD���� ���� ���� ����.
			user_PWD[strlen(user_PWD) - 1] = '\0';

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


};