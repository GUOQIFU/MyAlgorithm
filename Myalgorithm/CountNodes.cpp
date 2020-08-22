#include"Tree.h"

int CountNodes(BiTree &T)//��ȫ�������Ľڵ�ͳ��
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
		return pow(2, RightNum) - 1;//û�ж�������
	}
	else
	{
		return CountNodes(T->Lchild) + CountNodes(T->Rchild) + 1; 
	}
}

int NumOfTreeNode(BiTree &T)//ͳ�ƶ������ڵ�
{
	if (T == NULL) return 0;
	
	int LeftNodeNum = NumOfTreeNode(T->Lchild);
	int RightNodeNum = NumOfTreeNode(T->Rchild);

	return LeftNodeNum + RightNodeNum + 1;
}

int NumOfYezhiNode(BiTree &T)//ͳ��Ҷ�ӽڵ����
{
	if (T == NULL) return 0;
	if (T->Lchild == NULL && T->Rchild == NULL)
	{
		return 1;
	}
	return NumOfYezhiNode(T->Lchild) + NumOfYezhiNode(T->Rchild);
}

int NumOfKlevelTreeNodes(BiTree &T,int k)//���ص� k ��Ľڵ���
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


