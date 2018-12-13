#pragma once

// 메시지 주고 받은 것을 파일로 입출력 되도록. 로그인 사용자 별로.
// 로그인 회원가입 파일 가져와서 연동.
// add package, 로그인 정보 등도 서버로 넣고 빼고. 동기화하고. 메시지처럼.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <process.h> 
#include "Login.h"
//#include "obectClassFile.h"

#define BUF_SIZE 100 // 한번 보낼때 보낼 수 있는 최대 메시지 길이.
#define NAME_SIZE 20 // max ID 값으로 고쳐주기.
#define MAX_GUIDE_ID_LENGTH 50
unsigned WINAPI SendMsg(void * arg);
unsigned WINAPI RecvMsg(void * arg);

char name[NAME_SIZE];
char msg[BUF_SIZE];

extern LoginSystem loginSystem;

//
//LoginSystem loginSystem;

class ChatClient{
private:

	char * serv_ip_addr;
	char * serv_ip_port;
	char * current_id;

public:

	WSADATA wsaData;
	SOCKET hSock;
	SOCKADDR_IN servAdr;
	HANDLE hSndThread, hRcvThread;

	ChatClient(const char * serv_ip, const char * serv_port) {

		serv_ip_addr = (char *)malloc(sizeof(char) * 14);
		serv_ip_port = (char *)malloc(sizeof(char) * 5);
		
		strcpy(serv_ip_addr, serv_ip_addr);
		strcpy(serv_ip_port, serv_port);

		// 현재 로그인 된 사용자 아이디 가져옴. 
		current_id = loginSystem.getCurrentID();
	}
	
	~ChatClient() {
		free(serv_ip_addr);
		free(serv_ip_port);
	}

	void chat() {
		if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
			ErrorHandling("WSAStartup() error!");
		

		//sprintf(name, "[%s]", current_id);
		strcpy(name, current_id);
		hSock = socket(PF_INET, SOCK_STREAM, 0); // TCP 방식.

		memset(&servAdr, 0, sizeof(servAdr));
		servAdr.sin_family = AF_INET; // IPv4 주소 사용.
		servAdr.sin_addr.s_addr = inet_addr(serv_ip_addr);
		servAdr.sin_port = htons(atoi(serv_ip_port));

		if (connect(hSock, (SOCKADDR*)&servAdr, sizeof(servAdr)) == SOCKET_ERROR)
			ErrorHandling("connect() error");


		hSndThread =
			(HANDLE)_beginthreadex(NULL, 0, SendMsg, (void*)&hSock, 0, NULL); //////
		hRcvThread =
			(HANDLE)_beginthreadex(NULL, 0, RecvMsg, (void*)&hSock, 0, NULL); //////

		WaitForSingleObject(hSndThread, INFINITE); //////
		WaitForSingleObject(hRcvThread, INFINITE); //////

		closesocket(hSock);

		WSACleanup();
	}
	/*if (argc != 4) {
		printf("Usage : %s <IP> <port> <name>\n", argv[0]);
		exit(1);
	}*/

	void ErrorHandling(const char *msg)
	{
		// GUI랑 연동할 때 아마 오류 출력창을 따로 만들어서 그걸 켜서 출력해야 할듯.
		fputs(msg, stderr);
		fputc('\n', stderr);
		exit(1);
	}

};

unsigned WINAPI SendMsg(void * arg)   // send thread main
{
	SOCKET hSock = *((SOCKET*)arg);
	char guideID[MAX_GUIDE_ID_LENGTH + 1]; // 안되면 전역변수로 옮겨보기.
	char guideID_NameMsg[MAX_GUIDE_ID_LENGTH + 1 + NAME_SIZE + 1 + BUF_SIZE + 1];

	do {
		cout << "연결시킬 가이드를 입력하세요(0입력시 종료) : ";
		fgets(guideID, 51, stdin); // GUi랑 연동 시켜야 하는 부분.

		while (1)
		{

			cout << "보낼 메시지를 입력하세요 : ";
			fgets(msg, BUF_SIZE, stdin); // GUi랑 연동 시켜야 하는 부분.

			sprintf(guideID_NameMsg, "%s:%s:%s", guideID, name, msg); // 보낼 문자열 구성한 것.

			if (!strcmp(msg, "q\n") || !strcmp(msg, "Q\n")) // Q 또는 q 입력시 클라이언트 프로그램 종료.
			{
				closesocket(hSock);
				exit(0);
			}

			send(hSock, guideID_NameMsg, strlen(guideID_NameMsg), 0); // 서버로 send 함.
		}
	} while (strcmp(guideID, "0") != 0);

	return 0;
}

unsigned WINAPI RecvMsg(void * arg)   // read thread main
{
	int hSock = *((SOCKET*)arg);
	char guideID_NameMsg[MAX_GUIDE_ID_LENGTH + 1 + NAME_SIZE + 1 + BUF_SIZE + 1];
	int strLen, i = 0;
	char * receiveContents[3];
	char nameMsg[300];
	const char * current_id = loginSystem.getCurrentID();
	while (1)
	{
		strLen = recv(hSock, guideID_NameMsg, MAX_GUIDE_ID_LENGTH + 1 + NAME_SIZE + 1 + BUF_SIZE, 0); // nameMsg에 받아옴. 마지막 원소에 널문자는 들어가지 않는다.

		if (strLen == -1)
			return -1;


		guideID_NameMsg[strLen] = 0; //마지막 원소에 널문자를 따로 넣어줌.

		//guideID, currentUserID, message분리.
		receiveContents[i] = strtok(guideID_NameMsg, ":"); //토근 분해
		i++;
		while (receiveContents[i - 1] != nullptr) {
			receiveContents[i] = strtok(nullptr, ":");
			i++;
		}

		// 가이드의 온라인 상태 on(?)일때만.
		if (current_id == receiveContents[0] || current_id == receiveContents[1]) {
			sprintf(nameMsg, "[%s] %s", receiveContents[1], receiveContents[2]);
			fputs(nameMsg, stdout);
		}

		//
		//if (current_id)
		//	fputs(nameMsg, stdout); // GUI랑 연동시켜야 하는 부분.
	}
	return 0;
}