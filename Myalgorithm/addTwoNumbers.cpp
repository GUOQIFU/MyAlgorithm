#include"myheadfile.h"
#include"Leetcode.h"

ListNode *AddTwoNumbers(ListNode *L1, ListNode *L2)//链表两数相加
{
	if (L1 == NULL || L2 == NULL) return NULL;
	ListNode *pHead = new ListNode;
	ListNode *res;
	res = pHead;
	int jinwei = 0;
	while (L1 != NULL || L2 != NULL)
	{
		res->val = (L1?L1->val:0) + (L2?L2->val:0) + jinwei;
		if (res->val >= 10)
		{
			res->val = (res->val) % 10;
			jinwei = 1;
		}
		else
		{
			jinwei = 0;
		}

		L1 = L1 ? L1->next : L1;
		L2 = L2 ? L2->next : L2;

		if (jinwei == 1 && L1->next == NULL&& L2->next==NULL)
		{
			ListNode *pInsert = new ListNode;
			pInsert->val = 1;
			pInsert->next = NULL;
			res->next = pInsert;
		}
		if ( L1 != NULL && L2 != NULL )
		{
			ListNode *pInsert = new ListNode;
			res->next = pInsert;
			res = pInsert;
		}
		else
		{
			res->next = NULL;
		}
	}
	return pHead;
}