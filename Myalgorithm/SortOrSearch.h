#ifndef SORTORSEARCH_H
#define SORTORSEARCH_H
#include<iostream>
#include<string>
#include<vector>
using namespace std;
void Bubble_Sort(int *arr, int length);
void Select_Sort(int *arr, int length);
void Insert_Sort(int *arr,int length);
void Shell_Sort(int *arr,int length);
void Merge_Sort(int *arr, int left,int mid, int right);
void Merge(int *arr, int left, int right);
void Quick_Sort(int *arr,int left,int right);
void heap_Sort(int *arr,int length);
void Count_Sort(int *arr,int length);
void SequenceSearch(int *arr, int value);
void BinarySearch(int *arr, int value);
void InsertionSearch(int *arr, int value);
void FibonacciSearch(int *arr, int value);

#endif
