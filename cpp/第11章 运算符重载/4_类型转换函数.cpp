#include <iostream>
using namespace std;
class Complex
{
public:
	Complex()
	{
		real = 0;
		imag = 0;
	}
	Complex(double r, double i)
	{
		real = r;
		imag = i;
	}
	Complex(Complex &c)
	{
		real = c.real;
		imag = c.imag;
	}
	Complex(double r)
	{
		real = r;
		imag = 0;
	}
	operator double()
	{
		return real;
	}
private:
	double real;
	double imag;
};
int main()
{
	Complex c3(2.5, 3.9);
	double d = c3 + 3.5;
	/*
	由于左边变量d是double型，c3+3.5的运算结果应为double型的数据，
	所以需要先把Complex对象c3转换为double型数据，程序中定义类型转换函数
	*/

	cout << d << endl;
	cout << c3 + 3.5 << endl;//直接输出的话输出的也是double型的值6
	system("pause");
	return 0;
}