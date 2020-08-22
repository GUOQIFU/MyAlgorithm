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
void Pre_OrderTraverseWithoutRecursion(BiTree &T);//非递归前序遍历
void Mid_OrderTraverseWithoutRecursion(BiTree &T);//非递归中序遍历
void Back_OrderTraverseWithoutRecursion(BiTree &T);//非递归后序遍历
int GetMaxDepthBitree(BiTree &T);//返回二叉树最大深度
int GetMinDepthBitree(BiTree &T);//返回二叉树最小深度
int CountNodes(BiTree &T);//统计完全二叉树的节点数量
int NumOfTreeNode(BiTree &T);//统计二叉树节点
int NumOfYezhiNode(BiTree &T);//统计叶子节点个数
int NumOfKlevelTreeNodes(BiTree &T,int k);//返回第 k 层的节点数
bool IsBalancedTree(BiTree &T);//判断是否为平衡树
bool IsCompleteBitree(BiTree &T);//是否为完全二叉树
bool IsSameBitree(BiTree &T1, BiTree &T2);//判断是否为同一棵树
bool IsMirrorBitree(BiTree &T1, BiTree &T2);//判断是是否为镜像
TreeNode *ReverseMirrorBitree(BiTree &T);//反转二叉树，镜像二叉树

//TreeNode *DeleteNode(BitTree *pHead, int value);//删除
void BitTreeCout(TreeNode *Node);
#endif //!BITTREE_H
