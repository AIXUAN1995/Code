#include <iostream>
using namespace std;
class A
{
public:
	A(int i, double d)
	{
		a_i = i;
		a_d = d;
	}
	void set(int i, double d)
	{
		a_i = i;
		a_d = d;
	}
	void display()
	{
		cout << "输出信息:" << endl;
		cout << "a_i = " << a_i << endl;
		cout << "a_d = " << a_d << endl;
	}
	void input()
	{
		cin >> a_i >> a_d;
	}
private:
	int a_i;
	double a_d;
};
int main()
{
	A a(1, 3.5);//定义的时候系统调用构造函数为对象赋初值
	a.display();

	a.set(2, 5.5);//定义完成之后调用set()函数改变对象成员函数的值
	a.display();

	a.input();//通过input函数改变成员函数的值
	a.display();

	return 0;
}