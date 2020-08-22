#include"Leetcode.h"

vector<int> VecBjianVecA(vector<int> &A, vector<int> &B)
{
	if (A.size() == 0) return B;
	int maxvalue = B[0];
	for (int i = 1; i < B.size(); i++)
	{
		if (maxvalue < B[i])
			maxvalue = B[i];
	}
	int *vec = new int[maxvalue + 1];
	//memset(vec,0,sizeof(int)*4);
	for (size_t i = 0; i < maxvalue+1; i++)
	{
		vec[i] = 0;
	}
	for (size_t i = 0; i < A.size(); i++)
	{
		vec[A[i]]++;
	}

	vector<int> res;
	int j = 0;
	for (size_t i = 0; i < B.size(); i++)
	{
		if (vec[B[i]] != 1)
		{
			res.push_back(B[i]);
		}
	}
	return res;
}