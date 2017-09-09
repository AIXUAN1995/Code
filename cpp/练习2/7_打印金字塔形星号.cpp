//打印金字塔形星号
#include <iostream>
using namespace std;
int main()
{
	int n;
	cout<<"输入金字塔层数"<<endl;
	cin>>n;
	for(int i=0; i<n; i++)//i代表三角形的第i行
	{
		for (int j = i+1; j < n; j++)//j代表在第i行左边的第j个空白字符for(int j=n-1-i; j>=0; j--)
			cout<<" ";
		for(int k=0; k<2*i+1; k++)//k表示第i行的第k个星号字符
			cout<<"*";
		cout<<endl;
	}
	system("pause");
	return 0;
}