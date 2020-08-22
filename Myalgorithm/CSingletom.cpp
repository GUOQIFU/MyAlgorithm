#include<iostream>
#include "myheadfile.h"
using namespace std;
class CSingleton
{
private:
	CSingleton()
	{};
	static CSingleton *p;
public:
	static CSingleton *GetInstance()
	{
		if (p == NULL)
		{
			p = new CSingleton();
		}
		return p;
	}
};
CSingleton *CSingleton::p = NULL;//����ʽ
//CSingleton *CSingleton::p = new CSingleton;//����ʽ

//int main()
//{
//	CSingleton *t = CSingleton::GetInstance();
//	CSingleton *tt = CSingleton::GetInstance();
//	cout << t << " " << tt << endl;
//}