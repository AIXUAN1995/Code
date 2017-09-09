#include <iostream>
#include <string>
using namespace std;
//计算LCS的长度
int lcsLength(string x, string y, int i, int j, int ** c, char ** b)
{
	if (c[i][j] > -1)
		return c[i][j];
	if ((i == 0) || (j == 0))
		c[i][j] = 0;
	else if (x[i - 1] == y[j - 1])
	{
		c[i][j] = lcsLength(x, y, i - 1, j - 1, c, b) + 1;
		b[i - 1][j - 1] = 92;
	}
	else
	{
		int p = lcsLength(x, y, i - 1, j, c, b);
		int q = lcsLength(x, y, i, j - 1, c, b);
		if (p < q)//向左
		{
			c[i][j] = q;
			b[i - 1][j - 1] = 27;
		}
		else
		{
			c[i][j] = p;
			b[i - 1][j - 1] = 24;
		}
	}
	return c[i][j];
}

//构造Lcs输出最长公共子序列
void printLcs(char **b, string x, int i, int j)
{
	if (i == -1 || j == -1)
		return;
	if (b[i][j] == 92)
	{
		printLcs(b, x, i - 1, j - 1);
		cout << x[i];
	}
	else if (b[i][j] == 24)
	{
		printLcs(b, x, i - 1, j);
	}
	else
		printLcs(b, x, i, j - 1);

}
int main()
{
	string x = "BCAD";
	string y = "CABD";
	int x_len = x.length();
	int y_len = y.length();

	//定义c矩阵储存公共子序列的长度，行数为x的长度+1，列数为y的长度+1
	int ** c = new int*[x_len + 1];
	for (int i = 0; i<x_len + 1; i++)
		c[i] = new int[y_len + 1];

	//定义b矩阵记录箭头
	char ** b = new char*[x_len];
	for (char i = 0; i<x_len; i++)
		b[i] = new char[y_len];

	//将c数组出事化为-1
	for (int i = 0; i < x_len + 1; i++)
	{
		for (int j = 0; j < y_len + 1; j++)
			c[i][j] = -1;
	}

	//清空b矩阵
	for (int i = 0; i<x_len; i++)
	{
		for (int j = 0; j<y_len; j++)
			b[i][j] = ' ';
	}
	lcsLength(x, y, x_len, y_len, c, b);
	printLcs(b, x, x_len - 1, y_len - 1);

	//输出c矩阵
	cout << "\nc矩阵：" << endl;
	cout << "  " << y << endl;
	for (int i = 0; i<x_len + 1; i++)
	{
		if (i>0)
			cout << x[i - 1];
		else
			cout << " ";
		for (int j = 0; j<y_len + 1; j++)
			cout << c[i][j] << "\t";
		cout << endl;
	}

	//输出b矩阵
	cout << "b矩阵：" << endl;
	for (int i = 0; i<x_len; i++)
	{
		for (int j = 0; j<y_len; j++)
			cout << b[i][j];
		cout << endl;
	}

	for (int i = 0; i < x_len+1; i++)
		delete[] c[i];
	delete[] c;
	for (int i = 0; i < x_len; i++)
		delete[] b[i];
	delete[] b;
	system("pause");
	return 0;
}
