#include <iostream>
using namespace std;
void func(int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<"*"<<'\t';
		}
		cout<<endl;
	}
	cout<<endl;
}
void max(int x,int y,int z)
{
	cout<<((x>y?x:y)>z?(x>y?x:y):z)<<endl;
}
int main()
{
	int n;
	cin>>n;
	func(n);
	int x, y, z;
	cin>>x>>y>>z;
	max(x,y,z);
	system("pause");
	return 0;
}