#include<iostream>
#include<cmath>
using namespace std;

bool judge(double, double, double);
void count(double, double, double);
int main()
{
	double edge1, edge2, edge3;
	cout << "�����������߳���";
	cin >> edge1 >> edge2 >> edge3;
	if (judge(edge1, edge2, edge3)){
		cout << "������ı߳����Թ��������Σ�" << endl;
		count(edge1, edge2, edge3);
	}
	else
		cout << "������ı߳������Թ��������Σ�" << endl;
	system("pause");
	return 0;
}
bool judge(double e1, double e2, double e3){
	if ((e1 + e2 > e3) && (e1 + e3 > e2) && (e2 + e3 > e1))
		return 1;
	else
		return 0;
}
void count(double e1, double e2, double e3){
	double p, q;
	p = (e1 + e2 + e3) / 2;
	q = p*(p - e1)*(p - e2)*(p - e3);
	cout << sqrt(q);
}
