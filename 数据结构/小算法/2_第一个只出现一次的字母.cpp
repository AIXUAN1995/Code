//��һ���ַ������ҵ���һ��ֻ����һ�ε��ַ���������abaccdeff�������b��


#include <iostream>
#include <string>
using namespace std;
int main()
{
	char ch[26] = "";		//��ų��ֵ���ĸ
	int num[26] = {0};		//�����ĸ���ֵĴ���
	int n = 0;				//��ų��ֵ���ĸ������
	int flag = 1;			//��Ǳ���
	char ch_need;			//���Ҫ�ҵ���ĸ
	string s;
	cout << "�������ַ�����" << endl;
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
	cout << "��һ��ֻ����һ�ε��ַ�Ϊ��" << ch_need << endl;
	system("pause");
	return 0;
}