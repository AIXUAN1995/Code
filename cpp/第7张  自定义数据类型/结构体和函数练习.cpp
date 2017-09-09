#include <iostream>
#include <string>
using namespace std;
const int N = 5;
struct Book			//定义结构体类型
{
	string isbn;	//字符串型书号
	string name;	//字符串型书名
	double price;	//浮点型单价
	int stock;		//整型库存量
};
void sort1(Book bk[], int len);
void sort2(Book *p, int len);
void display(Book bk[], int len);
int main()
{
	//定义变量时给book1赋初值
	Book book1[N] = 
	{
		{"23924-1","计算机导论",26.5,120},
		{"13956-3","高等数学",31,95},
		{"87623-8","线性代数",28,267},
		{"56721-2","普通物理",42,102},
		{"34781-9","数据结构",22.5,298}
	};
	sort2(book1,N);
	display(book1,N);
	system("pause");
	return 0;
}
//用数组传递
void sort1(Book bk[], int len)
{
	bool flag = true;
	for(int i=0; i<len-1; ++i)
	{
		flag = true;	
		for(int j=0; j<len-1-i; ++j)
			if(bk[j].stock < bk[j+1].stock)
			{
				Book temp;
				temp = bk[j];
				bk[j] = bk[j+1];
				bk[j+1] = temp;
				flag = false;
			}
		if(flag)
			break;
	}
}
//用指针传递
void sort2(Book *p, int len)
{
	bool flag = true;
	for(int i=0; i<len-1; i++)
	{
		flag = true;
		for(int j=0; j<len-i-1; j++)
			if(p[j].stock < p[j+1].stock)
			{
				Book temp = p[j];
				p[j] = p[j+1];
				p[j+1] = temp;
				flag = false;
			}
		if(flag)
			break;
	}

}
void display(Book bk[], int len)
{
	cout<<"书号\t书名\t\t单价\t库存量"<<endl;
	for(int i=0; i<len; i++)
	{
		cout<<bk[i].isbn<<"\t"<<bk[i].name<<"\t";
		cout<<bk[i].price<<"\t"<<bk[i].stock<<endl;
	}
}