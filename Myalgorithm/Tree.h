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

class Guo_Tree //随机存储树，非必须平衡，非必须完满
{
public:
	Guo_Tree()
	{
	}
	~Guo_Tree()
	{}
	void Pre_CreatBiTree_Cin(BiTree &T);
	void Pre_CreatBitree_arr(BiTree &T, vector<int> &arr, int index);
	void InsertBiTreeNode(BiTree &T, int value);//尾 插入
};

class Guo_SearchTree
{
public:
	Guo_SearchTree()
	{}
	~Guo_SearchTree()
	{}
	int InsertSerchTreeNode(BiTree &T, int value);//搜索二叉树 插入
	TreeNode * SearchValue(BiTree &T, int value);
	void DeleteSerchNode(BiTree &T,int value);
};

TreeNode *NewTreeNode(int value);//新节点
void Pre_OrderTraverse(BiTree &T);//前序遍历
void Mid_OrderTraverse(BiTree &T);//中序遍历
void Back_OrderTraverse(BiTree &T);//后序遍历

//TreeNode *DeleteNode(BitTree *pHead, int value);//删除
void BitTreeCout(TreeNode *Node);
#endif //!BITTREE_H
