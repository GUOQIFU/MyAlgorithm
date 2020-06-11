#ifndef MYHEADFILE_H
#define MYHEADFILE_H
#include<iostream>
#include<vector>
#include<map>
using namespace std;
typedef struct ListNode_LRU {
	int m_key;//��key,value��map�洢��ʽ
	int m_value;
	ListNode_LRU *pPre;
	ListNode_LRU *pNext;
	ListNode_LRU(int key, int value)//���ƹ��캯��
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

bool LoopList_is(List List);//�ж������Ƿ��л�
ListNode *ListInsert(vector<int> vec);//����β�巨����
ListNode *ReverseList(ListNode *phead);//����ת
List FindFirstCommonNode(List List1,List list2);//������������ĵ�һ�������ڵ�
void ListCout(List List);//�������
void VectorCout(vector<int> arr);//vector���
void IntCout(int *arr, int length);
string StrCin();//�ַ�������
int WordsNumOfString(string s);//�ַ����е�����ͳ��
int LengthOfLongestSubstring(string s);//�ַ����е�����ִ�����
double sqrt1(double x);//���ֿ���
double sqrt2(double x);//ţ�ٵ���������
int GuapiJumpFloor(int n);//������̨�� ��һ�ο�����һ����������


#endif