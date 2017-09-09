/*
类静态成员练习：
静态数据成员很一般数据成员的区别：
	1.定义类时分配储存空间，一般的数据成员依附于对象
	2.在程序运行期间一直存在
	3.只能在类体外进行初始化
静态成员函数：
	可以直接访问所在类中的静态数据成员，
	若是访问非静态数据成员，应在成员名前加对象名和点（.）,
	以指明是访问哪个对象的成员。
*/
#include <iostream>
#include <string>
using namespace std;
class Employee
{
public:
	Employee(int num = 0, string name = "", float salary = 0)
	{
		empNum = num;
		empName = name;
		empSalary = salary;
	}
	void setValue(int num = 0, string name = "", float salary = 0)
	{
		empNum = num;
		empName = name;
		empSalary = salary;
	}
	void total()
	{
		empSumSal += empSalary;
		empSumEmp++;
	}
	static void average()
	{
		empAveSal = empSumSal / empSumEmp;
	}
private:
	int empNum;			//职工编号
	string empName;		//职工姓名
	float empSalary;	//职工工资
public:
	static int empSumEmp;	//职工总数
	static float empSumSal;	//工资总额
	static float empAveSal;	//平均工资
};
int Employee::empSumEmp = 0;
float Employee::empSumSal = 0;
float Employee::empAveSal = 0;
int main()
{
	const int N = 5;
	Employee emp[N];
	for (int i = 0; i < N; i++)
	{
		int num;
		string name;
		float salary;
		cout << "职工编号=";
		cin >> num;
		cout << "职工姓名=";
		cin >> name;
		cout << "职工工资=";
		cin >> salary;
		cout << endl;
		emp[i].setValue(num, name, salary);
	}
	for (int i = 0; i < N; i++)
		emp[i].total();
	Employee::average();//访问Employee类中的静态成员函数average();
	cout << "职工总数=" << Employee::empSumEmp << endl;
	cout << "工资总额=" << Employee::empSumSal << endl;
	cout << "平均工资=" << Employee::empAveSal << endl;
	system("pause");
	return 0;
}