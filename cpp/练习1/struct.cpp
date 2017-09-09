#include <iostream>
using namespace std;
struct SDate
{
	int nYear;
	int nMonth;
	int nDay;
	void input()
	{
		cout<<"输入年月日：";
		cin>>nYear>>nMonth>>nDay;
	}
	void print()
	{
		cout<<nYear<<"年"<<nMonth<<"月"<<nDay<<"日"<<endl;
	}
};
int main()
{
	struct SDate d1,d2;
	d1.input();
	d2.input();
	d1.print();
	d2.print();
	cout<<sizeof(d1)<<'\t'<<sizeof(d2)<<endl;
	system("pause");
	return 0;
}