#include <iostream>
#define f(x,y) (((x)*(x))+((y)*(y)))
//1.宏定义的时候要注意变量加括号
//2.整体也要加括号
int main()
{
	using namespace std;
	int x,y;
	cout<<"请输入要计算平方和2倍的两个数"<<endl;
	cin>>x>>y;
	cout<<2*f(x,y)<<endl;
	system("pause");
	return 0;
}