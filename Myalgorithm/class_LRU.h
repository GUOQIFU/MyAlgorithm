#ifndef CLASS_H
#define CLASS_H
#include<deque>//˫�˶��У��ɴӶ�ͷ��β��������
#include<queue>//���˶��У�ֻ�ܶ�ͷ������β��
#include<vector>
#include"myheadfile.h"
#include"thread_Lock.h"

typedef struct ListNode_LRU {
	int m_key;//��key,value��map�洢��ʽ
	int m_value;
	ListNode_LRU *pPre;
	ListNode_LRU *pNext;
	//ListNode_LRU(int key, int value)//���ƹ��캯��
	//{
	//	m_key = key;
	//	m_value = value;
	//	pPre = NULL;
	//	pNext = NULL;
	//};
};

//LRU�㷨  map+ѭ������ʵ��
class LRUCache {
public:
	LRUCache(int size);
	~LRUCache();
	void InserNode(int key, int value);//�������ݣ�������������ԭ�����ڣ���ֱ�����ò����¶�������
	void SetHead(ListNode_LRU* pNode);//���ڵ����ͷ���������ʹ�õĽڵ���ڶ���ͷ��
	void Remove(ListNode_LRU* pNode);//�Ƴ��ڵ�
	int Get(int key);//��ȡ�����������
	int GetSize();//��ȡ�洢����
	void LRUCOUT();//���յ�ǰ����洢˳�����
private:
	int m_capacity;//��������
	ListNode_LRU* pHead;//ͷ�ڵ�
	ListNode_LRU* pTail;//β�ڵ�
	map<int, ListNode_LRU*> mp;//map�洢���ݣ�����ʱ�临�Ӷ�O(1)����
};
#endif
