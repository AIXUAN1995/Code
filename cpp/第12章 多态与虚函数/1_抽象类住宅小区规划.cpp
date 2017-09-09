#include <iostream>
#include <string>
#include <cmath>
using namespace std;
//定义抽象类PlanElement
class PlanElement
{
public:
	virtual double area() = 0;
};
//定义绿地类Green
class Green:public PlanElement
{
public:
	virtual double area() = 0;
};
//定义长方形绿地类Rectangle
class Rectangle:public Green
{
public:
	Rectangle(double len,double wid)
	{
		length = len;
		width = wid;
	}
	virtual double area()
	{
		return length*width;
	}
protected:
	double length;
	double width;
};
//定义圆形绿地Circle
class Circle:public Green
{
public:
	Circle(int r):radius(r){}
	virtual double area()
	{
		return 3.14159*radius*radius;
	}
protected:
	double radius;
};
//定义三角形绿地类Triangle
class Triangle:public Green
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
		double s = (side1+side2+side3)/2;
		return sqrt(s*(s-side1)*(s-side2)*(s-side3));

	}
protected:
	double side1, side2, side3;
};
//定义建筑物类Constructor
class Constructor:public PlanElement
{
public:
	Constructor(double len, double wid)
	{
		length = len;
		width = wid;
	}
	virtual double area()
	{
		return length*width;
	}
protected:
	double length, width;
};
//定义房屋类Building
class Building:public Constructor
{
public:
	Building(double len, double wid, int lay):Constructor(len, wid)
	{
		layer = lay;
	}
protected:
	int layer;
};
class Road:public Constructor
{
public:
	Road(double len, double wid, string typ):Constructor(len, wid)
	{
		type = typ;
	}
protected:
	string type;
}; 
int main()
{
	Rectangle rect(80,7);//长方形绿地对象
	Circle circ(12);//圆形绿地对象
	Triangle tri(8,12,15);//三角形绿地对象
	Building build(112, 12, 30);//楼房对象
	Road ro(180, 9, "CementRoad");//道路对象
	PlanElement *ptr;//定义基类指针
	ptr = &rect;
	cout<<ptr->area()<<endl;
	ptr = &circ;
	cout<<ptr->area()<<endl;
	ptr = &tri;
	cout<<ptr->area()<<endl;
	ptr = &build;
	cout<<ptr->area()<<endl;
	ptr = &ro;
	cout<<ptr->area()<<endl;
	system("pause");
	return 0;
}