//������������ã�1.���ڵ��Գ���  2.�����ظ�����
#include <iostream>
using namespace std;
#define DEBUG			//���ڱ����ظ�����
#ifndef TRI				//�����ʶ��TRI
#define TRI				//����ṹ������Tri
struct Tri
{
	double x;
	double y;
	double z;
};
#endif
int main()
{
	int a[10] = {62, 45, 78, 82, 95, 68, 75, 98, 81, 60};
	cout<<"����ǰ�����ݣ�"<<endl;
	for(int i=0; i<10; ++i)
		cout<<a[i]<<" ";
	for(int i=0; i<9; ++i)
	{
		for(int j=0; j<9; ++j)
			if(a[j]<a[j+1])
			{
				int t = a[j];
				a[j] = a[j+1];
				a[j+1] = t;
			}
		#ifdef DEBUG				//���ڵ��Գ������������
			cout<<endl;
			for(int i=0; i<10; ++i)
				cout<<a[i]<<" ";			//������˳�������û����һ�ξ����һ��
			cout<<endl;
		#endif
	}	
	cout<<"���������ݣ�"<<endl;
	for(int i=0; i<10; ++i)
		cout<<a[i]<<" ";
	system("pause");
	return 0;
}