#include<iostream>
#include<time.h>
#define Swap(a,b) {int t=b; b=a; a=t;}
using namespace std;
const int NUM = 100;

int partition(int a[], int l, int r)
{
	int key = a[r];
	int i = l - 1;
	for (int j = l; j<r; j++)
	{
		if (a[j] <= key)
		{
			i++;
			Swap(a[i], a[j]);
		}
	}

	Swap(a[i + 1], a[r]);
	return i + 1;
}

int RandomPartition(int a[], int l, int r)
{
	srand(time(NULL));
	int i = rand() % (r - l + 1) + l;//随机划分: 
	Swap(a[i], a[r]);
	return partition(a, l, r);
}

int RandomSelect(int a[], int l, int r, int k)
{
	if (r <= l) return a[r];
	int i = RandomPartition(a, l, r);
	int j = i - l + 1;
	if (j == k)
		return a[i];
	if (j>k)
		return RandomSelect(a, l, i - 1, k);
	else
		return RandomSelect(a, i + 1, r, k - j);
}

void disp(int a[], int n)
{
	for (int i = 0; i<n; i++)
		cout << a[i];
}
void randNoRepeat(int a[], int min, int max, int num)
{
	//min：要产生随机数的下限，max要产生随机数的上限，num：随机数的个数
	//int num = max - min + 1;				//要随机数的个数
	int index;							//随机下标
	int *b = new int[max - min + 1];
	for (int i = 0; i < max-min+1; i++)			//准备要被随机的数
		b[i] = i+min;
	srand((int)time(0));				//随机种子
	for (int i = 0; i<num; i++)
	{
		//index = (int)((float)(num - i)*rand() / (RAND_MAX + 1.0));     //产生随机下标
		index = rand() % (max - min + 1 - i);
		a[i] = b[index];				//把不重复的随机数下标保存到数组中
		b[index] = b[max - min - i];		//用随机范围内的最后一个随机下标对应的值, 去替换己用过的值.这样就不重复了.（即
										//把上面用过的a[index]丢掉。）
	}
	delete[] b;
}
void Qsort(int a[], int p, int r)
{
	if (p < r)
	{
		int q = partition(a, p, r);
		Qsort(a, p, q - 1);
		Qsort(a, q + 1, r);
	}
}

int main()
{
	int min = 1;		//随机数上限
	int max = 200;		//随机数下限
	int a[NUM];

	//有重复的随机数
	//srand((unsigned)time(NULL));
	//for (int i = 0; i<NUM; i++)
	//{
	//	a[i] = rand() % 100;
	//	cout << a[i] << " ";
	//}

	randNoRepeat(a, min, max, NUM);
	for (int i = 0; i<NUM; i++)
	{
		cout << a[i] << " ";
	}
	int k;
	cout << "\n请输入k：" << endl;
	cin >> k;
	cout << "第" << k << "小的元素是：" << RandomSelect(a, 0, NUM - 1, k) << endl;
	Qsort(a, 0, NUM - 1);
	cout << endl;
	for (int i = 0; i<NUM; i++)
	{
		cout << a[i] << " ";
	}
	system("pause");
	return 0;

}