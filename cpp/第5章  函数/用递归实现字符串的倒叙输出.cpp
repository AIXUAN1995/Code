#include <iostream>
#include <string>
using namespace std;
void flashback(string str, int n)
{
	/*if(str[n] == '\0')
		return;
	flashback(str, n+1);
	cout<<str[n];*/
	if(n==str.size())
        return;
    flashback(str, n+1);//n++�ı���n��ֵ 
    cout<<str[n];
}
int main()
{
	cout<<"������Ҫת�������֣�"<<endl;
	string str;
	cin>>str;
	flashback(str, 0);
	system("pause");
	return 0;
}