#include<iostream>
#include<string>
#include"myheadfile.h"

string StrCin()
{
	string s;
	cout << " input the string please!" << endl;
	getline(cin, s);
	return s;
}
