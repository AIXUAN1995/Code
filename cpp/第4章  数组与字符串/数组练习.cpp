#include <iostream>
#define usize 5//宏变量可以用于数组的长度
const int n = 5;//静态变量也可以用于数组的长度
using namespace std;
int main()
{
	int c = 4;
	//int n = 5;
	//数组的定义有四种方法，第四种是2011年增加的
	//int a[5] {1, 2, 3, 4, 5}这种方法是正确的
	int a[11/2] = {1, 2, 3, 4, 5};//长度不能是变量，像int n = 5就不正确，只能用常量或是常量表达式
	for(int i=0; i<5; i++)
	{
		cout<<a[4]<<endl;//下标可以是赋值以后的变量，也可以是布尔型或是char类型
	}
	return 0;
}