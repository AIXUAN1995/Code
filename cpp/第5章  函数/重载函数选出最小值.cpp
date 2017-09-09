#include <iostream>
#include <vector>
using namespace std;
void max1(double a, double b)
{
	if(a < b)
		cout<<a<<endl;
	else
		cout<<b<<endl;
}
void max1(double a, double b, double c)
{
	if(a > b)
	{
		if(b > c)
			cout<<c<<endl;
		else
			cout<<b<<endl;
	}
	else
	{
		if(a > c)
			cout<<c<<endl;
		else
			cout<<a<<endl;
	}	
}
int main()
{
	int n;
	cout<<"请输入要比较的数字个数(两个或者是三个)"<<endl;
	cin>>n;
	vector<double>num(n);
	cout<<"请输入要比较的数字"<<endl;
	for(int i=0; i<n; i++)
		cin>>num[i];
	if(n == 2)
		max1(num[0], num[1]);
	else if(n == 3)
		max1(num[0], num[1], num[2]);
	else
		cout<<"对不起您输入的数字个数有误"<<endl;
	system("pause");
	return 0;
}
