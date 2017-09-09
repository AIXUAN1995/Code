#include <iostream> 
using namespace std;
int add(int x, int y)
{
	return x + y;
}
int minus1(int x, int y)
{
	return x - y;
}
int multi(int x, int y)
{
	return x*y;
}
int divide(int x, int y)
{
	return x / y;
}
int main()
{
	int a, b;
	int(*fp[4])(int, int);//定义函数指针数组
	cout << "请输入两个数：" << endl;
	cin >> a >> b;
	fp[0] = add;
	fp[1] = minus1;
	fp[2] = multi;
	fp[3] = divide;
	//一下两者输出结果相同
	for (int i = 0; i <= 3; i++)
		cout << (*fp[i])(a, b) << endl;
	for (int i = 0; i <= 3; i++)
		cout << fp[i](a, b) << endl;
	system("pause");
	return 0;
}