#include <iostream>
#include <memory.h>//不写并没有报错，可以正常运行
using namespace std;
int main()
{
	const int n = 4;
	int a[n];
	for(int i=0; i<n; ++i)
		cin>>a[i];
	for(int i=0; i<n; ++i)
		cout<<a[i]<<endl;
	//第一个参数是数组名，第二个参数是准备初始化数组元素的值，第三个参数是数组的大小，我们用sizeof取得，
	memset(a, 0, sizeof(int)*4);//将数组内容清零，由于memset是对每个字节进行赋值，所以对于int型变量我们赋值为0
	for(int i=0; i<n; ++i)
		cout<<a[i]<<endl;

	system("pause");
	return 0;
}