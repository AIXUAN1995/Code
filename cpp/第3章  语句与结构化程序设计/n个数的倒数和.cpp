#include <iostream>
using namespace std;
int main()
{
	int i, num;
	double sum;
	sum = 0;
	cout<<"������һ��������"<<endl;
	cin>>i;
	for(num=1; num<=i; num++)
	{
		sum = sum+(1.0/num);
	}
	cout<<sum<<endl;
	system("pause");
	return 0;
}