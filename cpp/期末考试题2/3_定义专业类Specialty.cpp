/*
����רҵ��Specialty��ʹ���������˽�����ݳ�Ա��רҵ����char * sname��ѧ��int score,
���岢ʵ�ָ���Ĵ������Ĺ��캯�����Լ�����Ĺ��г�Ա��������ʾרҵ���ֺ�ѧ�ֵĺ���Show��
����ѧ����Student�� ʹ���������˽�����ݳ�Ա������char *name, ����int year��רҵSpecialty ss,
���岢ʵ�ָ���Ĺ��캯�����Լ�����Ĺ��г�Ա��������ʾ���������䡢��רҵ�ĺ���Show��
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
		cout << "רҵ���ƣ�" << sname << ",ѧ��" << score << endl;
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
		cout << "������" << name << ",���䣺" << year << endl;
		ss.Show();
	}
};
int main()
{
	char *name = new char[10];
	char *sname = new char[10];
	int year, score;
	cout << "���������������䡢רҵ��ѧ��" << endl;
	cin >> name >> year >> sname >> score;
	Student s(name, year, sname, score);
	s.Show();
	system("pause");
	return 0;
}
