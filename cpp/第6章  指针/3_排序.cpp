#include <iostream>
#include <vector>
using namespace std;
void sort(double *p, int n)
{
	for(int i=0; i<n-1; i++)
	{
		bool flag = true;
		for(int j=0; j<n-1-i; j++)
		{
			if(*(p+j)<*(p+j+1))
			{
				double temp = *(p+j);
				*(p+j) = *(p+j+1);
				*(p+j+1) = temp;
				flag = false;
			}
		}
		if(flag)
			break;
	}
	for(int i=0; i<n; i++)
		cout<<*(p+i)<<" ";
}
int main()
{
	int n;
	cout<<"请输入数据个数："<<endl;
	cin>>n;
	vector<double>sum(n);
	cout<<"请输入数据:"<<endl;
	for(int i=0; i<n; i++)
		cin>>sum[i];
	sort(&sum[0], n);
	system("pause");
	return 0;
}