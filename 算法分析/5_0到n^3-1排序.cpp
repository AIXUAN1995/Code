/*˵�������O(n)ʱ���ڣ���0��n^3-1�����ڵ�n��������������*/
#include <iostream>
using namespace std;
const int n = 10;
//ÿ�������Ի�Ϊn������
struct Num
{
	int num;	//���ʮ������
	int d[3];	//���n������
};
void countingSort(Num a[], Num b[], int j)
{//a[]Ϊ���������飬b[]����������飬n�ǽ�������j�ǵ�ǰ�����λ
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
	Num a[n], b[n];//b[]��Ϊ����ʱ���н�

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

	//�������ǰ����
	for (int i = 0; i < n; i++)
		cout << a[i].num << " ";
	cout << endl;


	//���л�������ÿλ�ü�������
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

	//��������Ľ��
	for (int i = 0; i < n; i++)
		cout << a[i].num << " ";
	cout << endl;
	system("pause");
	return 0;
}