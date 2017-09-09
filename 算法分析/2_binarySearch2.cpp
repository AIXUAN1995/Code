#include <iostream>
using namespace std;
int binarySearch(int a[], int low, int high, int key, int *n)
{
	int middle = (low + high) / 2;
	(*n)++;
	if (low>high)
		return -1;
	else
	{
		if (key == a[middle])
			return middle;
		else if (a[middle]>key)
			binarySearch(a, low, middle - 1, key, n);
		else
			binarySearch(a, middle + 1, high, key, n);
	}

}
int Partition(int a[], int p, int r)
{
	int x = a[r];//最后一个值给暂时存入x
	int i = p - 1;
	for (int j = p; j < r; j++)
	{
		if (a[j] <= x)
		{
			i++;
			int temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
		for (int k = 0; k < 10; k++)
			cout << a[k] << " ";
		cout << endl;
	}
	int temp = a[i + 1];
	a[i + 1] = a[r];
	a[r] = temp;
	return i + 1;
}
void Qsort(int a[], int p, int r)
{
	if (p < r)
	{
		int q = Partition(a, p, r);
		Qsort(a, p, q - 1);
		Qsort(a, q + 1, r);
	}
}
int main()
{
	int a[10];
	int n = 0;//查找次数
	int key;
	int n2 = 0;	//排序次数

	//用随机数赋值
	for (int i = 0; i < 10; i++)
	{
		a[i] = rand() % 10;
		cout << a[i] << " ";
	}
	cout << endl;
	Qsort(a, 0, sizeof(a) / sizeof(a[0]) - 1);
	for (int i = 0; i<sizeof(a) / sizeof(a[0]); i++)
		cout << a[i] << " ";
	cout << endl;

	cout << "请输入要查询的数字" << endl;
	cin >> key;
	int flag = binarySearch(a, 0, sizeof(a) / sizeof(a[0]) - 1, key, &n);
	if (flag == -1)
		cout << "没有要查询的数字" << endl;
	else
		cout << "要查询的数字的位置是：" << flag << "查找次数为：" << n << endl;

	system("pause");
	return 0;
}