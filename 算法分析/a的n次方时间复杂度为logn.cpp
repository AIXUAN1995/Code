#include <iostream>
using namespace std;
double exponent(double a, int n)
{
	if (n == 1)
		return a;
	double d = exponent(a, n >> 1);
	d = d*d;
	if ((n & 1) == 1)
	{
		d = d*a;
	}
	return d;
}
int main()
{
	double a = 2;
	int n = 9;
	cout << exponent(a, n);
	system("pause");
	return 0;
}