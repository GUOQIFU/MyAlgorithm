#include<iostream>
#include<vector>
#include"myheadfile.h"

void ListCout(ListNode *List)
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
void VectorCout(int *arr,int length)
{
	for (size_t i = 0; i <= length; i++)
	{
		cout << arr[i] << ' ';
	}
}
