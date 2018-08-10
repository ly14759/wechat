#pragma once
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <json/json.h>
#include <string.h>

using namespace std;

//反序列化-读数据
inline void stringTOValue(string& inString, Json::Value& val)
{
	Json::Reader r;
	r.parse(inString, val, false);
}
//序列化-写数据
inline void valueTOString(string& outString, Json::Value& val)
{
	Json::StyledWriter w;	
	outString = w.write(val);
}

