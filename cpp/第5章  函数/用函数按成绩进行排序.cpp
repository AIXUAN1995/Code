#include <iostream>
#include <vector>
using namespace std;
void sort(vector<vector<double>>score, int m, int n);
int main()
{
	int m, n;
	cout<<"请输入学生人数m=\n";
	cin>>m;
	cout<<"请输入课程数n=\n";
	cin>>n;
	vector<vector<double>>score(m,vector<double>(n+2));
	cout<<"请输入学号和成绩"<<endl;
	for(int i=0; i<m; i++)			//输入
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
			cout<<"您的输入有误，程序结束！"<<endl;
			break;
		}
	}
	sort(score, m, n);
	system("pause");
	return 0;
}
void sort(vector<vector<double>>score, int m, int n)//先排序，再将及格的人的成绩输出
{
	bool flag = true;
	for(int i=0; i<m-1; i++)			//排序
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
				flag = false;			//出现不及格的成绩跳出循环
				break;
			}
		}
		if(flag)		
			for(int j=0; j<n+2; j++)
				cout<<score[i][j]<<"\t";	//输出
		cout<<endl;
	}
}