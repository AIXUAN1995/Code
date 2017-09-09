#include <iostream>
#include <string>
using namespace std;
const int N = 5;
struct Book			//����ṹ������
{
	string isbn;	//�ַ��������
	string name;	//�ַ���������
	double price;	//�����͵���
	int stock;		//���Ϳ����
};
void sort1(Book bk[], int len);
void sort2(Book *p, int len);
void display(Book bk[], int len);
int main()
{
	//�������ʱ��book1����ֵ
	Book book1[N] = 
	{
		{"23924-1","���������",26.5,120},
		{"13956-3","�ߵ���ѧ",31,95},
		{"87623-8","���Դ���",28,267},
		{"56721-2","��ͨ����",42,102},
		{"34781-9","���ݽṹ",22.5,298}
	};
	sort2(book1,N);
	display(book1,N);
	system("pause");
	return 0;
}
//�����鴫��
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
//��ָ�봫��
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
	cout<<"���\t����\t\t����\t�����"<<endl;
	for(int i=0; i<len; i++)
	{
		cout<<bk[i].isbn<<"\t"<<bk[i].name<<"\t";
		cout<<bk[i].price<<"\t"<<bk[i].stock<<endl;
	}
}