#include<iostream>
#include<vector>
#include"myheadfile.h"

void ListCout(List List)
{
	ListNode *p;
	p = List;
	while (p != NULL)
	{
		cout << p->val << " ";
		p = p->next;
	}
	cout << "\n";
	p = List;
	ListNode *ReList = ReverseList(p);//·­×ªÁ´±í
	while (ReList != NULL)
	{
		cout << ReList->val << " ";
		ReList = ReList->next;
	}
}
void VectorCout(vector<int> arr)
{
	for (size_t i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << ' ';
	}
}

void StringCout(string s)
{
	for (size_t i = 0; i < s.length(); i++)
	{
		cout << s[i];
	}
	cout << endl;
}

void StrCout(const char *str)
{
	int length = strlen(str);
	for (size_t i = 0; i < length; i++)
	{
		cout << str[i];
	}
	cout << endl;
}


void IntCout(int *arr,int length)
{
	for (size_t i = 0; i < length; i++)
	{
		cout << arr[i] << ' ';
	}
}



