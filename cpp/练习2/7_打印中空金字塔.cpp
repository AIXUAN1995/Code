//��ӡ������
#include <iostream>
using namespace std;

//��ӡʵ�Ľ�����
void pyramid1(int floor)
{
	//��ӡ����
	for (int i = 1; i <= floor; i++)
	{
		//��ӡÿ�㿪ʼ�Ŀո���
		for (int j = 1; j <= floor - i; j++)
			cout << " ";
		//��ӡ*
		for (int k = 1; k <= 2 * i - 1; k++)
			cout << "*";
		cout << endl;
	}
}

//��ӡ�пս�����
void pyramid2(int floor)
{
	//��ӡ����
	for (int i = 1; i <= floor; i++)
	{
		//��ӡ�ո�
		for (int j = 1; j <= floor - i; j++)
			cout << " ";
		//��ӡ*
		for (int k = 1; k <= 2 * i - 1; k++)
		{
			//�ж��ǲ��ǵ�һ����������һ��
			if (i == 1 || i == floor)
			{
				cout << "*";
			}
			else
			{
				if (k == 1 || k == 2 * i - 1)
					cout << "*";
				else
					cout << " ";
			}
		}
		cout << endl;
	}
}
int main()
{
	int floor = 5;
	pyramid1(floor);
	pyramid2(floor);
	system("pause");
	return 0;
}