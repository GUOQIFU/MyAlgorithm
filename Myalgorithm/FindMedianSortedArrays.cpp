#include"Leetcode.h"

double FindMedianSortedArray(vector<int> &arr1, vector<int> &arr2)//在两个排序的数组中寻找中位数
{
	int length = arr1.size() + arr2.size();
	int *arr3 = new int[length];
	int i = 0, j = 0;
	int index = 0;
	while (i < arr1.size() && j < arr2.size())
	{
		arr3[index++] = arr1[i] < arr2[j] ? arr1[i++] : arr2[j++];
	}
	while (i < arr1.size())
	{
		arr3[index++] = arr1[i++];
	}
	while (j < arr2.size())
	{
		arr3[index++] = arr2[j++];
	}

	if (length % 2 == 0) return (double)(arr3[length / 2] + arr3[length / 2] - 1) / 2;
	else return (double)(arr3[length / 2]);
}