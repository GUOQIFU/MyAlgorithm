#include<iostream>
#include<vector>
#include"myheadfile.h"

ListNode *ListInsert(vector<int> vec)
{
	if (vec.empty()) exit(1);
	List phead;
	ListNode  *pInsert, *q;
	phead = new ListNode;
	q = phead;//ͷ�ڵ�������
	for (size_t i = 0; i < vec.size(); i++)
	{
		q->val = vec[i];
		pInsert = new ListNode;
		if (i == vec.size() - 1)//ע���������
		{
			//q->next = phead;//����
			q->next = NULL;
			break;
		}
		else
		{
			q->next = pInsert;
			q = pInsert;
		}
	}
	return phead;
}