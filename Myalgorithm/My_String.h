#pragma once
#ifndef MY_STRING_H
#define MY_STRING_H
#include"myheadfile.h"

class My_String
{
public:
	My_String(const char *str);//��ͨ���캯��

	~My_String();//��������
	
	My_String(const My_String &s);//�������캯��
	
	My_String &operator=(const My_String &s); //��ֵ���غ���

public:
	char *_str;
	size_t size;
};

#endif

