/*����ѧ����Student,ʹ���������˽�����ݳ�Ա������char *name������int year�����岢ʵ�ָ���Ĺ��캯������������SetYear����ʾ����������ĺ���Show��Ҫ���Ա���������ⶨ�塣*/
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
	cout << "������" << name << ",����" << year << endl;
}
int main()
{
	Student s("zhangsan", 23);
	s.Show();

	char *ch = new char;
	int year;
	cout << "�����޸ĺ�����֣�" << endl;
	cin >> ch;
	cout << "�����޸ĺ�����䣺" << endl;
	cin >> year;
	s.SetName(ch);
	s.SetYear(year);
	s.Show();
	system("pause");
	return 0;
}