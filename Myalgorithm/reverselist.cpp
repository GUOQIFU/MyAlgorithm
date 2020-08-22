#include<iostream>
#include<stdio.h>
#include "myheadfile.h"
using namespace std;

 ListNode *ReverseList(ListNode *phead)//链表反转
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

 //用递归的方法反转链表
 ListNode *ReverseList2(ListNode *head) 
 {
	 if (head == NULL || head->next == NULL) 
	 {
		 return head;
	 }
	 // 递归反转 子链表
	 ListNode *newList = ReverseList2(head->next);

	 // 改变当前节点的指向，注意 Head 节点的返回是在那一层
	 ListNode *t1 = head->next;
	 // 让 2 的 next 指向 2
	 t1->next = head;
	 // 1 的 next 指向 null.
	 head->next = NULL;
	 // 把调整之后的链表返回。
	 return newList;
 }