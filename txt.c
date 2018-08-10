畅聊系统
	局域网内群聊功能
	C++ --STL
	UDP
	心跳包
	C/S 模型
	多线程编程
	开源库-》
	JOSN
	生产-消费者模型
	shell脚本

###原理：
	客户端-多线程-服务器端线程1-环形队列读取-服务器端线程2广播回去-多个客户端
	加锁-互斥与同步 
	单生产者-同步-信号量
	生产者-格子  消费者数据

###代码实现：
server-》
	udp_sercer.cpp
		sock, port, 构造，初始化， 读 ，写，析构
		data_pool;
	udp_server.h
	serverMain.cpp 
cilent-》
	发送
	接收
	
comm-》序列化 JOSN
data_pool-》数据池
	data_pool.h
		vector<string>, cap, pstep, gstep, blankSem, dataSem;
		构造，析构，放数据，取数据
	data_pool.cpp

广播-》map 迭代器
	INLCUDE=-I$(DATA_POOL)
	LDFLAGS=-lpthread
用户添加
	addUser(sockaddr_in &client)
{
	online.insert(std::pair<in, sockaddr>)(client.sin_addr, client);
	//唯一性
}

comm-》
	baseJOSN.h
	baseJOSN.cpp
		JOSN.cpp库
#include <json/json,h>
		void stringToValue(std::string, Json::Value& val); //反序列化-》read
		{
			Json::Reader r;
			r.parse(inString, val, false);
		}
		void valueTOString(val, string); //序列化-》write
		{
			Json::StyledWriter::w;
			outString = w.write(val);
		}
	data.cpp 数据格式
	data.h
		class data {
		public:
			void serialize(std::string &outString); //序列化
			{
				Json::Value root;
				root["nick_name"] = nick_name;
				root["message"] = message;
				root["school"] = school;
				root["cmd"] = cmd;
				valueTOString(root, outString);
			}
			void unserialize(inString);
			{
				stringTOValue(inString, root);
				nick_name = root["nick_name"].asString();
				//... ... ...
			}
		public:
			std::string nick_name;
			std::string message;
			std::string school;
			std::string cmd; //什么数据
		}
整体连接-》Makefile编写 server+data_pool+pthread client+data
展示-》window模块
		window.h
		window.cpp
		

