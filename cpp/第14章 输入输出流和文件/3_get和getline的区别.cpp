#include <iostream>
using namespace std;
int main()
{
	/*
	带3个参数的get()：istream & get(char *buf, int size, char delim = '\n')
	结束的条件：1.提取size-1个字符，或者遇到终止字符（默认终止字符为'\n'）
	*/
	char str2_1[5];
	char str2_2[5];
	cin.get(str2_1, 6);//在末尾会自动加一个结束标记（'\0'）;根据实际需要，
						//终止字符可以是任一个字符，所以末尾要流出一位
	cin.get(str2_2, 6);
	cout << str2_1;
	cout << str2_2;
	/*
	由于第一次调用后，换行符将留在输入队列中，
	因此第二次调用时看到的第一个字符便是换行符，
	因此第二个get函数认为已到达行尾，而没有发现任何可读取的内容，即数组name2值为空。

	解决办法：
	cin.get(str2_1, 6);
	cin.get();
	cin.get(str2_2, 6);
	*/

	/*
	输入一行字符的getline()函数
	istream & getline(char *buf, int size, char delim = '\n');
	结束的条件：1.提取size-1个字符，2.遇到行结束符，3.遇到指定的终止字符
	*/
	/*char str3_1[5];
	char str3_2[5];
	cin.getline(str3_1, 6);
	cin.getline(str3_2, 6);
	cout << str3_1;
	cout << str3_2;*/

	/*
	getline()在停止提取字符的同时，
	输入流的字符指针移到该终止字符之后，
	而get()函数遇到终止字符后也停止字符的提取，
	但指针指向该终止字符

	由于getline()函数有"绕过"终止字符的作用，所以使用起来更符合实际需要
	*/
}