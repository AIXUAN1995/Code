#include <iostream>
using namespace std;
#include <vector>
int main()
{
	int n, m=1;
	cout<<"����������"<<endl;
	cin>>n;
	vector<int>score(n);
	cout<<"����ɼ���"<<endl;
	for(int i=0; i<n; i++)
	{
		cin>>score[i];
	}
	for(int i=0; i<n; i++)
	{
		m = 1;
		for(int j=1+i; j<n; j++)
		{
			if(score[j] != -1 || score[i] != -1)
			{

					if(score[i] == score[j])
					{
						m++;
						score[j] = -1;
					}
			}
			
		}
		if(score[i] != -1)
			cout<<"�ɼ�Ϊ"<<score[i]<<"������Ϊ��"<<m<<endl;
		
	}
	system("pause");
	return 0;
}