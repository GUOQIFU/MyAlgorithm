#include"myheadfile.h"
#pragma warning(disable:4996);
using namespace std;

TreeNode *NewTreeNode(int value)
{
	TreeNode *p = new TreeNode;
	p->value = value;
	p->Lchild = NULL;
	p->Rchild = NULL;
	return p;
}


void BitTreeCout(TreeNode *Node)
{
	cout << Node->value <<' ';
}

void Guo_Tree::Pre_CreatBiTree_Cin(BiTree &T)//�������������Ĵ����������ṹ�������
{
	int ch;
	scanf("%d",&ch);
	if (ch == ' ')
	{
		T = NULL;
	}
	else
	{
	   // *T = new TreeNode;
		T = (BiTree)malloc(sizeof(TreeNode));
		T->value = ch;
		Pre_CreatBiTree_Cin(T->Lchild);
		Pre_CreatBiTree_Cin(T->Rchild);
	}
}

void Guo_Tree::Pre_CreatBitree_arr(BiTree &T, vector<int> &arr, int index)//������������
{
	if (index >= arr.size())
	{
		return;
	}
	T = NewTreeNode(arr[index]);

	Pre_CreatBitree_arr(T->Lchild, arr, 2 * index + 1);
	Pre_CreatBitree_arr(T->Rchild, arr, 2 * index + 2);
}


void Guo_Tree::InsertBiTreeNode(BiTree &T,int value)
{
	if (T = NULL)
	{
		T = NewTreeNode(value);
	}
	if (T)
	{
		T = T->Rchild;
	}
	T = NewTreeNode(value);
}




