#include <iostream>
using namespace std;
int main()
{
	const int n = 2;
	int a[n][n];
	int rowsum = 0, colsum = 0, diasum = 0, clisum = 0;
	cout<<"请输入"<<n<<"行"<<n<<"列的数组"<<endl;
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			cin>>a[i][j];
	//行和
	for(int i=0; i<n; i++)
	{
		rowsum = 0;
		for(int j=0; j<n; j++)
		{
			rowsum += a[i][j];
		}
		cout<<"第"<<i+1<<"行的和="<<rowsum<<endl;
	}
	//列和
	for(int j=0; j<n; j++)
	{
		colsum = 0;
		for(int i=0; i<n; i++)
			colsum += a[j][i];
		cout<<"第"<<j+1<<"列的和="<<colsum<<endl;
	}
	//对角线的和
	for(int i=0; i<n; i++)
		diasum  += a[i][i];
	cout<<"对角线元素之和="<<diasum<<endl;
	//斜对角线的和
	for(int i=0; i<n; i++)
		clisum += a[i][n-i-1];
	cout<<"斜对角线之和="<<clisum<<endl;
	system("pause");
	return 0;
}