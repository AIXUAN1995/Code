#include <iostream>
using namespace std;
int main()
{
	const int n = 6;
	int a[n];
	bool flag = false;
	cout<<"ÊäÈë"<<n<<"¸öÊý"<<endl;
	for(int i=0; i<n; i++)
		cin>>a[i];
	cout<<a[0]<<'\t';
	for(int i=1; i<n; i++)
	{
		for(int j=0; j<i; j++)
		{
			if(a[i] == a[j])
			{
				flag = false;
				break;
			}
			else
			{
				flag = true;
				continue;
			}
		}
		if(flag)
		{
			cout<<a[i]<<'\t';
		}
		
	}
	system("pause");
	return 0;
}