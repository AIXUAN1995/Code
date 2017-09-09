#include <iostream>
using namespace std;
int main()
{
	int j=0;
	for(int i=100; i<=200; i++)
	{
		if(i%3==0 && i%5!=0)
		{
			cout<<i<<endl;
			++j;
		}

	}
	cout<<j<<endl;
	return 0;
}