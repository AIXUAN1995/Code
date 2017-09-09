#include <iostream>
using namespace std;
int main()
{
	char ch = getchar();
	cin.sync();				//用来清除缓冲区中未读的信息
	cout << ch;				//检验清空缓冲区以后内存中的内容是否还存在
	/*char ch2 = getchar();
	char ch3 = getchar();
	if(ch == '\n')
		cout<<"true"<<endl;
	else
		cout<<ch<<endl;
	if(ch2 == '\n')
		cout<<"true2"<<endl;
	else
		cout<<ch2<<endl;
	if (ch3 == '\n')
		cout << "true3" << endl;
	else
		cout << ch3 << endl;*/
	system("pause");
	return 0;
}
