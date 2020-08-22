#include"myheadfile.h"

int Guo_SearchTree::InsertSerchTreeNode(BiTree &T, int value)//搜索二叉树 插入
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
			cout << "成功找到 "<< value <<" 节点" << endl;
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
	if (T == NULL) cout<<"该二叉树为空，无法删除"<<endl;
	else {
		BiTree DeleteTreeNode = SearchValue(T, value);
		if (DeleteTreeNode)
		{
			if (DeleteTreeNode->Lchild == NULL && DeleteTreeNode->Rchild == NULL)// 1.删除节点为叶子节点
			{
				delete(DeleteTreeNode);//释放内存，指针置空
				DeleteTreeNode = NULL;
			}
			if (DeleteTreeNode->Lchild != NULL && DeleteTreeNode->Rchild == NULL)//2.有左孩子，无右孩子
			{
				DeleteTreeNode->value = DeleteTreeNode->Lchild->value;//只需要将删除节点左孩子的数据覆盖删除节点就行了
				DeleteTreeNode->Lchild = DeleteTreeNode->Lchild->Lchild;
				DeleteTreeNode->Rchild = DeleteTreeNode->Lchild->Rchild;	
			}
			if (DeleteTreeNode->Lchild == NULL && DeleteTreeNode->Rchild != NULL)//3.有右孩子，无左孩子
			{
				DeleteTreeNode->value = DeleteTreeNode->Rchild->value;
				DeleteTreeNode->Rchild = DeleteTreeNode->Rchild->Rchild;
				DeleteTreeNode->Lchild = DeleteTreeNode->Rchild->Lchild;
			}
			if (DeleteTreeNode->Lchild != NULL && DeleteTreeNode->Rchild != NULL)//4.有左孩子，有右孩子
			{
				TreeNode *RightNode;
				RightNode = DeleteTreeNode;
				while (RightNode->Rchild)
				{
					RightNode = RightNode->Rchild;//找到最右孩子，因为它是最大的，将它与删除节点的数据交换
				}
				DeleteTreeNode->value = RightNode->value;
				if (RightNode->Lchild != NULL)//如果RightNode还有左孩子，按照只有左孩子的方法处理
				{
					RightNode->value = RightNode->Lchild->value;
					RightNode->Lchild = RightNode->Lchild->Lchild;
					RightNode->Rchild = RightNode->Lchild->Rchild;
				}
			}
		}
		else
		{
			cout << "没有找到需要删除的节点" << endl;
		}
	}
	

}