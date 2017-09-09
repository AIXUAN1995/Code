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
	string itemNum;		//��Ʒ����
	int itemUnits;		//��������
	double itemGrass;	//���۽��

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
	cout<<"������item1��ֵ��"<<endl;
	cin>>item1;
	cout<<"������item2��ֵ��"<<endl;
	cin>>item2;
	item3 = item1 + item2;
	cout<<"item1="<<item1<<endl;
	cout<<"item2="<<item2<<endl;
	cout<<"item3="<<item3<<endl;
	system("pause");
	return 0;
}
/*
<<������������һ�������������(���ǳ��õ�cout),���о���Ҫ����Ķ�����
���磺cout<<"haha";
Ҳ����˵<<�ĵ�һ���������������������
�ڳ�Ա������ʵ��<<���أ�����֪��this����Ϊ��һ�������������ǲ�����Ҫ��ġ�
*/