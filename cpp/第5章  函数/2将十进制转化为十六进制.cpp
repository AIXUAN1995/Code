//#include <iostream>
//#include <vector>
//using namespace std;
//int n=0;
//void radix(int num)
//{
//	int a;
//	if(num>=16)
//	{
//		while(num>=16)
//		{
//			a = num%16;
//			num = num/16;
//			cout<<a;
//			n++;
//		}
//		if(num<10 && num>=0)
//		{
//			cout<<num;
//			n++;
//		}
//		else if(num == 10)
//		{
//			cout<<"A";
//			n++;
//		}
//		else if(num == 11)
//		{
//			cout<<"B";
//			n++;
//		}
//		else if(num == 12)
//		{
//			cout<<"c";
//			n++;
//		}
//		else if(num == 13)
//		{
//			cout<<"D";
//			n++;
//		}
//		else if(num == 14)
//		{
//			cout<<"E";
//			n++;
//		}
//		else
//		{
//			cout<<"F";
//			n++;
//		}
//	}
//	else if(num<10 && num>=0)
//	{
//		cout<<num;
//		n++;
//	}
//	else if(num == 10)
//		{
//			cout<<"A";
//			n++;
//		}
//	else if(num == 11)
//	{
//		cout<<"B";
//		n++;
//	}
//	else if(num == 12)
//	{
//		cout<<"c";
//		n++;
//	}
//	else if(num == 13)
//	{
//		cout<<"D";
//		n++;
//	}
//	else if(num == 14)
//	{
//		cout<<"E";
//		n++;
//	}
//	else
//	{
//		cout<<"F";
//		n++;
//	}
//	cout<<n;
//
//}
//void sort(int num)
//{
//	radix(num);
//	vector<int>a(n);
//	a
//}
//
////��ʮ���Ƶ���ת��Ϊʮ���������
//int main()
//{
//	int num;
//	cout<<"������Ҫת�������֣�"<<10<<endl;
//	cin>>num;
//	radix(num);
//	system("pause");
//	return 0;
//}
#include <iostream>
using namespace std;
void radix(int num,int n)
{
	if(n == 2)
	{
		if(num == 0)
			return;
		int a = num % 2;
		radix(num/2, n);
		cout<<char(a+'0');
	}
	if(n == 8)
	{
		if(num == 0)
			return;
		int a = num % 8;
		radix(num/8, n);
		cout<<char(a+'0');
	}
	if(n == 16)
	{
		if(num == 0)//ת��Ϊ16����
		{
			return;
		}
		int a = num % 16;
		radix(num/16, n);
		cout<<char(a+(a<10?'0':'A'-10));
	}
}
int main()
{
	int num, n;
	cout<<"������Ҫת�������֣�"<<endl;
	cin>>num;
	cout<<"������Ҫת��Ϊ�Ľ�������"<<endl;
	cin>>n;
	radix(num, n);
	system("pause");
	return 0;
}