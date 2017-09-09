#include <iostream>
using namespace std;
struct Linklist
{
	int data;
	Linklist *next;
};
Linklist* init()//Á´Õ»µÄ³õÊ¼»¯
{
	return NULL;
}
int empty(Linklist *top)//ÅÐ¶Ï¿ÕÕ»
{
	if (top == NULL)
		return 1;
	else
		return 0;
}
Linklist* push(Linklist *top, int x)//ÈëÕ»
{
	Linklist *s;
	s = new Linklist;
	s->data = x;
	s->next = top;
	top = s;
	return top;
}
Linklist *pop(Linklist *top, int *x)//³öÕ»
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
		cout << "Õ»Îª¿Õ£¡" << endl;	
	cout << endl;
}
int main()
{
	int x;
	Linklist *l = new Linklist;
	l = NULL;
	if (empty(l))
		cout << "Õ»Îª¿Õ£¡" << endl;
	else
		cout << "Õ»²»Îª¿Õ£¡";
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