#include <iostream>
#include <string>
using namespace std;
class Student//定义学生类
{
public:
	Student(int nu, string na, string sp):num(nu), name(na), specia(sp){}
	void sDisplay()
	{
		cout<<"学号="<<num<<endl;
		cout<<"姓名="<<name<<endl;
		cout<<"专业="<<specia<<endl;
	}
protected:
	int num;
	string name;
	string specia;
};
class Assistant//定义助理类
{
public:
	Assistant(string na, string jo, double sa):name(na), job(jo), salary(sa){}
	void aDisplay()
	{
		cout<<"姓名="<<name<<endl;
		cout<<"职务="<<job<<endl;
		cout<<"工资="<<salary<<endl;
	}
protected:
	string name;
	string job;
	double salary;
};
class StuAssis:public Student, public Assistant//定义学生助理类
{
public:
	StuAssis(int nu, string na, string sp, string jo, double sa, int t, double d):Student(nu,na,sp),Assistant(na, jo, sa),time(t), discot(d){}
	void total()
	{
		totalSalary+=discot*salary;
	}
	void display()
	{
		cout<<"学号="<<num<<endl;
		cout<<"姓名="<<Student::name<<endl;
		cout<<"专业="<<specia<<endl;
		cout<<"职务="<<job<<endl;
		cout<<"工资="<<salary<<endl;
		cout<<"工作时间="<<time<<endl;
		cout<<"实际工资="<<salary*discot<<endl;
		cout<<"总工资="<<totalSalary<<endl;
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