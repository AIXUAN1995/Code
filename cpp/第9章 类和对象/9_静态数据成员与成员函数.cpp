/*
�ྲ̬��Ա��ϰ��
��̬���ݳ�Ա��һ�����ݳ�Ա������
	1.������ʱ���䴢��ռ䣬һ������ݳ�Ա�����ڶ���
	2.�ڳ��������ڼ�һֱ����
	3.ֻ������������г�ʼ��
��̬��Ա������
	����ֱ�ӷ����������еľ�̬���ݳ�Ա��
	���Ƿ��ʷǾ�̬���ݳ�Ա��Ӧ�ڳ�Ա��ǰ�Ӷ������͵㣨.��,
	��ָ���Ƿ����ĸ�����ĳ�Ա��
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
	int empNum;			//ְ�����
	string empName;		//ְ������
	float empSalary;	//ְ������
public:
	static int empSumEmp;	//ְ������
	static float empSumSal;	//�����ܶ�
	static float empAveSal;	//ƽ������
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
		cout << "ְ�����=";
		cin >> num;
		cout << "ְ������=";
		cin >> name;
		cout << "ְ������=";
		cin >> salary;
		cout << endl;
		emp[i].setValue(num, name, salary);
	}
	for (int i = 0; i < N; i++)
		emp[i].total();
	Employee::average();//����Employee���еľ�̬��Ա����average();
	cout << "ְ������=" << Employee::empSumEmp << endl;
	cout << "�����ܶ�=" << Employee::empSumSal << endl;
	cout << "ƽ������=" << Employee::empAveSal << endl;
	system("pause");
	return 0;
}