#include<iostream>
#include<stdio.h>
#include<vector>
#include"SortOrSearch.h"
#include"myheadfile.h"

double sqrt1(double x)
{
	if (x == 0) return 0;
	double JINGDU = 0.0001;
	double low = 0.0;
	double high = x;
	double mid = (low + high) / 2;
	while ((high - low) > JINGDU)
	{
		if (mid * mid > x)
		{
			high = mid;
		}
		else {
			low = mid;
		}
		mid = (low + high) / 2;
	}
	return mid;
}

double sqrt2(double n)
{
	if (n == 0) return 0;
	double last = 0.01;
	double x = 1.0;
	while (x < last)
	{
		last = x;
		x = (x + n / x) / 2;//Å£¶Ùµü´ú·¨
	}
	return x;
}