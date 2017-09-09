#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> sort(vector<vector<int>>score, int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			score[i][j] = 1;
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			cout << score[i][j];
		cout << endl;
	}
	return score;
}
int main()
{
	int m, n;
	cout << "ÊäÈë£º" << endl;
	cin >> m >> n;
	vector<vector<int>>score(m, vector<int>(n));
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			score[i][j] = 0;
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			cout << score[i][j];
		cout << endl;
	}
	score = sort(score, m, n);
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			cout << score[i][j];
		cout << endl;
	}
	system("pause");
	return 0;
}