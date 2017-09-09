#include<iostream>
using namespace std;
class A
{
public:
	A()  { cout << "A" << endl; }
	~A() { cout << "~A" << endl; }
};
class B
{
public:
	B()
	{
		f();  cout << "B" << endl;
	}
	virtual void f()
	{
		cout << "B::f" << endl;
	}
	virtual ~B()
	{
		cout << "~B" << endl;
	}
};

class D :public B, public A//建立对象的时候先调用基类的构造函数函数把继承的基类的成员进行初始化，然后再对自身变量进行初始化
{
public:
	D()	{ cout << "D" << endl; }
	void f() { cout << "D::f" << endl; }
	virtual ~D() { cout << "~D" << endl; }
private:
	A  a;
};
int  main()
{
	B* pB = new D;
	pB->f();
	delete pB;
	system("pause");
	return 0;
}
/*
B::f
B
A
D
D::f
~D
~A
~B
*/
