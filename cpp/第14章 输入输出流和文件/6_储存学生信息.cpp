#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct Student
{
	string num;		//ѧ��
	string name;	//����
	int age;		//����
	double score[4];//���ſεĳɼ�
};
int main()
{
	Student *s;
	int n;
	cout << "������ѧ��������" << endl;
	cin >> n;
	s = new Student[n];
	//д���ļ�
	ofstream outfile;
	outfile.open("e:\\����\\c++\\stufile2");
	if (!outfile)
	{
		cerr << "���ļ�ʧ�ܣ�" << endl;
		return 1;
	}
	cout << "������" << n << "��ѧ����ѧ�š���������������ſγ̵ĳɼ���" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "�������" << i + 1 << "��ѧ����ѧ�š���������������ſγ̵ĳɼ���" << endl;
		cin >> s[i].num >> s[i].name >> s[i].age >> s[i].score[0] >> s[i].score[1] >> s[i].score[2];
		outfile << s[i].num << " " << s[i].name << " " << s[i].age << " " << s[i].score[0] << " ";
		outfile << s[i].score[1] << " " << s[i].score[2] << endl;
	}
	outfile.close();

	//��ȡ�ļ�
	ifstream infile;
	infile.open("e:\\����\\c++\\stufile2");
	if (!infile)
	{
		cerr << "���ļ�ʧ�ܣ�" << endl;
		return 1;
	}
	cout << n << "��ѧ����ѧ�š���������������ſγ̵ĳɼ���" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "��" << i + 1 << "��ѧ����ѧ�š���������������ſγ̵ĳɼ���" << endl;
		infile >> s[i].num >> s[i].name >> s[i].age >> s[i].score[0];
		infile >> s[i].score[1] >> s[i].score[2];
		cout << s[i].num << " " << s[i].name << " " << s[i].age << " " << s[i].score[0] << " ";
		cout << s[i].score[1] << " " << s[i].score[2] << endl;
	}
	infile.close();
	for (int i = 0; i < n; i++)				//��ÿ��ѧ����ƽ���ɼ�
	{
		int sum = 0, ave;
		for (int j = 0; j < 3; j++)
			sum += s[i].score[j];
		ave = sum / 3;
		s[i].score[3] = ave;
	}

	bool flag = true;
	for (int i = 0; i < n-1; i++)
	{
		flag = true;
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (s[j].score[3] < s[j + 1].score[3])			//��ƽ���ɼ��ɴ�С����
			{
				Student t = s[j];
				s[j] = s[j + 1];
				s[j + 1] = t;
				flag = false;
			}
		}
		if (flag)
			break;
	}
	cout << "���������ѧ����Ϣ��" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << s[i].num << " " << s[i].name << " " << s[i].age << " " << s[i].score[0] << " ";
		cout << s[i].score[1] << " " << s[i].score[2] << endl;
	}
	delete []s;
	system("pause");
	return 0;
}