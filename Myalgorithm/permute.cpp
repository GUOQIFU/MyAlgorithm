#include"Leetcode.h"
#include<algorithm>

static vector<vector<int>> res;

static void backtrace(vector<int> &output, int first,int len)
{
	if (first == len)
	{
		res.push_back(output);//�ݹ鵽���һ���Ž��������ͽ����ķ���������
		return;
	}
	for (int i = first; i < len; i++)
	{
		swap(output[i],output[first]);//����ѡ��֮�󣬽���ݹ�
		backtrace(output, first + 1, len);
		swap(output[i],output[first]);//�ݹ�֮�󣬷��������״̬��������Ҫ��֮ǰ�Ĳ������г����������ֲ���
	}
}

vector<vector<int>> permute(vector<int> &arr)//����ȫ����
{
	backtrace(arr, 0, arr.size());
	return res;
}
