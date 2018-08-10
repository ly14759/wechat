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
#include <map>
#include <pthread.h>
#include "../data_pool/data_pool.h"
using namespace std;

#define MAX_SIZE (1024)
class udpServer
{
public:
	udpServer(int _port);
	int udpServerInit();
	int recvData(std::string& outString);
	int sendData(const std::string& inString, struct sockaddr_in& client , socklen_t len);
	void brocastData(const std::string& inString);
	~udpServer();
private:
	int sock; //套接字
	int port;
	dataPool pool;
	std::map<int, struct sockaddr_in> online;
};
