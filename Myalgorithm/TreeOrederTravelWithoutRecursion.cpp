#include"Tree.h"
#include<stack>

void Pre_OrderTraverseWithoutRecursion(BiTree &T)//非递归前序遍历
{
	if (T == NULL) return;
	TreeNode *p;
	p = T;
	stack<TreeNode*> sta;
	while (!sta.empty() || p)
	{
		while (p)
		{
			cout << p->value << ' ';
			sta.push(p);
			p = p->Lchild;
		}
		if (!sta.empty())//非循环
		{
			p = sta.top();
			sta.pop();
			p = p->Rchild;
		}
	}
}

void Mid_OrderTraverseWithoutRecursion(BiTree &T)//非递归中序遍历 （迭代法遍历二叉树）  
 
{
	if (T == NULL) return;
	TreeNode *p;
	p = T;
	stack<TreeNode*> sta;
	while (!sta.empty() || p)//empty();检测是否为空，为空则返回 true,不为空返回 false ;
	{
		while (p)//先将左子树依次压入栈中，
		{
			sta.push(p);
			p = p->Lchild;
		}
		if (!sta.empty())//该行判断，可以不需要
		{
			p = sta.top();
			sta.pop();
			cout << p->value <<' ';
			p = p->Rchild;//等 stack 最后弹出结束后 p 会指向栈最后节点（即是根节点）的右节点，从而开始新的一轮左子树的压栈
		}
	}

}

void Back_OrderTraverseWithoutRecursion(BiTree &T)//非递归后序遍历
{
	if (T == NULL) return;

	TreeNode *pCurrentNode, *pLastNode;
	pCurrentNode = T;
	pLastNode = NULL;
	stack<TreeNode*> sta;

	while (pCurrentNode)//遍历左子树，将 pCurrentNode 定位
	{
		sta.push(pCurrentNode);
		pCurrentNode = pCurrentNode->Lchild;
	}
	while (!sta.empty())
	{
		pCurrentNode = sta.top();
		sta.pop();
		//判断当前节点是否为根节点或者是否已被访问过。
		if (pCurrentNode->Rchild == NULL || pCurrentNode->Rchild == pLastNode)
		{
			cout << pCurrentNode->value << ' ';
			pLastNode = pCurrentNode;
		}
		else {
			sta.push(pCurrentNode);
			pCurrentNode = pCurrentNode->Rchild;
			while (pCurrentNode)
			{
				sta.push(pCurrentNode);
				pCurrentNode = pCurrentNode->Lchild;
			}
		}
	}
}

//
//void Pre_orderTravelBitree(BiTree &T)
//{
//	if (T == NULL) return;
//	TreeNode *p;
//	p = T;
//	stack<TreeNode*> sta;
//	while (sta.empty() || p)
//	{
//		while (p)
//		{
//			sta.push(p);
//			cout << p->value << endl;//前序
//			p = p->Lchild;
//		}
//		if (!sta.empty())
//		{
//			p = sta.top();
//			//cout << p->value << endl; //中序
//			sta.pop();
//			p = p->Rchild;
//		}
//	}
//}