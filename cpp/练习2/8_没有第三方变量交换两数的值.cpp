//在没有的第三方变量的情况下交换两个数的值
#include <iostream>
using namespace std;
int main()
{
	int m = 8, n = 9;
	cout << "交换之前：m = " << m << "n = " << n;
	//法一：
	n = m + n;
	m = n - m;
	n = n - m;
	//法二：
	n = n ^ m;
	m = n ^ m;
	n = n ^ m;
	//法三：
	m = m - n;
	n = m + n;
	m = n - m;

	cout << "交换之后：m = " << m << "n = " << n;

}