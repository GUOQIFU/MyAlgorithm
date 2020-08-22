#include"Tree.h"
#include"myheadfile.h"

bool IsSameBitree(BiTree &T1, BiTree &T2)
{
	if (T1 == NULL && T2 == NULL) return true;
	if (T1 == NULL || T2 == NULL) return false;
	
	if (T1->value != T2->value) return false;

	bool Left = IsSameBitree(T1->Lchild, T2->Lchild);
	bool Right = IsSameBitree(T1->Rchild, T2->Rchild);

	return Left && Right;
}