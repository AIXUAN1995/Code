/*���һ���㷨�����ܹ������κθ����Ľ���0��k֮���n�������Ƚ���Ԥ����Ȼ����O(1)��ʱ���ڻش������n���������ж�����������[a,b]�ڣ��㷨Ԥ�����ʱ��ӦΪO(n+k)*/
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