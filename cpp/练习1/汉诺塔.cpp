#include <iostream>
void hanoi(int,char,char,char);
int num = 0;
int main()
{
	using namespace std;
	int n;
	cout<<"输入盘子数n"<<endl;
	cin>>n;
	cout<<"移动次序"<<endl;
	hanoi(n,'a','b','c');
	cout<<"移动次数"<<endl;
	cout<<num<<endl;
	system("pause");
	return 0;
}
void hanoi(int n,char a,char b,char c)
{
	using namespace std;
	if(n == 1)
	{
		cout<<a<<"-->"<<c<<'\t';
		num++;
	}
	else
	{
		hanoi(n-1,a,c,b);
		cout<<a<<"-->"<<c<<'\t';
		num++;
		hanoi(n-1,b,a,c);
	}
}