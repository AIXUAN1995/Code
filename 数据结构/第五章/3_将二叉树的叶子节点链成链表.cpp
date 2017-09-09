#include <iostream>
using namespace std;
typedef struct bitnode						//节点
{
	char data;
	struct bitnode *lchild, *rchild;		//左右孩子指针
}BiTNode, *BiTree;
//遍历
void display(BiTree head)//先序遍历
{
	BiTree p = head->rchild;
	while (p != NULL)
	{
		cout << p->data << " ";
		p = p->rchild;
	}

}
//建立二叉树的二叉链表
void CreateBinTree(BiTree *T)
{
	//以先序遍历序列构造二叉树链表存储的二叉树
	char ch;
	cin >> ch;
	if (ch == '0')
		*T = NULL;			//读入0时，将节点置空
	else
	{
		(*T) = new BiTNode;//生成节点空间
		(*T)->data = ch;
		CreateBinTree(&((*T)->lchild));//构造二叉树的左子树
		CreateBinTree(&((*T)->rchild));//构造二叉树的右子树
	}
}
//二叉树的叶节点按从左至右的顺序链成一个单链表
void Link(BiTree bt, BiTree *tail)			//指针的指针
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