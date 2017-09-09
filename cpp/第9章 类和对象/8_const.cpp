#include <iostream>
#include <string>
using namespace std;
class Teacher
{
public:
	Teacher(string name, int age, string course):teacName(name)
	{
		teacAge = age;
		teacCourse = course;
	}
	Teacher(Teacher &t):teacName(t.teacName)
	{
		teacAge = t.teacAge;
		teacCourse = t.teacCourse;
	}
	void set(int age, string course)
	{
		teacAge = age;
		teacCourse = course;
	}
	void teacDisplay()const//定义const成员函数
	{
		cout<<"教师姓名："<<teacName<<"\t";
		cout<<"教师年龄："<<teacAge<<"\t";
		cout<<"主讲课程："<<teacCourse<<"\n";
	}
private:
	const string teacName;
	int teacAge;
	string teacCourse;
};

int main()
{
	Teacher teac1("Zhang", 36, "操作系统");
	const Teacher teac2(teac1);
	teac1.teacDisplay();
	teac2.teacDisplay();
	teac1.set(39, "数据结构");
	teac1.teacDisplay();
	//teac2.set(39, "数据机构");//错误，不能修改对象teac2的值
	system("pause");
	return 0;
}