#include <iostream>
inline int f(int x)//�������������Լ������е�ʱ�䣬�ٱ����ͬʱ�������ŵ���ָ��λ�ã�ʡ���õ�ʱ������
{
	return x*x;
}
//�������������������������ʵ��
//1.ʹ��switchʱ
//2.ʹ��ѭ����ʱ��
//3.ִ�д�������1000��ʱ
int main()
{
	using namespace std;
	int n;
	cout<<"������Ҫ�������"<<endl;
	cin>>n;
	cout<<f(n)<<endl;
	system("pause");
	return 0;
}