#include <iostream>
#include <string>
using namespace std;
string draw(int num)
{
	int rem;
	string str;
	while(num != 0)
	{
		rem = num % 10;
		num /= 10;
		if(rem%2 != 0)
			str += char(rem+'0');
	}
	return str;
	
}
void display(string str)
{
	for(int i=str.length()-1; i>=0; i--)
		cout<<str[i];
}
int main()
{
	int num;
	string str;
	cout<<"请输入一个整数：";
	cin>>num;
	str = draw(num);
	display(str);
	system("pause");
	return 0;
}