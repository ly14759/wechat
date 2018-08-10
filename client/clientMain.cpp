#include "udp_client.h"

void usage(std::string prot)
{
	std::cout << "Usage: " << prot << "port" << std::endl;
}

int main(int argc, char* argv[])
{
	if (argc != 3) {
		usage("to argv");
		return 1;
	}
	//atoi->字符转整型
	//ip port 保存在变量中
	udpClient cli(argv[1], atoi(argv[2]));
	cli.udpClientInit();
	std::string str;
	data d;
	for (;;) {
		cout << "nick_name-》";
		cin >> d.nick_name;
		cout << "school-》";
		cin >> d.school;
		cout << "message";
		cin >> d.message;
		d.cmd = "";
		d.serialize(str);
		//发送函数 有服务器地址
		cli.sendData(str);
	//	std::cout << "echo-》" << str << std::endl;
		cli.recvData(str);
		cout << "echo-》" << str << endl;
		d.unserialize(str);
		printf("OK\n");
	}
	return 0;
}
