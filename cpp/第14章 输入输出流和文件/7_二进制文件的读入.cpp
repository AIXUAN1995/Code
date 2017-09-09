#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct Book
{
	string isbn;
	string name;
	double price;
	int stock;
};
int main()
{
	Book book[6];
	ofstream outfile;
	ifstream infile;
	infile.open("e:\\stufile1.dat", ios::binary);
	cout<<"请输入6本书的信息（书名、书号、单价、库存量）："<<endl;
	for(int i=0; i<6; i++)
	{
		cin>>book[i].isbn>>book[i].name>>book[i].price>>book[i].stock;
		outfile.write((char*)&book[i], sizeof(book[i]));
	}
	outfile.close();
	infile.open("e:\\stufile1.dat", ios::binary);
	cout<<"读出文件内容并输出："<<endl;
	for(int i=0; i<6; i++)
	{
		infile.read((char*)&book[i], sizeof(book[i]));
		cout<<book[i].isbn<<"\t"<<book[i].name<<"\t";
		cout<<book[i].price<<"\t"<<book[i].stock<<endl;
	}
	infile.close();
	for(int i=0; i<5; i++)
		for(int j=0; j<5; j++)
			if(book[j].stock<book[j+1].stock)
			{
				Book temp;
				temp = book[j];
				book[j] = book[j+1];
				book[j+1] = temp;
			}
	cout<<"输出排序后的数据："<<endl;
	for(int i=0; i<6; i++)
	{
		cout<<book[i].isbn<<"\t"<<book[i].name<<"\t";
		cout<<book[i].price<<"\t"<<book[i].stock<<endl;
	}
	system("pause");
	return 0;
}