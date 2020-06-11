#include"Class.h"
#include"myheadfile.h"

LRUCache::LRUCache(int size)//���캯����ʼ�������С
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
		mp.erase(it++);//ע�⣺һ��Ҫ����д��it++ ���������κ�һ���ط����ᵼ���������ʧЧ��
	}
	delete pHead;//ֻ��ɾ����ָ��ָ����ڴ�ռ�
	pHead = NULL;//��ֹҰָ��
	delete pTail;
	pTail = NULL;
}

void LRUCache::SetHead(ListNode_LRU* pNode)//���ڵ����ͷ���������ʹ�õĽڵ���ڶ���ͷ��
{
	pNode->pNext = pHead;//�����ڴ�ռ䲻�������ģ�ֻ��Ҫ��ǰ��ָ��ָ���ַ��ȷ����
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
	if (pNode->pPre == NULL && pNode->pNext != NULL)//�����ͷ�ڵ�
	{
		pHead = pNode->pNext;
		pHead->pPre = NULL;
	}
	if (pNode->pNext == NULL && pNode->pPre != NULL)//�����β�ڵ�
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

void LRUCache::InserNode(int key,int value)//�������ݣ�������������ԭ�����ڣ���ֱ�����ò����¶�������
{ //map�е�keyֵ�������ظ���ֻ����Ψһ��
	map<int, ListNode_LRU*>::iterator it = mp.find(key);//�ҵ�keyֵ��valueֵ�����û���ҵ��򷵻�mp.end()
	if (it != mp.end())
	{
		ListNode_LRU* Node = it->second;//it->first ��ָ��keyֵ��it->second��ָ��valueֵ��pair<key,value>;
		Node->m_value = value;
		Remove(Node);//���Ƴ�����֮���ٷ���ͷ�ڵ㴦
		SetHead(Node);
	}
	else {
		ListNode_LRU* NewNode = new ListNode_LRU(key, value);
		if (mp.size() >= m_capacity)//�����½ڵ��ж��Ƿ񳬹��洢����
		{
			map<int, ListNode_LRU*>::iterator it = mp.find(pTail->m_key);//β�ڵ�
			Remove(pTail);//�Ƴ�β�ڵ㣬�����½ڵ�
			delete it->second;//ɾ��value ����keyֵ
			mp.erase(it);
		}
		SetHead(NewNode);//�ŵ�ͷ�ڵ�
		mp[key] = NewNode;//map�ṹ��λ�������Ժ����O(1)������Ч��O(1)��
	}
}

int LRUCache::Get(int key)//��ȡ�����������
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

int LRUCache::GetSize()//��ȡ�洢����
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
//	void SetHead(ListNode_LRU* Node);//����ͷ�ڵ�
//	void Remove(ListNode_LRU* Node);//�ڵ���Ƴ�
//	void NodeInsert(ListNode_LRU* Node);//�½ڵ�Ĳ���
//	void GetSize();
//	void GetValue(int key);
//private:
//	int e_campicity;
//	ListNode_LRU* pHead;
//	ListNode_LRU* pTail;
//	map<int, ListNode_LRU> mp;
//};

