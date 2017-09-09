#include <iostream>
#include <time.h>
using namespace std;
const int num_array = 13;
const int num_med_array = num_array / 5 + 1;
int array[num_array];
int midian_array[num_med_array];
//ð��������Щʱ������Ϊ��������
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
//���������㷨α����
INSERTION-SORT(A)                              cost    times
1  for j �� 2 to length[A]                      c1      n
2       do key �� A[j]                          c2      n - 1
3          Insert A[j] into the sorted sequence A[1 �E j - 1].     0...n - 1
4          i �� j - 1                           c4      n - 1
5          while i > 0 and A[i] > key           c5
6             do A[i + 1] �� A[i]               c6
7             i �� i - 1                        c7
8          A[i + 1] �� key                      c8      n - 1
*/
//������Ϊ�����������£�
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
//����λ������λ��
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
	// ����ʣ��Ԫ��
	int remain_num = right - index + 1;//ʣ��Ԫ�ظ���
	if (remain_num > 0)
	{
		insert_sort(array, index, remain_num - 1);
		int num = index - left;
		midian_array[num / 5] = array[index + remain_num / 2];
	}
	int elem_aux_array = (right - left) / 5 - 1;
	if ((right - left) % 5 != 0)
		elem_aux_array++;
	// ���ʣ��һ��Ԫ�ط��أ���������ݹ�
	if (elem_aux_array == 0)//�ҵ���λ������λ��
		return midian_array[0];
	else
		return find_median(midian_array, 0, elem_aux_array);
}
// Ѱ����λ��������λ��
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
	// Ѱ����λ������λ��
	int median = find_median(array, left, right);
	// ����λ������λ��������Ԫ�ؽ���
	int index = find_index(array, left, right, median);
	swap(array[index], array[right]);
	int pivot = array[right];
	// ���������ƶ�ָ�벢��ʼ��
	int i = left;
	int j = right - 1;
	// ������ŦԪ�ص�ֵ���������һ�λ���
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
	/* ������������д���(m = i - left + 1)
	1�����m=k�������ص���Ԫ��Ϊ����Ҫ�ҵĵ�kС��Ԫ�أ���ôֱ�ӷ�����Ԫa[i]����;
	2�����m>k����ô������Ҫ��������A[0....m-1]��Ѱ�ң�����������;
	3�����m<k����ô������Ҫ��������A[m+1...n-1]��Ѱ�ң����������䡣
	*/
	int m = i - left + 1;
	if (m == k)
		return array[i];
	else if (m > k)
		//��������൱��if( (i-left+1) >k)����if( (i-left) > k-1 )���ڴ˾���2.2����Ĵ���ʵ��һ�������Ӧ�����ˡ�
		return q_select(array, left, i - 1, k);
	else
		return q_select(array, i + 1, right, k - m);
}
//�������ظ��������
void randNoRepeat(int a[], int min, int max, int num)
{
	//min��Ҫ��������������ޣ�maxҪ��������������ޣ�num��������ĸ���
	//int num = max - min + 1;				//Ҫ������ĸ���
	int index;							//����±�
	int *b = new int[max - min + 1];
	for (int i = 0; i < max - min + 1; i++)			//׼��Ҫ���������
		b[i] = i + min;
	srand((int)time(0));				//�������
	for (int i = 0; i<num; i++)
	{
		//index = (int)((float)(num - i)*rand() / (RAND_MAX + 1.0));     //��������±�
		index = rand() % (max - min + 1 - i);
		a[i] = b[index];				//�Ѳ��ظ���������±걣�浽������
		b[index] = b[max - min - i];		//�������Χ�ڵ����һ������±��Ӧ��ֵ, ȥ�滻���ù���ֵ.�����Ͳ��ظ���.����
		//�������ù���a[index]��������
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

	cout << "Ѱ�ҵ�k��С��,������k:" << endl;
	cin >> k;
	int i = q_select(array, 0, num_array - 1, k);
	cout << i << endl;
	system("pause");
	return 0;
}