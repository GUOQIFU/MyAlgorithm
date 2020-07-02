#include<iostream>
#include<stdio.h>
#include<vector>
#include"SortOrSearch.h"
#include"myheadfile.h"
using namespace std;

void swap(vector<int> &arr, int i, int j)//������
{
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

//void swap(vector<int> *arr, int i, int j)//��ָ��
//{
//	int temp = (*arr)[i];
//	(*arr)[i] = (*arr)[j];
//	(*arr)[j] = temp;
//	arr->size();
//}

//ð������ O(n2)
void Bubble_Sort(vector<int> &arr)//����������ڻ�ȡ�����Ա;��ͷ��������ڻ�ȡָ��ָ��Ķ���ĳ�Ա��
{
	if (arr.empty()) exit(1);
	int temp = arr[0];
	for (size_t i = 0; i < arr.size(); i++)
	{
		for (size_t j = i; j < arr.size(); j++)
		{
			if (arr[i] > arr[j])
			{
				swap(arr, i, j);
			}
		}
	}
}

//ѡ������ O(n2)
void Select_Sort(vector<int> &arr)
{
	if (arr.empty()) exit(1);
	int index;
	for (size_t i = 0; i < arr.size() ; i++)
	{
		int minest = arr[i];	
		for (size_t j = i; j < arr.size() ; j++)
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

//�������� O(n2)
void Insert_Sort(vector<int> &arr)
{
	if (arr.empty()) exit(1);
	for (size_t i = 0; i < arr.size() - 1; i++)
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
//ϣ������ O��nlogn��
void Shell_Sort(vector<int> &arr)
{
	if (arr.empty()) return;
	int gap = arr.size() / 2;
	
	while (gap > 0)
	{
		for (size_t i = 0; i < arr.size() - gap; i++)
		{
			int preindex = i;
			int curent = arr[i+gap];//curentΪ�����ֵ
			
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

//�鲢���� O(nlogn)
void Merge_Sort(vector<int> &arr, int left, int mid, int right)
{
	int length = right - left + 1;
	int *arr1 = new int[length];
	memset(arr1, 0, length * sizeof(int));  
	int index = 0;
	int i = left, j = mid + 1;
	//int j = left;
	while (i <= mid && j <= right)
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
void Merge(vector<int> &arr, int left, int right)
{
	if (left == right) return;
	int mid = left + ((right - left) / 2);
	
		Merge(arr, left, mid);
		Merge(arr, mid + 1, right);

	Merge_Sort(arr, left, mid, right);
}


//�������� O(nlogn)
int GetIndex(vector<int> &arr, int left, int right)
{
	if (left > right)  return 0;
	int curent = arr[left];
	while (left < right)
	{
		while (left < right && curent <= arr[right])
			right--;
		arr[left] = arr[right];//�ڿ� vec[right]
		while (left < right && curent >= arr[left])
			left++;
		arr[right] = arr[left];//��� vec[right]  �ڿ� vec[left]
	}
	arr[left] = curent;//��� vec[left]
	return left;
}

void Quick_Sort(vector<int> &arr,int left,int right)
{
	if (left > right) return;
	if (left < right)
	{
		int index = GetIndex(arr, left, right);
		Quick_Sort(arr, 0, index - 1);
		Quick_Sort(arr, index + 1, right);
	}
}

//�������� O��n+k��
void Count_Sort(vector<int> &arr)
{
	if (arr.empty()) return;
	int maxvalue = arr[0];
	int minvalue = arr[0];
	for (size_t i = 0; i < arr.size(); i++)
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
	int *newarr = new int[length1];//������ʵ������ڴ�ռ�
	//memset(newarr, 0, sizeof(int)*length1);//��������ȫ����Ϊ0
	for (size_t i = 0; i < length1; i++)
	{
		newarr[i] = 0;
	}
	int index = 0;
	for (size_t i = 0; i < arr.size(); i++)
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

//������
void heap_Adjust(vector<int> &arr, int i, int length)
{
	int temp = arr[i];
	for(int left = 2 * i + 1; left < length; left = 2 * left + 1)
	{
		int right = left + 1;
		if (right < length && arr[left] < arr[right])//����ҽڵ������ڵ�
		{
			left++;
		}
		if (arr[i] < arr[left])
		{
			arr[i] = arr[left];
		//	swap(arr, i, left);
			i = left;
		}
		else {
			break;
		}
		arr[i] = temp;
	}
}

void heap_Sort(vector<int> &arr)
{
	//if (arr.empty()) return;
	int size = arr.size();
	for (int i = (size / 2) - 1 ; i >= 0; i--)
	{
		heap_Adjust(arr,i, size);
	}
	while (size > 0)
	{
		swap(arr, 0, size - 1);
		size--;
		heap_Adjust(arr, 0, size);
		
	}
}