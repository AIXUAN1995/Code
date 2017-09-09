/*定义学生类Student,使其包含两个私有数据成员：名字char *name和年龄int year，定义并实现该类的构造函数和析构函数SetYear、显示姓名和年龄的函数Show。要求成员函数在类外定义。*/
#include <iostream> 
#include <string>
using namespace std;
class Student
{
private:
	char *name;
	int year;
public:
	Student(char *name1, int year1);
	void SetName(char *name2);
	void SetYear(int year2);
	void Show();
};
Student::Student(char *name1, int year1)
{
	name = name1;
	year = year1;
}
void Student::SetName(char *name2)
{
	name = name2;
}
void Student::SetYear(int year2)
{
	year = year2;
}
void Student::Show()
{
	cout << "姓名：" << name << ",年龄" << year << endl;
}
int main()
{
	Student s("zhangsan", 23);
	s.Show();

	char *ch = new char;
	int year;
	cout << "输入修改后的名字：" << endl;
	cin >> ch;
	cout << "输入修改后的年龄：" << endl;
	cin >> year;
	s.SetName(ch);
	s.SetYear(year);
	s.Show();
	system("pause");
	return 0;
}