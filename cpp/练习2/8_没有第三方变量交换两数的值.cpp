//��û�еĵ���������������½�����������ֵ
#include <iostream>
using namespace std;
int main()
{
	int m = 8, n = 9;
	cout << "����֮ǰ��m = " << m << "n = " << n;
	//��һ��
	n = m + n;
	m = n - m;
	n = n - m;
	//������
	n = n ^ m;
	m = n ^ m;
	n = n ^ m;
	//������
	m = m - n;
	n = m + n;
	m = n - m;

	cout << "����֮��m = " << m << "n = " << n;

}