#include <iostream>
using namespace std;
int main()
{
	const int n = 6;
	int a[n];
	bool flag = false;
	cout<<"������"<<n<<"����"<<endl;
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
	for(int i=0; i<n; i++)			//��������
	{
		cout<<a[i]<<endl;
	}
	int num = 1;					//������
	for(int i=1; i<n; i++)
	{
		if(a[i] == a[i-1])
		{
			num++;
		}
		else
		{
			cout<<a[i-1]<<"�ĸ���:"<<num<<endl;
			num = 1;
		}
	}
	cout<<a[n-1]<<"�ĸ���:"<<num<<endl;
	system("pause");
	return 0;
}