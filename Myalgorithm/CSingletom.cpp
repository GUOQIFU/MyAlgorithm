#include<iostream>
#include "Class.h"
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
CSingleton *CSingleton::p = NULL;

//int main()
//{
//	CSingleton *t = CSingleton::GetInstance();
//	CSingleton *tt = CSingleton::GetInstance();
//	cout << t << " " << tt << endl;
//}