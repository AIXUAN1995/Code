#include <iostream>
#include <conio.h>
using namespace std;
int main()
{
	char password[8]={0};
	int i;
	char ch;
	for(i=0; (ch=getch())!='\r';i++)
	{
		password[i] = ch;
		/*if(password[i]=='\r')
		{
			break;
		}*/
		putchar('*');
	}
	putchar('\n');

	//password[i] = '\n';
	system("pause");
	return 0;
}