//�༶����
#include <iostream>
#include <string>
using namespace std;
class Point//����
{
public:
	Point(int x1, int y1) :x(x1), y(y1){}
	void pDisplay()
	{
		cout << "x=" << x << endl;
		cout << "y=" << y << endl;
	}
private:
	int x;
	int y;
};
class Circle :public Point
{
public:
	Circle(int x1, int y1, int r1):Point(x1, y1), r(r1){}
	void cDisplay()
	{
		pDisplay();
		cout << "r=" << r << endl;
	}
	double area()
	{
		return 3.1415926*r*r;
	}
private:
	int r;
};
class Volume :public Circle
{
public:
	Volume(int x1, int y1, int r1, int h1) :Circle(x1, y1, r1), h(h1){}
	void vDisplay()
	{
		cDisplay();
		cout << "h=" << h << endl;
	}
	double vol()
	{
		return area()*h;
	}
private:
	int h;
};
int main()
{
	Point p(10, 20);
	cout << "������꣺" << endl;
	p.pDisplay();
	Circle c(10, 20, 5);
	cout << "Բ��Բ�����ꡢ�뾶�������" << endl;
	c.cDisplay();
	cout << "a=" << c.area() << endl;
	Volume v(1, 20, 5, 4);
	cout << "Բ�����Բ�����ꡢ�뾶���ߺ������" << endl;
	v.vDisplay();
	cout << "v=" << v.vol() << endl;
	system("pause");
	return 0;
}