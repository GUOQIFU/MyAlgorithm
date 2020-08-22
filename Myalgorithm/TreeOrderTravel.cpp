#ifndef TREEORDERTRAVEL_H
#define TREEORDERTRAVEL_H
#include"Tree.h"

void Pre_OrderTraverse(BiTree &T)
{
	if (T)
	{
		BitTreeCout(T);
		Pre_OrderTraverse(T->Lchild);
		Pre_OrderTraverse(T->Rchild);
	}
}

void Mid_OrderTraverse(BiTree &T)
{
	if (T)
	{
		Mid_OrderTraverse(T->Lchild);
		BitTreeCout(T);
		Mid_OrderTraverse(T->Rchild);
	}
}

void Back_OrderTraverse(BiTree &T)
{
	if (T)
	{
		Back_OrderTraverse(T->Lchild);
		Back_OrderTraverse(T->Rchild);
		BitTreeCout(T);
	}
}

#endif // !TREEORDERTRAVEL_H
