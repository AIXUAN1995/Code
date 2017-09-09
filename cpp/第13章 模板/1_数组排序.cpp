#include <iostream>
#include <vector>
using namespace std;
template <class T>
vector<T> sort(vector<T>a, int len)
{
	bool flag = true;
	for (int i = 0; i < len-1; i++)
	{
		flag = true;
		for (int j = 0; j < len - 1 - i; j++)
		{
			if (a[j]>a[j + 1])
			{
				T temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
				flag = false;
			}
		}
		if (flag)
			break;
	}
	return a;
}
int main()
{
	int len1, len2;
	cout << "请输入数组的长度：" << endl;
	cin >> len1;
	vector<int>a1(len1);
	cout << "输入" << len1 << "个值" << endl;
	for (int i = 0; i < len1; i++)
	{
		cin >> a1[i];
	}
	a1 = sort(a1, len1);

	cout << "请输入数组的长度：" << endl;
	cin >> len2;
	vector<double>a2(len2);
	cout << "输入" << len2 << "个值" << endl;
	for (int i = 0; i < len2; i++)
	{
		cin >> a2[i];
	}
	a2 = sort(a2, len2);
	cout << "排序后的a1:" << endl;
	for (int i = 0; i < len1; i++)
	{
		cout << a1[i] << " ";
	}
	cout << endl;
	cout << "排序后的a2:" << endl;
	for (int i = 0; i < len2; i++)
	{
		cout << a2[i] << " ";
	}
	system("pause");
	return 0;
}