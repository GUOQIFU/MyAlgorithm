#include<iostream>
#include<stdio.h>
#include<vector>
#include"SortOrSearch.h"
#include"myheadfile.h"
//˳�����
int SequenceSearch(int *arr, int value,int length)
{
	if (length == 0) exit(1);
	for (size_t i = 0; i < length; i++)
	{
		if (arr[i] == value) return i;
	}
}
//���ֲ���
int BinarySearch(int *arr, int value, int length)
{
	if (length == 0) exit(1);
	int low = 0, high = length - 1;
	while (low < high)
	{
		int mid = low + (high - low) / 2;
		if (value == arr[mid]) return mid;
		if (value < arr[mid]) high = mid - 1;
		if (value > arr[mid]) low = mid + 1;
	}
	return -1;
}
//�������
int InsertionSearch(int *arr, int value, int length)
{
	if (length == 0) exit(1);
	int low = 0, high = length - 1;
	while (low < high)
	{
		int mid = low + (value - arr[low]) / (arr[high] - value) * (high - low);
		if (value == arr[mid]) return mid;
		if (value < arr[mid]) high = mid - 1;
		if (value > arr[mid]) low = mid + 1;
	}
	return -1;
}

//쳲���������
int F(int n)//����쳲���������
{
	int *F = new int[n+1];
	F[0] = 0; 
	F[1] = 1;
	for (size_t i = 2; i <= n; i++)
	{
		F[i] = F[i - 1] + F[i - 2];
	}
	return F[n];
}

int FibonacciSearch(int *arr, int value, int length)
{
	if (length == 0) exit(1);
	int n = 0;
	while (length > F(n))//����������쳲��������е�λ��
	{
		n++;
	}
	int *arr1 = new int[F(n) - 1];
	memcpy(arr1, arr, length * sizeof(int));

	for (size_t i = length; i < F(n) - 1; i++)
	{
		arr1[i] = arr[length - i];//���½������鲹��
	}

	int low = 0, high = length - 1;
	while (low <= high)
	{
		int mid = low + F(n-1) - 1;
		if (value == arr1[mid]) return mid;
		if (value < arr1[mid])
		{
			high = mid - 1;
			n = n - 1;
		}
		if (value > arr1[mid])
		{
			low = mid + 1;
			n = n - 2;
		}
	}
}