#include <iostream>
#include <string>
using namespace std;
class A
{
public:
	A(int x1):x(x1)
	{
		cout<<"���캯��A�����ã�\n";
	}
	~A()
	{
		cout<<"����������ִ�У�\n";
	}
private:
	int x;
};
class B:public A
{
public:
	B(int x1, int y1):A(x1), y(y1)
	{
		cout<<"���캯��B�����ã�\n";
	}
	~B()
	{
		cout<<"��������~B�����ã�\n";
	}
private:
	int y;
};
class C:public B
{
public:
	C(int x1, int y1, int x11, int y11, int z1):B(x1, y1),b(x11, y11),z(z1)
	{
		cout<<"���캯��C�����ã�\n";
	}
	~C()
	{
		cout<<"��������~C�����ã�\n";
	}
private:
	B b;
	int z;
};
int main()
{
	A a1(10);
	B b1(2,5);
	C c1(2,4,6,8,10);
	system("pause");
	return 0;
}