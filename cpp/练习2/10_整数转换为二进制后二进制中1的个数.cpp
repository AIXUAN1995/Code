//������ת��Ϊ�����ƺ�ͳ�Ƹö��������е�1�ĸ���
#include <iostream>
using namespace std;
int func(int x)
{
	int countx = 0;
	while (x)
	{
		countx++;
		x = x&(x - 1);
		cout << x << endl;
	}
	return countx;
}
int main()
{
	cout << func(9999);
	system("pause");
	return 0;
}