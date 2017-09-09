#include <iostream>
using namespace std;
typedef struct bitnode						//�ڵ�
{
	char data;
	struct bitnode *lchild, *rchild;		//���Һ���ָ��
}BiTNode, *BiTree;
//����
void display(BiTree head)//�������
{
	BiTree p = head->rchild;
	while (p != NULL)
	{
		cout << p->data << " ";
		p = p->rchild;
	}

}
//�����������Ķ�������
void CreateBinTree(BiTree *T)
{
	//������������й������������洢�Ķ�����
	char ch;
	cin >> ch;
	if (ch == '0')
		*T = NULL;			//����0ʱ�����ڵ��ÿ�
	else
	{
		(*T) = new BiTNode;//���ɽڵ�ռ�
		(*T)->data = ch;
		CreateBinTree(&((*T)->lchild));//�����������������
		CreateBinTree(&((*T)->rchild));//�����������������
	}
}
//��������Ҷ�ڵ㰴�������ҵ�˳������һ��������
void Link(BiTree bt, BiTree *tail)			//ָ���ָ��
{
	if (bt->lchild == NULL && bt->rchild == NULL)
	{
		(*tail)->rchild = bt;
		*tail = (*tail)->rchild;
		return;
	}
	Link(bt->lchild, tail);
	Link(bt->rchild, tail);
}
int main()
{
	BiTree bt;
	CreateBinTree(&bt);
	BiTNode *head, *tail;
	head = new BiTNode;
	head->lchild = head->rchild = NULL;
	tail = head;
	Link(bt, &tail);
	display(head);
	system("pause");
	return 0;
}