//普通函数重载运算符
#include <iostream>
#include <string>
using namespace std;
class A
{
private:
	int a;
	double b;
public:
	A(int a1, double b1)
	{
		a = a1;
		b = b1;
	}
	void display()
	{
		cout << a << " " << b;

	}
	//没法调用
	//ostream &operator<<(ostream &)
	//{
	//	cout << a << " " << b;
	//}
	int geta()
	{
		return a;
	}
	double getb()
	{
		return b;
	}
	void seta(int a1)
	{
		a = a1;
	}
	void setb(double b1)
	{
		b = b1;
	}
};
A operator+( A &a1,  A &a2)
{
	
	A c(0,0);
	c.seta(a1.geta()+a2.geta());
	c.setb(a1.getb()+a2.getb());
	return c;
}
int main()
{
	A a1(1, 1.1);
	A a2(1, 1.1);
	A a3 = a1 + a2;
	cout << a3.geta()<<a3.getb();
	system("pause");
	return 0;
}