#include<iostream>
#include<string>
using namespace std;
void fun(char*a, int i, int j)
{
	int t;
	while(i<j)
	{
		t = a[i];
		a[i] = a[j];
		a[j] = t;
		i++;
		j--;
	}
}
int main()
{
	char str[30];
	int i, j;
	cout<<"���룺";
	cin.getline(str,30);
	cout<<"����i��j";
	cin>>i>>j;
	fun(str, i, j);
	cout<<endl;
	cout<<"���ĺ��"<<str;
	system("pause");
	return 0;
}