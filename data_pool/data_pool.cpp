#include "data_pool.h"

dataPool::dataPool(int _cap)
	:pool(_cap)
	,cap(_cap)
	,gStep(0)
	,pStep(0)
{
	sem_init(&blankSem, 0, cap);
	sem_init(&dataSem, 0, 0);
}

dataPool::~dataPool()
{
	cap = 0;
	gStep = 0;
	pStep = 0;
	//1.vector 销毁
	//2.信号量销毁
	sem_destroy(&blankSem);
	sem_destroy(&dataSem);

}

//放入数据
void dataPool::putData(const string& inString)
{
	//等待信号量函数： 格子数减一
	sem_wait(&blankSem);	
	pool[pStep++] = inString;
	pStep %= cap;
	//发布信号量函数：数据数加一
	sem_post(&dataSem);
}

//取走数据
void dataPool::getData(string& outString)
{
	sem_wait(&dataSem);
	outString = pool[gStep--];
	gStep %= cap;
	sem_post(&blankSem);
}





