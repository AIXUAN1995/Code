//在一个字符串中找到第一个只出现一次的字符。如输入abaccdeff，则输出b。


#include <iostream>
#include <string>
using namespace std;
int main()
{
	char ch[26] = "";		//存放出现的字母
	int num[26] = {0};		//存放字母出现的次数
	int n = 0;				//存放出现的字母种类数
	int flag = 1;			//标记变量
	char ch_need;			//存放要找的字母
	string s;
	cout << "请输入字符串：" << endl;
	cin >> s;
	for (int i = 0; i < s.length(); i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (ch[j] == s[i])
			{
				num[j]++;
				flag = 0;
				break;
			}
		}
		if (flag == 1)
		{
			ch[n] = s[i];
			num[n++]++;
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (num[i] == 1)
		{
			ch_need = ch[i];
			break;
		}
	}
	cout << "第一个只出现一次的字符为：" << ch_need << endl;
	system("pause");
	return 0;
}