#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int M, N, max;
	cout<<"请输入矩阵的行数M：";
	cin>>M;
	cout<<"请输入矩阵的列数N：";
	cin>>N;
	vector<vector<double>>num(M, vector<double>(N));
	cout<<"请输入数组元素："<<endl;
	for(int i=0; i<M; i++)
		for(int j=0; j<N; j++)
		{
			cin>>num[i][j];
			if(i == 0 && j == 0)
				max = num[i][j];
			else if(max<num[i][j])
				max = num[i][j];
		}
	cout<<"最大值为："<<max;
	system("pause");
	return 0;
}