#include <iostream>
#include <string>
using namespace std;
int get();
int main()
{
	/*
	����������get()��int get();
	���ܣ�������������ȡһ���ַ���
		��ASCII����Ϊ�����ķ���ֵ�� 
		���������е��ļ�������ʱ��
		�򷵻��ļ��Ľ������EOF��End Of File����Ϊ����ֵ��

	string�ͱ���ʹ�õ�ʱ���Ƕ�̬�����ڴ�ģ�
	����ʱ�������ֵ����������ڴ�ռ䲻��ֱ��ʹ��
	*/
	/*string str;
	for (int i = 0; i < 5; i++)
		str[i] = cin.get();
	for (int i = 0; i < 5; i++)
		cout << str[i] << " ";
	//������ʾ��string subscript out of range	
	*/

	//�������ַ�ʽ����ʵ��
	/*string str;
	for (int i = 0; i < 5; i++)
		str += cin.get();
	for (int i = 0; i < 5; i++)
		cout << str[i] << " ";*/

	//��һ��������get()��istream & get(char &ch);
	//string str1;
	//char ch;
	//for (int i = 0; i < 5; i++)
	//{
	//	//while (cin.get(ch))//һֱѭ�����ܽ���
	//	cin.get(ch);
	//	str1 += ch;
	//}
	//cout << str1;

	/*
	��3��������get()��istream & get(char *buf, int size, char delim = '\n')
	������������1.��ȡsize-1���ַ�������������ֹ�ַ���Ĭ����ֹ�ַ�Ϊ'\n'��
	*/
	//char str2[5];
	//cin.get(str2, 6);//��ĩβ���Զ���һ��������ǣ�'\0'��;����ʵ����Ҫ��
	//				//��ֹ�ַ���������һ���ַ�������ĩβҪ����һλ
	//cout << str2;

	/*
	����һ���ַ���getline()����
	istream & getline(char *buf, int size, char delim = '\n');
	������������1.��ȡsize-1���ַ���2.�����н�������3.����ָ������ֹ�ַ�
	*/
	/*char str3[5];
	cin.getline(str3, 6);
	cout << str3;
	*/

	/*
	�ж��ļ�������־��eof()����
	��ʽ������int eof();
	���ܣ��ж��������еĵ�ǰ�ַ��Ƿ����ļ������ı�־��
	����ǣ���������ֵΪ��0���棩���������ķ���ֵΪ0���٣���
	*/

	/*
	�鿴��ǰ�ַ���peek()����
	��ʽ������int peek();
	���ܣ������ķ���ֵΪ�������еĵ�ǰ�ַ���ָ��ָ����ַ�����
	ָ���ַ���ָ�벢���ƶ�λ�ã������ǰ�ַ����ļ���������
	�����ķ���ֵΪEOF��
	*/
	char ch1, ch2, ch3;
	ch1 = cin.get();
	ch2 = cin.get();
	ch3 = cin.get();
	cout << ch1 << ch2 << ch3;
	/*
	������룺ABCD
	��������ABC
	*/
	char ch4, ch5, ch6;
	ch4 = cin.peek();
	ch5 = cin.peek();
	ch6 = cin.peek();
	cout << ch4 << ch5 << ch6;
	/*
	������룺ABC
	��������AAA
	*/

	/*
	�Թ������ַ���ignore()����
	��ʽ������istream & ignore(int n = 1, int delim = EOF)
	���ܣ��Թ��������е�n���ַ�����ָ���ַ���ָ������ƶ�n��λ�ã�Ĭ��ֵΪ1����
		���ָ�����ƶ��Ĺ�����������ֹ�ַ���Ĭ��ֵΪEOF������������ƶ���
		�������ƶ�n��λ�ã������ƶ�����ֹ�ַ�����
	*/

	/*
	ͳ�ƶ�ȡ�ַ�������gcount()����
	��ʽ������int gcount();
	���ܣ������ķ���ֵΪ��һ�����������ȡ���ַ�������
	*/

	/*
	��������ַ���put()����
	��ʽ������ostream & put(char ch);
	���ܣ���������ַ�
	*/
	char chp = 'A';
	cout.put(chp);
	cout.put('A');
	cout.put(65);
	//����Ķ���A
	system("pause");
	return 0;
}