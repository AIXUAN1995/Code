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
		cout << "���֤�ţ�\t" << id << endl;
		cout << "������\t\t" << name << endl;
		cout << "�Ա�\t\t" << sex << endl;
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
		cout << "���֤�ţ�\t" << id <<endl;
		cout << "������\t\t" << name << endl;
		cout << "�Ա�\t\t" << sex << endl;
		cout << "ְ�ƣ�\t\t" << rank << endl;
		cout << "�����γ̣�\t" << course << endl;
		cout << "нˮ��\t\t" << salary << endl;
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
		cout << "���֤�ţ�\t" << id << endl;
		cout << "������\t\t" << name << endl;
		cout << "�Ա�\t\t" << sex << endl;
		cout << "ѧ�ţ�\t\t" << num << endl;
		cout << "רҵ��\t\t" << major <<endl;
		cout << "�ɼ���\t\t" << grade <<endl;
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
		cout << "���֤�ţ�\t" << id << endl;
		cout << "������\t\t" << name << endl;
		cout << "�Ա�\t\t" << sex << endl;
		cout << "ѧ�ţ�\t\t" << num << endl;
		cout << "רҵ��\t\t" << major << endl;
		cout << "�ɼ���\t\t" << grade << endl;
		cout << " ��Ŀ��\t\t" << items << endl;
	}
};
int main()
{
	//Person��
	Person p(111111, "����", "��");
	p.display();
	p.set(222222, "����", "Ů");
	cout << "�޸ĺ�" << endl;
	p.display();

	//Student��
	Student s(111111, "����", "��", 123345, "�������", 999);
	s.display();
	s.set(222222, "����", "Ů", 123123, "�������", 1000);
	cout << "�޸ĺ�" << endl;
	s.display();

	//Teacher��
	Teacher t(111111, "����", "��", "����", "�������", 10000);
	t.display();
	t.set(222222, "����", "Ů", "����", "���ݿ�", 10000);
	cout << "�޸ĺ�" << endl;
	t.display();

	//SportStudent��
	SportStudent ss(111111, "����", "��", 123345, "�������", 999, "basketball");
	ss.display();
	ss.set(222222, "����", "Ů", 123123, "�������", 999, "table tennis");
	cout << "�޸ĺ�" << endl;
	ss.display();
	system("pause");
	return 0;
}