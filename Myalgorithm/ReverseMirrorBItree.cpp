#include"Tree.h"
#include"myheadfile.h"

TreeNode *ReverseMirrorBitree(BiTree &T)//·´×ª¶ş²æÊ÷£¬¾µÏñ¶ş²æÊ÷
{
	if (T == NULL) return NULL;
	TreeNode *Left = ReverseMirrorBitree(T->Lchild);
	TreeNode *Right = ReverseMirrorBitree(T->Rchild);

	T->Lchild = Right;
	T->Rchild = Left;

	return T;
}