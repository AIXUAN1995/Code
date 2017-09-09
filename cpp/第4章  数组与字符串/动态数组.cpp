#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int n, sumage, aveage;
	sumage = 0;
	cout<<"请输入要计算的人数n=";
	cin>>n;
	vector<int>age(n);              //创建动态数组
	cout<<endl<<"请输入n个年龄值：";
	for(int i=0; i<n; i++)
	{
		cin>>age[i];
		sumage += age[i];
	}
	//sumage = 0;                    //可以写到第一个循环中
	//for(int i=0; i<n; i++)
	//{
	//	sumage += age[i];
	//}
	aveage = sumage/n;
	cout<<aveage<<endl;

	system("pause");
	return 0;
}