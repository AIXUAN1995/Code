#include <iostream>
using namespace std;
short fact(double num)
{
	short fac;
	if(num == 1 || num == 0)
		fac = 1;
	else
		fac = num*fact(num-1);
	return fac;
}
int main()
{
	short num = 0;
	cout<<"������Ҫ��׳˵����֣�"<<endl;
	cin>>num;
	cout<<fact(num)<<endl;
	system("pause");
	return 0;
}