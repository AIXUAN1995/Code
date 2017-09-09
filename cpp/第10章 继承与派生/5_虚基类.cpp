///*
//�ڶ������ļ̳��У����������಻��Ҫ���������ݳ�Ա��ֱ�ӻ�����г�ʼ����
//���һ����������г�ʼ����
//
//����������������������ĳ�ʼ��������ϵͳ���ԣ����������ã���
//�Ա�֤���������ݳ�Ա������ʼ��һ�Ρ�
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
	cout << d.cube() << endl;//��ȷ����d��ֻ��һ����Ա����cube();
	cout << d.add() << endl;
	system("pause");
	return 0;
}