#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct Student
{
	string num;		//学号
	string name;	//姓名
	int age;		//年龄
	double score[4];//三门课的成绩
};
int main()
{
	Student *s;
	int n;
	cout << "请输入学生人数：" << endl;
	cin >> n;
	s = new Student[n];
	//写入文件
	ofstream outfile;
	outfile.open("e:\\代码\\c++\\stufile2");
	if (!outfile)
	{
		cerr << "打开文件失败！" << endl;
		return 1;
	}
	cout << "请输入" << n << "个学生的学号、姓名、年龄和三门课程的成绩：" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "请输入第" << i + 1 << "名学生的学号、姓名、年龄和三门课程的成绩：" << endl;
		cin >> s[i].num >> s[i].name >> s[i].age >> s[i].score[0] >> s[i].score[1] >> s[i].score[2];
		outfile << s[i].num << " " << s[i].name << " " << s[i].age << " " << s[i].score[0] << " ";
		outfile << s[i].score[1] << " " << s[i].score[2] << endl;
	}
	outfile.close();

	//读取文件
	ifstream infile;
	infile.open("e:\\代码\\c++\\stufile2");
	if (!infile)
	{
		cerr << "打开文件失败！" << endl;
		return 1;
	}
	cout << n << "个学生的学号、姓名、年龄和三门课程的成绩：" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "第" << i + 1 << "名学生的学号、姓名、年龄和三门课程的成绩：" << endl;
		infile >> s[i].num >> s[i].name >> s[i].age >> s[i].score[0];
		infile >> s[i].score[1] >> s[i].score[2];
		cout << s[i].num << " " << s[i].name << " " << s[i].age << " " << s[i].score[0] << " ";
		cout << s[i].score[1] << " " << s[i].score[2] << endl;
	}
	infile.close();
	for (int i = 0; i < n; i++)				//求每个学生的平均成绩
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
			if (s[j].score[3] < s[j + 1].score[3])			//按平均成绩由大到小排序
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
	cout << "输出排序后的学生信息：" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << s[i].num << " " << s[i].name << " " << s[i].age << " " << s[i].score[0] << " ";
		cout << s[i].score[1] << " " << s[i].score[2] << endl;
	}
	delete []s;
	system("pause");
	return 0;
}