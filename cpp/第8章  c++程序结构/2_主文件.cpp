/*ͷ�ļ����ڴ�Ŷ����Ͷ��塢����������ȫ�ֱ���������ʵ�����������Ϊ����ӿڣ�
��Դ�����ļ�������͵�ʵ�֡������塢ȫ�ֱ�������.*/
#include <iostream>
#include "ͷ�ļ�.h"
using namespace std;
int add(int a, int b)
{
	extern int m;//����mΪ���ⲿ������ʵ�����Ǹ��߱���ϵͳm�Ķ����ں��棬
				//�����Ƕ�m�Ķ��壬�����䲢����ͬʱ��m��ֵ
	m++;
	return a+b;
}
int n=0;
int sub(int a, int b)
{
	n++;
	return a-b;
}
int main()
{
	int x, y;
	for(int i=1; i<=4; ++i)
	{
		cout<<"������x��y��ֵ��"<<endl;
		cin>>x>>y;
		if(x<y)
			cout<<"x+y="<<add(x, y)<<endl;
		else
			cout<<"x-y="<<sub(x, y)<<endl;
	}
	cout<<"m="<<m<<endl;
	cout<<"n="<<n<<endl;
	system("pause");
	return 0;
}