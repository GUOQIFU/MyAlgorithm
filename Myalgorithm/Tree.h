#pragma once
#ifndef BITTREE_H
#define BITTREE_H
#include<iostream>
#include<vector>
using namespace std;

typedef struct TreeNode
{
	int value;
	struct  TreeNode *Lchild;
	struct  TreeNode *Rchild;
}TreeNode,*BiTree;

class Guo_Tree //����洢�����Ǳ���ƽ�⣬�Ǳ�������
{
public:
	Guo_Tree()
	{
	}
	~Guo_Tree()
	{}
	void Pre_CreatBiTree_Cin(BiTree &T);
	void Pre_CreatBitree_arr(BiTree &T, vector<int> &arr, int index);
	void InsertBiTreeNode(BiTree &T, int value);//β ����
};

class Guo_SearchTree
{
public:
	Guo_SearchTree()
	{}
	~Guo_SearchTree()
	{}
	int InsertSerchTreeNode(BiTree &T, int value);//���������� ����
	TreeNode * SearchValue(BiTree &T, int value);
	void DeleteSerchNode(BiTree &T,int value);
};

TreeNode *NewTreeNode(int value);//�½ڵ�
void Pre_OrderTraverse(BiTree &T);//ǰ�����
void Mid_OrderTraverse(BiTree &T);//�������
void Back_OrderTraverse(BiTree &T);//�������
void Pre_OrderTraverseWithoutRecursion(BiTree &T);//�ǵݹ�ǰ�����
void Mid_OrderTraverseWithoutRecursion(BiTree &T);//�ǵݹ��������
void Back_OrderTraverseWithoutRecursion(BiTree &T);//�ǵݹ�������
int GetMaxDepthBitree(BiTree &T);//���ض�����������
int GetMinDepthBitree(BiTree &T);//���ض�������С���
int CountNodes(BiTree &T);//ͳ����ȫ�������Ľڵ�����
int NumOfTreeNode(BiTree &T);//ͳ�ƶ������ڵ�
int NumOfYezhiNode(BiTree &T);//ͳ��Ҷ�ӽڵ����
int NumOfKlevelTreeNodes(BiTree &T,int k);//���ص� k ��Ľڵ���
bool IsBalancedTree(BiTree &T);//�ж��Ƿ�Ϊƽ����
bool IsCompleteBitree(BiTree &T);//�Ƿ�Ϊ��ȫ������
bool IsSameBitree(BiTree &T1, BiTree &T2);//�ж��Ƿ�Ϊͬһ����
bool IsMirrorBitree(BiTree &T1, BiTree &T2);//�ж����Ƿ�Ϊ����
TreeNode *ReverseMirrorBitree(BiTree &T);//��ת�����������������

//TreeNode *DeleteNode(BitTree *pHead, int value);//ɾ��
void BitTreeCout(TreeNode *Node);
#endif //!BITTREE_H
