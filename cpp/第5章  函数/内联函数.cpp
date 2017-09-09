#include <iostream>
inline int f(int x)//用内联函数可以减少运行的时间，再编译的同时将函数放到了指定位置，省得用的时候在找
{
	return x*x;
}
//不过有三种情况内联函数不能实现
//1.使用switch时
//2.使用循环的时候
//3.执行次数超过1000次时
int main()
{
	using namespace std;
	int n;
	cout<<"请输入要计算的数"<<endl;
	cin>>n;
	cout<<f(n)<<endl;
	system("pause");
	return 0;
}