#include <iostream>
using namespace std;
int main()
{
	int rows;
	cout<<"������nά�����������n:"<<endl;
	cin>>rows;
	double **p;
	p = new double *[rows];
	for(int i=0; i<rows; i++)
		p[i] = new double [rows];
	cout<<"�������ά�����е�ֵ��"<<endl;
	for(int i=0; i<rows; i++)
		for(int j=0; j<rows; j++)
			cin>>p[i][j];
	double *rowsum, *colsum, diasum = 0, clinsum = 0;
	rowsum = new double [rows];
	colsum = new double [rows];

	for(int i=0; i<rows; i++)		//�����к�
	{
		rowsum[i] = 0;
		for(int j=0; j<rows; j++)
			rowsum[i] += p[i][j];
	}
	for(int j=0; j<rows; j++)		//�����к�
	{
		colsum[j] = 0;
		for(int i=0; i<rows; i++)
			colsum[j] += p[i][j];
	}
	for(int i=0; i<rows; i++)		//���������Խ���֮��
	{
		diasum += p[i][i];
		clinsum += p[i][rows-i-1];
	}
	for(int i=0; i<rows; i++)
		cout<<"��"<<i+1<<"�еĺͣ�"<<rowsum[i]<<endl;
	for(int i=0; i<rows; i++)
		cout<<"��"<<i+1<<"�еĺͣ�"<<colsum[i]<<endl;
	cout<<"�Խ��ߵĺͣ�"<<diasum<<endl;
	cout<<"б�Խ��ߵĺͣ�"<<clinsum<<endl;
	delete [] rowsum;				//һ��Ҫ��Ҫ��̬�����ڴ�֮��Ҫ�ͷ�
	delete [] colsum;
	for(int i=0; i<rows; i++)
		delete [] p[i];
	delete [] p;
	system("pause");
	return 0;
}