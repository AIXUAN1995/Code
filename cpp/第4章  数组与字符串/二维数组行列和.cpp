#include <iostream>
using namespace std;
int main()
{
	const int n = 2;
	int a[n][n];
	int rowsum = 0, colsum = 0, diasum = 0, clisum = 0;
	cout<<"������"<<n<<"��"<<n<<"�е�����"<<endl;
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			cin>>a[i][j];
	//�к�
	for(int i=0; i<n; i++)
	{
		rowsum = 0;
		for(int j=0; j<n; j++)
		{
			rowsum += a[i][j];
		}
		cout<<"��"<<i+1<<"�еĺ�="<<rowsum<<endl;
	}
	//�к�
	for(int j=0; j<n; j++)
	{
		colsum = 0;
		for(int i=0; i<n; i++)
			colsum += a[j][i];
		cout<<"��"<<j+1<<"�еĺ�="<<colsum<<endl;
	}
	//�Խ��ߵĺ�
	for(int i=0; i<n; i++)
		diasum  += a[i][i];
	cout<<"�Խ���Ԫ��֮��="<<diasum<<endl;
	//б�Խ��ߵĺ�
	for(int i=0; i<n; i++)
		clisum += a[i][n-i-1];
	cout<<"б�Խ���֮��="<<clisum<<endl;
	system("pause");
	return 0;
}