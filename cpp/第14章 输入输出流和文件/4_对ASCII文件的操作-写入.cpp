#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	//�����������Ա����
	//�ļ���������.open(�ļ���, �򿪷�ʽ);
	int stu[6][4];
	ofstream outfile;							//�����ļ�������
	outfile.open("e:\\����\\c++\\stufile.txt");	//�򿪻��½��ļ���Ĭ��Ϊд��ʽ
	if (!outfile)								//����򲻿����½��ļ����ɹ�
	{
		cerr << "���ļ�ʧ�ܣ�" << endl;
		return 1;
	}
	cout << "������6��ѧ�������ݣ�����ѧ�ź�3�ſγ̵ĳɼ���" << endl;
	for (int i = 0; i < 6; i++)
	{
		cin >> stu[i][0] >> stu[i][1] >> stu[i][2] >> stu[i][3];//��������
		outfile << stu[i][0] << " " << stu[i][1] << " ";		//д���ļ����ÿո�ָ�����
		outfile << stu[i][2] << " " << stu[i][3] << " ";		//д���ļ���û��ĩβ�ӻ��з�
	}
	outfile.close();											//�ر��ļ�
	system("pause");
	return 0;
}