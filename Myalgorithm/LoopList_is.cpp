#include<iostream>
#include<string>
#include"myheadfile.h"

bool LoopList_is(List List)//¿ìÂýÖ¸Õë
{
	if (!List) return false;
	ListNode *slowPointer, *fastpointer;
	slowPointer = fastpointer = List;
	while (slowPointer != NULL && fastpointer != NULL)
	{
		slowPointer = slowPointer->next;
		fastpointer = fastpointer->next->next;
		if (slowPointer == fastpointer)
			return true;
	}
	return false;
}

