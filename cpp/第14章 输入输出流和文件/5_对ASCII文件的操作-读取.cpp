#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	int stu[6][5];							//最后一列用于存放平均成绩
	ifstream infile;
	infile.open("e:\\代码\\c++\\stufile.txt");	//打开文件，默认为读方式
	if (!infile)							//如果打开文件不成功
	{
		cerr << "打开方式失败！" << endl;
		return 1;
	}
	cout << "读出文件中的数据并显示：" << endl;
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			infile >> stu[i][j];			//读出文件内容
			cout << stu[i][j] << "\t";		//显示读出的内容
		}
		cout << endl;
	}
	infile.close();
	for (int i = 0; i < 6; i++)				//求每个学生的平均成绩
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
			if (stu[j][4]<stu[j+1][4])			//按平均成绩由大到小排序
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
	cout << "输出排序后的数据：" << endl;
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 5; j++)
			cout << stu[i][j] << "\t";
		cout << endl;
	}
	system("pause");
	return 0;
}