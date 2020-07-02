#pragma once
#ifndef MY_STRING_H
#define MY_STRING_H
#include"myheadfile.h"

class My_String
{
public:
	My_String(const char *str);//普通构造函数

	~My_String();//析构函数
	
	My_String(const My_String &s);//拷贝构造函数
	
	My_String &operator=(const My_String &s); //赋值重载函数

public:
	char *_str;
	size_t size;
};

#endif

