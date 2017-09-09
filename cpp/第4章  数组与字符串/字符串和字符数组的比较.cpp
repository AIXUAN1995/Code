#include <iostream>
#include <string>
using namespace std;
int main()
{
	const char name1[5] = {'z','h','a','n','g'};
	const char name2[6] = "zhang";//必须用六个长度，不然会报错
	//string name3 = "zhang";
	//string name5 = name2;
	////char name4[6] = name3;			//不能赋值
	//for(int i=0; i<5; i++)
	//	cout<<name1[i];
	//cout<<endl;
	//cout<<sizeof(name1);
	//cout<<endl;
	//for(int j=0; j<6; j++)
	//{
	//	cout<<name2[j];
	//}
	//cout<<endl;
	//cout<<sizeof(name2);
	//cout<<endl;
	///*for(int k=0; k<6; k++)			//也能将string型的数直接用循环拆成单个字符输出
	//{
	//	cout<<name3[k];
	//}
	//cout<<endl;
	//cout<<sizeof(name3)<<endl;*/
	//cout<<"name5="<<name5<<endl;


	////字符数组的常用函数原型及功能
	////strlen  原型：int strlen(const char[]);
	////功能：计算数组中字符的个数
	//int len1;
	//len1 = strlen(name2);				//不包括'\0'
	//cout<<"用strlen计算name2的长度（不包括\\0）"<<endl;
	//cout<<len1<<endl;

	////strcpy  原型：char * strcpy(char[],const char[]);
	////功能：将第二个数组中的字符复制到第一个形参数组中
	//char name6[6];
	//strcpy(name6,name1);
	//cout<<"用strcpy将name1中的值copy到name6中"<<endl;
	//for(int i=0; i<6; i++)
	//	cout<<name6[i];
	//cout<<endl;


	////strcat  原型：char * strcat(char[],const char[]);
	////功能：将第二个数组中的字符拼接到第一个形参数组中字符的后面
	////strcat(name1,name2);//此时name1的长度应该能容纳下name1和name2两个的长度否则就会出现溢出
	////cout<<"用strcat将name2拼接到name1的后面"<<endl;
	////cout<<name1<<endl;


	//strcmp  原型：int strcmp(const char[],const char[]);
	//功能：比较两个形参数组的大小，相等的结果为零，第一个字符串大的结果为1，第二个字符串大的结果为-1
	int n;
	n = strcmp(name1, name2);
	cout<<"用strmp比较name1和name2的大小"<<endl;
	cout<<n<<endl;
	//为什么name1[5] = {'z','h','a','n','g'}和name2[6] = "zhang"比较会出错
	//而name1[6] = “zhang”和name2 = "zhang"比较就不会出错呢？
	//原因：并不是出错，而是name2最后一位是'\0'，而name1没有'\0'，
	//用于和name1中'\0'比较的是一个随机值，而这个值是'\0'的可能性很小，所以一般情况输出的值为1
	//如果在name1的末尾加上结束标记符'\0',则不会出现这种情况
	system("pause");
	return 0;
}