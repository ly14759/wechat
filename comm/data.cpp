#include "data.h"

data::data()
	:nick_name("")
	,school("")
	,message("")
	,cmd("")
{}
data::~data()
{
	nick_name = "";
	school = "";
	message = "";
	cmd = "";
}
void data::serialize(string& outString)
{
	root["nick_name"] = nick_name;
	root["school"] = school;
	root["message"] = message;
	root["cmd"] = cmd;
	valueTOString(outString, root);
}

void data::unserialize(string& inString)
{
	stringTOValue(inString, root);
	nick_name = root["nick_name"].asString();
	school = root["school"].asString();
	message = root["message"].asString();
	cmd = root["cmd"].asString();
}
