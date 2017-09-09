/*说明如何在O(n)时间内，对0到n^3-1区间内的n个整数进行排序*/
#include <iostream>
using namespace std;
const int n = 10;
//每个数可以化为n进制数
struct Num
{
	int num;	//存放十进制数
	int d[3];	//存放n进制数
};
void countingSort(Num a[], Num b[], int j)
{//a[]为待排序数组，b[]是排序后数组，n是进制数，j是当前排序的位
	int c[n];
	memset(c, 0, n*sizeof(int));
	for (int i = 0; i < n; i++)
		c[a[i].d[j]]++;
	for (int i = 1; i < n; i++)
		c[i] += c[i - 1];
	for (int i = n - 1; i >= 0; i--)
	{
		c[a[i].d[j]]--;
		b[c[a[i].d[j]]] = a[i];
	}

}
int main()
{
	Num a[n], b[n];//b[]作为交换时的中介

	for (int i = 0; i < n; i++)
	{
		a[i].num = rand() % (n*n*n - 1);
		int temp = a[i].num;
		for (int j = 0; j < 3; j++)
		{
			a[i].d[j] = temp % n;
			temp /= n;
		}
	}

	//输出排序前数据
	for (int i = 0; i < n; i++)
		cout << a[i].num << " ";
	cout << endl;


	//进行基数排序，每位用计数排序
	for (int i = 0; i < 3; i++)
	{
		countingSort(a, b, i);
		for (int j = 0; j < n; j++)
		{
			Num temp = a[j];
			a[j] = b[j];
			b[j] = temp;
		}
	}

	//输出排序后的结果
	for (int i = 0; i < n; i++)
		cout << a[i].num << " ";
	cout << endl;
	system("pause");
	return 0;
}