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
	cout<<"������Ҫ�������"<<endl;
	cin>>n;
	cout<<jiecheng(n)<<endl;
	system("pause");
	return 0;
}