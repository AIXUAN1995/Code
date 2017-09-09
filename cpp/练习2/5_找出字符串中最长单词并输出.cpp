#include <iostream>
#include <string>
using namespace std;
int main()
{
	string str, str1;
	int numChar = 0, n = 0;
	getline(cin,str);
	for(int i=0; str[i]!='\0'; i++)
	{
		if(str[i] != ' ')
			numChar++;
		else
		{
			if(numChar>n)
				n = numChar;//找出最长的单词的中的字符个数
			numChar = 0;
		}

	}
	if(numChar>n)
		n = numChar;
	numChar = 0;
	bool flag = false;
	for(int i=0; str[i]!='\0'; i++)
	{
		if(str[i] != ' ')
		{
			numChar++;
			str1 += str[i];
		}
		else if(n == numChar)//判断单词中的字符数是否与最长的单词字符数相等
		{
			cout<<str1;
			flag = true;
			break;
		}
		else
		{ 
			if(numChar>n)
				n = numChar;
			numChar = 0;
			str1 = "";
		}

	}
	if(flag == false)
		cout<<str1;
	cout<<"字符个数为："<<n <<endl;
	system("pause");
	return 0;
}
