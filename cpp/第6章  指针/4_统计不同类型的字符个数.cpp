#include <iostream>
#include <string>
using namespace std;
void count(string *p);
int main()
{
	string str;
	cout<<"请输入一行字符："<<endl;
	getline(cin, str);
	count(&str);
	system("pause");
	return 0;
}
void count(string *p)
{
	int len = (*p).size();
	int cap = 0, ord = 0, num = 0, oth = 0;
	for(int i=0; i<len; i++)
	{
		if((*p)[i] >= 'A' && (*p)[i] <= 'Z')
			cap++;
		else if((*p)[i] >= 'a' && (*p)[i] <= 'z')
			ord++;
		else if((*p)[i] >= '0' && (*p)[i] <= '9')
			num++;
		else
			oth++;
	}
	cout<<"大写字母个数："<<cap<<endl;
	cout<<"小写字母个数："<<ord<<endl;
	cout<<"数字个数："<<num<<endl;
	cout<<"其他字符个数："<<oth<<endl;
}