#include <iostream>
using namespace std;
template <class T>
T maximum(T x, T y);
template <class T>
T maximum(T x, T y, T z);
int main()
{
	int ia, ib;
	double da, db, dc;
	cout << "请输入2个整数：";
	cin >> ia >> ib;
	cout << "最大值 = " << maximum(ia, ib) << endl;
	cout << "请输入3个浮点数：";
	cin >> da >> db >> dc;
	cout << "最大值 = " << maximum(da, db, dc) << endl;
	system("pause");
	return 0;
}
template <class T>
T maximum(T x, T y)//找2个数中的最大值
{
	T max;
	if (x >= y)
		max = x;
	else
		max = y;
	return max;
}
template <class T>//找3个值中的最大值
T maximum(T x, T y, T z)
{
	T max;
	if (x >= y)
		max = x;
	else
		max = y;
	if (max < z)
		max = z;
	return max;
}