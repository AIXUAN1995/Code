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
		cout << "��" << i - 1 << "���ڵ㲻����";
		return 0;
	}
	else
	{	
		if (i == 1)//����Ϊ1�ĳ���
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
	int n, x, j = 1, i = 0, num;//�μӵ�����n�����������ֵx��ѭ������j������Ǳ�i,��һ���������˵ı��num
	cout << "�����뱨�������ֵ" << endl;
	cin >> x;
	cout << "����μӵ�������" << endl;
	cin >> n;
	cout << "�ӵڼ����˿�ʼ������" << endl;
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