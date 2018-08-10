#include "udp_server.h"

//构造函数
udpServer::udpServer(int _port)
	:sock(-1)
	,port(_port)
{}

//套接字定义函数
int udpServer::udpServerInit()
{
	//1.建立套接字
	sock = socket(AF_INET, SOCK_DGRAM, 0);
	if (sock < 0) {
		perror("SOCKET failed");
		return -1;
	}
	std::cout << "socket: " <<  sock <<std::endl;
	//2.初始化
	struct sockaddr_in local; //服务器端的套接字地址
	bzero(&local, sizeof(local));
	local.sin_family = AF_INET;
	local.sin_addr.s_addr = htonl(INADDR_ANY);
	local.sin_port = htons(port);
	//3.绑定套接字
	if (bind(sock, (struct sockaddr*)&local, sizeof(local)) < 0) {
		perror("BIND failed");
		return -2;
	}
	return 0;
}

//读数据 函数
int udpServer::recvData(std::string& outString)
{
	struct sockaddr_in client;
	socklen_t len = sizeof(client);
	char buf[MAX_SIZE] = {0};
	//recvfrom函数，由于不知道客户端的地址，调用这个函数后，客户端sendto给服务器端，recvfrom从sock
	//中接受，并把客户端的地址保存在后面俩个参数中。recvfrom在未接受到数据时是阻塞的；
	//返回值时接受到数据的长度
	ssize_t s = recvfrom(sock, buf, sizeof(buf) - 1, 0, (struct sockaddr*)&client, &len);
	//获取之后 用map维护 key:ip, value:client

	if (s > 0) {
		buf[s] = 0;
		outString = buf;
		//加入在线客户端
		online.insert(pair<int, struct sockaddr_in>(client.sin_addr.s_addr,client));
		printf("[%s : %d]: %s\n", inet_ntoa(client.sin_addr), ntohs(client.sin_port),buf);
		//pool //放数据
		pool.putData(outString);
	} else {
		perror("recvfrom GG");
		return -3;
	}
	return 0;
}
//写数据 函数
int udpServer::sendData(const std::string& inString, struct sockaddr_in& client, socklen_t len)
{
	ssize_t se = sendto(sock, inString.c_str(), inString.size(), 0, (struct sockaddr*)&client, len);
	//sendto(sock, inString.c_str, inString.size(), 0, (struct sockaddr*)&client, len);
	return 0;
}
//广播
void udpServer::brocastData(const std::string& inString)
{
	string str;
	pool.getData(str);
	map<int, struct sockaddr_in>::iterator it = online.begin();
	for (; it != online.end(); ++it) {
		sendData(str, it->second, sizeof(it->second));
	}
}

//
udpServer::~udpServer()
{
	close(sock);
	port = -1;
}





