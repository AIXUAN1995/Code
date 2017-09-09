#include <iostream>
using namespace std;
int main()
{
	const char *p, *q;
	p = "xyz";
	cout<<*p<<endl;//x
	cout<<p<<endl;//xyz
	cout<<p[0]<<" "<<p[1]<<endl;//执行结果为x y
	//p[0] = 'a';//如果定义的指针为const char *p则编译都不会通过，如果定义的变量是char *p,运行时异常
	cout<<sizeof(p);//4

	//数组与指针
	char a1[] = "abcdefghihklmn";
	char *a2 = "opqrstuvwxyz";

	cout<<&a1<<endl;//地址：与字符串首地址相同
	cout<<a1<<endl;//abcdefghijklmn
	cout<<&a1[0]<<endl;//abcdefghijklmn

	cout<<&a2<<endl;//地址：与字符串首地址相同
	cout<<a2<<endl;//opqrstuvwxyz
	cout<<&a2[0]<<endl;//opqrstuvwxyz

	system("pause");
	return 0;
}