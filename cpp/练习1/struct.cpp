#include <iostream>
using namespace std;
struct SDate
{
	int nYear;
	int nMonth;
	int nDay;
	void input()
	{
		cout<<"���������գ�";
		cin>>nYear>>nMonth>>nDay;
	}
	void print()
	{
		cout<<nYear<<"��"<<nMonth<<"��"<<nDay<<"��"<<endl;
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