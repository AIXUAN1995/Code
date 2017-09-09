#include <iostream>
using namespace std;
bool leap(int year);
int main()
{
	int year;
	cout<<"请输入要判断的年份："<<endl;
	cin>>year;
	bool flag = false;
	flag = leap(year);
	if(flag == true)
	{
		cout<<year<<"是闰年"<<endl;
	}
	else
		cout<<year<<"不是闰年"<<endl;
	system("pause");
	return 0;
}
bool leap(int year)
{
	if((year%4 == 0 && year%100 != 0) || year % 400 == 0)
		return true;

}