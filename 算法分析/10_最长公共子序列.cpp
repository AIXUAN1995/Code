#include <iostream>
#include <string>
using namespace std;
//����LCS�ĳ���
void lcsLength(string x, string y, int x_len, int y_len, int ** c, char ** b)
{

	//��a��b���бȽ�
	for (int i = 0; i<x_len; i++)
	{
		for (int j = 0; j<y_len; j++)
		{
			if (x[i] == y[j])//����
			{
				c[i + 1][j + 1] = c[i][j] + 1;
				b[i][j] = 92;
			}
			else if (c[i + 1][j]>c[i][j + 1])//����
			{
				c[i + 1][j + 1] = c[i + 1][j];
				b[i][j] = 27;
			}
			else//����
			{
				c[i + 1][j + 1] = c[i][j + 1];
				b[i][j] = 24;
			}

		}
	}

}

//����Lcs��������������
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
	string x = "abcbdab";
	string y = "bdcaba";
	int x_len = x.length();
	int y_len = y.length();

	//����c���󴢴湫�������еĳ��ȣ�����Ϊx�ĳ���+1������Ϊy�ĳ���+1
	int ** c = new int*[x_len + 1];
	for (int i = 0; i<x_len + 1; i++)
		c[i] = new int[y_len + 1];

	//����b�����¼��ͷ
	char ** b = new char*[x_len];
	for (char i = 0; i<x_len; i++)
		b[i] = new char[y_len];

	//��c����ĵ�һ�к͵�һ�и�ֵΪ0
	for (int i = 0; i<x_len + 1; i++)
		c[i][0] = 0;
	for (int i = 0; i<y_len + 1; i++)
		c[0][i] = 0;

	//���b����
	for (int i = 0; i<x_len; i++)
	{
		for (int j = 0; j<y_len; j++)
			b[i][j] = ' ';
	}
	lcsLength(x, y, x_len, y_len, c, b);
	printLcs(b, x, x_len - 1, y_len - 1);

	//���c����
	cout << "\nc����" << endl;
	cout << "  " << y << endl;
	for (int i = 0; i<x_len + 1; i++)
	{
		if (i>0)
			cout << x[i - 1];
		else
			cout << " ";
		for (int j = 0; j<y_len + 1; j++)
			cout << c[i][j];
		cout << endl;
	}

	//���b����
	cout << "b����" << endl;
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