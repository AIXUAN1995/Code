#include <iostream>
#define f(x,y) (((x)*(x))+((y)*(y)))
//1.�궨���ʱ��Ҫע�����������
//2.����ҲҪ������
int main()
{
	using namespace std;
	int x,y;
	cout<<"������Ҫ����ƽ����2����������"<<endl;
	cin>>x>>y;
	cout<<2*f(x,y)<<endl;
	system("pause");
	return 0;
}