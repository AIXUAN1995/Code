#include <iostream>
#include <string>
using namespace std;
int main()
{
	string str;
	int numChar = 0;
	getline(cin,str);
	for(int i=0; str[i]!='\0'; i++)
	{
		if(str[i] != ' ')
		{
			cout<<str[i];
			numChar++;
		}
		else
		{
			cout<<"字符数为："<<numChar<<endl;
			numChar = 0;
			
		}

	}
	cout<<"字符数为："<<numChar<<endl;
	system("pause");
	return 0;
}
