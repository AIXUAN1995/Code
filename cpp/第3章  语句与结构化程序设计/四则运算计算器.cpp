#include <iostream>
using namespace std;
int main()
{
	double a, b, c;
	char d;
	cout<<"������ʽ"<<endl;
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
		cout<<"��������"<<endl;
	}
	return 0;
}