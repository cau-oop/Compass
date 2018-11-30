#include<iostream>

using namespace std;

class Greeter {

public:
	//void work() {
	//	int optionNum;
	//	char inputId[31], inputPwd[51];
	//	bool success;

	//	// system work flow
	//	initialMessage();
	//	do {
	//		loginOptionMessage();
	//		scanf("%d", &optionNum);

	//		if (optionNum == 1) {
	//			success = false;
	//			Admin *admin = new Admin();

	//			do {

	//				printf("\n아이디와 비밀번호를 입력하세요.(종료 : id : 0, pwd : 0)\n");
	//				printf("Id : ");
	//				scanf("%s", inputId);

	//				printf("Pwd : ");
	//				scanf("%s", inputPwd);

	//				if (!strcmp(inputId, "0") && !strcmp(inputPwd, "0"))
	//					break;

	//				success = admin->checkIsAdmin(inputId, inputPwd);

	//			} while (strcmp(inputId, "0") && !success);

	//			if (success) {
	//				int optionN = 0;

	//				greet(inputId, 1);

	//				while (optionN != 7) {
	//					availAdminOption();
	//					scanf("%d", &optionN);

	//					if (optionN == 1) {
	//						printf("\n새 아이디를 입력하세요(취소 : 0) : ");
	//						scanf("%s", inputId);

	//						if (strcmp(inputId, "0"))
	//							admin->setAdminID(inputId);
	//					}

	//					else if (optionN == 2) {
	//						printf("\n새 비밀번호를 입력하세요(취소 : 0) : ");
	//						scanf("%s", inputPwd);

	//						if (strcmp(inputPwd, "0"))
	//							admin->setAdminPwd(inputPwd);
	//					}

	//					else if (optionN == 3) {
	//						printf("\n새 아이디를 입력하세요(취소 : 0) : ");
	//						scanf("%s", inputId);

	//						if (strcmp(inputId, "0"))
	//							admin->setMgrID(inputId);
	//					}

	//					else if (optionN == 4) {
	//						printf("\n새 비밀번호를 입력하세요(취소 : 0) : ");
	//						scanf("%s", inputPwd);

	//						if (strcmp(inputPwd, "0"))
	//							admin->setMgrPwd(inputPwd);
	//					}

	//					else if (optionN == 5) {
	//						admin->addFoodInfo();
	//					}

	//					else if (optionN == 6) {
	//						admin->viewFoodInfo();
	//					}

	//				}

	//			}

	//			delete(admin);
	//		}

	//		if (optionNum == 2) {
	//			success = false;
	//			FoodDBManager *mgr = new FoodDBManager();

	//			do {

	//				printf("\n아이디와 비밀번호를 입력하세요.(종료 : id : 0, pwd : 0)\n");
	//				printf("Id : ");
	//				scanf("%s", inputId);

	//				printf("Pwd : ");
	//				scanf("%s", inputPwd);

	//				if (!strcmp(inputId, "0") && !strcmp(inputPwd, "0"))
	//					break;

	//				success = mgr->checkIsManager(inputId, inputPwd);

	//			} while (strcmp(inputId, "0") && !success);

	//			if (success) {
	//				int optionN = 0;

	//				greet(inputId, 2);

	//				while (optionN != 3) {
	//					availDBMgrOption();
	//					scanf("%d", &optionN);

	//					if (optionN == 1) {
	//						mgr->addFoodInfo();
	//					}

	//					else if (optionN == 2) {
	//						mgr->viewFoodInfo();
	//					}
	//				}
	//			}

	//			delete(mgr);
	//		}

	//		if (optionNum == 3) {
	//			greet(3);

	//			int optionN = 0;
	//			User *currentUser = new User();

	//			while (optionN != 3) {
	//				availUserOption();
	//				scanf("%d", &optionN);

	//				if (optionN == 1) {
	//					currentUser->checkHealth();
	//				}

	//				else if (optionN == 2) {
	//					currentUser->convertToPremiumUser();
	//					break; // 프리미엄 계정으로 전환 시 메인화면으로 돌아가서 프리미엄 계정으로 새로 로그인 해야함.
	//				}
	//			}

	//		}

	//		if (optionNum == 4) {
	//			success = false;
	//			User *premiumUser = new PremiumUser();

	//			do {

	//				printf("\n아이디와 비밀번호를 입력하세요.(종료 : id : 0, pwd : 0)\n");
	//				printf("Id : ");
	//				scanf("%s", inputId);

	//				printf("Pwd : ");
	//				scanf("%s", inputPwd);

	//				if (!strcmp(inputId, "0") && !strcmp(inputPwd, "0"))
	//					break;

	//				success = premiumUser->checkPremiumUser(inputId, inputPwd);

	//			} while (strcmp(inputId, "0") && !success);

	//			if (success) {
	//				int optionN = 0;

	//				greet(inputId, 4);

	//				while (optionN != 2) {
	//					availPremiumUserOption();
	//					scanf("%d", &optionN);

	//					if (optionN == 1) {
	//						premiumUser->checkHealth();
	//					}
	//				}

	//			}

	//			delete(premiumUser);
	//		}


	//	} while (optionNum != 5);

	//	exitMessage();
	//}

	static void initialMessage() {
		printf("////////////////////   Welcome to Compass!!!   ////////////////////\n");
	}

	static void loginOptionMessage() {
		printf("\nWho are you?\n");
		printf("1 : General User\n");
		printf("2 : One-man Travel Agency\n");
		printf("3 : Guide except for Travel Agency\n");
		printf("4 : Exit");
	}

	static void exitMessage() {
		printf("\n\n////////////////////   Have a nice day!!!   ////////////////////\n\n");
	}

	void greet(char * id, const char * who) {
		if (who == "General User")
			printf("\nHello General User %s sir.\n", id);

		else if (who == "Premium User")
			printf("\nHello Premium User sir.\n");

		else if (who == "Travel Agency")
			printf("\nHello Travel Agency %s sir.\n", id);

		else if (who == "Guide")
			printf("\nHello Guide %s sir.\n", id);
	}

	static void availGeneralUserOption() {
		printf("\nGeneralUser Sir. What are you supposed to do?\n\n");
		/*printf("1. Change id\n");
		printf("2. Change password\n");
		printf("3. Change Manager id\n");
		printf("4. Change Manager password\n");
		printf("5. add food in food-DB\n");
		printf("6. View food info in food-DB\n");
		printf("7. logout\n\n");*/
	}

	static void availTravelAgencyOption() {
		printf("\nTravel Agency Sir. What are you supposed to do?\n\n");
		/*printf("1. add food in food-DB\n");
		printf("2. View food info in food-DB\n");
		printf("3. logout\n\n");*/
	}

	static void availGuideOption() {
		printf("\nGuide Sir. What are you supposed to do?\n\n");
		//printf("1. check Health\n");
		//printf("2. change to premium member\n");
		//printf("3. move to first screen\n\n"); // admin, DBManager, User, Premium User 중 어느 것으로 앱에 접속할 것인지 결정하는 화면으로 이동.
	}

	static void availPremiumUserOption() {
		printf("\nPremium User Sir. What are you supposed to do?\n\n");
		/*printf("1. check Health\n");
		printf("2. logout\n\n");*/
	}

};