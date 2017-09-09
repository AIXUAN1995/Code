#include <iostream>
using namespace std;
//判断是不是完数
bool f(int n)
{
	int sum=0;
	for(int i=1;i<n;i++)
	{
		if(n%i==0)
		{
			sum += i;
		}
	}
	if(sum==n)
	{
		return true;
	}
	else
	{
		return false;
	}
	
}
//将完数写成因式相加的形式输出
void res(int n)
{
	cout<<n<<" = 1";
	for(int i=2;i<n;++i)
	{
		if(n%i==0)
		{
			cout<<" + "<<i;
		}
	}
	cout<<endl;
}
int main()
{
	int a;
	cout<<"请输入一个数a，以判断1到a中的完数";
	cin>>a;
	for(int i=1;i<a;++i)
	{
		if(f(i))
		{
			res(i);
		}
	}
	system("pause");
	return 0;
}