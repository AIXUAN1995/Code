#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int n = 0, m = 0, num = 0, sum = 0;
	cout<<"请输入学生人数n="<<endl;
	cin>>n;
	cout<<"请输入课程数m="<<endl;
	cin>>m;
	vector<vector<int>>stGrade(n,vector<int>(m+2));
	cout<<"请输入学生学号和成绩:"<<endl;
	for(int i=0; i<n; i++)					//输入学号和成绩
	{
		for(int j=0; j<=m; j++)
		{
			cin>>stGrade[i][j];
			stGrade[i][m+1] += stGrade[i][j];
		}
	}
	for(int i=0; i<n-1; i++)				//按总成绩排序
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
	bool flag = true;						//输出各科都及格的学号和成绩
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
	//for(int i=0; i<n; i++)					//找出各科成绩都及格的学生
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
	//cout<<"符合的人数："<<num<<endl;
	//
	//*for(int i=0; i<num; i++)
	//{
	//	for(int j=0; j<=m; j++)
	//		cout<<stPass[i][j]<<endl;
	//}*/
	system("pause");
	return 0;
	
}