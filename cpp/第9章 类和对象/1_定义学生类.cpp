#include <iostream>
#include <string>
using namespace std;
const int len = 3;
class Student
{
private:
	int num;
	string name;
	int age;
	double grade[len];
public:
	void set();
	double average();
	double maxscore();
};
double Student::average()
{
	double sum = 0;
	for (int i = 0; i < len; i++)
		sum += grade[i];
	return sum / 3;
}
double Student::maxscore()
{
	double max = grade[0];
	for (int i = 0; i < len; i++)
		if (max < grade[i])
			max = grade[i];
	return max;
}
void Student::set()
{
	cout << "请输入学号：";
	cin >> num;
	cout << "请输入姓名：";
	cin >> name;
	cout << "请输入年龄：";
	cin >> age;
	cout << "请输入"<<len<<"门课程成绩：";
	for (int i = 0; i < len; i++)
	{
		cin >> grade[i];
	}

}
int main()
{
	Student *stu;
	int num;
	cout << "请输入学生人数：" << endl;
	cin >> num;
	stu = new Student[num];
	for (int i = 0; i < num; i++)
		stu[i].set();
	for (int i = 0; i < num; i++)
	{
		cout << "第" << i+1<< "个同学的平均成绩：" << stu[i].average();
		cout << "第" << i+1 << "个同学的最高分：" << stu[i].maxscore();
		cout << endl;
	}
	system("pause");
	return 0;
}