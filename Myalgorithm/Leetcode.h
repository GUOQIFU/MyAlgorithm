#pragma once
#ifndef LEETCODE_H
#define LEETCODE_H

#include"myheadfile.h"

ListNode *ReverseList(ListNode *phead);//����ת
ListNode *ReverseList2(ListNode *head);//����ת �ݹ�
List FindFirstCommonNode(List List1, List list2);//������������ĵ�һ�������ڵ�
int GuapiJumpFloor(int n);//������̨�� ��һ�ο�����һ����������
int WordsNumOfString(string s);//�ַ����е�����ͳ��
int LengthOfLongestSubstring(string s);//�ַ����е�����ִ�����
vector<int> DoubleNumSumOfArray(vector<int> &arr, int target);//����֮��
ListNode *AddTwoNumbers(ListNode *L1, ListNode *L2);//�����������
double FindMedianSortedArray(vector<int> &arr1, vector<int> &arr2);//�����������������Ѱ����λ��

int MinPathSum(vector<vector<int>> &grid);//������С·������̬�滮
vector<vector<int>> permute(vector<int> &arr);//����ȫ����
vector<vector<string>>SolveNQueens(int n);//N�ʺ�����
int maxProfit_1(vector<int> &price);//��Ʊ�����������,1�ν���
int maxProfit_2(vector<int> &price);//��Ʊ����������⣬2�ν���
int maxProfit_more(vector<int> &price);//��Ʊ����������⣬��ν���
vector<int> VecBjianVecA(vector<int> &A,vector<int> &B);//��������A,B��A�е�B���У���B-A

#endif // !LEETCODE_H
