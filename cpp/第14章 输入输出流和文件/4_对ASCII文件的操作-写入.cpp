#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	//调用流对象成员函数
	//文件流对象名.open(文件名, 打开方式);
	int stu[6][4];
	ofstream outfile;							//定义文件流对象
	outfile.open("e:\\代码\\c++\\stufile.txt");	//打开或新建文件，默认为写方式
	if (!outfile)								//如果打不开或新建文件不成功
	{
		cerr << "打开文件失败！" << endl;
		return 1;
	}
	cout << "请输入6个学生的数据，包括学号和3门课程的成绩：" << endl;
	for (int i = 0; i < 6; i++)
	{
		cin >> stu[i][0] >> stu[i][1] >> stu[i][2] >> stu[i][3];//输入数据
		outfile << stu[i][0] << " " << stu[i][1] << " ";		//写入文件，用空格分隔数据
		outfile << stu[i][2] << " " << stu[i][3] << " ";		//写入文件，没行末尾加换行符
	}
	outfile.close();											//关闭文件
	system("pause");
	return 0;
}