#include <iostream>
using namespace std;
enum WeekDay{Sun, Mon, Tue, Wed, Tues, Fri, Sat};
int main()
{
	WeekDay wd = Sun;
	cout << wd;			//����Ľ����0��
	//����ֱ����cin��cout�������ö�����ͱ�����ֵ

	//������ת���ٸ�ֵ
	WeekDay wd2 = WeekDay(2);                                                                             
	system("pause");
	return 0;
}