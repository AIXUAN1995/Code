#include <iostream>
template <typename T>
//T max(T x, T y)      //����ʱ�ᱨ�������ж���max������
//{
//	return x>y?x:y;    //	1	IntelliSense: �ж�� ���غ��� "max" ʵ��������б�ƥ��:	e:\c++\����ģ��\����ģ��\����ģ��.cpp	18	8	����ģ��
//
//}
T m(T x, T y)
{
	return x>y?x:y;
}
int main()
{
	using namespace std;

	double x, y;
	cout<<"������������Ҫ�Ƚϵ���"<<endl;
	cin>>x>>y;
	cout<<m(x, y);
	system("pause");
	return 0;
}