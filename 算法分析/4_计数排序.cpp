#include <iostream>
using namespace std;
template <class T>
int getArrayLen(T& arr)
{
	return (sizeof(arr) / sizeof(arr[0]));
}
const int k = 10;
const int n = 20;
void fun(int arr[], int arr2[], int len)
{
	int c[k];
	for (int i = 0; i < k; i++)
		c[i] = 0;
	for (int i = 0; i < len; i++)
		c[arr[i]]++;


	for (int i = 1; i < k; i++)
		c[i] = c[i - 1] + c[i];

	for (int i = len - 1; i >= 0; i--)
	{
		c[arr[i]]--;//脚标从0开始，所以存放时提前减1
		arr2[c[arr[i]]] = arr[i];
	}
}
int main()
{
	int arr[n];
	int arr2[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % k;
		cout << arr[i] << " ";
	}
	cout << endl;
	fun(arr, arr2, getArrayLen(arr));
	for (int i = 0; i < n; i++)
		cout << arr2[i] << " ";
	cout << endl;
	system("pause");
	return 0;
}