#include <iostream>
#include <string>
using namespace std;
void count(string *p);
int main()
{
	string str;
	cout<<"������һ���ַ���"<<endl;
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
	cout<<"��д��ĸ������"<<cap<<endl;
	cout<<"Сд��ĸ������"<<ord<<endl;
	cout<<"���ָ�����"<<num<<endl;
	cout<<"�����ַ�������"<<oth<<endl;
}