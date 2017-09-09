#include <iostream>
#include <cmath>
using namespace std;
class Triangle
{
private:
	double a;
	double b;
	double c;
	double p;
public:
	void set(double, double, double);
	double circumference();
	double area();
};
void Triangle::set(double x,double y, double z)
{
	a = x;
	b = y;
	c = z;
}
double Triangle::circumference()
{
	return a + b + c;
}
double Triangle::area()
{
	p = circumference()/2;
	return sqrt(p*(p - a)*(p - b)*(p - c));
}
int main()
{
	double a, b, c;
	cout << "���������ߵĳ��ȣ�" << endl;
	cin >> a >> b >> c;
	Triangle t;
	t.set(a, b, c);
	cout << "�ܳ�Ϊ��" << t.circumference();
	cout << "���Ϊ��" << t.area();
	system("pause");
	return 0;
}