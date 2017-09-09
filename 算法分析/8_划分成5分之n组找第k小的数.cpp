#include <iostream>
#include <time.h>
using namespace std;
const int num_array = 13;
const int num_med_array = num_array / 5 + 1;
int array[num_array];
int midian_array[num_med_array];
//冒泡排序（晚些时候将修正为插入排序）
/*void insert_sort(int array[], int left, int loop_times, int compare_times)
{
for (int i = 0; i < loop_times; i++)
{
for (int j = 0; j < compare_times - i; j++)
{
if (array[left + j] > array[left + j + 1])
swap(array[left + j], array[left + j + 1]);
}
}
}*/
/*
//插入排序算法伪代码
INSERTION-SORT(A)                              cost    times
1  for j ← 2 to length[A]                      c1      n
2       do key ← A[j]                          c2      n - 1
3          Insert A[j] into the sorted sequence A[1 ‥ j - 1].     0...n - 1
4          i ← j - 1                           c4      n - 1
5          while i > 0 and A[i] > key           c5
6             do A[i + 1] ← A[i]               c6
7             i ← i - 1                        c7
8          A[i + 1] ← key                      c8      n - 1
*/
//已修正为插入排序，如下：
void insert_sort(int array[], int left, int loop_times)
{
	for (int j = left; j < left + loop_times; j++)
	{
		int key = array[j];
		int i = j - 1;
		while (i>left && array[i]>key)
		{
			array[i + 1] = array[i];
			i--;
		}
		array[i + 1] = key;
	}
}
//找中位数的中位数
int find_median(int array[], int left, int right)
{
	if (left == right)
		return array[left];
	int index;
	for (index = left; index < right - 5; index += 5)
	{
		insert_sort(array, index, 4);
		int num = index - left;
		midian_array[num / 5] = array[index + 2];
	}
	// 处理剩余元素
	int remain_num = right - index + 1;//剩余元素个数
	if (remain_num > 0)
	{
		insert_sort(array, index, remain_num - 1);
		int num = index - left;
		midian_array[num / 5] = array[index + remain_num / 2];
	}
	int elem_aux_array = (right - left) / 5 - 1;
	if ((right - left) % 5 != 0)
		elem_aux_array++;
	// 如果剩余一个元素返回，否则继续递归
	if (elem_aux_array == 0)//找到中位数的中位数
		return midian_array[0];
	else
		return find_median(midian_array, 0, elem_aux_array);
}
// 寻找中位数的所在位置
int find_index(int array[], int left, int right, int median)
{
	for (int i = left; i <= right; i++)
	{
		if (array[i] == median)
			return i;
	}
	return -1;
}
int q_select(int array[], int left, int right, int k)
{
	// 寻找中位数的中位数
	int median = find_median(array, left, right);
	// 将中位数的中位数与最右元素交换
	int index = find_index(array, left, right, median);
	swap(array[index], array[right]);
	int pivot = array[right];
	// 申请两个移动指针并初始化
	int i = left;
	int j = right - 1;
	// 根据枢纽元素的值对数组进行一次划分
	while (true)
	{
		while (array[i] < pivot)
			i++;
		while (array[j] > pivot)
			j--;
		if (i < j)
			swap(array[i], array[j]);
		else
			break;
	}
	swap(array[i], array[right]);
	/* 对三种情况进行处理：(m = i - left + 1)
	1、如果m=k，即返回的主元即为我们要找的第k小的元素，那么直接返回主元a[i]即可;
	2、如果m>k，那么接下来要到低区间A[0....m-1]中寻找，丢掉高区间;
	3、如果m<k，那么接下来要到高区间A[m+1...n-1]中寻找，丢掉低区间。
	*/
	int m = i - left + 1;
	if (m == k)
		return array[i];
	else if (m > k)
		//上条语句相当于if( (i-left+1) >k)，即if( (i-left) > k-1 )，于此就与2.2节里的代码实现一、二相对应起来了。
		return q_select(array, left, i - 1, k);
	else
		return q_select(array, i + 1, right, k - m);
}
//产生不重复的随机数
void randNoRepeat(int a[], int min, int max, int num)
{
	//min：要产生随机数的下限，max要产生随机数的上限，num：随机数的个数
	//int num = max - min + 1;				//要随机数的个数
	int index;							//随机下标
	int *b = new int[max - min + 1];
	for (int i = 0; i < max - min + 1; i++)			//准备要被随机的数
		b[i] = i + min;
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
int main()
{
	int k;
	int array[num_array];
	randNoRepeat(array,1,200,num_array);
	for (int i = 0; i < num_array; i++)
		cout << array[i] << " ";
	cout << endl;

	cout << "寻找第k最小数,请输入k:" << endl;
	cin >> k;
	int i = q_select(array, 0, num_array - 1, k);
	cout << i << endl;
	system("pause");
	return 0;
}