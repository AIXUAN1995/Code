//将整数转换为二进制后，统计该二进制数中的1的个数
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