#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int M, N, max;
	cout<<"��������������M��";
	cin>>M;
	cout<<"��������������N��";
	cin>>N;
	vector<vector<double>>num(M, vector<double>(N));
	cout<<"����������Ԫ�أ�"<<endl;
	for(int i=0; i<M; i++)
		for(int j=0; j<N; j++)
		{
			cin>>num[i][j];
			if(i == 0 && j == 0)
				max = num[i][j];
			else if(max<num[i][j])
				max = num[i][j];
		}
	cout<<"���ֵΪ��"<<max;
	system("pause");
	return 0;
}