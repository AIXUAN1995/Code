#include <iostream>
using namespace std;
int main()
{
	int i, num;
	i = num = 0;
	cout<<"请输入要倒置的整数"<<endl;
	cin>>num;
	while(num)
	{
		i = i*10 + num%10;
		num = num/10;
	}
	cout<<i<<endl;
	return 0;
}