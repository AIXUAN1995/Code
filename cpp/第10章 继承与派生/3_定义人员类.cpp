#include <iostream>
#include <string>
using namespace std;
class Person
{
protected:
	int id;
	string name;
	string sex;
public:
	Person(int id1, string name1, string sex1)
	{
		id = id1;
		name = name1;
		sex = sex1;
	}
	void set(int id1, string name1, string sex1)
	{
		id = id1;
		name = name1;
		sex = sex1;
	}
	void display()
	{
		cout << "身份证号：\t" << id << endl;
		cout << "姓名：\t\t" << name << endl;
		cout << "性别：\t\t" << sex << endl;
	}
};
class Teacher:public Person
{
protected:
	string rank;
	string course;
	double salary;
public:
	Teacher(int id1, string name1, string sex1, string rank1, string course1, double salary1) :Person(id1, name1, sex1)
	{
		rank = rank1;
		course = course1;
		salary = salary1;
	}
	void set(int id1, string name1, string sex1, string rank1, string course1, double salary1)
	{
		id = id1;
		name = name1;
		sex = sex1;
		rank = rank1;
		course = course1;
		salary = salary1;
	}
	void display()
	{
		cout << "身份证号：\t" << id <<endl;
		cout << "姓名：\t\t" << name << endl;
		cout << "性别：\t\t" << sex << endl;
		cout << "职称：\t\t" << rank << endl;
		cout << "主讲课程：\t" << course << endl;
		cout << "薪水：\t\t" << salary << endl;
	}
};
class Student:public Person
{
protected:
	int num;
	string major;
	double grade;
public:
	Student(int id1, string name1, string sex1, int num1, string major1, double grade1) :Person(id1, name1, sex1)
	{
		num = num1;
		major = major1;
		grade = grade1;
	}
	void set(int id1, string name1, string sex1, int num1, string major1, double grade1)
	{
		id = id1;
		name = name1;
		sex = sex1;
		num = num1;
		major = major1;
		grade = grade1;
	}
	void display()
	{
		cout << "身份证号：\t" << id << endl;
		cout << "姓名：\t\t" << name << endl;
		cout << "性别：\t\t" << sex << endl;
		cout << "学号：\t\t" << num << endl;
		cout << "专业：\t\t" << major <<endl;
		cout << "成绩：\t\t" << grade <<endl;
	}
};
class SportStudent :public Student
{
private:
	string items;
public:
	SportStudent(int id1, string name1, string sex1, int num1, string major1, double grade1, string items1) :Student(id1, name1, sex1, num1, major1, grade1)
	{
		items = items1;
	}
	void set(int id1, string name1, string sex1, int num1, string major1, double grade1, string items1)
	{
		id = id1;
		name = name1;
		sex = sex1;
		num = num1;
		major = major1;
		grade = grade1;
		items = items1;
	}
	void display()
	{
		cout << "身份证号：\t" << id << endl;
		cout << "姓名：\t\t" << name << endl;
		cout << "性别：\t\t" << sex << endl;
		cout << "学号：\t\t" << num << endl;
		cout << "专业：\t\t" << major << endl;
		cout << "成绩：\t\t" << grade << endl;
		cout << " 项目：\t\t" << items << endl;
	}
};
int main()
{
	//Person类
	Person p(111111, "张三", "男");
	p.display();
	p.set(222222, "李四", "女");
	cout << "修改后：" << endl;
	p.display();

	//Student类
	Student s(111111, "张三", "男", 123345, "软件工程", 999);
	s.display();
	s.set(222222, "李四", "女", 123123, "软件工程", 1000);
	cout << "修改后：" << endl;
	s.display();

	//Teacher类
	Teacher t(111111, "张三", "男", "教授", "程序设计", 10000);
	t.display();
	t.set(222222, "李四", "女", "教授", "数据库", 10000);
	cout << "修改后：" << endl;
	t.display();

	//SportStudent类
	SportStudent ss(111111, "张三", "男", 123345, "软件工程", 999, "basketball");
	ss.display();
	ss.set(222222, "李四", "女", 123123, "软件工程", 999, "table tennis");
	cout << "修改后：" << endl;
	ss.display();
	system("pause");
	return 0;
}