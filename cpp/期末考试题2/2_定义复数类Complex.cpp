/*
���帴����Complex��ʹ���������˽�����ݳ�Ա��ʵ��float real���鲿float imag�����岢ʵ���ܹ��������Complex�����ӷ�����������غ������Լ��ܹ����Complex�����������������������غ�����
*/
#include <iostream> 
using namespace std;
class Complex
{
private:
	float real;
	float imag;
public:
	Complex(){}
	Complex(float real1, float imag1)
	{
		real = real1;
		imag = imag1;
	}
	Complex operator+(const Complex &c1)
	{
		Complex c;
		c.real = real + c1.real;
		c.imag = imag + c1.imag;
		return c;
	}
	friend ostream &operator<<(ostream &, Complex &);
};
ostream &operator<<(ostream & out, Complex & c)
{
	if (c.imag != 0 && c.real != 0)
		out << c.real << "+" << c.imag << "i" << endl;
	else if(c.real == 0)
		cout << c.imag << "i" << endl;
	else
		out << c.real;
	return out;
}
int main()
{
	Complex c1(2, 4);
	Complex c2(-2, 7);
	Complex c3 = c1 + c2;
	cout << c3;
	system("pause");
	return 0;
}
