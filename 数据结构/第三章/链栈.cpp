#include <iostream>
using namespace std;
struct Linklist
{
	int data;
	Linklist *next;
};
Linklist* init()//��ջ�ĳ�ʼ��
{
	return NULL;
}
int empty(Linklist *top)//�жϿ�ջ
{
	if (top == NULL)
		return 1;
	else
		return 0;
}
Linklist* push(Linklist *top, int x)//��ջ
{
	Linklist *s;
	s = new Linklist;
	s->data = x;
	s->next = top;
	top = s;
	return top;
}
Linklist *pop(Linklist *top, int *x)//��ջ
{
	Linklist *p;
	if (top == NULL)
		return NULL;
	else
	{
		*x = top->data;
		p = top;
		top = top->next;
		delete p;
		return top;
	}
}
void display(Linklist *l)
{
	Linklist *p = l;
	if (p != NULL)
	{
		while (p->next != NULL)
		{
			cout << "(" << p->data << ")->";
			p = p->next;
		}
		cout << "(" << p->data << ")";
	}
	else
		cout << "ջΪ�գ�" << endl;	
	cout << endl;
}
int main()
{
	int x;
	Linklist *l = new Linklist;
	l = NULL;
	if (empty(l))
		cout << "ջΪ�գ�" << endl;
	else
		cout << "ջ��Ϊ�գ�";
	l = push(l, 1);
	display(l);
	l = push(l, 2);
	l = push(l, 3);
	display(l);
	l = pop(l, &x);
	display(l);
	system("pause");
	return 0;
}