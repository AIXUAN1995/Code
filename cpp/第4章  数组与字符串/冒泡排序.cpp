#include <iostream>
using namespace std;
int main()
{
	int a[] = {35, 54, 76, 98, 43, 13, 9};
	int len = sizeof(a)/sizeof(a[0]);
	for(int i=0; i<len; i++)
	{
		for(int j=0; j<len-1-i; j++)
		{
			if(a[j]>a[j+1])
			{
				int temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}
	for(int k=0; k<len; k++)
	{
		cout<<a[k]<<endl;
	}
	return 0;
}