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
	Complex(double r)
	{
		real = r;
		imag = 0;
	}
	friend Complex operator+(const Complex &c1, const Complex &c2)
	{
		return Complex(c1.real + c2.real, c1.imag + c2.imag);
	}
	friend ostream &operator<<(ostream &cout, Complex &c)
	{
		cout << c.real;
		if (c.imag > 0)
		{
			cout << "+";
			cout << c.imag << "i";
		}
		if (c.imag < 0)
		{
			cout << c.imag << "i";
		}
		return cout;
	}
private:
	double real;
	double imag;
};
int main()
{
	Complex c1, c2(2.5, 3.9), c3(c2), c4, c5;
	c4 = c3 + 3.5;
	c5 = c2 + c4;
	cout << "c1=" << c1 << endl;
	cout << "c2=" << c2 << endl;
	cout << "c3=" << c3 << endl;
	cout << "c4=" << c4 << endl;
	cout << "c5=" << c5 << endl;
	system("pause");
	return 0;
}