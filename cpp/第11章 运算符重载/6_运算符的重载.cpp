#include <iostream>
#include <string>
using namespace std;
class ItemSales
{
public:
	ItemSales();
	friend istream &operator>>(istream &, ItemSales &);
	friend ostream &operator<<(ostream &, ItemSales &);
	friend ItemSales operator+(const ItemSales &, const ItemSales &);

private:
	string itemNum;		//产品代码
	int itemUnits;		//销售数量
	double itemGrass;	//销售金额

};
ItemSales::ItemSales()
{
	itemNum = "";
	itemUnits = 0;
	itemGrass = 0;
}
istream &operator>>(istream &cin, ItemSales &i)
{
	cin>>i.itemNum>>i.itemUnits>>i.itemGrass;
	return cin;
}
ostream &operator<<(ostream &cout, ItemSales &i)
{
	cout<<i.itemNum<<"\t"<<i.itemUnits<<"\t"<<i.itemGrass<<endl;
	return cout;
}
ItemSales operator+(const ItemSales &i1, const ItemSales &i2)
{
	ItemSales i;
	i.itemNum = i1.itemNum;
	i.itemUnits = i1.itemUnits + i2.itemUnits;
	i.itemGrass = i1.itemGrass + i2.itemGrass;
	return i;
}
int main()
{
	ItemSales item1, item2, item3;
	cout<<"请输入item1的值："<<endl;
	cin>>item1;
	cout<<"请输入item2的值："<<endl;
	cin>>item2;
	item3 = item1 + item2;
	cout<<"item1="<<item1<<endl;
	cout<<"item2="<<item2<<endl;
	cout<<"item3="<<item3<<endl;
	system("pause");
	return 0;
}
/*
<<有两个参数，一个是输出流对象(我们常用的cout),还有就是要输出的东西。
例如：cout<<"haha";
也就是说<<的第一个参数必须是输出流对象。
在成员函数里实现<<重载，我们知道this会作为第一个参数，而这是不符合要求的。
*/