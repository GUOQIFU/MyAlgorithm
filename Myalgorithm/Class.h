#ifndef CLASS_H
#define CLASS_H
#include<deque>//双端队列，可从队头队尾插入数据
#include<queue>//单端队列，只能对头出、队尾进
#include<vector>
#include"myheadfile.h"
class CSingleton;//单例模式

//生产者消费者模式——工厂模式
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

//LRU算法  map+循环链表实现
class LRUCache {
public:
	LRUCache(int size);
	~LRUCache();
	void InserNode(int key, int value);//插入数据，如果插入的数据原本存在，就直接适用并更新队列排序
	void SetHead(ListNode_LRU* pNode);//将节点放在头部，将最近使用的节点放在队里头部
	void Remove(ListNode_LRU* pNode);//移除节点，非删除？？
	int Get(int key);//获取缓存里的数据
	int GetSize();//获取存储容量
private:
	int m_capacity;//缓存容量
	ListNode_LRU* pHead;//头节点
	ListNode_LRU* pTail;//尾节点
	map<int, ListNode_LRU*> mp;//map存储数据，搜索时间复杂度O(1)级别
};

#endif
