#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	int stu[6][5];							//���һ�����ڴ��ƽ���ɼ�
	ifstream infile;
	infile.open("e:\\����\\c++\\stufile.txt");	//���ļ���Ĭ��Ϊ����ʽ
	if (!infile)							//������ļ����ɹ�
	{
		cerr << "�򿪷�ʽʧ�ܣ�" << endl;
		return 1;
	}
	cout << "�����ļ��е����ݲ���ʾ��" << endl;
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			infile >> stu[i][j];			//�����ļ�����
			cout << stu[i][j] << "\t";		//��ʾ����������
		}
		cout << endl;
	}
	infile.close();
	for (int i = 0; i < 6; i++)				//��ÿ��ѧ����ƽ���ɼ�
	{
		int sum = 0, ave;
		for (int j = 0; j <= 3; j++)
			sum += stu[i][j];
		ave = sum / 3;
		stu[i][4] = ave;
	}
	bool flag = true;
	for (int i = 0; i < 5; i++)
	{
		flag = true;
		for (int j = 0; j < 5 - i; j++)
		{
			if (stu[j][4]<stu[j+1][4])			//��ƽ���ɼ��ɴ�С����
				for (int k = 0; k < 5; k++)
				{
					int temp = stu[j][k];
					stu[j][k] = stu[j + 1][k];
					stu[j + 1][k] = temp;
					flag = false;
				}
		}
		if (flag)
			break;
	}
	cout << "������������ݣ�" << endl;
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 5; j++)
			cout << stu[i][j] << "\t";
		cout << endl;
	}
	system("pause");
	return 0;
}