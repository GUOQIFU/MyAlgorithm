#include<iostream>
#include<stdio.h>
#include "myheadfile.h"
using namespace std;

 ListNode *ReverseList(ListNode *phead)//����ת
 {
	 if (phead == NULL) return NULL;
	 ListNode *pCurent , *pre, *pNext;
	pCurent = phead;
	 pre = NULL;
	 while (pCurent != NULL)
	 {
		 pNext = pCurent->next;
		 if (pNext == NULL)
		 {
			 pCurent->next = pre;
			 return pCurent;
		 }
		 pCurent->next = pre;
		 pre = pCurent;
		 pCurent = pNext;
	 }
 }

 //�õݹ�ķ�����ת����
 ListNode *ReverseList2(ListNode *head) 
 {
	 if (head == NULL || head->next == NULL) 
	 {
		 return head;
	 }
	 // �ݹ鷴ת ������
	 ListNode *newList = ReverseList2(head->next);

	 // �ı䵱ǰ�ڵ��ָ��ע�� Head �ڵ�ķ���������һ��
	 ListNode *t1 = head->next;
	 // �� 2 �� next ָ�� 2
	 t1->next = head;
	 // 1 �� next ָ�� null.
	 head->next = NULL;
	 // �ѵ���֮��������ء�
	 return newList;
 }