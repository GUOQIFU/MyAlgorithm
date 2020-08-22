#include"myheadfile.h"

int Guo_SearchTree::InsertSerchTreeNode(BiTree &T, int value)//���������� ����
{
	//TreeNode *p;
	if (T == NULL)
	{
		T = NewTreeNode(value);
		//T = p;
	}
	else {
		if (value == T->value) return -1;
		else{
			if (value < T->value) InsertSerchTreeNode(T->Lchild, value);
			else InsertSerchTreeNode(T->Rchild, value);	
		}
	}
}

TreeNode *Guo_SearchTree::SearchValue(BiTree &T, int value)
{
	if (T == NULL) return NULL;
	else {
		if (value == T->value)
		{
			cout << "�ɹ��ҵ� "<< value <<" �ڵ�" << endl;
			return T;	
		}
		else {
			if(value < T->value)  SearchValue(T->Lchild, value);
			else {
				SearchValue(T->Rchild, value);
			}
		}	
		
	}
}
void Guo_SearchTree::DeleteSerchNode(BiTree &T,int value)
{
	if (T == NULL) cout<<"�ö�����Ϊ�գ��޷�ɾ��"<<endl;
	else {
		BiTree DeleteTreeNode = SearchValue(T, value);
		if (DeleteTreeNode)
		{
			if (DeleteTreeNode->Lchild == NULL && DeleteTreeNode->Rchild == NULL)// 1.ɾ���ڵ�ΪҶ�ӽڵ�
			{
				delete(DeleteTreeNode);//�ͷ��ڴ棬ָ���ÿ�
				DeleteTreeNode = NULL;
			}
			if (DeleteTreeNode->Lchild != NULL && DeleteTreeNode->Rchild == NULL)//2.�����ӣ����Һ���
			{
				DeleteTreeNode->value = DeleteTreeNode->Lchild->value;//ֻ��Ҫ��ɾ���ڵ����ӵ����ݸ���ɾ���ڵ������
				DeleteTreeNode->Lchild = DeleteTreeNode->Lchild->Lchild;
				DeleteTreeNode->Rchild = DeleteTreeNode->Lchild->Rchild;	
			}
			if (DeleteTreeNode->Lchild == NULL && DeleteTreeNode->Rchild != NULL)//3.���Һ��ӣ�������
			{
				DeleteTreeNode->value = DeleteTreeNode->Rchild->value;
				DeleteTreeNode->Rchild = DeleteTreeNode->Rchild->Rchild;
				DeleteTreeNode->Lchild = DeleteTreeNode->Rchild->Lchild;
			}
			if (DeleteTreeNode->Lchild != NULL && DeleteTreeNode->Rchild != NULL)//4.�����ӣ����Һ���
			{
				TreeNode *RightNode;
				RightNode = DeleteTreeNode;
				while (RightNode->Rchild)
				{
					RightNode = RightNode->Rchild;//�ҵ����Һ��ӣ���Ϊ�������ģ�������ɾ���ڵ�����ݽ���
				}
				DeleteTreeNode->value = RightNode->value;
				if (RightNode->Lchild != NULL)//���RightNode�������ӣ�����ֻ�����ӵķ�������
				{
					RightNode->value = RightNode->Lchild->value;
					RightNode->Lchild = RightNode->Lchild->Lchild;
					RightNode->Rchild = RightNode->Lchild->Rchild;
				}
			}
		}
		else
		{
			cout << "û���ҵ���Ҫɾ���Ľڵ�" << endl;
		}
	}
	

}