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
void sort(itemSales *item, int num, int n);	//������
void display(itemSales *item, int num, int n);	//�������
int main()
{
	int num, n;
	cout<<"��������Ʒ��������"<<endl;
	cin>>num;
	itemSales *item = new itemSales[num];
	for(int i=0; i<num; i++)
	{
		cout<<"�������"<<i+1<<"����Ʒ�����۴��룺"<<endl;
		cin>>item[i].itemNum;
		cout<<"�������"<<i+1<<"����Ʒ�ĵ��ۣ�"<<endl;
		cin>>item[i].itemPrice;
		cout<<"�������"<<i+1<<"����Ʒ������������"<<endl;
		cin>>item[i].itemUnits;
		item[i].itemAmount = item[i].itemPrice * item[i].itemUnits;
	}
	cout<<"��ѡ����Ҫ����ķ�ʽ��\n";
	cout<<"������Ʒ����������1��������������������2���������۽��������3�����߶�����������4\n";
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
	if(n == 1)				//����Ʒ��������
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
	else if(n == 2)			//����������������
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
	else if(n == 3)			//�������۽������
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
		cout<<"����Ʒ��������\n";
	if(n == 2)
		cout<<"��������������\n";
	if(n == 3)
		cout<<"�����۽������\n";
	cout<<"��Ʒ����\t"<<"��Ʒ����\t"<<"��Ʒ����\t"<<"���۽��\n";
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
//	{"��Ʒ1",25.0,100},
//	{"��Ʒ2",35.0,200},
//	{"��Ʒ3",26.0,500},
//	{"��Ʒ4",34.0,300},
//	{"��Ʒ5",31.0,400},
//	{"��Ʒ6",28.0,800},
//	{"��Ʒ7",20.0,700},
//	{"��Ʒ8",30.0,900}
//	};
//	for(int i=0;i<Num;++i){
//		items[i].itemtotal=items[i].itemPrice *items[i].itemUnits ;
//	}
//	cout<<"����Ʒ�������"<<endl;
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
//		cout<<"��Ʒ����\t��Ʒ����\t��������\t���۽��"<<endl;
//		for(int i=0;i<Num;++i){
//			cout<<items[i].itemNum <<"\t"<<"\t"<<items[i].itemPrice <<"\t"<<"\t"<<items[i].itemUnits<<"\t"<<"\t"<<items[i].itemtotal<<endl;}
//	cout<<"�������������"<<endl;
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
//	cout<<"��Ʒ����\t��Ʒ����\t��������\t���۽��"<<endl;
//	for(int i=0;i<Num;++i){
//		cout<<items[i].itemNum <<"\t"<<"\t"<<items[i].itemPrice <<"\t"<<"\t"<<items[i].itemUnits<<"\t"<<"\t"<<items[i].itemtotal<<endl ;}
//	cout<<"�����۽�����"<<endl;
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
//    cout<<"��Ʒ����\t��Ʒ����\t��������\t���۽��"<<endl;
//	for(int i=0;i<Num;++i){
//		cout<<items[i].itemNum <<"\t"<<"\t"<<items[i].itemPrice <<"\t"<<"\t"<<items[i].itemUnits<<"\t"<<"\t"<<items[i].itemtotal <<endl;} 
//	system("pause");
//	return 0;
//}
