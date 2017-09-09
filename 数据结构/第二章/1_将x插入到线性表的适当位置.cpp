#include <iostream>
using namespace std;
const int MAXSIZE = 100;
struct SeqList
{
	int data[MAXSIZE];
	int last;
};
int insert(SeqList* l, int x, int elenum)
{
	for (int i = 0; i < elenum; i++)
	{
		if (l->data[i]>x)
		{
			for (int j = elenum - 1; j >= i; j--)
				l->data[j + 1] = l->data[j];
			l->data[i] = x;
			return 0;
		}
	}
	l->data[elenum] = x;
	return 0;
}
int main()
{
	int x;
	cout << "请输入要插入的整数：" << endl;
	cin >> x;
	SeqList s;
	s.last = 0;
	for (int i = 0; i < 10; i++)
	{
		s.data[i] = i;
		s.last++;
	}
	insert(&s, x, 10);
	for (int i = 0; i < s.last; i++)
		cout << s.data[i] << " ";
	system("pause");
	return 0;
}