#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct Student
{
	string name, num;
	int age;
	double score[3];
};
void account(vector<Student>stu, int n)
{
	int n1 = 0;
	for(int i=0; i<n; i++)
	{
		if(stu[i].score[0]<60 || stu[i].score[1]<60 || stu[i].score[2]<60)
			n1++;
	}
	cout<<n1*100.0/n<<"%";
}
int main()
{
	int n;
	cout<<"请输入学生人数："<<endl;
	cin>>n;
	vector<Student>stu(n);
	for(int i=0; i<n; i++)
	{
		cout<<"请输入第"<<i<<"个学生的姓名：";
		cin>>stu[i].name;
		cout<<"请输入第"<<i<<"个学生的学号：";
		cin>>stu[i].num;
		cout<<"请输入第"<<i<<"个学生的年龄：";
		cin>>stu[i].age;
		cout<<"请输入第"<<i<<"个学生的语文成绩：";
		cin>>stu[i].score[0];
		cout<<"请输入第"<<i<<"个学生的数学成绩：";
		cin>>stu[i].score[1];
		cout<<"请输入第"<<i<<"个学生的英语成绩：";
		cin>>stu[i].score[2];
	}
	account(stu, n);
	system("pause");
	return 0;
}