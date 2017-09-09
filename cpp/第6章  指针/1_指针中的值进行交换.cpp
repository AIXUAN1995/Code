#include <iostream>
using namespace std;
int main()
{
	int a = 9, b = 5;
	int *p1, *p2;
	//cout<<*p1<<'\t'<<*p2<<endl;//为什么这句会出错？
	p1 = &a;
	p2 = &b;
	cout<<*p1<<'\t'<<*p2<<endl;
	cout<<p1<<'\t'<<p2<<endl;
	int *temp;
	temp = p1;
	p1 = p2;
	p2 = temp;
	cout<<*p1<<'\t'<<*p2<<endl;
	cout<<p1<<'\t'<<p2<<endl;
	system("pause");
	return 0;
}