//����һԪ����ʽP(x,n) = a0 + a1x + a2x^2 + ... +anx^n��ֵ������x, n, a0, a1, ... ,an,
//�������ʽP(x,n)��ֵ������㷨��⣬��ѡ����ʵ����롢�����ʽ��Ҫ���㷨���нϺõ�ʱ�����ܡ�
#include <iostream>
#include <string>
using namespace std;

//��һ��˫��ѭ��
double func1(double x, int n)
{//�˷�������ϵ��aʱΪ���ݷ�������
	double a, sum = 0, product = 1;
	for (int i = 0; i < n; i++)
	{
		cout << "����a" << endl;
		cin >> a;
		product = 1;
		for (int j = 0; j < i; j++)
		{
			product *= x;
		}
		sum += a*product;
	}
	return sum;
}

//������һ��ѭ��
double func2(double x, int n)
{//�˷�������ϵ��aʱ��Ҫ�ɽ���˳������
	double a, sum = 0;
	for (int i = 0; i < n; i++)
	{
		cout << "����a" << endl;
		cin >> a;
		sum = sum*x + a;
	}
	return sum;
}
int main()
{
	double x;
	int n;
	cout << "����x:" << endl;
	cin >> x;
	cout << "����n:" << endl;
	cin >> n;
	
	cout << "��Ϊ��" << func1(x, n) << endl;
	system("pause");
	return 0;
}