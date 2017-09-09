#include <iostream>
using namespace std;
typedef struct lnode
{
	int number;
	struct lnode *next;
}LNode, *Linklist;
Linklist Creat(int n)
{
	Linklist L = NULL;
	LNode *s, *r = NULL;
	int j = 1;
	while (j <= n)
	{
		s = new LNode;
		s->number = j;
		if (L == NULL)
			L = s;
		else
			r->next = s;
		r = s;
		j++;
	}
	if (r != NULL)
		r->next = L;
	return L;
}
Linklist Del(Linklist L, int i)
{
	Linklist p = L, s = NULL;
	int j = 1;
	if (p == NULL)
	{
		cout << "第" << i - 1 << "个节点不存在";
		return 0;
	}
	else
	{	
		if (i == 1)//报数为1的出列
		{
			s = p;
			cout << s->number << endl;
			p = p->next;
			delete s;
			return p;
		}
		else
		{
			while (j != i - 1)
			{
				j++;
				p = p->next;
			}
			if (L->next)
			{
				s = p->next;
				p->next = s->next;
				cout << s->number << endl;
				delete s;
			}
			return p->next;
		}
	}
}
int main()
{
	int n, x, j = 1, i = 0, num;//参加的人数n，报数的最大值x，循环计数j，数组角标i,第一个报数的人的编号num
	cout << "请输入报数的最大值" << endl;
	cin >> x;
	cout << "输入参加的人数：" << endl;
	cin >> n;
	cout << "从第几个人开始报数：" << endl;
	cin >> num;
	Linklist L = Creat(n);
	Linklist p = L;
	for (int k = 1; k < num; k++)
	{
		p = L->next;
	}
	for (int k = 0; k < n; k++)
	{
		p = Del(p, x);
	}
	return 0;
}