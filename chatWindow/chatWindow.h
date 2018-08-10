#pragma once
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>

using namespace std;

class chatWindown {
public:
	chatWindown();
	~chatWindown();
	//画窗口函数
	void drawHeader();
	void drawOutput();
	void drawFlist();
	void drawInput();
	//头行跑马
	void runStringHeader(string str);

public:
	WINDOW* header;
	WINDOW* output;
	WINDOW* flist;
	WINDOW* input;
};
