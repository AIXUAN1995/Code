//法一
#include <iostream>
using namespace std;
int main()
{
	int num, len = 0, n, sum = 0;
	cout<<"请输入一个整数：";
	cin>>num;
	while(num!=0)
	{
		n = num % 10;
		num /= 10;
		sum += n;
		len++;
	}
	cout<<"位数："<<len<<"各位数码之和："<<sum;
	system("pause");
	return 0;
}
//法二
#include<iostream>
#include<string>
using namespace std;
int main()
{
	int n, m=0, sum = 0, m1;
	cin>>n;
	for(int i=1; i<=n; i=i*10)
		m++;				//判断位数
	for(int i=0; i<m; i++)
	{
		sum = sum+n%10;
		n /= 10;
	}
	cout<<m<<endl;
	cout<<sum;
	system("pause");
	return 0;
}