#include <iostream>
#include <memory.h>//��д��û�б���������������
using namespace std;
int main()
{
	const int n = 4;
	int a[n];
	for(int i=0; i<n; ++i)
		cin>>a[i];
	for(int i=0; i<n; ++i)
		cout<<a[i]<<endl;
	//��һ�����������������ڶ���������׼����ʼ������Ԫ�ص�ֵ������������������Ĵ�С��������sizeofȡ�ã�
	memset(a, 0, sizeof(int)*4);//�������������㣬����memset�Ƕ�ÿ���ֽڽ��и�ֵ�����Զ���int�ͱ������Ǹ�ֵΪ0
	for(int i=0; i<n; ++i)
		cout<<a[i]<<endl;

	system("pause");
	return 0;
}