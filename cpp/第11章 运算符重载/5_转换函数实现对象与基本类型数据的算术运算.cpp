#include <iostream>
using namespace std;
class Circle
{
public:
	Circle()
	{
		x = 0;
		y = 0;
		r = 1;
	}
	Circle(double x1, double y1, double r1)
	{
		x = x1;
		y = y1;
		r = r1;
	}
	operator double()
	{
		return r;
	}
	friend ostream & operator<<(ostream &, Circle &);
private:
	double x;
	double y;
	double r;
};
ostream & operator<<(ostream &output, Circle &c)
{
	output << "(" << c.x << "," << c.y << "," << c.r << ")";
	return output;
}
int main()
{
	Circle c1(7.5, 5.8, 10.3);
	double r2, r3, r4, r5;
	r2 = c1 + 5.7;
	r3 = c1 - 4.6;
	r4 = c1 * 3;
	r5 = c1 / 2;
	cout << "c1=" << c1 << endl;
	cout << "r2=" << r2 << endl;
	cout << "r3=" << r3 << endl;
	cout << "r4=" << r4 << endl;
	cout << "r5=" << r5 << endl;
	system("pause");
	return 0;
	/*
	程序中实现了Circle对象与double型数据的加减乘除运算，
	通过定义一个类型转换函数operator double(),把对象Circle对象转换为double型数据，
	之后，便可容易的实现相关运算了
	*/
}