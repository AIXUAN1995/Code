#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int n = 0, m = 0, num = 0, sum = 0;
	cout<<"������ѧ������n="<<endl;
	cin>>n;
	cout<<"������γ���m="<<endl;
	cin>>m;
	vector<vector<int>>stGrade(n,vector<int>(m+2));
	cout<<"������ѧ��ѧ�źͳɼ�:"<<endl;
	for(int i=0; i<n; i++)					//����ѧ�źͳɼ�
	{
		for(int j=0; j<=m; j++)
		{
			cin>>stGrade[i][j];
			stGrade[i][m+1] += stGrade[i][j];
		}
	}
	for(int i=0; i<n-1; i++)				//���ܳɼ�����
	{
		int a = 0;
		for(int j=0; j<n-1-i; j++)
		{
			if(stGrade[i][m+1]<stGrade[i+1][m+1])
			{
				for(int k=0; k<m+2; k++)
				{
					int temp;
					temp = stGrade[i][k];
					stGrade[i][k] = stGrade[i+1][k];
					stGrade[i+1][k] = temp;
					a = 1;
				}
			}
		}
		if(a == 0)
		{
			break;
		}
	}
	bool flag = true;						//������ƶ������ѧ�źͳɼ�
	for(int i=0; i<n; i++)
	{
		flag = true;
		for(int j=1; j<=m; j++)
		{
			if(stGrade[i][j] < 60)
			{
				flag = false;
				break;
			}
		}
		if(flag == true)
		{
			for(int j=0; j<m+2; j++)
				cout<<stGrade[i][j]<<'\t';
		}
		cout<<endl;
	}
	
	//bool flag = true;
	//for(int i=0; i<n; i++)					//�ҳ����Ƴɼ��������ѧ��
	//{
	//	flag = true;
	//	for(int j=1; j<=m; j++)
	//	{
	//		stGrade[i][m+1] += stGrade[i][j];	
	//		if(stGrade[i][j]<60)
	//		{
	//			flag = false;
	//			break;
	//		}
	//	}
	//	if(flag == true)
	//	{
	//		num++;
	//		for(int j=0; j<m+2; j++)
	//		{
	//			cout<<stGrade[i][j]<<'\t';
	//		}
	//		cout<<endl;
	//		/*for(int j=0; j<=m; j++)
	//		{
	//			stPass[i][j] = stGrade[i][j];
	//		}*/
	//	}
	//}
	//cout<<"���ϵ�������"<<num<<endl;
	//
	//*for(int i=0; i<num; i++)
	//{
	//	for(int j=0; j<=m; j++)
	//		cout<<stPass[i][j]<<endl;
	//}*/
	system("pause");
	return 0;
	
}