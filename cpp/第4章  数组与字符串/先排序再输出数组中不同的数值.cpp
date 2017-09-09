#include <iostream>
using namespace std;
int main()
{
	const int n = 6;
	int a[n];
	bool flag = false;
	cout<<"请输入"<<n<<"个数"<<endl;
	for(int i=0; i<n; i++)
	{
		cin>>a[i];
	}
	for(int i=0; i<n-1; i++)
	{
		flag = false;
		for(int j=0; j<n-1-i; j++)
		{
			if(a[j]>a[j+1])
			{
				int temp;
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
				flag = true;
			}
			
		}
		if(!flag)
			{
				break;
			}
	}
	for(int i=0; i<n; i++)			//排序后输出
	{
		cout<<a[i]<<endl;
	}
	int num = 1;					//计数器
	for(int i=1; i<n; i++)
	{
		if(a[i] == a[i-1])
		{
			num++;
		}
		else
		{
			cout<<a[i-1]<<"的个数:"<<num<<endl;
			num = 1;
		}
	}
	cout<<a[n-1]<<"的个数:"<<num<<endl;
	system("pause");
	return 0;
}