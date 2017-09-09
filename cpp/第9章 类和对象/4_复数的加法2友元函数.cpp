#include <iostream>
using namespace std;
class complex
{
private:
	double x1, x2, y1, y2, *x = NULL, *y = NULL;
public:
	complex(double a1, double a2, double b1, double b2, double &a, double &b)
	{
		x1 = a1;
		x2 = a2;
		y1 = b1;
		y2 = b2;
		x = &a;
		y = &b;
	}
	friend void add(complex &com);
};
void add(complex &com)
{
	*com.x = com.x1 + com.x2;
	*(com.y) = com.y1 + com.y2;
}
int main()
{
	double x1, x2, y1, y2, x, y;
	cin >> x1 >> x2 >> y1 >> y2;
	complex com = { x1, x2, y1, y2, x, y };
	add(com);
	if (y > 0)
		cout << x << '+' << y << 'i' << endl;
	else if (y < 0)
		cout << x << y << 'i' << endl;
	else
		cout << x;
	system("pause");
	return 0;
}