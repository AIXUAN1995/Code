#include <iostream>
#include <string>
#include <cmath>
using namespace std;
const double PI = 3.14159;
//���������Shape
class Shape
{
public:
	virtual double area() = 0;//���
	virtual double circumference() = 0;//�ܳ�
	virtual void showInformation() = 0;//ͼ����Ϣ
};
//����Բ����Circle
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
		cout<<"��״��Բ��"<<","<<"�뾶��"<<radius<<endl;
	}
protected:
	double radius;
};
//������������Square
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
		cout<<"��״��������"<<","<<"�߳���"<<length<<endl;
	}
protected:
	double length;
};
//���峤������Rectangle
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
		cout<<"��״��������"<<","<<"������"<<length<<","<<width<<endl;
	}
protected:
	double length, width;
};
//������������Triangle
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
		cout<<"��״��������"<<","<<"�����߳���"<<side1<<","<<side2<<","<<side3<<endl;
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
	cout<<"������������ͼ�Σ�"<<endl;
	maxarea->showInformation();
	cout<<"��������ܳ���ͼ�Σ�"<<endl;
	maxcircumference->showInformation();
	system("pause");
	return 0;
}