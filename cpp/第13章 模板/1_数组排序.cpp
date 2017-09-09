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
	cout << "����������ĳ��ȣ�" << endl;
	cin >> len1;
	vector<int>a1(len1);
	cout << "����" << len1 << "��ֵ" << endl;
	for (int i = 0; i < len1; i++)
	{
		cin >> a1[i];
	}
	a1 = sort(a1, len1);

	cout << "����������ĳ��ȣ�" << endl;
	cin >> len2;
	vector<double>a2(len2);
	cout << "����" << len2 << "��ֵ" << endl;
	for (int i = 0; i < len2; i++)
	{
		cin >> a2[i];
	}
	a2 = sort(a2, len2);
	cout << "������a1:" << endl;
	for (int i = 0; i < len1; i++)
	{
		cout << a1[i] << " ";
	}
	cout << endl;
	cout << "������a2:" << endl;
	for (int i = 0; i < len2; i++)
	{
		cout << a2[i] << " ";
	}
	system("pause");
	return 0;
}