#include <iostream>
#include <string>
#include <cmath>
using namespace std;
const double PI = 3.14159;
//定义抽象类Shape
class Shape
{
public:
	virtual double area() = 0;//面积
	virtual double circumference() = 0;//周长
	virtual void showInformation() = 0;//图形信息
};
//定义圆形类Circle
class Circle:public Shape
{
public:
	Circle(double r)
	{
		radius = r;
	}
	virtual double area()
	{
		return PI*radius*radius;
	}
	virtual double circumference()
	{
		return PI*2*radius;
	}
	virtual void showInformation()
	{
		cout<<"形状：圆形"<<","<<"半径："<<radius<<endl;
	}
protected:
	double radius;
};
//定义正方形类Square
class Square:public Shape
{
public:
	Square(double len)
	{
		length = len;
	}
	virtual double area()
	{
		return length*length;
	}
	virtual double circumference()
	{
		return 4*length;
	}
	virtual void showInformation()
	{
		cout<<"形状：正方形"<<","<<"边长："<<length<<endl;
	}
protected:
	double length;
};
//定义长方形类Rectangle
class Rectangle:public Shape
{
public:
	Rectangle(double len, double wid)
	{
		length = len;
		width = wid;
	}
	virtual double area()
	{
		return length*width;
	}
	virtual double circumference()
	{
		return 2*(length+width);
	}
	virtual void showInformation()
	{
		cout<<"形状：长方形"<<","<<"长、宽："<<length<<","<<width<<endl;
	}
protected:
	double length, width;
};
//定义三角形类Triangle
class Triangle:public Shape
{
public:
	Triangle(double a, double b, double c)
	{
		side1 = a;
		side2 = b;
		side3 = c;
	}

	virtual double area()
	{
		double p = (side1+side2+side3)/2;
		return sqrt(p*(p-side1)*(p-side2)*(p-side3));
	}
	virtual double circumference()
	{
		return (side1+side2+side3);
	}
	virtual void showInformation()
	{
		cout<<"形状：三角形"<<","<<"三个边长："<<side1<<","<<side2<<","<<side3<<endl;
	}
protected:
	double side1, side2, side3;
};
int main()
{
	Circle cir(3);
	Square sq(4);
	Rectangle rect(2,5);
	Triangle tri(3, 4, 5);
	Shape *sp[]= {&cir, &sq, &rect, &tri};
	Shape *maxarea = sp[0], *maxcircumference = sp[0];
	for(int i=1; i<4; i++)
	{
		if(sp[i]->area()>maxarea->area())
			maxarea = sp[i];
		if(sp[i]->circumference()>maxcircumference->circumference())
			maxcircumference = sp[i];
	}
	cout<<"具有最大面积的图形："<<endl;
	maxarea->showInformation();
	cout<<"具有最大周长的图形："<<endl;
	maxcircumference->showInformation();
	system("pause");
	return 0;
}