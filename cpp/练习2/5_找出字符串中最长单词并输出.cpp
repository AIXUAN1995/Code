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
				n = numChar;//�ҳ���ĵ��ʵ��е��ַ�����
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
		else if(n == numChar)//�жϵ����е��ַ����Ƿ�����ĵ����ַ������
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
	cout<<"�ַ�����Ϊ��"<<n <<endl;
	system("pause");
	return 0;
}
