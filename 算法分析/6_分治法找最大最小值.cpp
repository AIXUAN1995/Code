#include <iostream>
#include <time.h>
using namespace std;
const int NUM = 30;
void SearchMaxMin(int a[], int num, int &max, int &min)
{
	min = a[0];
	max = a[0];
	for (int i = 1; i<num; i++)
	{
		if (a[min]>a[i])
			min = i;
		else if (a[max]<a[i])
			max = i;
	}
}
void minMax(int a[], int i, int j, int &min, int &max)
{
	int mid, max1, max2, min1, min2;
	if (i == j){
		max = a[i];
		min = a[i];
		return;
	}
	if (j == i + 1)
	{
		if (a[i]>a[j]){ min = a[j]; max = a[i]; }
		else{ min = a[i]; max = a[j]; }
	}
	else
	{
		mid = (i + j) / 2;
		minMax(a, i, mid, min1, max1);
		minMax(a, mid + 1, j, min2, max2);
		if (min1>min2)min = min2;
		else min = min1;
		if (max1>max2)max = max1;
		else max = max2;
	}
}
int main()
{
	int a[NUM];
	
	srand((unsigned)time(NULL));
	for (int i = 0; i<NUM; i++)
	{
		a[i] = rand() % 100;
		cout << a[i] << " ";
	}
	int max = a[0];
	int min = a[0];
	minMax(a, 0, NUM - 1, min, max);
	cout << "最大值：" << max << "最小值：" << min << endl;
	system("pause");
	return 0;
}