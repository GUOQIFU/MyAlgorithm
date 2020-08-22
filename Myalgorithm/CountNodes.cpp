#include"Tree.h"

int CountNodes(BiTree &T)//完全二叉树的节点统计
{
	TreeNode *LNode = T;
	TreeNode *RNode = T;
	int LeftNum = 0;
	int RightNum = 0;

	while (LNode)
	{
		LeftNum++;
		LNode = LNode->Lchild;
	}

	while (RNode)
	{
		RightNum++;
		RNode = RNode->Rchild;
	}

	if (LeftNum == RightNum)
	{
		return pow(2, RightNum) - 1;//没有多大的意义
	}
	else
	{
		return CountNodes(T->Lchild) + CountNodes(T->Rchild) + 1; 
	}
}

int NumOfTreeNode(BiTree &T)//统计二叉树节点
{
	if (T == NULL) return 0;
	
	int LeftNodeNum = NumOfTreeNode(T->Lchild);
	int RightNodeNum = NumOfTreeNode(T->Rchild);

	return LeftNodeNum + RightNodeNum + 1;
}

int NumOfYezhiNode(BiTree &T)//统计叶子节点个数
{
	if (T == NULL) return 0;
	if (T->Lchild == NULL && T->Rchild == NULL)
	{
		return 1;
	}
	return NumOfYezhiNode(T->Lchild) + NumOfYezhiNode(T->Rchild);
}

int NumOfKlevelTreeNodes(BiTree &T,int k)//返回第 k 层的节点数
{
	if (T == NULL && k < 1) return 0 ;
	if (k == 1)
	{
		return 1;
	}
	int LeftNumNodes = NumOfKlevelTreeNodes(T->Lchild, k - 1);
	int RightNumNodes = NumOfKlevelTreeNodes(T->Rchild, k - 1);

	return LeftNumNodes + RightNumNodes; 
}


