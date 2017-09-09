#include <iostream>
using namespace std;
typedef struct bitnode						//�ڵ�
{
	char data;
	struct bitnode *lchild, *rchild;		//���Һ���ָ��
}BiTNode, *BiTree;
//����
int Count(BiTree bt)//�������
{
	if (bt == NULL)
		return 0;//�ݹ���ý���������
	return (Count(bt->lchild) + Count(bt->rchild) + 1);
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
	i = Count(bt);
	cout << "�ڵ������" << i;
	system("pause");
	return 0;
}