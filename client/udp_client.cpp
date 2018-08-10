#include "udp_client.h"

//构造函数
udpClient::udpClient(char* _ip, int _port)
	:sock(-1)
	,serverIp(_ip)
	,serverPort(_port)
{}

//套接字定义函数
int udpClient::udpClientInit()
{
	//1.建立套接字
	sock = socket(AF_INET, SOCK_DGRAM, 0);
	if (sock < 0) {
		perror("client: SOCKET failed");
		return -1;
	}
	std::cout << "socket: " <<  sock <<std::endl;
	return 0;
}

//读数据 函数
int udpClient::recvData(std::string& outString)
{
	struct sockaddr_in server;
	socklen_t len = sizeof(server);
	char buf[MAX_SIZE] = {0};
	//recvfrom函数，由于不知道客户端的地址，调用这个函数后，客户端sendto给服务器端，recvfrom从sock
	//中接受，并把客户端的地址保存在后面俩个参数中。recvfrom在未接受到数据时是阻塞的；
	//返回值时接受到数据的长度
	ssize_t s = recvfrom(sock, buf, sizeof(buf) - 1, 0, (struct sockaddr*)&server, &len);
	//获取之后 用map维护 key:ip, value:client

	if (s > 0) {
		buf[s] = 0;
		outString = buf;
		//printf("[%s : %d]: %s\n", inet_ntoa(client.sin_addr), ntohs(client.sin_port),buf);
		printf("outString:%s\n", outString.c_str());
		//.. 转换函数
		//pool //放数据
	} else {
		perror("cilent recvfrom GG");
		return -3;
	}
	return 0;
}
//写数据 函数
int udpClient::sendData(const std::string& inString)
{
	//初始化 服务器端套件字地址
	struct sockaddr_in server;
	bzero(&server, sizeof(server));
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = inet_addr(serverIp);
	server.sin_port = htons(serverPort);
	ssize_t s = sendto(sock, inString.c_str(), inString.size(), 0, (struct sockaddr*)&server, sizeof(server));
	if (s < 0) {
		perror("client sendto failed");
		return -4;
	}
	//广播
	return 0;
}

//
udpClient::~udpClient()
{
	close(sock);
	serverIp = NULL;
	serverPort = -1;
}





