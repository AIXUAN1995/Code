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
	cout<<"������5��ѧ������Ϣ��ѧ�š�������רҵ���ɼ�����"<<endl;
	for(int i=0; i<5; ++i)
	{
		cin>>stu[i].num>>stu[i].name>>stu[i].major;
		if(stu[i].major == "cs")
			cin>>stu[i].grade.iGrade;
		else
			cin>>stu[i].grade.cGrade;
	}
	cout<<"���ѧ����Ϣ��"<<endl;
}