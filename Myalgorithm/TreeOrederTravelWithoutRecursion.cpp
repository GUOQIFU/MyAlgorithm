#include"Tree.h"
#include<stack>

void Pre_OrderTraverseWithoutRecursion(BiTree &T)//�ǵݹ�ǰ�����
{
	if (T == NULL) return;
	TreeNode *p;
	p = T;
	stack<TreeNode*> sta;
	while (!sta.empty() || p)
	{
		while (p)
		{
			cout << p->value << ' ';
			sta.push(p);
			p = p->Lchild;
		}
		if (!sta.empty())//��ѭ��
		{
			p = sta.top();
			sta.pop();
			p = p->Rchild;
		}
	}
}

void Mid_OrderTraverseWithoutRecursion(BiTree &T)//�ǵݹ�������� ��������������������  
 
{
	if (T == NULL) return;
	TreeNode *p;
	p = T;
	stack<TreeNode*> sta;
	while (!sta.empty() || p)//empty();����Ƿ�Ϊ�գ�Ϊ���򷵻� true,��Ϊ�շ��� false ;
	{
		while (p)//�Ƚ�����������ѹ��ջ�У�
		{
			sta.push(p);
			p = p->Lchild;
		}
		if (!sta.empty())//�����жϣ����Բ���Ҫ
		{
			p = sta.top();
			sta.pop();
			cout << p->value <<' ';
			p = p->Rchild;//�� stack ��󵯳������� p ��ָ��ջ���ڵ㣨���Ǹ��ڵ㣩���ҽڵ㣬�Ӷ���ʼ�µ�һ����������ѹջ
		}
	}

}

void Back_OrderTraverseWithoutRecursion(BiTree &T)//�ǵݹ�������
{
	if (T == NULL) return;

	TreeNode *pCurrentNode, *pLastNode;
	pCurrentNode = T;
	pLastNode = NULL;
	stack<TreeNode*> sta;

	while (pCurrentNode)//�������������� pCurrentNode ��λ
	{
		sta.push(pCurrentNode);
		pCurrentNode = pCurrentNode->Lchild;
	}
	while (!sta.empty())
	{
		pCurrentNode = sta.top();
		sta.pop();
		//�жϵ�ǰ�ڵ��Ƿ�Ϊ���ڵ�����Ƿ��ѱ����ʹ���
		if (pCurrentNode->Rchild == NULL || pCurrentNode->Rchild == pLastNode)
		{
			cout << pCurrentNode->value << ' ';
			pLastNode = pCurrentNode;
		}
		else {
			sta.push(pCurrentNode);
			pCurrentNode = pCurrentNode->Rchild;
			while (pCurrentNode)
			{
				sta.push(pCurrentNode);
				pCurrentNode = pCurrentNode->Lchild;
			}
		}
	}
}

//
//void Pre_orderTravelBitree(BiTree &T)
//{
//	if (T == NULL) return;
//	TreeNode *p;
//	p = T;
//	stack<TreeNode*> sta;
//	while (sta.empty() || p)
//	{
//		while (p)
//		{
//			sta.push(p);
//			cout << p->value << endl;//ǰ��
//			p = p->Lchild;
//		}
//		if (!sta.empty())
//		{
//			p = sta.top();
//			//cout << p->value << endl; //����
//			sta.pop();
//			p = p->Rchild;
//		}
//	}
//}