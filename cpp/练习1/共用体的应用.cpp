#include <iostream>
#include <string>
using namespace std;
union StuGrade
{
	char cGrade;
	int iGrade;
};
struct Student
{
	string num;
	string name;
	string major;
	StuGrade grade;
};
int main()
{
	Student stu[5];
	cout<<"请输入5个学生的信息（学号、姓名、专业、成绩）："<<endl;
	for(int i=0; i<5; ++i)
	{
		cin>>stu[i].num>>stu[i].name>>stu[i].major;
		if(stu[i].major == "cs")
			cin>>stu[i].grade.iGrade;
		else
			cin>>stu[i].grade.cGrade;
	}
	cout<<"输出学生信息："<<endl;
}