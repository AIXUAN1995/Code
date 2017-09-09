#include <iostream>
using namespace std;
typedef struct bitnode						//�ڵ�
{
	char data;
	struct bitnode *lchild, *rchild;		//���Һ���ָ��
}BiTNode, *BiTree;
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