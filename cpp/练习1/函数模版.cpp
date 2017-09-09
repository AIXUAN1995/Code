#include <iostream>
template <typename T>
//T max(T x, T y)      //编译时会报错，初步判断是max的问题
//{
//	return x>y?x:y;    //	1	IntelliSense: 有多个 重载函数 "max" 实例与参数列表匹配:	e:\c++\函数模版\函数模版\函数模版.cpp	18	8	函数模版
//
//}
T m(T x, T y)
{
	return x>y?x:y;
}
int main()
{
	using namespace std;

	double x, y;
	cout<<"请输入两个需要比较的数"<<endl;
	cin>>x>>y;
	cout<<m(x, y);
	system("pause");
	return 0;
}