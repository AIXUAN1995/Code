#include <iostream>
using namespace std;
int main()
{
	const int n = 10;
	int a[n][n];

	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			a[i][j] = 0;
		}
	}
	for(int i=0; i<n; i++)
	{
		a[i][0] = 1;
		a[i][i] = 1;
	}
	for(int i=2; i<n; i++)
	{
		for(int j=1; j<i; j++)
		{
			a[i][j] = a[i-1][j-1] + a[i-1][j];
		}
	}
	
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<i+1; j++)
		{
			cout<<a[i][j]<<'\t';
		}
		cout<<endl;
	}
	system("pause");
	return 0;
}
