#ifndef MYHEADFILE_H
#define MYHEADFILE_H
#include<iostream>
#include<stdio.h>
#include<vector>
#include<map>
#include<stack>
#include<queue>
#include<string>
#include<assert.h>
#include<stdlib.h>
#include<algorithm>
#include"Tree.h"
#include"thread_Lock.h"
#include"SortOrSearch.h"


using namespace std;

typedef struct ListNode {
	int val;
	struct ListNode *next;
}ListNode,*List;

bool LoopList_is(List List);//判断链表是否有环
ListNode *ListInsert(vector<int> vec);//链表尾插法插入

void ListCout(List List);//链表输出
void VectorCout(vector<int> arr);//vector输出
void DoubleVectorCout(vector<vector<int>> &vec);

void StringCout(string s);
void StrCout(const char *str);
void IntCout(int *arr, int length);
string StrCin();//字符串输入

double sqrt1(double x);//二分开方
double sqrt2(double x);//牛顿迭代法开方

char *my_strcpy(char *deststr,const char *str);
char *my_strcat(char *deststr, const char *str);
int my_strlen(const char *str);
void *my_memcpy(void *deststr, const void *str,size_t count);
//char *mymecpy(char *deststr, const char *str, size_t count);



#endif