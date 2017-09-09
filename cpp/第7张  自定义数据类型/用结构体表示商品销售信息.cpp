#include <iostream>
#include <string>
using namespace std;
struct itemSales
{
	string itemNum;
	double itemPrice;
	int itemUnits;
	double itemAmount;
};
void sort(itemSales *item, int num, int n);	//排序函数
void display(itemSales *item, int num, int n);	//输出函数
int main()
{
	int num, n;
	cout<<"请输入商品的数量："<<endl;
	cin>>num;
	itemSales *item = new itemSales[num];
	for(int i=0; i<num; i++)
	{
		cout<<"请输入第"<<i+1<<"个商品的销售代码："<<endl;
		cin>>item[i].itemNum;
		cout<<"请输入第"<<i+1<<"个商品的单价："<<endl;
		cin>>item[i].itemPrice;
		cout<<"请输入第"<<i+1<<"个商品的销售数量："<<endl;
		cin>>item[i].itemUnits;
		item[i].itemAmount = item[i].itemPrice * item[i].itemUnits;
	}
	cout<<"请选择您要排序的方式：\n";
	cout<<"按照商品单价请输入1，按照销售数量请输入2，按照销售金额请输入3，三者都排序请输入4\n";
	cin>>n;
	
	if(n == 1)
	{
		sort(item, num, n);
		display(item, num, n);
	}
	if(n == 2)
	{
		sort(item, num, n);
		display(item, num, n);
	}
	if(n == 3)
	{
		sort(item, num, n);
		display(item, num, n);
	}
	if(n == 4)
	{
		sort(item, num, 1);
		display(item, num, 1);
		sort(item, num, 2);
		display(item, num, 2);
		sort(item, num, 3);
		display(item, num, 3);
	}
	delete [] item;
	system("pause");
	return 0;
}

void sort(itemSales *item, int num, int n)
{
	bool flag = true;
	if(n == 1)				//按商品数量排序
		for(int i=0; i<num-1; i++)
		{
			flag = true;
			for(int j=0; j<num-1-i; j++)
			{
				if(item[j].itemPrice < item[j+1].itemPrice)
				{
					itemSales temp = item[j];
					item[j] = item[j+1];
					item[j+1] = temp;
					flag = false;
				}
			}
			if(flag)
				break;
		}
	else if(n == 2)			//按照销售数量排序
		for(int i=0; i<num-1; i++)
		{
			flag = true;
			for(int j=0; j<num-1-i; j++)
			{
				if(item[j].itemUnits < item[j+1].itemUnits)
				{
					itemSales temp = item[j];
					item[j] = item[j+1];
					item[j+1] = temp;
					flag = false;
				}
			}
			if(flag)
				break;
		}
	else if(n == 3)			//按照销售金额排序
		for(int i=0; i<num-1; i++)
		{
			flag = true;
			for(int j=0; j<num-1-i; j++)
			{
				if(item[j].itemAmount < item[j+1].itemAmount)
				{
					itemSales temp = item[j];
					item[j] = item[j+1];
					item[j+1] = temp;
					flag = false;
				}
			}
			if(flag)
				break;
		}
}
void display(itemSales *item, int num, int n)
{
	if(n == 1)
		cout<<"按商品单价排序\n";
	if(n == 2)
		cout<<"按销售数量排序\n";
	if(n == 3)
		cout<<"按销售金额排序\n";
	cout<<"商品代码\t"<<"商品单价\t"<<"商品数量\t"<<"销售金额\n";
	for(int i=0; i<num; i++)
	{
		cout<<item[i].itemNum<<"\t\t"<<item[i].itemPrice<<"\t\t";
		cout<<item[i].itemUnits<<"\t\t"<<item[i].itemAmount<<endl;
	}
}
//#include<iostream>
//#include<string>
//using namespace std;
//const int Num=8;
//struct itemSales{
//	string itemNum;
//	double itemPrice;
//	int itemUnits;
//	double itemtotal;
//};
//int main(){
//	itemSales items[8]={
//	{"商品1",25.0,100},
//	{"商品2",35.0,200},
//	{"商品3",26.0,500},
//	{"商品4",34.0,300},
//	{"商品5",31.0,400},
//	{"商品6",28.0,800},
//	{"商品7",20.0,700},
//	{"商品8",30.0,900}
//	};
//	for(int i=0;i<Num;++i){
//		items[i].itemtotal=items[i].itemPrice *items[i].itemUnits ;
//	}
//	cout<<"按商品单价输出"<<endl;
//	for(int i=0;i<Num-1;++i){
//		for(int j=0;j<Num-1;++j){
//			itemSales temp;
//			if(items[j].itemPrice <items[j+1].itemPrice){
//				temp=items[j];
//				items[j]=items[j+1];
//				items[j+1]=temp;
//			}
//		}
//	}
//		cout<<"商品代码\t商品单价\t销售数量\t销售金额"<<endl;
//		for(int i=0;i<Num;++i){
//			cout<<items[i].itemNum <<"\t"<<"\t"<<items[i].itemPrice <<"\t"<<"\t"<<items[i].itemUnits<<"\t"<<"\t"<<items[i].itemtotal<<endl;}
//	cout<<"按销售数量输出"<<endl;
//	for(int i=0;i<Num-1;++i){
//		for(int j=0;j<Num-1;++j){
//			itemSales temp;
//			if(items[j].itemUnits  <items[j+1].itemUnits ){
//				temp=items[j];
//				items[j]=items[j+1];
//				items[j+1]=temp;
//			}
//		}
//	}
//	cout<<"商品代码\t商品单价\t销售数量\t销售金额"<<endl;
//	for(int i=0;i<Num;++i){
//		cout<<items[i].itemNum <<"\t"<<"\t"<<items[i].itemPrice <<"\t"<<"\t"<<items[i].itemUnits<<"\t"<<"\t"<<items[i].itemtotal<<endl ;}
//	cout<<"按销售金额输出"<<endl;
//	for(int i=0;i<Num-1;++i){
//		for(int j=0;j<Num-1;++j){
//			itemSales temp;
//			if(items[j].itemtotal<items[j+1].itemtotal ){
//				temp=items[j];
//				items[j]=items[j+1];
//				items[j+1]=temp;
//			}
//		}
//	}
//    cout<<"商品代码\t商品单价\t销售数量\t销售金额"<<endl;
//	for(int i=0;i<Num;++i){
//		cout<<items[i].itemNum <<"\t"<<"\t"<<items[i].itemPrice <<"\t"<<"\t"<<items[i].itemUnits<<"\t"<<"\t"<<items[i].itemtotal <<endl;} 
//	system("pause");
//	return 0;
//}
