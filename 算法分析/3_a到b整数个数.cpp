/*设计一个算法，它能够对于任何给定的介于0到k之间的n个整数先进行预处理，然后在O(1)的时间内回答输入的n个整数中有多少落在区间[a,b]内，算法预处理的时间应为O(n+k)*/
#include <iostream>
using namespace std;
template <class T>
int getArrayLen(T& arr)
{
	return (sizeof(arr) / sizeof(arr[0]));
}
const int k = 10;
int fun(int arr[], int len, int a, int b)
{
	int c[k];
	for (int i = 0; i < k; i++)
		c[i] = 0;
	for (int i = 0; i < len; i++)
		c[arr[i]]++;
	for (int i = 1; i < k; i++)
		c[i] = c[i - 1] + c[i];

	if (a == 0)
		return c[b];
	else
		return c[b] - c[a - 1];
}
int main()
{
	int arr[k];
	for (int i = 0; i < k; i++)
	{
		arr[i] = rand() % 10;
		cout << arr[i] << " ";
	}
	cout << endl;

	cout << fun(arr, getArrayLen(arr), 0, 6) << endl;
	cout << fun(arr, getArrayLen(arr), 3, 9) << endl;
	system("pause");
	return 0;
}