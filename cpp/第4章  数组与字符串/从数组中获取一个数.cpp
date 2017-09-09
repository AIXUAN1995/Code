#include <iostream>
using namespace std;
int main()
{
	int n;
	int a[] = {12, 34, 45, 56 , 76, 56};
	cout<<"请输入要查询的数字"<<endl;
	cin>>n;
	bool flag = true;
	for(int i=0; i<sizeof(a)/sizeof(a[0]); i++)
	{
		if(n==a[i])
		{
			cout<<"您要找的数字所在的位置是："<<i+1<<endl;
			flag = false;
			
		}
	}
	if(flag)
	{
		cout<<"对不起，您输入的数字不存在"<<endl;
	}
	return 0;
}