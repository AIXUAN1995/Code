#include <iostream>
#include <string>
using namespace std;
class ItemSales
{
private:
	string itemNum;		//��Ʒ����
	double itemPrice;	//��Ʒ����
	int itemUnits;		//��������
public:
	friend ItemSales operator+(const ItemSales &, const ItemSales &);
	friend ItemSales operator-(const ItemSales &, const ItemSales &);
	void operator++();
	friend istream & operator>>(istream &, ItemSales &);
	friend ostream & operator<<(ostream &, ItemSales &);
	//��������ȡ�������>>�����������������<<����Ҫ���������cin��cout���ã�
	//����ֻ�ܶ���Ϊ��ͨ��������Ԫ���������ܶ���Ϊ��Ա������

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
		cout << "��ͬ��Ʒ��������ӣ�" << endl;
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
			cout << "��Ʒ����Ϊ����" << endl;
			return it1;
		}
		return it;
	}
	else
	{
		cout << "��Ʒ��ͬ�����������" << endl;
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
	cout << "������Ʒ�Ĵ��롢���ۡ�������" << endl;
	cin >> it1;
	cout << "������Ʒ�Ĵ��롢���ۡ�������" << endl;
	cin >> it2;
	cout << "������Ʒ�Ĵ��롢���ۡ�������" << endl;
	cin >> it3;
	it4 = it1 + it2;
	cout << "it1+it2=" << it4 << endl;
	it5 = it1 - it3;
	cout << "it1-it3=" << it5 << endl;

	system("pause");
	return 0;
}