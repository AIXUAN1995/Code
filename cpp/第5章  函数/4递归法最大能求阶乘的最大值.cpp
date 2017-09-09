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
	cout<<"请输入要求阶乘的数字："<<endl;
	cin>>num;
	cout<<fact(num)<<endl;
	system("pause");
	return 0;
}