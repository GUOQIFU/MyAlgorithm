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

//TreeNode *DeleteNode(BitTree *pHead, int value);//ɾ��
void BitTreeCout(TreeNode *Node);
#endif //!BITTREE_H
