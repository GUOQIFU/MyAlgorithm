#include"myheadfile.h"
#include"My_String.h"

#pragma warning(disable:4996);

My_String::My_String(const char *str)
{
	if (str == NULL)
	{
		_str = new char[1];
		_str = '\0';
	}else {
		int length = strlen(str);
		_str = new char[length + 1];
		my_strcpy(_str, str);
	}
}

My_String::~My_String()
{
	while (_str != NULL)
	{
		delete[]_str;
	}
}

My_String::My_String(const My_String &s)
{
	int length = strlen(s._str);
	if (length == 0)
	{
		_str = new char[1];
		_str = '\0';
	}
	else {
		_str = new char[length + 1];
		my_strcpy(_str,s._str);
	}
}
My_String &My_String::operator = (const My_String &s)//·ûºÅÖØÔØº¯Êý
{
	if (this == &s)
	{
		return *this;
	}
	delete[]_str;
	int length = strlen(s._str);
	_str = new char[length + 1];
	my_strcpy(_str, s._str);
	return *this;
}
//
//class MyString
//{
//public:
//	MyString(const char *str);
//
//	~MyString();
//
//	MyString(const MyString &s);
//
//	MyString &operator=(const MyString &s);
//
//private:
//	char *_str;
//};
//
//MyString::MyString(const char *str)
//{
//	if (str == NULL)
//	{
//		_str = new char[1];
//		_str = '\0';
//	}
//	else {
//		_str = new char[strlen(str) + 1];
//		strcpy(_str, str);
//	}
//}
//
//MyString::~MyString()
//{
//	while (_str != NULL)
//	{
//		delete[]_str;
//	}
//}
//
//MyString::MyString(const MyString &s)
//{
//	if (s._str == NULL)
//	{
//		_str = new char[1];
//		strcpy(_str, s._str);
//	}
//	else {
//		_str = new char[strlen(s._str) + 1];
//		strcpy(_str, s._str);
//	}
//}
//
//MyString &MyString::operator=(const MyString &s)
//{
//	if (_str == s._str)
//	{
//		return *this;
//	}
//	delete[]_str;
//	_str = new char[strlen(s._str) + 1];
//	strcpy(_str, s._str);
//	return *this;
//}