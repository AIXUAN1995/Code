#include <iostream>
using namespace std;
int main()
{
	int a=3, b=4, c=7, d=9;
	//cout<<max(max(a,b),max(c,d));
	cout<<max(max(max(a,b),c),d);//两种方法都可求四个数的最大值
	system("pause");
	return 0;
}
//求两个函数的最大值
int max(int x,int y)
{
	return x>y?x:y;
}