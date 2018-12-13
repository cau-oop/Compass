#pragma once

// �޽��� �ְ� ���� ���� ���Ϸ� ����� �ǵ���. �α��� ����� ����.
// �α��� ȸ������ ���� �����ͼ� ����.
// add package, �α��� ���� � ������ �ְ� ����. ����ȭ�ϰ�. �޽���ó��.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <process.h> 
#include "Login.h"
//#include "obectClassFile.h"

#define BUF_SIZE 100 // �ѹ� ������ ���� �� �ִ� �ִ� �޽��� ����.
#define NAME_SIZE 20 // max ID ������ �����ֱ�.
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

		// ���� �α��� �� ����� ���̵� ������. 
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
		hSock = socket(PF_INET, SOCK_STREAM, 0); // TCP ���.

		memset(&servAdr, 0, sizeof(servAdr));
		servAdr.sin_family = AF_INET; // IPv4 �ּ� ���.
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
		// GUI�� ������ �� �Ƹ� ���� ���â�� ���� ���� �װ� �Ѽ� ����ؾ� �ҵ�.
		fputs(msg, stderr);
		fputc('\n', stderr);
		exit(1);
	}

};

unsigned WINAPI SendMsg(void * arg)   // send thread main
{
	SOCKET hSock = *((SOCKET*)arg);
	char guideID[MAX_GUIDE_ID_LENGTH + 1]; // �ȵǸ� ���������� �Űܺ���.
	char guideID_NameMsg[MAX_GUIDE_ID_LENGTH + 1 + NAME_SIZE + 1 + BUF_SIZE + 1];

	do {
		cout << "�����ų ���̵带 �Է��ϼ���(0�Է½� ����) : ";
		fgets(guideID, 51, stdin); // GUi�� ���� ���Ѿ� �ϴ� �κ�.

		while (1)
		{

			cout << "���� �޽����� �Է��ϼ��� : ";
			fgets(msg, BUF_SIZE, stdin); // GUi�� ���� ���Ѿ� �ϴ� �κ�.

			sprintf(guideID_NameMsg, "%s:%s:%s", guideID, name, msg); // ���� ���ڿ� ������ ��.

			if (!strcmp(msg, "q\n") || !strcmp(msg, "Q\n")) // Q �Ǵ� q �Է½� Ŭ���̾�Ʈ ���α׷� ����.
			{
				closesocket(hSock);
				exit(0);
			}

			send(hSock, guideID_NameMsg, strlen(guideID_NameMsg), 0); // ������ send ��.
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
		strLen = recv(hSock, guideID_NameMsg, MAX_GUIDE_ID_LENGTH + 1 + NAME_SIZE + 1 + BUF_SIZE, 0); // nameMsg�� �޾ƿ�. ������ ���ҿ� �ι��ڴ� ���� �ʴ´�.

		if (strLen == -1)
			return -1;


		guideID_NameMsg[strLen] = 0; //������ ���ҿ� �ι��ڸ� ���� �־���.

		//guideID, currentUserID, message�и�.
		receiveContents[i] = strtok(guideID_NameMsg, ":"); //��� ����
		i++;
		while (receiveContents[i - 1] != nullptr) {
			receiveContents[i] = strtok(nullptr, ":");
			i++;
		}

		// ���̵��� �¶��� ���� on(?)�϶���.
		if (current_id == receiveContents[0] || current_id == receiveContents[1]) {
			sprintf(nameMsg, "[%s] %s", receiveContents[1], receiveContents[2]);
			fputs(nameMsg, stdout);
		}

		//
		//if (current_id)
		//	fputs(nameMsg, stdout); // GUI�� �������Ѿ� �ϴ� �κ�.
	}
	return 0;
}