#include<iostream>
#include<stdio.h>
#include<vector>
#include"SortOrSearch.h"
#include"myheadfile.h"
List FindFirstCommonNode(List list1, List list2)
{
	List list_1 = list1;
	int list1_length = 0, list2_length = 0;
	while (list1 != NULL)
	{
		list1_length++;
		list1 = list1->next;
	}
	while (list2_length != NULL)
	{
		list2_length++;
		list2 = list2->next;
	}
	if (list2_length > list1_length)//如果2的长度大于1，那么交换，否则不换。
	{
		list1 = list2;
		list2 = list_1;
	}
	int sub_length = list1_length > list2_length ? (list1_length - list2_length) : 
		                                           (list2_length - list1_length);
	                                              //寻找长的数量，让长链表先走
	for (size_t i = 0; i < sub_length; i++)
	{
		list1 = list1->next;
	}
	while (list1 != list2)
	{
		list1 = list1->next;
		list2 = list2->next;
	}
	if (list1 == NULL) return 0;
	else return list1;
}