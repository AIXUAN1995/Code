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
	int i = rand() % (r - l + 1) + l;//�������: 
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
	//min��Ҫ��������������ޣ�maxҪ��������������ޣ�num��������ĸ���
	//int num = max - min + 1;				//Ҫ������ĸ���
	int index;							//����±�
	int *b = new int[max - min + 1];
	for (int i = 0; i < max-min+1; i++)			//׼��Ҫ���������
		b[i] = i+min;
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
	int min = 1;		//���������
	int max = 200;		//���������
	int a[NUM];

	//���ظ��������
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
	cout << "\n������k��" << endl;
	cin >> k;
	cout << "��" << k << "С��Ԫ���ǣ�" << RandomSelect(a, 0, NUM - 1, k) << endl;
	Qsort(a, 0, NUM - 1);
	cout << endl;
	for (int i = 0; i<NUM; i++)
	{
		cout << a[i] << " ";
	}
	system("pause");
	return 0;

}