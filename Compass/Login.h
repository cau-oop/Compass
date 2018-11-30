#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<string>
#include<ctime>
#define ID_MAX_LENGTH 30
#define PWD_MAX_LENGTH 30
#define NAME_MAX_LEGTH 30
#define BIRTH_MAX_LEGTH 6
#define PHONE_NUMBER_MAX_LEGTH 11
#define INTEREST_COUNTRY_MAX_LEGTH 50
#define INTEREST_REGION_MAX_LEGTH 50 // 관심 도시(또는 유명 지역 이름)(다수 선택 가능)

#define AGENCY_NAME_MAX_LENGTH 30
#define BUSYNESS_LICENSE_MAX_LENGTH 10
#define MAIN_COUNTRY_MAX_LENGTH 50
#define MAIN_REGION_MAX_LENGTH 50

#define GUIDE_LICENSE_MAX_LENGTH 30

using namespace std;

class LoginSystem {
private:
	char *currentLogID;
	static FILE * writer_UserInfo;
	static FILE * reader_UserInfo;

public:
	LoginSystem(char * input_ID) {
		currentLogID = (char*)malloc((ID_MAX_LENGTH + 1) * sizeof(char));
		currentLogID = input_ID;
	}

	static void createMember() {
		int optionNum; // 메뉴 옵션 중 선택 번호.
		char isSuccess; // 회원가입 성공, 실패 여부.

		// general member, one-man travel agency, guide 중 어느것으로 회원가입 하더라도 공통으로 입력받을 요소.
		char ID[ID_MAX_LENGTH + 1], PWD[PWD_MAX_LENGTH + 1],
			name[NAME_MAX_LEGTH + 1], phoneNumber[PHONE_NUMBER_MAX_LEGTH + 1]; 
		
		// general member로 회원가입 시 입력받을 요소.
		bool isPremium;
		char birthDate[BIRTH_MAX_LEGTH + 1], interestCountry[INTEREST_COUNTRY_MAX_LEGTH + 1],
			interestRegion[INTEREST_REGION_MAX_LEGTH + 1];
		char legalGender, advertise_AcceptOrNot;
		
		// one-man travel agency, guide 중 어느것으로 회원가입 하더라도 공통으로 입력받을 요소.
		char mainCountry[MAIN_COUNTRY_MAX_LENGTH + 1], mainRegion[MAIN_REGION_MAX_LENGTH + 1];

		// one-man travel agency로 회원가입 시 입력받을 요소.
		char AgencyName[AGENCY_NAME_MAX_LENGTH + 1], travelBusinessLicenseNumber[BUSYNESS_LICENSE_MAX_LENGTH + 1];

		// guide로 회원가입 시 입력받을 요소.
		char guideLicenseNumber[GUIDE_LICENSE_MAX_LENGTH + 1];


		// 회원가입 창과 회원가입 메뉴(옵션).
		cout << "\/\/\/ Join Membership \/\/\/" << endl;

		cout << "1 : General Member\n" << endl;
		cout << "2 : One-man Travel Agency\n" << endl;
		cout << "3 : Guide except for Travel Agency\n" << endl;
		cout << "4 : Exit" << endl;


		// 메뉴(옵션) 중 선택.
		cout << "입력 : ";
		cin >> optionNum;


		// 각 메뉴(1~4) 선택 시 operation.
		switch (optionNum) {

			// 사용자 회원가입
		case1:

			isSuccess = getUserInfo(ID, PWD, name, legalGender,
				 birthDate, phoneNumber, advertise_AcceptOrNot,
				 interestCountry, interestRegion); // 사용자로부터 정보를 입력 받음. 회원가입 성공 여부를 반환(true, false).
			
			// 회원가입 성공 시.
			if (isSuccess) {
				cout << "\n성공적으로 등록되셨습니다." << endl;

				isPremium = convertToPremiumMemberOrNot();

				// 사용자 정보를 파일(시스템)에 저장.
				addUserInfo(ID, PWD, isPremium, name, legalGender,
					birthDate, phoneNumber, advertise_AcceptOrNot,
					interestCountry, interestRegion); 
			}

			// 회원가입 실패 시(실패 : 취소하는 경우 밖에 없음).
			else {
				cout << "회원가입을 취소하셨습니다." << endl;
			}

			break;
			
		// 1인 여행사(사업자) 회원가입
		case2:


			isSuccess = getUserInfo(ID, PWD, name, AgencyName, phoneNumber, travelBusinessLicenseNumber
			mainCountry, mainRegion); // 사용자로부터 정보를 입력 받음. 회원가입 성공 여부를 반환(true, false).

		 //   회원가입 성공 시.
			//if (isSuccess) {
			//	cout << "\n성공적으로 등록되셨습니다." << endl;

			//	isPremium = convertToPremiumUserOrNot();

			//	 사용자 정보를 파일(시스템)에 저장.
			//	addUserInfo(inputId, inputPwd, isPremium, name, legalGender,
			//		birthDate, phoneNumber, advertise_AcceptOrNot,
			//		interestCountry, interestRegion);
			//}

			// 회원가입 실패 시(실패 : 취소하는 경우 밖에 없음).
			//else {
			//	cout << "회원가입을 취소하셨습니다." << endl;
			//}

			break;

			// 사업자 아닌 가이드 회원가입
		case3:

			break;
			
		default:
			exit(0);
		}


	}

