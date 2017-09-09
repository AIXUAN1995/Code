/*
虽然带参数的构造函数Rectangle()和赋值成员函数set()在形式与功能上基本相同，
但二者在程序中的作用是不同的，也不能相互替代。
构造函数只有在定义对象时才执行，而且是自动执行（不需要书写调用语句），为新建立的对象赋值，
赋值成员函数的功能就是改变对象的取值，根据需要，随时可以通过函数调用语句调用执行。

带默认参数的构造函数和其他构造函数同时出现时容易出现二义性：
Rectangle(int len = 1, int w = 1);
Rectangle();
Rectangle(int);

Rectangle r1;
Rectangle r2(8);

定义对象r1时，由于没有给出任何参数，即可以调用无参构造函数，也可以调用全部参数都带默认值的构造函数；
定义对象r2是，由于给出了一个参数，既可以调用带1个参数的构造函数，也可以调用全部参数都带默认值的构造函数。
以上两种情况都会出现二义性，编译系统报语法错误（指定了多个默认构造函数）
*/
#include <iostream>
using namespace std;
class Rectangle
{
public:
	Rectangle();//无参构造函数
	Rectangle(int, int);//有参构造函数
	//Rectangle(int len = 1, int w = 3);//带默认值的构造函数
	void set(int len, int w);
	int area();
private:
	int length;
	int width;
};
Rectangle::Rectangle()
{
	length = 3;
	width = 5;
}
Rectangle::Rectangle(int len, int w)//定义带参数的构造函数
{
	length = len;
	width = w;
}
void Rectangle::set(int len, int w)
{
	length = len;
	width = w;
}
int Rectangle::area()
{
	return (length*width);
}
int main()
{
	Rectangle rec1;
	cout << rec1.area() << endl;
	Rectangle rec2;
	rec2.set(6, 8);
	cout << rec2.area() << endl;
	Rectangle rec3(5, 6);
	cout << rec3.area() << endl;
	rec3.set(7, 8);
	cout << rec3.area() << endl;
	system("pause");
	return 0;
}