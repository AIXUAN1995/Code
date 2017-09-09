#include <iostream>
using namespace std;
typedef struct bitnode						//节点
{
	char data;
	struct bitnode *lchild, *rchild;		//左右孩子指针
}BiTNode, *BiTree;

//建立一棵空的带头结点的空二叉树
BiTree Initiate()
{
	BiTNode *bt;
	bt = new BiTNode;
	bt->lchild = NULL;
	bt->rchild = NULL;
	return bt;
}
//建立一棵不带头节点的空二叉树
BiTree Initiate2()
{
	BiTNode *bt;
	bt = NULL;
	return bt;
}
//生成一棵以x为根节点数据域信息以lbt和rbt为左右子树的二叉树
BiTree Create(BiTree p, char x, BiTree lbt, BiTree rbt)
{
	if (p == NULL)
		return NULL;
	p->data = x;
	p->lchild = lbt;
	p->rchild = rbt;
	return p;
}
//在parent所指节点和左子树之间插入
BiTree InsertL(BiTree bt, char x, BiTree parent)
{
	BiTree p;
	if (parent == NULL)
	{
		cout << "插入错误！";
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
//在parent所指节点和右子树之间插入
BiTree InsertR(BiTree bt, char x, BiTree parent)
{
	BiTree p;
	if (parent == NULL)
	{
		cout << "插入错误！";
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
//删除parent的左子树
BiTree DeleteL(BiTree bt, BiTree parent)
{
	BiTree p;
	if (parent == NULL || parent->lchild == NULL)
	{
		cout << "删除出错！";
		return NULL;
	}
	p = parent->lchild;
	parent->lchild = NULL;
	delete p;
	/*
	当*p为非叶子节点时， 这样删除仅释放了所删除子树根节点的空间
	若要删除子树分支中的节点，需用后面介绍的遍历操作来实现。
	*/
	return bt;
}
//删除parent的右子树
BiTree DeleteR(BiTree bt, BiTree parent)
{
	BiTree p;
	if (parent == NULL || parent->rchild == NULL)
	{
		cout << "删除出错！";
		return NULL;
	}
	p = parent->rchild;
	parent->rchild = NULL;
	delete p;
	/*
	当*p为非叶子节点时， 这样删除仅释放了所删除子树根节点的空间
	若要删除子树分支中的节点，需用后面介绍的遍历操作来实现。
	*/
	return bt;
}
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