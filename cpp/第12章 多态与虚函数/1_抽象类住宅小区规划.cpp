#include <iostream>
#include <string>
#include <cmath>
using namespace std;
//���������PlanElement
class PlanElement
{
public:
	virtual double area() = 0;
};
//�����̵���Green
class Green:public PlanElement
{
public:
	virtual double area() = 0;
};
//���峤�����̵���Rectangle
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
//����Բ���̵�Circle
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
//�����������̵���Triangle
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
//���彨������Constructor
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
//���巿����Building
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
	Rectangle rect(80,7);//�������̵ض���
	Circle circ(12);//Բ���̵ض���
	Triangle tri(8,12,15);//�������̵ض���
	Building build(112, 12, 30);//¥������
	Road ro(180, 9, "CementRoad");//��·����
	PlanElement *ptr;//�������ָ��
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