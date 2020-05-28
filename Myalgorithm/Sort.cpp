#include<iostream>
#include<stdio.h>
#include<vector>
#include"SortOrSearch.h"
#include"myheadfile.h"
using namespace std;

void swap(int *arr, int i, int j)
{
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}
//冒泡排序 O(n2)
void Bubble_Sort(int *arr,int length)
{
	if (length == 0) exit(1);
	for (size_t i = 0; i < length; i++)
	{
		for (size_t j = i; j < length; j++)
		{
			if (arr[i] > arr[j])
			{
				swap(arr, i, j);
			}
		}
	}
}

//选择排序 O(n2)
void Select_Sort(int *arr, int length)
{
	if (length == 0) exit(1);
	int index;
	for (size_t i = 0; i < length ; i++)
	{
		int minest = arr[i];	
		for (size_t j = i; j < length ; j++)
		{
			if (minest > arr[j])
			{
				minest = arr[j];
				index = j;
			}
		}
		int temp = arr[i];
		arr[i] = minest;
		arr[index] = temp;
	}
}

//插入排序 O(n2)
void Insert_Sort(int *arr,int length)
{
	if (length == 0) exit(1);
	for (size_t i = 0; i < length - 1; i++)
	{
		int preindex = i;
		int curent = arr[i+1];
		while (preindex >= 0 && curent < arr[preindex])
		{
			arr[preindex + 1] = arr[preindex];
			preindex--;
		}
		arr[preindex + 1] = curent;
	}
}
//希尔排序 O（nlogn）
void Shell_Sort(int *arr,int length)
{
	if (length == 0) exit(1);
	int gap = length / 2;
	
	while (gap > 0)
	{
		for (size_t i = 0; i < length - gap; i++)
		{
			int preindex = i;
			int curent = arr[i+gap];//curent为后面的值
			
			while (preindex >= 0 && curent < arr[preindex])
			{
				arr[preindex +gap] = arr[preindex];
				preindex = preindex - gap;
			}
			arr[preindex + gap] = curent;
		}
		gap = gap / 2;
	}
}

//归并排序 O(nlogn)
void Merge_Sort(int *arr, int left, int mid, int right)
{
	int length = right - left + 1;
	int *arr1 = new int[length];
//	memset(arr1, 0, length * sizeof(int));  
	int index = 0;
	int i = left,j = mid +1;
	//int j = left;
	while(i <= mid && j <= right)
	{
		arr1[index++] = arr[i] < arr[j] ? arr[i++] : arr[j++];
	}
	while (i <= mid)
	{
		arr1[index++] = arr[i++];
	}
	while (j <= right)
	{
		arr1[index++] = arr[j++];
	}
	for (size_t i = 0; i < length; i++)
	{
		arr[left++] = arr1[i];
	}
}

void Merge(int *arr, int left, int right)
{
	if (left == right) exit(1);
	int mid = left + ((right - left) / 2);
	if (left < right)
	{
		Merge(arr, left, mid);
		Merge(arr, mid + 1, right);
	}
	Merge_Sort(arr, left, mid, right);
}

//快速排序 O(nlogn)
int GetIndex(int *arr, int left, int right)
{
	if (left > right)  exit(1);
	int curent = arr[left];
	while (left < right)
	{
		while (left < right && curent <= arr[right])
			right--;
		arr[left] = arr[right];//挖坑 vec[right]
		while (left < right && curent >= arr[left])
			left++;
		arr[right] = arr[left];//填坑 vec[right]  挖坑 vec[left]
	}
	arr[left] = curent;//填坑 vec[left]
	return left;
}

void Quick_Sort(int *arr,int left,int right)
{
	if (left > right) exit(1);
	if (left < right)
	{
		int index = GetIndex(arr, left, right);
		Quick_Sort(arr, 0, index - 1);
		Quick_Sort(arr, index + 1, right);
	}
}

//计数排序 O（n+k）
void Count_Sort(int *arr,int length)
{
	if (length == 0) exit(1);
	int maxvalue = arr[0];
	int minvalue = arr[0];
	for (size_t i = 0; i < length; i++)
	{
		if (maxvalue < arr[i])
		{
			maxvalue = arr[i];
		}
		if (minvalue > arr[i])
		{
			minvalue = arr[i];
		}	
	}
	int length1 = maxvalue - minvalue + 1;
	int *newarr = new int[length1];//申请合适的数组内存空间
	//memset(newarr, 0, sizeof(int)*length1);//将新数组全部置为0
	for (size_t i = 0; i < length1; i++)
	{
		newarr[i] = 0;
	}
	int index = 0;
	for (size_t i = 0; i < length; i++)
	{
	    index = arr[i] - minvalue;
		newarr[index]++;
	}
	index = 0;
	for (size_t i = 0; i < length1; i++)
	{
		while (newarr[i]--)
		{
			arr[index++] = i + minvalue;
		}
	}
	delete newarr;
}

//堆排序
void heap_Adjust(int *arr, int i, int length)
{
	//int temp = arr[i];
	for(int left = 2 * i + 1; left < length; left = 2 * left + 1)
	{
		int right = left + 1;
		if (right < length && arr[left] < arr[right])//如果右节点大于左节点
		{
			left++;
		}
		if (arr[i] < arr[left])
		{
		//	arr[i] = arr[left];
			swap(arr, i, left);
			i = left;
		}
		else {
			break;
		}
	//	arr[i] = temp;
	}
}
void heap_Sort(int *arr, int length)
{
	if (length == 0) exit(1);
	for (int i = (length / 2) - 1 ; i >= 0; i--)
	{
		heap_Adjust(arr,i,length);
	}
	while (length > 0)
	{
		swap(arr, 0, length-1);
		length--;
		heap_Adjust(arr, 0,length);
	}
}