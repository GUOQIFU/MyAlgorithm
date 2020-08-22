#include<iostream>
#include<stdio.h>
#include<vector>
#include"SortOrSearch.h"
#include"myheadfile.h"
#include"Leetcode.h"

int GuapiJumpFloor(int n)//ì³²¨À­ÆõÊýÁÐ
{
	int *vec = new int[n + 1];
	if( n >= 0) vec[0] = 0;
    if( n >= 1) vec[1] = 1;
	if( n >= 2) vec[2] = 2;
	for (int i = 3; i <= n; i++)
	{
		vec[i] = vec[i - 1] + vec[i - 2];
	}
	return vec[n];
}