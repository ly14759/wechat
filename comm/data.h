#pragma once
#include "baseJOSN.hpp"


class data {
public:
	data();
	~data();
	//序列化
	void serialize(string& outString);
	//反序列化
	void unserialize(string& inString);
public:
	string nick_name;
	string school;
	string message;
	string cmd;//数据备注：空
	Json::Value root;
};
