
#ifndef MYHEADFILE_H
#define MYHEADFILE_H
#include<iostream>
#include<vector>
using namespace std;

const struct ListNode {
	int val;
	struct ListNode *next;
};
bool LoopList_is(ListNode *List);//�ж������Ƿ��л�
ListNode *ListInsert(vector<int> vec);//����β�巨����
ListNode *ReverseList(ListNode *phead);//����ת
void ListCout(ListNode *List);//�������
void VectorCout(int *arr, int length);//vector���
string StrCin();//�ַ�������
int WordsNumOfString(string s);//�ַ����е�����ͳ��
int LengthOfLongestSubstring(string s);//�ַ����е�����ִ�����
#endif