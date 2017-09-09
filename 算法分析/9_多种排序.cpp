#include <iostream>
#include <ctime>
using namespace std;
const int len = 100;


//≤Â»Î≈≈–Ú
void insertionSort(int a[])
{
	int key;
	for (int i = 2; i<len; i++)
	{
		key = a[i];
		int j = i - 1;
		while (j>0 && a[j]>key)
		{
			a[j + 1] = a[j];
			j--;
		}

		a[j + 1] = key;
	}

}

//øÏ≈≈
void Qsort(int a[], int low, int high, int len)
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
	Qsort(a, low, first - 1, len);
	Qsort(a, first + 1, high, len);
}

//∂—≈≈–Ú
//1.∂—µƒŒ¨ª§
void MaxHeap(int a[], int i, int length)
{
	int l = 2 * i;
	int r = 2 * i + 1;
	int max = i;
	if (l < length && a[l]>a[i])
		max = l;
	if (r < length && a[r]>a[max])
		max = r;
	if (max != i)
	{
		int temp = a[i];
		a[i] = a[max];
		a[max] = temp;
		MaxHeap(a, max, length);
	}
}
//2.Ω®∂—
void buildMaxHeap(int a[], int len)
{
	for (int i = len / 2; i >= 1; i--)
		MaxHeap(a, i, len);
}
//3.∂—≈≈–Ú
void heapSort(int a[], int len)
{
	int length = len;
	buildMaxHeap(a, len);
	for (int i = length - 1; i >= 2; i--)
	{
		int temp = a[1];
		a[1] = a[i];
		a[i] = temp;
		length--;
		MaxHeap(a, 1, length);
	}
}
int main()
{
	int a[len];
	for (int i = 1; i<len; i++)
		a[i] = rand() % 10000;

	for (int i = 1; i<len; i++)
		cout << a[i] << " ";
	cout << endl;
	time_t now_time;  now_time = time(NULL);  cout << now_time << endl;
	//Qsort(a,0,len,len);
	//insertionSort(a);
	heapSort(a, len);
	for (int i = 1; i<len; i++)
		cout << a[i] << " ";
	cout << endl;
	now_time = time(NULL);  cout << now_time;
	system("pause");
	return 0;
}