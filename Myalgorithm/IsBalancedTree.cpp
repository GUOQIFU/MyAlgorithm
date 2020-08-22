#include"Tree.h"
#include"myheadfile.h"

bool IsBalancedTree(BiTree &T)
{
	if (T == NULL) return false;
	int LeftNodes = GetMaxDepthBitree(T->Lchild);
	int RightNodes = GetMaxDepthBitree(T->Rchild);//�õ�����������������
	int SubDepth = LeftNodes > RightNodes ? LeftNodes - RightNodes : RightNodes - LeftNodes;
	if (SubDepth >= 0 && SubDepth <= 1)
		return true;
}