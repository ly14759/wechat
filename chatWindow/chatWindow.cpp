#include "chatWindow.h"

chatWindown::chatWindown()
{
	initscr();
}

chatWindown::~chatWindown()
{
	delwin(header);
	delwin(output);
	delwin(flist);
	delwin(input);
	endwin();
}

//头行
void chatWindown::drawHeader()
{
	LINES;//总长
	COLS; //总宽
	int y = 0;//坐标
	int x = 0;//
	int h = LINES / 5;//高度
	int w = COLS;	//宽度

	//创建窗口
	header = newwin(h,w,y,x);
	//制作边框
	box(header, '+', '-');
	//刷新到显示器
	wrefresh(header);
}
//输出框
void chatWindown::drawOutput()
{
	LINES;//总长
	COLS; //总宽
	int y = LINES / 5;//坐标
	int x = 0;//
	int h = 3*LINES / 5;//高度
	int w = 2*COLS / 3;	//宽度

	//创建窗口
	output = newwin(h,w,y,x);
	//制作边框
	box(output, '+', '-');
	//刷新到显示器
	wrefresh(output);
}
//在线用户框
void chatWindown::drawFlist()
{
	LINES;//总长
	COLS; //总宽
	int y = LINES / 5;//坐标
	int x = 2*COLS / 3;//
	int h = 3*LINES / 5;//高度
	int w = COLS / 3;	//宽度

	//创建窗口
	flist = newwin(h,w,y,x);
	//制作边框
	box(flist, '+', '-');
	//刷新到显示器
	wrefresh(flist);
}
//输入窗口
void chatWindown::drawInput()
{
	LINES;//总长
	COLS; //总宽
	int y = 4*LINES / 5;//坐标
	int x = 0;//
	int h = LINES / 5;//高度
	int w = COLS;	//宽度

	//创建窗口
	input = newwin(h,w,y,x);
	//制作边框
	box(input, '+', '-');
	//刷新到显示器
	wrefresh(input);
}

int main()
{
	chatWindown win;
	win.drawHeader();
	win.drawOutput();
	win.drawFlist();
	win.drawInput();
	sleep(1);
	while (1)
	{}
	return 0;
}
