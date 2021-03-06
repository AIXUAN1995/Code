//在建立链表的过程中排序
#include <iostream>
using namespace std;
typedef struct Node
{
	double ratio;			//系数
	int exponent;			//指数
	struct Node *next;
}*LinkList, LNode;
LinkList creat_List(int n);//创建链表
LinkList insert_List(LinkList L, LNode *p, LNode **tail);//插入节点
LinkList add_List(LinkList L, LinkList L1, LinkList L2, LNode **tail);//链表相加
void ergodic_List(LinkList L);//遍历链表
void exchange(LNode *q);//将相邻的两个节点中的元素进行交换
LinkList creat_List(int n)	//创建一元多项式链表
{
	LinkList L = NULL;
	LNode *newNode = NULL;
	LNode *tail, *pre;						//尾指针tail，用于插入的指针pre
	double x;
	int y;										//定义系数和指数
	cout << "请输入系数和指数：" << endl;
	cin >> x >> y;
	L = new LNode();
	L->ratio = x;
	L->exponent = y;
	L->next = NULL;
	pre = tail = L;
	for (int i = 1; i < n; i++)
	{
		cout << "请输入系数和指数：" << endl;
		cin >> x >> y;
		newNode = new LNode();
		newNode->ratio = x;
		newNode->exponent = y;
		if (y <= pre->exponent)					//与第一个结点进行判断
		{
			newNode->next = pre;
			pre = newNode;
			L = pre;
			continue;
		}
		while (pre->next != NULL)
		{
			if (y <= pre->next->exponent)
			{
				newNode->next = pre->next;
				pre->next = newNode;
				pre = L;
				break;
			}
			pre = pre->next;
		}
	}
	return L;
}
LinkList add_List(LinkList L, LinkList L1, LinkList L2, LNode *tail)
{
	LNode *curNode = L, *pa = L1, *pb = L2;
	while (pa != NULL || pb != NULL)
	{
		while (pa != NULL && pb != NULL)
		{
			if (pa->exponent != pb->exponent)//指数不相等
			{
				if (pa->exponent > pb->exponent)
				{
					if (pb->ratio != 0)
					{
						tail->next = pb;
						tail = pb;
					}
					pb = pb->next;
				}
				else
				{
					if (pa->ratio != 0)
					{
						tail->next = pa;
						tail = pa;
					}
					pa = pa->next;
				}
			}
			else //指数相等
			{
				if (pa->ratio + pb->ratio != 0)
				{
					pa->ratio = pa->ratio + pb->ratio;
					tail->next = pa;
					tail = pa;
					pa = pa->next;
					pb = pb->next;
				}
				else
				{
					pa = pa->next;
					pb = pb->next;
				}

			}
		}
		while (pb != NULL)
		{
			tail->next = pb;
			tail = pb;
			pb = pb->next;
		}
		while (pa != NULL)
		{
			tail->next = pa;
			tail = pa;
			pa = pa->next;
		}
	}
	return L;
}
void ergodic_List(LinkList L)//遍历链表
{
	LNode *curNode = L->next;
	if (curNode == NULL)//判断链表是否为空
	{
		cout << 0 << endl;
		return;
	}
	else//对第一个节点进行操作
	{
		if (curNode->exponent == 0)//指数为零
			cout << curNode->ratio;
		else if(curNode->exponent == 1)//指数为1
		{
			if (curNode->ratio == -1)
				cout << "-x";
			else if (curNode->ratio == 1)
				cout << "x";
			else
				cout << curNode->ratio << "x";
		}
		else						//指数不为零
		{
			if (curNode->ratio == -1)
				cout << "-x^" << curNode->exponent;
			else if (curNode->ratio == 1)
				cout << "x^" << curNode->exponent;
			else
				cout << curNode->ratio << "x";
		}
		curNode = curNode->next;
	}
	while (curNode)//对第二个及以后的节点的操作
	{
		if(curNode->exponent == 1)			//指数等于1
		{
			if (curNode->ratio == -1)
				cout << "-x";
			else if (curNode->ratio == 1)
				cout << "+" << "x";
			else if (curNode->ratio < 0)
				cout << curNode->ratio << "x";
			else
				cout << "+" << curNode->ratio << "x";
		}
		else								//指数不等于1
		{
			if (curNode->ratio == -1)
				cout << "-x^" << curNode->exponent;
			else if (curNode->ratio == 1)
				cout << "+" << "x^" << curNode->exponent;
			else if (curNode->ratio < 0)
				cout << curNode->ratio << "x^" << curNode->exponent;
			else
				cout << "+" << curNode->ratio << "x^" << curNode->exponent;
		}
		curNode = curNode->next;

	}
}
void exchange(LNode *q)//将相邻的两个节点中的元素进行交换
{
	double tempratio = q->ratio;
	int tempexponent = q->exponent;
	q->ratio = q->next->ratio;
	q->exponent = q->next->exponent;
	q->next->ratio = tempratio;
	q->next->exponent = tempexponent;
}
int main()
{
	LinkList L = NULL, L1 = NULL, L2 = NULL;
	L = new LNode();
	LNode *tail = L;
	int n1 = 0, n2 = 0;
	//输入第一个多项式
	cout << "请输入一元多项式的项数：" << endl;
	cin >> n1;
	while (n1 <= 0)
	{
		cout << "输入有误, 请重新输入！" << endl;
		cout << "请输入一元多项式的项数：" << endl;
		cin >> n1;
	}
	L1 = creat_List(n1);

	//输入第二个多项式
	cout << "请输入一元多项式的项数：" << endl;
	cin >> n2;
	while (n2 <= 0)
	{
		cout << "输入有误, 请重新输入！" << endl;
		cout << "请输入一元多项式的项数：" << endl;
		cin >> n2;
	}
	L2 = creat_List(n2);
	L = add_List(L, L1, L2, tail);
	ergodic_List(L);
	system("pause");
	return 0;
}
