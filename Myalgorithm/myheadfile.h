#ifndef MYHEADFILE_H
#define MYHEADFILE_H
#include<iostream>
#include<vector>
#include<map>
using namespace std;
typedef struct ListNode_LRU {
	int m_key;//（key,value）map存储格式
	int m_value;
	ListNode_LRU *pPre;
	ListNode_LRU *pNext;
	ListNode_LRU(int key, int value)//类似构造函数
	{
		m_key = key;
		m_value = value;
		pPre = NULL;
		pNext = NULL;
	};
};
typedef struct ListNode {
	int val;
	struct ListNode *next;
}ListNode,*List;

bool LoopList_is(List List);//判断链表是否有环
ListNode *ListInsert(vector<int> vec);//链表尾插法插入
ListNode *ReverseList(ListNode *phead);//链表反转
List FindFirstCommonNode(List List1,List list2);//查找两个链表的第一个公共节点
void ListCout(List List);//链表输出
void VectorCout(vector<int> arr);//vector输出
void IntCout(int *arr, int length);
string StrCin();//字符串输入
int WordsNumOfString(string s);//字符串中单词数统计
int LengthOfLongestSubstring(string s);//字符串中的最大字串长度
double sqrt1(double x);//二分开方
double sqrt2(double x);//牛顿迭代法开方
int GuapiJumpFloor(int n);//青蛙跳台阶 跳一次可以跳一步或者两步


#endif