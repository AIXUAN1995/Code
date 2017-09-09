#include <iostream>
using namespace std;
int main()
{
	char a;
	cout << "请输入一个大写字母";
	cin >> a;
	//法一：
	//cout << a+32<<endl;//输出的是数
	//a = a + 32;
	//cout << a << endl;//输出的是字符，因为在赋值的过程中发生了类型转换
	//法二：
	cout << a + 'a' - 'A' << endl;//输出的同样是数字，证明两个字符想减是ASCII码进行减法
	a = a + 'a' - 'A';
	cout << a << endl;
	system("pause");
	return 0;
}
