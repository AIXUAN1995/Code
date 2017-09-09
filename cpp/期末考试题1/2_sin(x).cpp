#include <iostream>
using namespace std;
int main()
{
	double sum = 0, num = 0;
	double t = 1, x, n = 1, a, b = 1;
	cout<<"ÇëÊäÈëxµÄÖµ£º"<<endl;
	cin>>x;
	a = x;
	do
	{
		num = t*a/b;
		t = -t;
		a *= x*x;
		b *= (n+1)*(n+2);
		n += 2;
		sum += num;
	}while(a/b>=0.0000001);
	cout<<"sin("<<x<<")="<<sum<<endl;
	system("pause");
	return 0;
}