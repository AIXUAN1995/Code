#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int n;
	cout<<"���������������"<<endl;
	cin>>n;
	vector<double>num(n);
	cout<<"����������Ԫ�أ�"<<endl;
	for(int i=0; i<n; i++)
	{
		cin>>num[i];
	}
	double temp = num[n-1];
	for(int i=n-2; i>=0; i--)
	{
		num[i+1] = num[i];
	}
	num[0] = temp;
	for(int i=0; i<n; i++)
	{
		cout<<num[i]<<" ";
	}
	system("pause");
	return 0;
}