	static void login() {
		
	}

	// 사용자 정보를 입력 받음.

	// 회원가입 시 필요한 General Member 정보를 입력 받음.
	// 아이디(글자수 제한), 비밀번호(글자수 제한), 이름(글자수 제한), 성별(M, W만), 생년월일(6자리, 유효한(전에 과제)), 전화번호(11자리) 등
	// 유효한지 확인하는 함수 구현해서 넣기.
	// 성별, 생년월일 등 유효한지 확인해야 나중에 파일에서 다시 가져와서 이용할 때 오류 안남(예외 생기는 것 방지).
	static bool getUserInfo(char * input_ID, char * input_PWD, char * input_name, char & input_gender,
		char * input_birth, char * input_phoneNumber, char & input_advertiseAcceptOrNot,
		char * input_interestCountry, char * input_interestRegion) {
		
		cout << "회원님의 정보를 입력받아 '일반 회원' 회원가입을 진행합니다(회원가입을 취소하고 싶은 경우 각 입력과정들 중 하나에서 0을 입력.)\n" << endl;
		cout << "\n회원 아이디와 비밀번호를 설정합니다" << endl;

		// 아이디.
		do {
			cout << "아이디를 입력해주세요(띄어쓰기 허용 x, 회원가입 취소 : 0, 다시 입력 : 1) : ";
			cin >> input_ID;
			return !isCancelJoinMember(input_ID);
		} while (atoi(input_ID) == 1);

		// 비밀번호.
		do {
			cout << "비밀번호를 입력해주세요(띄어쓰기 허용 x, 회원가입 취소 : 0, 다시 입력 : 1) : ";
			cin >> input_PWD;
			return !isCancelJoinMember(input_PWD);
		} while (atoi(input_PWD) == 1);

		// 이름.
		do {
			cout << "이름을 입력해주세요(회원가입 취소 : 0, 다시 입력 : 1) : ";
			cin >> input_name;
			return !isCancelJoinMember(input_name);
		} while (atoi(input_name) == 1);


		do {
			cout << "성별을 입력해주세요(남자 : M, 여자 : W, 회원가입 취소 : 0, 다시 입력 : 1) : ";
			cin >> input_gender;
			return !isCancelJoinMember(input_gender);
		} while (input_gender == '1');


		do {
			cout << "생년월일을 입력해주세요(ex 180528, 회원가입 취소 : 0, 다시 입력 : 1) : ";
			cin >> input_birth;
			return !isCancelJoinMember(input_birth);
		} while (atoi(input_birth) == 1);


		do {
			cout << "전화번호를 입력해주세요(ex 01067891234, 회원가입 취소 : 0, 다시 입력 : 1) : ";
			cin >> input_phoneNumber;
			return !isCancelJoinMember(input_phoneNumber);
		} while (atoi(input_phoneNumber) == 1);


		do {
			cout << "광고수신여부를 입력해주세요(허용 : Y, 거부 : N, 회원가입 취소 : 0, 다시 입력 : 1) : ";
			cin >> input_advertiseAcceptOrNot;
			return !isCancelJoinMember(input_advertiseAcceptOrNot);
		} while (input_advertiseAcceptOrNot == '1');


		do {
			cout << "관심 나라를 입력해주세요(ex 한국, 미국, 회원가입 취소 : 0, 다시 입력 : 1, 복수개 입력 시 ';'로 구분.) : ";
			cin >> input_interestCountry;
			return !isCancelJoinMember(input_interestCountry);
		} while (atoi(input_interestCountry) == 1);


		do {
			cout << "관심 도시(또는 유명 지역, 관광명소)를 입력해주세요(ex 서울, 뉴욕, 후지산, 신주쿠, 회원가입 취소 : 0, 다시 입력 : 1, 복수개 입력 시 ';'로 구분.) : ";
			cin >> input_interestRegion;
			return !isCancelJoinMember(input_interestRegion);
		} while (atoi(input_interestRegion) == 1);

		
		return true;
	}
	 
