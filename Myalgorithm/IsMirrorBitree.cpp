#include"Tree.h"
#include"myheadfile.h"

bool IsMirrorBitree(BiTree &T1, BiTree &T2)//ÅÐ¶ÏÊÇÊÇ·ñÎª¾µÏñ
{
	if (T1 == NULL && T2 == NULL) return true;
	if (T1 == NULL || T2 == NULL) return false;
	if (T1->value != T2->value) return false;

	bool Left = IsMirrorBitree(T1->Lchild, T2->Rchild);
	bool Right = IsMirrorBitree(T1->Rchild, T2->Lchild);

	return Left & Right;
}
