#include <iostream>
using namespace std;
class A
{
public:
	A(int i, double d)
	{
		a_i = i;
		a_d = d;
	}
	void set(int i, double d)
	{
		a_i = i;
		a_d = d;
	}
	void display()
	{
		cout << "�����Ϣ:" << endl;
		cout << "a_i = " << a_i << endl;
		cout << "a_d = " << a_d << endl;
	}
	void input()
	{
		cin >> a_i >> a_d;
	}
private:
	int a_i;
	double a_d;
};
int main()
{
	A a(1, 3.5);//�����ʱ��ϵͳ���ù��캯��Ϊ���󸳳�ֵ
	a.display();

	a.set(2, 5.5);//�������֮�����set()�����ı�����Ա������ֵ
	a.display();

	a.input();//ͨ��input�����ı��Ա������ֵ
	a.display();

	return 0;
}