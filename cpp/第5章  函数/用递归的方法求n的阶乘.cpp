#include <iostream>
int jiecheng(int n)
{
	if(n<=1)
	{
		return 1;
	}
	return (n * jiecheng(n-1));
}
int main()
{
	using namespace std;
	int n;
	cout<<"请输入要计算的数"<<endl;
	cin>>n;
	cout<<jiecheng(n)<<endl;
	system("pause");
	return 0;
}