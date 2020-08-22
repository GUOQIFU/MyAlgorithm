#include"Tree.h"
#include"myheadfile.h"

int GetMaxDepthBitree(BiTree &T)//返回二叉树的最大深度
{
	if (T == NULL)
	{
		return 0;
	}
	return max(GetMaxDepthBitree(T->Lchild),GetMaxDepthBitree(T->Rchild)) + 1;
}

int GetMinDepthBitree(BiTree &T)//返回二叉树最小深度
{
	if (T == NULL)
	{
		return 0;
	}
	if (T->Lchild == NULL && T->Rchild == NULL)
	{
		return 1;
	}
	if (T->Lchild == NULL)
	{
		return GetMinDepthBitree(T->Rchild) + 1;
	}
	if (T->Rchild == NULL)
	{
		return GetMinDepthBitree(T->Lchild) + 1;
	}

	return min(GetMinDepthBitree(T->Lchild), GetMinDepthBitree(T->Rchild)) + 1;
}