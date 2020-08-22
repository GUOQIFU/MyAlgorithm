#include"Leetcode.h"
#include<algorithm>

static vector<vector<int>> res;

static void backtrace(vector<int> &output, int first,int len)
{
	if (first == len)
	{
		res.push_back(output);//递归到最后一步才将排列推送进最后的返回数组中
		return;
	}
	for (int i = first; i < len; i++)
	{
		swap(output[i],output[first]);//作好选择之后，进入递归
		backtrace(output, first + 1, len);
		swap(output[i],output[first]);//递归之后，返回最初的状态，所以需要对之前的操作进行撤销，或者弥补。
	}
}

vector<vector<int>> permute(vector<int> &arr)//返回全排列
{
	backtrace(arr, 0, arr.size());
	return res;
}
