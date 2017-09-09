//计算一元多项式P(x,n) = a0 + a1x + a2x^2 + ... +anx^n的值，输入x, n, a0, a1, ... ,an,
//输出多项式P(x,n)的值，设计算法求解，请选择合适的输入、输出格式，要求算法具有较好的时间性能。
#include <iostream>
#include <string>
using namespace std;

//法一：双重循环
double func1(double x, int n)
{//此方法输入系数a时为升幂方法输入
	double a, sum = 0, product = 1;
	for (int i = 0; i < n; i++)
	{
		cout << "输入a" << endl;
		cin >> a;
		product = 1;
		for (int j = 0; j < i; j++)
		{
			product *= x;
		}
		sum += a*product;
	}
	return sum;
}

//法二：一重循环
double func2(double x, int n)
{//此方法输入系数a时需要由降幂顺序输入
	double a, sum = 0;
	for (int i = 0; i < n; i++)
	{
		cout << "输入a" << endl;
		cin >> a;
		sum = sum*x + a;
	}
	return sum;
}
int main()
{
	double x;
	int n;
	cout << "输入x:" << endl;
	cin >> x;
	cout << "输入n:" << endl;
	cin >> n;
	
	cout << "和为：" << func1(x, n) << endl;
	system("pause");
	return 0;
}