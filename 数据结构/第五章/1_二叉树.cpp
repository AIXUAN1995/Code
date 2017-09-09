#include <iostream>
using namespace std;
typedef struct bitnode						//�ڵ�
{
	char data;
	struct bitnode *lchild, *rchild;		//���Һ���ָ��
}BiTNode, *BiTree;

//����һ�ÿյĴ�ͷ���Ŀն�����
BiTree Initiate()
{
	BiTNode *bt;
	bt = new BiTNode;
	bt->lchild = NULL;
	bt->rchild = NULL;
	return bt;
}
//����һ�ò���ͷ�ڵ�Ŀն�����
BiTree Initiate2()
{
	BiTNode *bt;
	bt = NULL;
	return bt;
}
//����һ����xΪ���ڵ���������Ϣ��lbt��rbtΪ���������Ķ�����
BiTree Create(BiTree p, char x, BiTree lbt, BiTree rbt)
{
	if (p == NULL)
		return NULL;
	p->data = x;
	p->lchild = lbt;
	p->rchild = rbt;
	return p;
}
//��parent��ָ�ڵ��������֮�����
BiTree InsertL(BiTree bt, char x, BiTree parent)
{
	BiTree p;
	if (parent == NULL)
	{
		cout << "�������";
		return NULL;
	}
	if ((p = new BiTNode) == NULL)
		return NULL;
	p->data = x;
	p->lchild = NULL;
	p->rchild = NULL;
	if (parent->lchild == NULL)
		parent->lchild = p;
	else
	{
		p->lchild = parent->lchild;
		parent->lchild = p;
	}
	return bt;
}
//��parent��ָ�ڵ��������֮�����
BiTree InsertR(BiTree bt, char x, BiTree parent)
{
	BiTree p;
	if (parent == NULL)
	{
		cout << "�������";
		return NULL;
	}
	if ((p = new BiTNode) == NULL)
		return NULL;
	p->data = x;
	p->rchild = NULL;
	p->rchild = NULL;
	if (parent->rchild == NULL)
		parent->rchild = p;
	else
	{
		p->rchild = parent->rchild;
		parent->rchild = p;
	}
	return bt;
}
//ɾ��parent��������
BiTree DeleteL(BiTree bt, BiTree parent)
{
	BiTree p;
	if (parent == NULL || parent->lchild == NULL)
	{
		cout << "ɾ������";
		return NULL;
	}
	p = parent->lchild;
	parent->lchild = NULL;
	delete p;
	/*
	��*pΪ��Ҷ�ӽڵ�ʱ�� ����ɾ�����ͷ�����ɾ���������ڵ�Ŀռ�
	��Ҫɾ��������֧�еĽڵ㣬���ú�����ܵı���������ʵ�֡�
	*/
	return bt;
}
//ɾ��parent��������
BiTree DeleteR(BiTree bt, BiTree parent)
{
	BiTree p;
	if (parent == NULL || parent->rchild == NULL)
	{
		cout << "ɾ������";
		return NULL;
	}
	p = parent->rchild;
	parent->rchild = NULL;
	delete p;
	/*
	��*pΪ��Ҷ�ӽڵ�ʱ�� ����ɾ�����ͷ�����ɾ���������ڵ�Ŀռ�
	��Ҫɾ��������֧�еĽڵ㣬���ú�����ܵı���������ʵ�֡�
	*/
	return bt;
}
void Visit(BiTree bt, int *i)
{
	cout << bt->data;
	(*i)++;
}
//����
void PreOrder(BiTree bt, int *i)//�������
{
	if (bt == NULL)
		return;//�ݹ���ý���������
	Visit(bt, i);
	PreOrder(bt->lchild, i);//����������
	PreOrder(bt->rchild, i);//����������
}
//�����������Ķ�������
void CreateBinTree(BiTree *T)
{
	//������������й������������洢�Ķ�����
	char ch;
	cin >> ch;
	if (ch == '0')
		*T = NULL;			//����0ʱ������ڵ��ÿ�
	else
	{
		(*T) = new BiTNode;//���ɽڵ�ռ�
		(*T)->data = ch;
		CreateBinTree(&((*T)->lchild));//�����������������
		CreateBinTree(&((*T)->rchild));//�����������������
	}
}
int main()
{
	BiTree bt;
	int i = 0;//��¼�ڵ����
	CreateBinTree(&bt);
	PreOrder(bt, &i);
	cout << "�ڵ������" << i;
	system("pause");
	return 0;
}