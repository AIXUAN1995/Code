#include <iostream>
#include <string>
using namespace std;
class Student//����ѧ����
{
public:
	Student(int nu, string na, string sp):num(nu), name(na), specia(sp){}
	void sDisplay()
	{
		cout<<"ѧ��="<<num<<endl;
		cout<<"����="<<name<<endl;
		cout<<"רҵ="<<specia<<endl;
	}
protected:
	int num;
	string name;
	string specia;
};
class Assistant//����������
{
public:
	Assistant(string na, string jo, double sa):name(na), job(jo), salary(sa){}
	void aDisplay()
	{
		cout<<"����="<<name<<endl;
		cout<<"ְ��="<<job<<endl;
		cout<<"����="<<salary<<endl;
	}
protected:
	string name;
	string job;
	double salary;
};
class StuAssis:public Student, public Assistant//����ѧ��������
{
public:
	StuAssis(int nu, string na, string sp, string jo, double sa, int t, double d):Student(nu,na,sp),Assistant(na, jo, sa),time(t), discot(d){}
	void total()
	{
		totalSalary+=discot*salary;
	}
	void display()
	{
		cout<<"ѧ��="<<num<<endl;
		cout<<"����="<<Student::name<<endl;
		cout<<"רҵ="<<specia<<endl;
		cout<<"ְ��="<<job<<endl;
		cout<<"����="<<salary<<endl;
		cout<<"����ʱ��="<<time<<endl;
		cout<<"ʵ�ʹ���="<<salary*discot<<endl;
		cout<<"�ܹ���="<<totalSalary<<endl;
	}
private:
	int time;
	double discot;
	static double totalSalary;
};
double StuAssis::totalSalary=0;
int main()
{
	StuAssis sa1(1001, "Zhang", "CS", "Teaching", 600, 5, 0.8);
	sa1.total();
	sa1.display();
	StuAssis sa2(1002, "Li", "MA", "Research", 500, 5, 0.8);
	sa2.total();
	sa2.display();
	system("pause");
	return 0;
}