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
	cout << "������2��������";
	cin >> ia >> ib;
	cout << "���ֵ = " << maximum(ia, ib) << endl;
	cout << "������3����������";
	cin >> da >> db >> dc;
	cout << "���ֵ = " << maximum(da, db, dc) << endl;
	system("pause");
	return 0;
}
template <class T>
T maximum(T x, T y)//��2�����е����ֵ
{
	T max;
	if (x >= y)
		max = x;
	else
		max = y;
	return max;
}
template <class T>//��3��ֵ�е����ֵ
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