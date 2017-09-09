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
	cout << "������ѧ�ţ�";
	cin >> num;
	cout << "������������";
	cin >> name;
	cout << "���������䣺";
	cin >> age;
	cout << "������"<<len<<"�ſγ̳ɼ���";
	for (int i = 0; i < len; i++)
	{
		cin >> grade[i];
	}

}
int main()
{
	Student *stu;
	int num;
	cout << "������ѧ��������" << endl;
	cin >> num;
	stu = new Student[num];
	for (int i = 0; i < num; i++)
		stu[i].set();
	for (int i = 0; i < num; i++)
	{
		cout << "��" << i+1<< "��ͬѧ��ƽ���ɼ���" << stu[i].average();
		cout << "��" << i+1 << "��ͬѧ����߷֣�" << stu[i].maxscore();
		cout << endl;
	}
	system("pause");
	return 0;
}