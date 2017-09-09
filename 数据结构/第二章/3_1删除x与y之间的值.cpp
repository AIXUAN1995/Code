//使用的前提是数组中的值由小到大排序
#include <iostream>
using namespace std;
const int MAXSIZE = 100;
struct SeqList
{
	int data[MAXSIZE];
	int last;
};
int del(SeqList* l, int x, int y)
{
	if (l == NULL)
		return -1;
	if (x > y)
		return -2;
	if (l->data[l->last] < x || l->data[0] > y)
		return 1;
	int min = 0, max = 0;
	for (int i = 0; i <= l->last; i++)
	{
		if (l->data[i] >= x)
		{
			min = i;
			break;
		}
	}
	for (int i = min; i <= l->last; i++)
	{
		if (l->data[i] > y)
		{
			max = i;
			break;
		}
		if (l->data[l->last] == l->data[min])
			max = l->last+1;
	}
	for (int i = max; i <= l->last; i++)
		l->data[min++] = l->data[max++];
	l->last = l->last - max + min;
	return 0;
}
int main()
{
	SeqList *s = new SeqList;
	s->last = -1;
	int x = 1, y = -1;
	for (int i = 0; i < 10; i++)
	{	
		s->data[i] = i;
		s->last++;
	}
	if (del(s, x, y) == 0)
	{
		for (int i = 0; i <= s->last; i++)
			cout << s->data[i] << " ";
	}
	else if (del(s, x, y) == 1)
	{
		cout << "不存在要删除的值";
	}
	else if (del(s, x, y) == -2)
		cout << "x或y的值输入有误！";
	else
		cout << "数组为空" << endl;
	system("pause");
	return 0;
}