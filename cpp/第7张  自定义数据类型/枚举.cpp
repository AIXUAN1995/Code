#include <iostream>
using namespace std;
enum WeekDay{Sun, Mon, Tue, Wed, Tues, Fri, Sat};
int main()
{
	WeekDay wd = Sun;
	cout << wd;			//输出的结果是0；
	//不能直接用cin和cout输入输出枚举类型变量的值

	//可以先转化再赋值
	WeekDay wd2 = WeekDay(2);                                                                             
	system("pause");
	return 0;
}