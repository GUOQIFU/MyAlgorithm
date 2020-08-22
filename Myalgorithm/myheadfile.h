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

bool LoopList_is(List List);//�ж������Ƿ��л�
ListNode *ListInsert(vector<int> vec);//����β�巨����

void ListCout(List List);//�������
void VectorCout(vector<int> arr);//vector���
void DoubleVectorCout(vector<vector<int>> &vec);

void StringCout(string s);
void StrCout(const char *str);
void IntCout(int *arr, int length);
string StrCin();//�ַ�������

double sqrt1(double x);//���ֿ���
double sqrt2(double x);//ţ�ٵ���������

char *my_strcpy(char *deststr,const char *str);
char *my_strcat(char *deststr, const char *str);
int my_strlen(const char *str);
void *my_memcpy(void *deststr, const void *str,size_t count);
//char *mymecpy(char *deststr, const char *str, size_t count);



#endif