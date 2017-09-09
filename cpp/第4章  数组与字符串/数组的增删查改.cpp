#include <iostream>
using namespace std;
int main()
{
	int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int length = sizeof(a)/sizeof(a[0]);
	for(int i=0; i<10; i++)
		cout<<a[i]<<endl;
	//增加
	//cout<<"增加"<<endl;
	//a[10] = 11;						//在数组中增加元素很可能会出错
	//for(int i=0; i<length+1; i++)
	//	cout<<a[i]<<endl;
	//cout<<a<<endl;
	//删除
	cout<<"删除"<<endl;
	cout<<"请输入要删除的数据"<<endl;
	int num;
	cin>>num;
	bool flag = false;
	for(int i=0; i<length; i++)
	{
		
		if(a[i] == num)
		{
			for(int j=i; j<length-1; j++)
				a[j] = a[j+1];
			for(int i=0; i<length-1; i++)
			{
				cout<<a[i]<<endl;
			}
			flag = true;
			break;
		}		
	}
	if(flag == false)
	{
		cout<<"没有找的您要删除的值"<<endl;
	}
	
	system("pause");
	//
	return 0;
}