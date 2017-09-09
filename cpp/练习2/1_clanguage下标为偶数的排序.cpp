#include <iostream>
#include <string>
using namespace std;
int main()
{
	char a[] = "clanguage", t;
	int i, j, k, s;
	s = strlen(a);
	for(i=0; i<s-2; i+=2)
	{
		k = i;
		for(j=i+2; j<s; j=j+2)
		{
			if(a[i]>a[j])
				k = j;
			if(k != i)
			{
				t = a[i];
				a[i] = a[k];
				a[k] = t;
				k = i;
			}
			puts(a);
			cout<<endl;
		}
	}
	puts(a);
	cout<<endl;
	system("pause");
	return 0;
}