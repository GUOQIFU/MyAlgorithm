#include"Class.h"
#include"myheadfile.h"

LRUCache::LRUCache(int size)//构造函数初始化缓存大小
{
	m_capacity = size;
	pHead = NULL;
	pTail = NULL;
}

LRUCache::~LRUCache()
{
	map<int, ListNode_LRU*>::iterator it = mp.begin();
	for (;it != mp.end();)
	{
		delete it->second;
		it->second = NULL;
		mp.erase(it++);//注意：一定要这样写，it++ 放在其他任何一个地方都会导致其迭代器失效。
	}
	delete pHead;//只是删除了指针指向的内存空间
	pHead = NULL;//防止野指针
	delete pTail;
	pTail = NULL;
}

void LRUCache::SetHead(ListNode_LRU* pNode)//将节点放在头部，将最近使用的节点放在队里头部
{
	pNode->pNext = pHead;//链表内存空间不是连续的，只需要把前后指针指向地址明确就行
	pNode->pPre = NULL;
	if (pHead == NULL)
	{
		pHead = pNode;
	}
	else {
		pHead->pPre = pNode;
		pHead = pNode;
	}
	if (pTail == NULL)
	{
		pTail = pHead;
	}
}

void LRUCache::Remove(ListNode_LRU* pNode)//
{
	if (pNode->pPre == NULL && pNode->pNext != NULL)//如果是头节点
	{
		pHead = pNode->pNext;
		pHead->pPre = NULL;
	}
	if (pNode->pNext == NULL && pNode->pPre != NULL)//如果是尾节点
	{
		pTail = pNode->pPre;
		pTail->pNext = NULL;
	}
	if (pNode->pNext == NULL && pNode->pPre == NULL)
	{
		pHead = pNode;
		pHead = NULL;
	}
	if (pNode->pNext != NULL && pNode->pPre != NULL)
	{
		pNode->pPre->pNext = pNode->pNext;
		pNode->pNext->pPre = pNode->pPre;
	} 
}

void LRUCache::InserNode(int key,int value)//插入数据，如果插入的数据原本存在，就直接适用并更新队列排序
{ //map中的key值不能有重复，只能是唯一的
	map<int, ListNode_LRU*>::iterator it = mp.find(key);//找到key值的value值，如果没有找到则返回mp.end()
	if (it != mp.end())
	{
		ListNode_LRU* Node = it->second;//it->first 是指向key值，it->second是指向value值，pair<key,value>;
		Node->m_value = value;
		Remove(Node);//先移除掉，之后再放至头节点处
		SetHead(Node);
	}
	else {
		ListNode_LRU* NewNode = new ListNode_LRU(key, value);
		if (mp.size() >= m_capacity)//插入新节点判断是否超过存储容量
		{
			map<int, ListNode_LRU*>::iterator it = mp.find(pTail->m_key);//尾节点
			Remove(pTail);//移除尾节点，插入新节点
			delete it->second;//删除value 保留key值
			mp.erase(it);
		}
		SetHead(NewNode);//放到头节点
		mp[key] = NewNode;//map结构定位，方便以后查找O(1)，查找效率O(1)。
	}
}

int LRUCache::Get(int key)//获取缓存里的数据
{
	map<int, ListNode_LRU*>::iterator it = mp.find(key);
	if (it != mp.end())
	{
		ListNode_LRU* Node = it->second;
		Remove(Node);
		SetHead(Node);
		return Node->m_value;
	}
	else {
		return -1;
	}
}

int LRUCache::GetSize()//获取存储容量
{
	return mp.size();
}
 
//class LRU {
//public:
//	LRU(int size)
//	{
//		e_ca 
//mpicity = size;
//		pHead = NULL;
//		pTail = NULL;
//	}
//	~LRU() {};
//	void SetHead(ListNode_LRU* Node);//设置头节点
//	void Remove(ListNode_LRU* Node);//节点的移除
//	void NodeInsert(ListNode_LRU* Node);//新节点的插入
//	void GetSize();
//	void GetValue(int key);
//private:
//	int e_campicity;
//	ListNode_LRU* pHead;
//	ListNode_LRU* pTail;
//	map<int, ListNode_LRU> mp;
//};

