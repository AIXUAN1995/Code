//��ͨ��ʽ
#include <iostream>
#include <cmath>
using namespace std;
const int NUM = 10;
double average(double a[NUM],double ave)
{
	double sum = 0, num; 
	for(int i=0; i<NUM; i++)
		sum += a[i];
	ave = sum/NUM;
	num = a[0];
	for(int i=0; i<NUM; i++)
	{
		if(abs(a[i]-ave)<abs(num-ave))
			num = a[i];
	}
	cout<<"ƽ��ֵ��"<<ave<<endl;
	return num;
}
int main()
{
	double a[NUM],ave = 0;
	cout<<"������10������";
	for(int i=0; i<NUM; i++)
		cin>>a[i];
	cout<<"С��ƽ��ֵ����ӽ�ƽ��ֵ����Ϊ��"<<average(a, ave);
	system("pause");
	return 0;
}

//ָ��
#include <iostream>
#include <cmath>
using namespace std;
const int NUM = 10;
double average(double a[NUM],double *p)
{
	double sum = 0, num;
	for(int i=0; i<NUM; i++)
		sum += a[i];
	*p = sum/NUM;
	num = a[0];
	for(int i=0; i<NUM; i++)
	{
		if(abs(a[i]-*p)<abs(num-*p))
			num = a[i];
	}
	
	return num;
}
int main()
{
	double a[NUM],ave = 0;
	cout<<"������10������";
	for(int i=0; i<NUM; i++)
		cin>>a[i];
	cout<<"С��ƽ��ֵ����ӽ�ƽ��ֵ����Ϊ��"<<average(a, &ave);
	cout<<"ƽ��ֵ��"<<ave<<endl;
	system("pause");
	return 0;
}