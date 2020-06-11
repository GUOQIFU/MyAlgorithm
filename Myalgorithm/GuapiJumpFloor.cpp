#include<iostream>
#include<stdio.h>
#include<vector>
#include"SortOrSearch.h"
#include"myheadfile.h"

int GuapiJumpFloor(int n)//ì³²¨À­ÆõÊýÁÐ
{
	int *vec = new int[n + 1];
	 vec[0] = 0;
     vec[1] = 1;
	 vec[2] = 2;
	for (int i = 3; i <= n; i++)
	{
		vec[i] = vec[i - 1] + vec[i - 2];
	}
	return vec[n];
}