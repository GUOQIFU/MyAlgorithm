#pragma once
#ifndef LEETCODE_H
#define LEETCODE_H

#include"myheadfile.h"

ListNode *ReverseList(ListNode *phead);//链表反转
ListNode *ReverseList2(ListNode *head);//链表反转 递归
List FindFirstCommonNode(List List1, List list2);//查找两个链表的第一个公共节点
int GuapiJumpFloor(int n);//青蛙跳台阶 跳一次可以跳一步或者两步
int WordsNumOfString(string s);//字符串中单词数统计
int LengthOfLongestSubstring(string s);//字符串中的最大字串长度
vector<int> DoubleNumSumOfArray(vector<int> &arr, int target);//两数之和
ListNode *AddTwoNumbers(ListNode *L1, ListNode *L2);//链表两数相加
double FindMedianSortedArray(vector<int> &arr1, vector<int> &arr2);//在两个排序的数组中寻找中位数

int MinPathSum(vector<vector<int>> &grid);//矩阵最小路径，动态规划
vector<vector<int>> permute(vector<int> &arr);//返回全排列
vector<vector<string>>SolveNQueens(int n);//N皇后问题
int maxProfit_1(vector<int> &price);//股票最大利润问题,1次交易
int maxProfit_2(vector<int> &price);//股票最大利润问题，2次交易
int maxProfit_more(vector<int> &price);//股票最大利润问题，多次交易
vector<int> VecBjianVecA(vector<int> &A,vector<int> &B);//两个数组A,B，A有的B都有，求B-A

#endif // !LEETCODE_H
