//条件编译的作用：1.用于调试程序  2.避免重复定义
#include <iostream>
using namespace std;
#define DEBUG			//用于避免重复定义
#ifndef TRI				//定义标识符TRI
#define TRI				//定义结构体类型Tri
struct Tri
{
	double x;
	double y;
	double z;
};
#endif
int main()
{
	int a[10] = {62, 45, 78, 82, 95, 68, 75, 98, 81, 60};
	cout<<"排序前的数据："<<endl;
	for(int i=0; i<10; ++i)
		cout<<a[i]<<" ";
	for(int i=0; i<9; ++i)
	{
		for(int j=0; j<9; ++j)
			if(a[j]<a[j+1])
			{
				int t = a[j];
				a[j] = a[j+1];
				a[j+1] = t;
			}
		#ifdef DEBUG				//用于调试程序的条件编译
			cout<<endl;
			for(int i=0; i<10; ++i)
				cout<<a[i]<<" ";			//排序后的顺序输出，没排序一次就输出一次
			cout<<endl;
		#endif
	}	
	cout<<"排序后的数据："<<endl;
	for(int i=0; i<10; ++i)
		cout<<a[i]<<" ";
	system("pause");
	return 0;
}