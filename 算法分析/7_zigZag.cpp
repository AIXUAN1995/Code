#include <iostream>
using namespace std;
void zigZag(string text, int nRow)
{
	int i = -1; 
	int j = 0;
	int k = 0;
	int len = text.size();
	int col;
	if (nRow == 1)
	{
		for (int x = 0; x < len; x++)
			cout << text[x];
		return;
	}

	if (len % (nRow * 2 - 2) > nRow)
		col = (len / (nRow * 2 - 2))*(nRow - 1) + 2;
	else
		col = (len / (nRow * 2 - 2))*(nRow - 1) + 1;

	char **a = new char*[nRow];
	for (int x = 0; x < nRow; x++)
		a[x] = new char[col];
	for (int x = 0; x < nRow; x++)
	{
		for (int y = 0; y < col; y++)
			a[x][y] = 0;
	}

	while (k < len)
	{
		while (i < nRow-1 && k<len)
		{
			i++;
			a[i][j] = text[k++];
		}
		while (i > 0 && k<len)
		{
			i--;
			j++;
			a[i][j] = text[k++];
		}
	}
	for (int x = 0; x < nRow; x++)
	{
		for (int y = 0; y < col; y++)
			cout << a[x][y];
		cout << endl;
	}
}
int main()
{
	string s = "paypalishiring";
	zigZag(s,5);
	system("pause");
	return 0;
}