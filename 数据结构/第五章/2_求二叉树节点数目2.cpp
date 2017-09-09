#include <iostream>
using namespace std;
typedef struct bitnode						//节点
{
	char data;
	struct bitnode *lchild, *rchild;		//左右孩子指针
}BiTNode, *BiTree;
//遍历
int Count(BiTree bt)//先序遍历
{
	if (bt == NULL)
		return 0;//递归调用结束的条件
	return (Count(bt->lchild) + Count(bt->rchild) + 1);
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
	i = Count(bt);
	cout << "节点个数：" << i;
	system("pause");
	return 0;
}