#include"Tree.h"
#include"myheadfile.h"

TreeNode *ReverseMirrorBitree(BiTree &T)//��ת�����������������
{
	if (T == NULL) return NULL;
	TreeNode *Left = ReverseMirrorBitree(T->Lchild);
	TreeNode *Right = ReverseMirrorBitree(T->Rchild);

	T->Lchild = Right;
	T->Rchild = Left;

	return T;
}