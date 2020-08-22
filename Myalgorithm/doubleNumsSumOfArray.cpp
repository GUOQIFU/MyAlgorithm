#include"myheadfile.h"
#include"Leetcode.h"

vector<int> DoubleNumSumOfArray(vector<int> &arr, int target)
{
	if (arr.size() == 0) return arr;
	vector<int> res;
	for (int i = 0; i < arr.size(); i++)
	{
		for (size_t j = arr.size() - 1; j > i; j--)
		{
			if (arr[i] + arr[j] == target)
			{
				res.push_back(i);
				res.push_back(j);
			}
		}
	}
	return res;
}