/*头文件用于存放对类型定义、函数声明、全局变量声明等实体的声明，作为对外接口；
而源程序文件存放类型的实现、函数体、全局变量定义.*/
#include <iostream>
#include "头文件.h"
using namespace std;
int add(int a, int b)
{
	extern int m;//声明m为有外部变量，实际上是告诉编译系统m的定义在后面，
				//并不是对m的定义，这个语句并不能同时给m赋值
	m++;
	return a+b;
}
int n=0;
int sub(int a, int b)
{
	n++;
	return a-b;
}
int main()
{
	int x, y;
	for(int i=1; i<=4; ++i)
	{
		cout<<"请输入x和y的值："<<endl;
		cin>>x>>y;
		if(x<y)
			cout<<"x+y="<<add(x, y)<<endl;
		else
			cout<<"x-y="<<sub(x, y)<<endl;
	}
	cout<<"m="<<m<<endl;
	cout<<"n="<<n<<endl;
	system("pause");
	return 0;
}