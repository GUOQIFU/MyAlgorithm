#include<iostream>
#include<stdio.h>
#include "myheadfile.h"
using namespace std;

 ListNode *ReverseList(ListNode *phead)//Á´±í·´×ª
 {
	 if (phead == NULL) return NULL;
	 ListNode *pCurent, *pre, *pNext;
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