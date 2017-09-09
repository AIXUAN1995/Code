#include <iostream>
using namespace std;
int main()
{
	double a, b, c;
	char d;
	cout<<"输入表达式"<<endl;
	cin>>a>>d>>c;
	if(d=='+')
	{
		c = a + c;
		cout<<c<<endl;
	}
	else if(d=='-')
	{
		c = a - c;
		cout<<c<<endl;
	}
	else if(d == '*')
	{
		c = a * c;
		cout<<c<<endl;
	}
	else if(d == '/')
	{
		c = a / c;
		cout<<c<<endl;
	}
	else
	{
		cout<<"输入有误"<<endl;
	}
	return 0;
}