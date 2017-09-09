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
	for (int i = 0; i < num; i++)//背包容量为0的列
		info[i][0] = 0;
	for (int i = 0; i <= c; i++)//物品价值为0的行
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
	int n = 0;//记录选取的物品个数
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
	cout << "最大价值:" << info[num][c] << endl;
	return n;
}
int main()
{
	int v[NUM + 1] = {0, 6, 3, 5, 4, 6 };	//物品的价值
	int w[NUM + 1] = {0, 2, 2, 6, 5, 4 };	//物品的重量
	int s[NUM + 1] = {0};					//物品的选取状态
	int c;						//背包的最大容量
	cout << "请输入背包最大容量：" << endl;
	cin >> c;
	int n = knapsack(v, w, s, c, NUM);//选取物品个数
	cout << "选取物品个数：" << n << endl;
	cout << "物品重量：" << endl;
	for (int i = 1; i<=NUM; i++)
	{
		cout << w[i] << " ";

	}
	cout << "\n物品价值：" << endl;
	for (int i = 1; i<=NUM; i++)
	{
		cout << v[i] << " ";

	}
	cout << "\n选取的物品：" << endl;
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
