#include <iostream>
using namespace std;
const int NUM = 5;
int info[100][100];
int max(int a, int b)
{
	if (a >= b)
		return a;
	return b;
}
int knapsack(int v[], int w[], int s[], int c, int num)
{
	for (int i = 0; i < num; i++)//��������Ϊ0����
		info[i][0] = 0;
	for (int i = 0; i <= c; i++)//��Ʒ��ֵΪ0����
		info[0][i] = 0;
	for (int i = 1; i<=num; i++)
	{
		for (int j = 0; j <= c; j++)
		{
			if (j >= w[i])
				info[i][j] = max(info[i - 1][j], info[i - 1][j - w[i]] + v[i]);
			else
				info[i][j] = info[i - 1][j];
		}
	}
	int j = c;
	int n = 0;//��¼ѡȡ����Ʒ����
	for (int i = num; i > 0; i--)
	{
		if (info[i][j] > info[i - 1][j])
		{
			s[i] = 1;
			j = j - w[i];
			n++;
		}
		else
			s[i] = 0;
	}
	cout << "����ֵ:" << info[num][c] << endl;
	return n;
}
int main()
{
	int v[NUM + 1] = {0, 6, 3, 5, 4, 6 };	//��Ʒ�ļ�ֵ
	int w[NUM + 1] = {0, 2, 2, 6, 5, 4 };	//��Ʒ������
	int s[NUM + 1] = {0};					//��Ʒ��ѡȡ״̬
	int c;						//�������������
	cout << "�����뱳�����������" << endl;
	cin >> c;
	int n = knapsack(v, w, s, c, NUM);//ѡȡ��Ʒ����
	cout << "ѡȡ��Ʒ������" << n << endl;
	cout << "��Ʒ������" << endl;
	for (int i = 1; i<=NUM; i++)
	{
		cout << w[i] << " ";

	}
	cout << "\n��Ʒ��ֵ��" << endl;
	for (int i = 1; i<=NUM; i++)
	{
		cout << v[i] << " ";

	}
	cout << "\nѡȡ����Ʒ��" << endl;
	for (int i = 1; i<=NUM; i++)
	{
		cout << s[i] << " ";

	}
	cout << "\ninfo:" << endl;
	for (int i = 1; i <= NUM; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			cout << info[i][j] << "\t";
		}
		cout << endl;
	}

	system("pause");
	return 0;
}
