#include <iostream>
#include <string>
using namespace std;
#define SIGN(A) ((A > 0) ? 1 : -1)
int IntegerMultiply(int X, int Y, int N)
{
	int sign = SIGN(X) * SIGN(Y);
	int x = abs(X);
	int y = abs(Y);
	if ((0 == x) || (0 == y))
		return 0;
	if (1 == N)
		return x*y;
	else
	{
		int XL = x / pow(10, N / 2);
		int XR = x - XL * pow(10, N / 2);
		int YL = y / pow(10, N / 2);
		int YR = y - YL * pow(10, N / 2);

		int XLYL = IntegerMultiply(XL, YL, N / 2);
		int XRYR = IntegerMultiply(XR, YR, N / 2);
		int XLYRXRYL = IntegerMultiply(XL + XR, YR + YL, N / 2) - XLYL - XRYR;
		return sign * (XLYL * pow(10, N) + XLYRXRYL * pow(10, N / 2) + XRYR);
	}
}
int main()
{
	int x = 42311;
	int y = 43211;
	cout << "x * y = " << IntegerMultiply(x, y, 8) << endl;
	cout << "x * y = " << x*y << endl;
	system("pause");
	return 0;
}