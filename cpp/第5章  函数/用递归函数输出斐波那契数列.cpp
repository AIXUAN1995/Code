#include <iostream>
using namespace std;
//��һ
//void fib1(int a, int b ,int n)
//{
//	if(n == 0)
//	{
//		return;
//	}
//	cout<<a<<" ";
//	fib(b, a+b, n-1);
//}
//����
int fib2(int n)
{
	if(n == 1 || n==0)
		return 1;
	else
		return fib2(n-1)+fib2(n-2);
}
int main()
{
	int a = 1, b = 1, n;
	cout<<"������Ҫ�����쳲��������������ĸ�����"<<endl;
	cin>>n;
	//fib1(a, b, n);
	for(int i=0; i<n; i++)
		cout<<fib2(i)<<" ";
	system("pause");
	return 0;
}
//int f(int n)
//{
// if (n==0||n==1)    //ע��������ѭ����ֵΪ0
//  return 1;
// else
//  return f(n-1)+f(n-2);
//}
//int main()
//{
// int i,a[12];
// for (i=0;i<12;i++)
// {
//  a[i]=f(i);
//  cout<<f(i)<<endl;
// }
// system("pause");
// return 0;
// 
//}