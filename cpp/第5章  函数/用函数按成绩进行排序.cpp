#include <iostream>
#include <vector>
using namespace std;
void sort(vector<vector<double>>score, int m, int n);
int main()
{
	int m, n;
	cout<<"������ѧ������m=\n";
	cin>>m;
	cout<<"������γ���n=\n";
	cin>>n;
	vector<vector<double>>score(m,vector<double>(n+2));
	cout<<"������ѧ�źͳɼ�"<<endl;
	for(int i=0; i<m; i++)			//����
	{
		bool flag = true;
		for(int j=0; j<n+1; j++)
		{
			cin>>score[i][j];
			if(j >= 1)
			{
				if(score[i][j] > 0)
					score[i][n+1] += score[i][j];
				else
				{
					flag = false;
					break;
				}
			}
		}
		if(flag == false)
		{
			cout<<"�����������󣬳��������"<<endl;
			break;
		}
	}
	sort(score, m, n);
	system("pause");
	return 0;
}
void sort(vector<vector<double>>score, int m, int n)//�������ٽ�������˵ĳɼ����
{
	bool flag = true;
	for(int i=0; i<m-1; i++)			//����
	{
		flag = true;
		for(int j=0; j<m-i-1; j++)
			if(score[j][n+1]<score[j+1][n+1])
			{
				flag = false;
				for(int k=0; k<n+2; k++)
				{
					double temp = score[j][k];
					score[j][k] = score[j+1][k];
					score[j+1][k] = temp;	
				}
			}
		if(flag)
			break;
	} 
	for(int i=0; i<m; i++)
	{
		flag = true;
		for(int j=1; j<n+1; j++)
		{
			if(score[i][j] < 60)
			{
				flag = false;			//���ֲ�����ĳɼ�����ѭ��
				break;
			}
		}
		if(flag)		
			for(int j=0; j<n+2; j++)
				cout<<score[i][j]<<"\t";	//���
		cout<<endl;
	}
}