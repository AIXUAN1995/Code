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
	void teacDisplay()const//����const��Ա����
	{
		cout<<"��ʦ������"<<teacName<<"\t";
		cout<<"��ʦ���䣺"<<teacAge<<"\t";
		cout<<"�����γ̣�"<<teacCourse<<"\n";
	}
private:
	const string teacName;
	int teacAge;
	string teacCourse;
};

int main()
{
	Teacher teac1("Zhang", 36, "����ϵͳ");
	const Teacher teac2(teac1);
	teac1.teacDisplay();
	teac2.teacDisplay();
	teac1.set(39, "���ݽṹ");
	teac1.teacDisplay();
	//teac2.set(39, "���ݻ���");//���󣬲����޸Ķ���teac2��ֵ
	system("pause");
	return 0;
}