#include <iostream>
using namespace std;
int main()
{
	const char *p, *q;
	p = "xyz";
	cout<<*p<<endl;//x
	cout<<p<<endl;//xyz
	cout<<p[0]<<" "<<p[1]<<endl;//ִ�н��Ϊx y
	//p[0] = 'a';//��������ָ��Ϊconst char *p����붼����ͨ�����������ı�����char *p,����ʱ�쳣
	cout<<sizeof(p);//4

	//������ָ��
	char a1[] = "abcdefghihklmn";
	char *a2 = "opqrstuvwxyz";

	cout<<&a1<<endl;//��ַ�����ַ����׵�ַ��ͬ
	cout<<a1<<endl;//abcdefghijklmn
	cout<<&a1[0]<<endl;//abcdefghijklmn

	cout<<&a2<<endl;//��ַ�����ַ����׵�ַ��ͬ
	cout<<a2<<endl;//opqrstuvwxyz
	cout<<&a2[0]<<endl;//opqrstuvwxyz

	system("pause");
	return 0;
}