#include <iostream>
#include <string>
using namespace std;
class ItemSales
{
public:
	ItemSales(){}
	ItemSales(string, int, double);
	friend ItemSales operator+(const ItemSales &, const ItemSales &);
	friend void display(const ItemSales &);
private:
	string itemNum;//产品代码
	int itemUnits;//销售数量
	double itemGrass;//销售金额
};
ItemSales::ItemSales(string nu, int un, double gr)
{
	itemNum = nu;
	itemUnits = un;
	itemGrass = gr;
}
ItemSales operator+(const ItemSales &i1, const ItemSales &i2)
{
	ItemSales i;
	i.itemNum = i1.itemNum;
	i.itemUnits = i1.itemUnits + i2.itemUnits;
	i.itemGrass = i1.itemGrass + i2.itemGrass;
	return i;
}
void display(const ItemSales &i)
{
	cout << "产品代码：" << i.itemNum << "\t";
	cout << "销售数量：" << i.itemUnits << "\t";
	cout << "销售金额：" << i.itemGrass << endl;
}
int main()
{
	ItemSales sale1("012", 10, 25), sale2("012", 20, 50), sale3;
	cout << "sale1:" << endl;
	display(sale1);
	cout << "sale2:" << endl;
	display(sale2);
	sale3 = sale1 + sale2;
	cout << "sale3:" << endl;
	display(sale3);
	system("pause");
	return 0;
}