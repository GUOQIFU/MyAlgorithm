#ifndef SORTORSEARCH_H
#define SORTORSEARCH_H
#include<iostream>
#include<string>
#include<vector>
using namespace std;
void swap(vector<int> &arr, int i, int j);
void Bubble_Sort(vector<int> &vec);
void Select_Sort(vector<int> &vec);
void Insert_Sort(vector<int> &vec);
void Shell_Sort(vector<int> &vec);
void Merge_Sort(vector<int> &vec, int left,int mid, int right);
void Merge(vector<int> &vec, int left, int right);
void Quick_Sort(vector<int> &vec,int left,int right);
void heap_Sort(vector<int> &vec);
void Count_Sort(vector<int> &vec);
int SequenceSearch(int *arr, int value,int length);
int BinarySearch(int *arr, int value,int length);
int InsertionSearch(int *arr, int value,int length );
int FibonacciSearch(int *arr, int value,int length);
#endif
