#include <iostream>
using namespace std;
class Date
{
public:
	Date()
	{
		year = 2013;
		month = 1;
		day = 1;
	}
	Date(int y, int m, int d)
	{
		year = y;
		month = m;
		day = d;
	}
	friend Date& operator--(Date &d);
	friend int compare(Date &d1, Date &d2);
	friend void display(Date &d);
private:
	int year;
	int month;
	int day;
};
Date& operator--(Date &d)
{
	if((d.month == 1) && (d.day == 1))
	{
		--d.year;
		d.month = 12;
		d.day = 31;
		goto exit;
	}
	if(d.day == 1)
	{
		--d.month;
		if(d.month == 4 || d.month == 6 || d.month == 9 || d.month == 11)
		{
			d.day = 30;
		}
		if(d.month == 1 || d.month == 3 || d.month == 8 || d.month == 10 || d.month == 12)
		{
			d.day = 31;
		}
		if(d.month == 2)
		{
			if((d.year%4 == 0 && d.year%100 != 0) || (d.year%400 == 0))
				d.day = 29;
			else
				d.day = 28;
		}
		goto exit;
	}
	--d.day;
exit:return d;
}
int compare(Date &d1, Date &d2)
{
	if((d1.year == d2.year) && (d1.month==d2.month)&&(d1.day == d2.day))
		return 1;
	else
		return 0;
}
void display(Date &d)
{
	cout<<d.year<<"-"<<d.month<<"-"<<d.day<<endl;
}
int main()
{
	Date d1(2011, 9, 1);
	Date d2(2012, 3, 5);
	for(int i=0; i<10000; i++)
	{
		if(compare(d1,d2)==0)
		{
			--d2;
			display(d2);
			cout<<i<<endl;
		}
		
	}
	system("pause");
	return 0;
}