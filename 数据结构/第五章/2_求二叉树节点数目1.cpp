#include <iostream>
using namespace std;
typedef struct bitnode						//节点
{
	char data;
	struct bitnode *lchild, *rchild;		//左右孩子指针
}BiTNode, *BiTree;
void Visit(BiTree bt, int *i)
{
	cout << bt->data;
	(*i)++;
}
//遍历
void PreOrder(BiTree bt, int *i)//先序遍历
{
	if (bt == NULL)
		return;//递归调用结束的条件
	Visit(bt, i);
	PreOrder(bt->lchild, i);//遍历左子树
	PreOrder(bt->rchild, i);//遍历右子树
}
//建立二叉树的二叉链表
void CreateBinTree(BiTree *T)
{
	//以先序遍历序列构造二叉树链表存储的二叉树
	char ch;
	cin >> ch;
	if (ch == '0')
		*T = NULL;			//读入0时，将相节点置空
	else
	{
		(*T) = new BiTNode;//生成节点空间
		(*T)->data = ch;
		CreateBinTree(&((*T)->lchild));//构造二叉树的左子树
		CreateBinTree(&((*T)->rchild));//构造二叉树的右子树
	}
}
int main()
{
	BiTree bt;
	int i = 0;//记录节点个数
	CreateBinTree(&bt);
	PreOrder(bt, &i);
	cout << "节点个数：" << i;
	system("pause");
	return 0;
}