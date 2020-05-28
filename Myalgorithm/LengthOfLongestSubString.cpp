#include<iostream>
#include<string>
#include"myheadfile.h"

int LengthOfLongestSubstring(string s)
{
	int maxvalue = 0;
	for (size_t i = 0; i < s.length(); i++)//找到s中最大值
	{
		maxvalue = maxvalue > s[i] ? maxvalue : s[i];
	}
	bool *mark = new bool[maxvalue + 1];
	for (size_t i = 0; i <= maxvalue; i++)
	{
		mark[i] = false;
	}
	int i = 0, j = 0;
	int maxnum = 0;
	while (i < s.length() && j < s.length())
	{
		if (!mark[s[i]])
		{
			mark[s[i]] = true;
			i++;
			maxnum = maxnum > (i - j) ? maxnum : (i - j);//滑动窗口性质
		}
		else
		{
			mark[s[i]] = false;
			j++;
		}	
	}
	return maxnum;
}