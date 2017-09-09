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
void Qsort(int a[], int low, int high, int *n, int len)
{
	if (low >= high)
		return;
	int first = low;
	int last = high;
	int key = a[first];
	while (first<last)
	{
		while (first<last && key <= a[last])
			last--;
		a[first] = a[last];
		while (first<last && key >= a[first])
			first++;
		a[last] = a[first];
	}
	a[first] = key;
	(*n)++;
	cout << "��" << *n << "������";
	for (int i = 0; i<len; i++)
		cout << a[i] << " ";
	cout << endl;
	Qsort(a, low, first - 1, n, len);
	Qsort(a, first + 1, high, n, len);
}
int main()
{
	int a[10];
	int n = 0;//���Ҵ���
	int key;
	int n2 = 0;	//�������

	//���������ֵ
	for (int i = 0; i < 10; i++)
	{
		a[i] = rand()%10;
	}
	Qsort(a, 0, sizeof(a) / sizeof(a[0]) - 1, &n2, sizeof(a) / sizeof(a[0]));
	for (int i = 0; i<sizeof(a) / sizeof(a[0]); i++)
		cout << a[i] << " ";
	cout << endl;

	cout << "������Ҫ��ѯ������" << endl;
	cin >> key;
	int flag = binarySearch(a, 0, sizeof(a) / sizeof(a[0]) - 1, key, &n);
	if (flag == -1)
		cout << "û��Ҫ��ѯ������" << endl;
	else
		cout << "Ҫ��ѯ�����ֵ�λ���ǣ�" << flag << "���Ҵ���Ϊ��" << n << endl;

	system("pause");
	return 0;
}