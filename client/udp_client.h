#pragma once
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "../comm/data.h"
using namespace std;

#define MAX_SIZE (1024)
class udpClient
{
public:
	udpClient(char* _ip, int _port);
	int udpClientInit();
	int recvData(std::string& outString);
	int sendData(const std::string& inString);
	~udpClient();
private:
	int sock; //套接字
	char* serverIp;
	int serverPort;
};
