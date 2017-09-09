#include <iostream>
using namespace std;
int main()
{
	int rows;
	cout<<"请输入n维数组的行列数n:"<<endl;
	cin>>rows;
	double **p;
	p = new double *[rows];
	for(int i=0; i<rows; i++)
		p[i] = new double [rows];
	cout<<"请输入二维数组中的值："<<endl;
	for(int i=0; i<rows; i++)
		for(int j=0; j<rows; j++)
			cin>>p[i][j];
	double *rowsum, *colsum, diasum = 0, clinsum = 0;
	rowsum = new double [rows];
	colsum = new double [rows];

	for(int i=0; i<rows; i++)		//计算行和
	{
		rowsum[i] = 0;
		for(int j=0; j<rows; j++)
			rowsum[i] += p[i][j];
	}
	for(int j=0; j<rows; j++)		//计算列和
	{
		colsum[j] = 0;
		for(int i=0; i<rows; i++)
			colsum[j] += p[i][j];
	}
	for(int i=0; i<rows; i++)		//计算两个对角线之和
	{
		diasum += p[i][i];
		clinsum += p[i][rows-i-1];
	}
	for(int i=0; i<rows; i++)
		cout<<"第"<<i+1<<"行的和："<<rowsum[i]<<endl;
	for(int i=0; i<rows; i++)
		cout<<"第"<<i+1<<"列的和："<<colsum[i]<<endl;
	cout<<"对角线的和："<<diasum<<endl;
	cout<<"斜对角线的和："<<clinsum<<endl;
	delete [] rowsum;				//一定要主要动态分配内存之后要释放
	delete [] colsum;
	for(int i=0; i<rows; i++)
		delete [] p[i];
	delete [] p;
	system("pause");
	return 0;
}