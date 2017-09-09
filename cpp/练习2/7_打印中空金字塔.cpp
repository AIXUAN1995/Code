//打印金字塔
#include <iostream>
using namespace std;

//打印实心金字塔
void pyramid1(int floor)
{
	//打印层数
	for (int i = 1; i <= floor; i++)
	{
		//打印每层开始的空格数
		for (int j = 1; j <= floor - i; j++)
			cout << " ";
		//打印*
		for (int k = 1; k <= 2 * i - 1; k++)
			cout << "*";
		cout << endl;
	}
}

//打印中空金字塔
void pyramid2(int floor)
{
	//打印层数
	for (int i = 1; i <= floor; i++)
	{
		//打印空格
		for (int j = 1; j <= floor - i; j++)
			cout << " ";
		//打印*
		for (int k = 1; k <= 2 * i - 1; k++)
		{
			//判断是不是第一层或者是最后一层
			if (i == 1 || i == floor)
			{
				cout << "*";
			}
			else
			{
				if (k == 1 || k == 2 * i - 1)
					cout << "*";
				else
					cout << " ";
			}
		}
		cout << endl;
	}
}
int main()
{
	int floor = 5;
	pyramid1(floor);
	pyramid2(floor);
	system("pause");
	return 0;
}