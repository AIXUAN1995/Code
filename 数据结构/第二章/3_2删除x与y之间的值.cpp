//����Ҫ���򣬿���ֱ��ɾ��
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
	int len = l->last;
	if (l == NULL)
		return -1;
	if (x > y)
		return -2;
	for (int i = 0; i <= l->last; i++)
	{
		if (l->data[i] >= x && l->data[i] <= y)
		{		
			for (int j = i; j < l->last; j++)
				l->data[j] = l->data[j + 1];
			i--;
			l->last--;
		}
	}
	if (l->last == len)
		return 1;
	return 0;
}
int main()
{
	SeqList *s = new SeqList;
	s->last = -1;
	int x = -10, y = -10;
	for (int i = 0; i < 10; i++)
	{	
		s->data[i] = -i;
		s->last++;
	}
	if (del(s, x, y) == 0)
	{
		for (int i = 0; i <= s->last; i++)
			cout << s->data[i] << " ";
	}
	else if (del(s, x, y) == 1)
	{
		cout << "������Ҫɾ����ֵ";
	}
	else if (del(s, x, y) == -2)
		cout << "x��y��ֵ��������";
	else
		cout << "����Ϊ��" << endl;
	system("pause");
	return 0;
}