	// 회원가입 시 필요한 One-Man Travel Agency 정보를 입력 받음.
	// 유효한지 확인하는 함수 구현해서 넣기.
	// 유효한지 확인해야 나중에 파일에서 다시 가져와서 이용할 때 오류 안남(예외 생기는 것 방지).
	static bool getUserInfo(char * input_ID, char * input_PWD, char * input_name, char * input_agencyName, char * input_phoneNumber,
		char * input_LicenseNumber, char * input_mainCountry, char * input_mainRegion) {

		cout << "회원님의 정보를 입력받아 '사업자' 회원가입을 진행합니다(회원가입을 취소하고 싶은 경우 각 입력과정들 중 하나에서 0을 입력.)\n" << endl;
		cout << "\n회원 아이디와 비밀번호를 설정합니다" << endl;

		// 아이디.
		do {
			cout << "아이디를 입력해주세요(띄어쓰기 허용 x, 회원가입 취소 : 0, 다시 입력 : 1) : ";
			cin >> input_ID;
			return !isCancelJoinMember(input_ID);
		} while (atoi(input_ID) == 1);

		// 비밀번호.
		do {
			cout << "비밀번호를 입력해주세요(띄어쓰기 허용 x, 회원가입 취소 : 0, 다시 입력 : 1) : ";
			cin >> input_PWD;
			return !isCancelJoinMember(input_PWD);
		} while (atoi(input_PWD) == 1);

		// 사업자 이름.
		do {
			cout << "사업자 이름을 입력해주세요(회원가입 취소 : 0, 다시 입력 : 1) : ";
			cin >> input_name;
			return !isCancelJoinMember(input_name);
		} while (atoi(input_name) == 1);

		// 여행사 이름.
		do {
			cout << "여행사 이름을 입력해주세요(회원가입 취소 : 0, 다시 입력 : 1) : ";
			cin >> input_agencyName;
			return !isCancelJoinMember(input_agencyName);
		} while (atoi(input_agencyName) == 1);

		// 전화번호.
		do {
			cout << "전화번호를 입력해주세요(ex 01067891234, 회원가입 취소 : 0, 다시 입력 : 1) : ";
			cin >> input_phoneNumber;
			return !isCancelJoinMember(input_phoneNumber);
		} while (atoi(input_phoneNumber) == 1);

		// 여행사 사업자 등록번호.
		do {
			cout << "여행사 사업자 등록번호(10자리, '-' 제외)를 입력해주세요(회원가입 취소 : 0, 다시 입력 : 1) : ";
			cin >> input_LicenseNumber;
			return !isCancelJoinMember(input_LicenseNumber);
		} while (input_LicenseNumber == '1');


		do {
			cout << "해당 여행사(패키지)에서 주로 취급하는 나라를 입력해주세요(ex 한국, 미국, 회원가입 취소 : 0, 다시 입력 : 1, 복수개 입력 시 ';'로 구분.) : ";
			cin >> input_mainCountry;
			return !isCancelJoinMember(input_mainCountry);
		} while (atoi(input_mainCountry) == 1);


		do {
			cout << "해당 여행사(패키지)에서 주로 취급하는 도시(또는 유명 지역, 관광명소)를 입력해주세요(ex 서울, 뉴욕, 후지산, 신주쿠, 회원가입 취소 : 0, 다시 입력 : 1, 복수개 입력 시 ';'로 구분.) : ";
			cin >> input_mainRegion;
			return !isCancelJoinMember(input_mainRegion);
		} while (atoi(input_mainRegion) == 1);


		return true;
	}

