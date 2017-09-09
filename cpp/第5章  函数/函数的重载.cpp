#include <iostream>
void f(int, int);
void f(int);
int main()
{
	using namespace std;
	int a, b;
	cin>>a>>b;
	f(a, b);
	f(a+b);
	system("pause");
	return 0;
}
void f(int a, int b)
{
	using namespace std;
	int num = a * b;
	cout<<num<<endl;
}
void f(int a)
{
	using namespace std;
	cout<<a<<endl;
}