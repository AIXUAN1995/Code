#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct Student
{
	string name, num;
	int age;
	double score[3];
};
void account(vector<Student>stu, int n)
{
	int n1 = 0;
	for(int i=0; i<n; i++)
	{
		if(stu[i].score[0]<60 || stu[i].score[1]<60 || stu[i].score[2]<60)
			n1++;
	}
	cout<<n1*100.0/n<<"%";
}
int main()
{
	int n;
	cout<<"������ѧ��������"<<endl;
	cin>>n;
	vector<Student>stu(n);
	for(int i=0; i<n; i++)
	{
		cout<<"�������"<<i<<"��ѧ����������";
		cin>>stu[i].name;
		cout<<"�������"<<i<<"��ѧ����ѧ�ţ�";
		cin>>stu[i].num;
		cout<<"�������"<<i<<"��ѧ�������䣺";
		cin>>stu[i].age;
		cout<<"�������"<<i<<"��ѧ�������ĳɼ���";
		cin>>stu[i].score[0];
		cout<<"�������"<<i<<"��ѧ������ѧ�ɼ���";
		cin>>stu[i].score[1];
		cout<<"�������"<<i<<"��ѧ����Ӣ��ɼ���";
		cin>>stu[i].score[2];
	}
	account(stu, n);
	system("pause");
	return 0;
}