#ifndef CLASS_H
#define CLASS_H
#include<deque>//˫�˶��У��ɴӶ�ͷ��β��������
#include<queue>//���˶��У�ֻ�ܶ�ͷ������β��
#include<vector>
#include"myheadfile.h"
class CSingleton;//����ģʽ

//������������ģʽ��������ģʽ
//template<typename T>
//class Factory {
//public:
//	void produce(T item);
//	T consume();
//	void clear();
//	void configure(int cap, bool log = false);
//private:
//	vector<T> _factory;
//	int _size = 5;
//	bool logEnable = false;
//};

//LRU�㷨  map+ѭ������ʵ��
class LRUCache {
public:
	LRUCache(int size);
	~LRUCache();
	void InserNode(int key, int value);//�������ݣ�������������ԭ�����ڣ���ֱ�����ò����¶�������
	void SetHead(ListNode_LRU* pNode);//���ڵ����ͷ���������ʹ�õĽڵ���ڶ���ͷ��
	void Remove(ListNode_LRU* pNode);//�Ƴ��ڵ㣬��ɾ������
	int Get(int key);//��ȡ�����������
	int GetSize();//��ȡ�洢����
private:
	int m_capacity;//��������
	ListNode_LRU* pHead;//ͷ�ڵ�
	ListNode_LRU* pTail;//β�ڵ�
	map<int, ListNode_LRU*> mp;//map�洢���ݣ�����ʱ�临�Ӷ�O(1)����
};

#endif
