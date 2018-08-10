//数据池-》环形队列-》数组vector实现-》大小取模来控制环形大小
#pragma once
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string.h>
#include <semaphore.h>

using namespace std;

class dataPool{
public:
	dataPool(int _cap = 10);
	~dataPool();
	//放入数据
	void putData(const string& inString);
	//送出数据
	void getData(string& outString);
public:
	vector<string> pool;//模拟环形队列
	int cap; //最大容量
	int pStep;//生产者-放数据-位置
	int gStep;//消费者-取数据-位置
	sem_t blankSem;//信号量-生产者-剩余格子
	sem_t dataSem; //信号量-消费者-可用数据
};
