#include <iostream>
using namespace std;
//—°‘Ò≈≈–Ú
int main()
{
	int a[] = {35, 54, 76, 98, 43, 13, 9};
	int len = sizeof(a)/sizeof(a[0]);
	for(int i=0; i<len-1; i++)
	{
		for(int j=i; j<len; j++)
		{
			if(a[i]>a[j])
			{
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
	for(int k=0; k<len; k++)
	{
		cout<<a[k]<<endl;
	}
	return 0;
}