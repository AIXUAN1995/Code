#include <iostream>
using namespace std;
void add(double x1, double y1, double x2, double y2, double &x, double &y)
{
	x = x1 + x2;
	y = y1 + y2;
}
int main()
{
	double x1, x2, y1, y2, x, y;
	cin >> x1 >> x2 >> y1 >> y2;
	add(x1, x2, y1, y2, x, y);
	if (y > 0)
		cout << x << '+' << y << 'i' << endl;
	else if (y < 0)
		cout << x << y << 'i' << endl;
	else
		cout << x;
	system("pause");
	return 0;
}