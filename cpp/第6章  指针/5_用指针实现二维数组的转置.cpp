#include <iostream>
using namespace std;
int main()
{
	int m, n;
	cout<<"�����������������"<<endl;
	cin>>m;
	cout<<"�����������������"<<endl;
	cin>>n;
	double **p;
	p = new double *[m];
	for(int i=0; i<m; i++)
		p[i] = new double [n];
	cout<<"�������ά���飺"<<endl;
	for(int i=0; i<m; i++)		//�������к�������
		for(int j=0; j<n; j++)
			cin>>p[i][j];
	//ֱ�ӽ��н���
	//cout<<"ת��ǰ��"<<endl;
	//for(int i=0; i<m; i++)		//�������к������
	//{
	//	for(int j=0; j<n; j++)
	//		cout<<p[i][j]<<" ";
	//	cout<<endl;
	//}
	//cout<<"ת�ú�"<<endl;
	//for(int j=0; j<n; j++)		//�������к������
	//{
	//	for(int i=0; i<m; i++)
	//		cout<<p[i][j]<<" ";
	//	cout<<endl;
	//}

	//��ָ����н���
	double **p1;
	cout<<"ת��ǰ��"<<endl;
	for(int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++)
		{
			cout<<p[i][j]<<" ";
			cout<<&p[i][j]<<" ";//��̬����ĵ�ַ���ڴ��ϲ���������
			p1 = p;
		}
		cout<<endl;
	}
	cout<<"ת�ú�"<<endl;
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