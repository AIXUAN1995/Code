#include <iostream>
using namespace std;
int main()
{
	int a=3, b=4, c=7, d=9;
	//cout<<max(max(a,b),max(c,d));
	cout<<max(max(max(a,b),c),d);//���ַ����������ĸ��������ֵ
	system("pause");
	return 0;
}
//���������������ֵ
int max(int x,int y)
{
	return x>y?x:y;
}