#include <iostream>
using namespace std;
int main()
{
	char a;
	cout << "������һ����д��ĸ";
	cin >> a;
	//��һ��
	//cout << a+32<<endl;//���������
	//a = a + 32;
	//cout << a << endl;//��������ַ�����Ϊ�ڸ�ֵ�Ĺ����з���������ת��
	//������
	cout << a + 'a' - 'A' << endl;//�����ͬ�������֣�֤�������ַ������ASCII����м���
	a = a + 'a' - 'A';
	cout << a << endl;
	system("pause");
	return 0;
}
