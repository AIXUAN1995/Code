#include <iostream>
#include <string>
using namespace std;
int main()
{
	string str;
	cout<<"ÇëÊäÈë×Ö·û´®£º";
	cin>>str;
	for(int i=0; i<str.length(); i++)
		if(str[i]<'0' || str[i]>'9')
			cout<<str[i];
	system("pause");
	return 0;
}