#include<iostream>
#include<stdio.h>
#include"myheadfile.h"

int WordsNumOfString(string s)
{
	if (s.empty()) return 0;
	int count = 0;
	for (size_t i = 0; i < s.length(); i++)
	{
		if ((s[i] >= 'a' && s[i] <= 'z' )||( s[i] >= 'A' && s[i] <= 'Z'))
		{
			count++;
			while (((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) && s[i] != '\0')
			{
				i++;
			}
		}
	}
	return count;
}