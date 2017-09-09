#include <iostream>
#include <string>
using namespace std;
class ItemSales
{
private:
	string itemNum;		//商品代码
	double itemPrice;	//商品单价
	int itemUnits;		//销售数量
public:
	friend ItemSales operator+(const ItemSales &, const ItemSales &);
	friend ItemSales operator-(const ItemSales &, const ItemSales &);
	void operator++();
	friend istream & operator>>(istream &, ItemSales &);
	friend ostream & operator<<(ostream &, ItemSales &);
	//由于流提取运算符（>>）和流插入运算符（<<）需要被流类对象cin和cout调用，
	//所以只能定义为普通函数或友元函数，不能定义为成员函数。

};
ItemSales operator+(const ItemSales &it1, const ItemSales &it2)
{
	if (it2.itemNum == it1.itemNum && it2.itemPrice == it1.itemPrice)
	{
		ItemSales it;
		it.itemNum = it1.itemNum;
		it.itemPrice = it1.itemPrice;
		it.itemUnits = it1.itemUnits + it2.itemUnits;
		return it;
	}
	else
	{
		cout << "不同商品，不能相加！" << endl;
		return it1;
	}
}
ItemSales operator-(const ItemSales &it1, const ItemSales &it2)
{
	if (it2.itemNum == it1.itemNum && it2.itemPrice == it1.itemPrice)
	{
		ItemSales it;
		it.itemNum = it1.itemNum;
		it.itemPrice = it1.itemPrice;
		it.itemUnits = it1.itemUnits - it2.itemUnits;
		if (it.itemUnits < 0)
		{
			cout << "商品数量为负！" << endl;
			return it1;
		}
		return it;
	}
	else
	{
		cout << "商品不同，不能相减！" << endl;
		return it1;
	}
}
void ItemSales::operator++()
{
	itemUnits++;
}
istream &operator>>(istream &input, ItemSales &it)
{
	input >> it.itemNum >> it.itemPrice >> it.itemUnits;
	return input;
}
ostream &operator<<(ostream &output, ItemSales &it)
{
	output << it.itemNum <<"\t"<< it.itemPrice <<"\t"<< it.itemUnits;
	return output;
}
int main()
{
	ItemSales it1, it2, it3, it4, it5;
	cout << "输入商品的代码、单价、数量：" << endl;
	cin >> it1;
	cout << "输入商品的代码、单价、数量：" << endl;
	cin >> it2;
	cout << "输入商品的代码、单价、数量：" << endl;
	cin >> it3;
	it4 = it1 + it2;
	cout << "it1+it2=" << it4 << endl;
	it5 = it1 - it3;
	cout << "it1-it3=" << it5 << endl;

	system("pause");
	return 0;
}