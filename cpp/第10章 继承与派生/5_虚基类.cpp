///*
//在对虚基类的继承中，最后的派生类不仅要对新增数据成员和直接基类进行初始化，
//而且还对虚基类进行初始化。
//
//虚基类的其他派生类对虚基类的初始化被编译系统忽略（即不起作用），
//以保证虚基类的数据成员仅被初始化一次。
//
//*/
#include <iostream>
#include <string>
using namespace std;
class A
{
public:
	A(int x = 1)
	{
		a = x;
	}
	int cube()
	{
		return a*a*a;
	}
protected:
	int a;
};
class B :virtual public A
{
public:
	B(int x, int y):A(x)
	{
		b = y;
	}
	int add()
	{
		return a + b;
	}
protected:
	int b;
};
class C :virtual public A
{
public:
	C(int x, int z):A(x)
	{
		c = z;
	}
	int add()
	{
		return a + c;
	}
protected:
	int c;
};
class D :public B, public C
{
public:
	D(int x, int y, int z, int u) :A(x), B(x, y), C(x, z)
	{
		d = u;
	}
	int add()
	{
		return a + b + c + d;
	}
private:
	int d;
};
int main()
{
	D d(2, 3, 5, 6);
	cout << d.cube() << endl;//正确，类d中只有一个成员函数cube();
	cout << d.add() << endl;
	system("pause");
	return 0;
}