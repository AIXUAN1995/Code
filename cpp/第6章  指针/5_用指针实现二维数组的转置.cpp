#include <iostream>
using namespace std;
int main()
{
	int m, n;
	cout<<"请输入数组的行数："<<endl;
	cin>>m;
	cout<<"请输入数组的列数："<<endl;
	cin>>n;
	double **p;
	p = new double *[m];
	for(int i=0; i<m; i++)
		p[i] = new double [n];
	cout<<"请输入二维数组："<<endl;
	for(int i=0; i<m; i++)		//按照先行后列输入
		for(int j=0; j<n; j++)
			cin>>p[i][j];
	//直接进行交换
	//cout<<"转置前："<<endl;
	//for(int i=0; i<m; i++)		//按照先行后列输出
	//{
	//	for(int j=0; j<n; j++)
	//		cout<<p[i][j]<<" ";
	//	cout<<endl;
	//}
	//cout<<"转置后："<<endl;
	//for(int j=0; j<n; j++)		//按照先列后行输出
	//{
	//	for(int i=0; i<m; i++)
	//		cout<<p[i][j]<<" ";
	//	cout<<endl;
	//}

	//用指针进行交换
	double **p1;
	cout<<"转置前："<<endl;
	for(int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++)
		{
			cout<<p[i][j]<<" ";
			cout<<&p[i][j]<<" ";//动态数组的地址在内存上不是连续的
			p1 = p;
		}
		cout<<endl;
	}
	cout<<"转置后："<<endl;
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
			cout<<p1[j][i]<<" ";
		cout<<endl;
	}
	for(int i=0; i<m; i++)
		delete [] p[i];
	delete [] p;
	system("pause");
	return 0;
}