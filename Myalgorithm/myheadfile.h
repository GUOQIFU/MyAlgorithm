
#ifndef MYHEADFILE_H
#define MYHEADFILE_H
#include<iostream>
#include<vector>
using namespace std;

const struct ListNode {
	int val;
	struct ListNode *next;
};
bool LoopList_is(ListNode *List);//判断链表是否有环
ListNode *ListInsert(vector<int> vec);//链表尾插法插入
ListNode *ReverseList(ListNode *phead);//链表反转
void ListCout(ListNode *List);//链表输出
void VectorCout(int *arr, int length);//vector输出
string StrCin();//字符串输入
int WordsNumOfString(string s);//字符串中单词数统计
int LengthOfLongestSubstring(string s);//字符串中的最大字串长度
#endif