	static bool getAgencyInfo() {

	}

	// 회원가입 취소
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
		char * registerTime = getCurrentTime(); //프리미엄 고객으로 결제한 날짜와 시간을 나타내는 문자열

		
		do {
			// 아직 정액제 회원(프리미엄 회원) 납부요금 아직 정하지 않았음.
			cout << "정액제 회원 등록시 월 3000원의 요금을 내고 가이드 컨설팅 서비스(가이드와의 채팅)를 이용하실 수 있습니다. ";
			cout << "결제하시겠습니까?(Y,N)" << endl;
			cin >> yesOrNo;

			if (yesOrNo == 'Y') {
				cout << "카드번호를 입력해주세요(16자리, 4자리씩 '-'로 구분해주세요)." << endl;
				cin >> cardNumber;

				cout << "\n" << endl;

				cout << "환영합니다 고객님" << endl << registerTime << "에 프리미엄 등급이 되셨습니다.\n\n";

				return true;
			}

			else if (yesOrNo == 'N') {
				cout << "감사합니다. 차분히 결정해주세요.\n" << endl;
				return false;
			}

			else {
				cout << "정확히 다시 입력해주세요.\n" << endl;
			}
		} while (yesOrNo != 'Y' && yesOrNo != 'N');
		
	}


	// 현재 날짜와 시간을 계산하기 위한 함수.
	// 프리미엄 고객으로 결제한 날짜와 시간을 계산하기 위한 함수.
	static char * getCurrentTime() {
		time_t now;
		time(&now);
		return ctime(&now);
	}

	// DB 관리 시스템 클래스 만들어서 파일 입출력은 따로 관리할까?
	static void addUserInfo(char * input_ID, const char * input_PWD, const bool input_isPremium, const char * input_name, const char input_gender,
		const char * input_birth, const char * input_phoneNumber, const char input_advertiseAcceptOrNot,
		const char * input_interestCountry, const char * input_interestRegion) {

		const char *fileName = strcat(input_ID, ".txt");
		
		
		//각 요소들은 줄바꿈으로 저장.

		// pwd 저장.
		writer_UserInfo = fopen(fileName, "w");
		fputs(input_PWD, writer_UserInfo);
		fputs("\n", writer_UserInfo);

		// premium 회원인지 아닌지 저장.(true, false).
		fputs((input_isPremium ? "true" : "false"), writer_UserInfo);
		fputs("\n", writer_UserInfo);

		// name 저장.
		fputs(input_name, writer_UserInfo);
		fputs("\n", writer_UserInfo);

		// legal gender 저장.
		fputc(input_gender, writer_UserInfo);
		fputs("\n", writer_UserInfo);

		// birth 저장.
		fputs(input_birth, writer_UserInfo);
		fputs("\n", writer_UserInfo);

		// phone number 저장.
		fputs(input_phoneNumber, writer_UserInfo);
		fputs("\n", writer_UserInfo);

		// 광고 수신 여부 저장.
		fputc(input_advertiseAcceptOrNot, writer_UserInfo);
		fputs("\n", writer_UserInfo);

		// 관심 나라 저장.
		fputs(input_interestCountry, writer_UserInfo);
		fputs("\n", writer_UserInfo);

		// 관심 도시(또는 유명 지역 또는 유명 명소) 저장.
		fputs(input_interestRegion, writer_UserInfo);
		fputs("\n", writer_UserInfo);
		
	}



};