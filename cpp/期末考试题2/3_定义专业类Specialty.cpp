/*
定义专业类Specialty，使其包括两个私有数据成员：专业名称char * sname和学分int score,
定义并实现该类的带参数的构造函数，以及该类的公有成员函数：显示专业名字和学分的函数Show。
定义学生类Student， 使其包含三个私有数据成员：名字char *name, 年龄int year，专业Specialty ss,
定义并实现该类的构造函数，以及该类的公有成员函数：显示姓名、年龄、和专业的函数Show。
*/
#include <iostream> 
#include <string>
using namespace std;
class Specialty
{
private:
	char* sname;
	int score;
public:
	Specialty(){}
	Specialty(char* sname1, int score1)
	{
		sname = sname1;
		score = score1;
	}
	void Show()
	{
		cout << "专业名称：" << sname << ",学分" << score << endl;
	}
};
class Student
{
private:
	char *name;
	int year;
	Specialty ss;
public:
	Student(char *name1, int year1, char *sname1, int score1) :ss(sname1,score1)
	{
		name = name1;
		year = year1;
	}
	void Show()
	{
		cout << "姓名：" << name << ",年龄：" << year << endl;
		ss.Show();
	}
};
int main()
{
	char *name = new char[10];
	char *sname = new char[10];
	int year, score;
	cout << "请输入姓名、年龄、专业、学分" << endl;
	cin >> name >> year >> sname >> score;
	Student s(name, year, sname, score);
	s.Show();
	system("pause");
	return 0;
}
