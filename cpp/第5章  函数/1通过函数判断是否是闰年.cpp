#include <iostream>
using namespace std;
bool leap(int year);
int main()
{
	int year;
	cout<<"������Ҫ�жϵ���ݣ�"<<endl;
	cin>>year;
	bool flag = false;
	flag = leap(year);
	if(flag == true)
	{
		cout<<year<<"������"<<endl;
	}
	else
		cout<<year<<"��������"<<endl;
	system("pause");
	return 0;
}
bool leap(int year)
{
	if((year%4 == 0 && year%100 != 0) || year % 400 == 0)
		return true;

}