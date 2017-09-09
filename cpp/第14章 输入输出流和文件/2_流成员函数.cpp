#include <iostream>
#include <string>
using namespace std;
int get();
int main()
{
	/*
	不带参数的get()：int get();
	功能：从输入流中提取一个字符，
		其ASCII码作为函数的返回值， 
		当遇到流中的文件结束符时，
		则返回文件的结束标记EOF（End Of File）作为函数值。

	string型变量使用的时候是动态分配内存的，
	定义时如果不赋值，不会分配内存空间不能直接使用
	*/
	/*string str;
	for (int i = 0; i < 5; i++)
		str[i] = cin.get();
	for (int i = 0; i < 5; i++)
		cout << str[i] << " ";
	//错误提示：string subscript out of range	
	*/

	//下面这种方式可以实现
	/*string str;
	for (int i = 0; i < 5; i++)
		str += cin.get();
	for (int i = 0; i < 5; i++)
		cout << str[i] << " ";*/

	//带一个参数的get()：istream & get(char &ch);
	//string str1;
	//char ch;
	//for (int i = 0; i < 5; i++)
	//{
	//	//while (cin.get(ch))//一直循环不能结束
	//	cin.get(ch);
	//	str1 += ch;
	//}
	//cout << str1;

	/*
	带3个参数的get()：istream & get(char *buf, int size, char delim = '\n')
	结束的条件：1.提取size-1个字符，或者遇到终止字符（默认终止字符为'\n'）
	*/
	//char str2[5];
	//cin.get(str2, 6);//在末尾会自动加一个结束标记（'\0'）;根据实际需要，
	//				//终止字符可以是任一个字符，所以末尾要流出一位
	//cout << str2;

	/*
	输入一行字符的getline()函数
	istream & getline(char *buf, int size, char delim = '\n');
	结束的条件：1.提取size-1个字符，2.遇到行结束符，3.遇到指定的终止字符
	*/
	/*char str3[5];
	cin.getline(str3, 6);
	cout << str3;
	*/

	/*
	判断文件结束标志的eof()函数
	格式声明：int eof();
	功能：判断输入流中的当前字符是否是文件结束的标志，
	如果是，函数返回值为非0（真），否则函数的返回值为0（假）。
	*/

	/*
	查看当前字符的peek()函数
	格式声明：int peek();
	功能：函数的返回值为输入流中的当前字符（指针指向的字符），
	指向字符的指针并不移动位置，如果当前字符是文件结束符，
	则函数的返回值为EOF。
	*/
	char ch1, ch2, ch3;
	ch1 = cin.get();
	ch2 = cin.get();
	ch3 = cin.get();
	cout << ch1 << ch2 << ch3;
	/*
	如果输入：ABCD
	输出结果：ABC
	*/
	char ch4, ch5, ch6;
	ch4 = cin.peek();
	ch5 = cin.peek();
	ch6 = cin.peek();
	cout << ch4 << ch5 << ch6;
	/*
	如果输入：ABC
	输出结果：AAA
	*/

	/*
	略过若干字符的ignore()函数
	格式声明：istream & ignore(int n = 1, int delim = EOF)
	功能：略过输入流中的n个字符（把指向字符的指针向后移动n个位置，默认值为1），
		如果指针在移动的过程中遇到终止字符（默认值为EOF），不再向后移动，
		即或者移动n个位置，或者移动到终止字符处。
	*/

	/*
	统计读取字符个数的gcount()函数
	格式声明：int gcount();
	功能：函数的返回值为上一次输入操作读取的字符个数。
	*/

	/*
	输出单个字符的put()函数
	格式声明：ostream & put(char ch);
	功能：输出单个字符
	*/
	char chp = 'A';
	cout.put(chp);
	cout.put('A');
	cout.put(65);
	//输出的都是A
	system("pause");
	return 0;
}