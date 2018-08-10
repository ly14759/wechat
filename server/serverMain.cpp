#include "udp_server.h"

void usage(std::string prot)
{
	std::cout << "Usage: " << prot << "port" << std::endl;
}

//服务器端接受数据
void* readFun(void* arg)
{
	string str;
	udpServer* ser = (udpServer*)arg;
	ser->recvData(str);	

}

//客户端发送数据
void* sendFun(void* arg)
{
	string str;
	udpServer* ser = (udpServer*)arg;
	ser->brocastData(str);
}
int main(int argc, char* argv[])
{

	//俩线程创建
	//生产 P
	//消费 C
	
	if (argc != 2) {
		usage("to argv");
		return 1;
	}
	udpServer ser(atoi(argv[1]));
	ser.udpServerInit();
	for (;;) {
//	std::string str;
		pthread_t readTid, sendTid;
		pthread_create(&readTid, NULL, readFun, (void*)&ser);
		pthread_create(&sendTid, NULL, sendFun, (void*)&ser);
		pthread_detach(sendTid);
		pthread_detach(readTid);
	}
	//for (;;) {
	//	struct sockaddr_in client;
	//	socklen_t len = sizeof(client);
	//	ser.recvData(str, client, len);
	//	std::cout << "echo-》" << str << std::endl;
	//	ser.sendData(str, client, len);
	//}
	return 0;
}
