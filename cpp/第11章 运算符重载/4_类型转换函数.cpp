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
	������߱���d��double�ͣ�c3+3.5��������ӦΪdouble�͵����ݣ�
	������Ҫ�Ȱ�Complex����c3ת��Ϊdouble�����ݣ������ж�������ת������
	*/

	cout << d << endl;
	cout << c3 + 3.5 << endl;//ֱ������Ļ������Ҳ��double�͵�ֵ6
	system("pause");
	return 0;
}