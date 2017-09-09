#include <tchar.h>
#include <iostream>
#include <string>
#include <conio.h>
#include <iomanip>
using namespace std;
//�����˻��ṹ��
struct BankAccount
{
	int account;		//�˺ţ����6λ��
	char * password;	//���루���6λ��
	char * name;		//���������10����ĸ��
	char * idCard;		//���֤�ţ����18����ĸ��
	float amount;		//���
};
//�˶��ʻ�
BankAccount * checkAccount(BankAccount bas[], int baslen, int account, char *password = NULL)
{
	for(int i=0; i<baslen; i++)
	{
		if(bas[i].account == account)
		{
			if(password == NULL)
				return &bas[i];
			if(strcmp(bas[i].password, password) == 0)
				return &bas[i];
			else
				return NULL;
		}
	}
	return NULL;
}
//ȡ��
float drawMoney(BankAccount *ba, float amount)
{
	ba->amount-=amount;
	return amount;
}
//���
bool saveMoney(BankAccount *ba, float amount)
{
	if(amount <= 0)
		return false;
	ba->amount += amount;
	return true;
}
//ת��
bool transferMoney(BankAccount bas[], int baslen, BankAccount *ba, int toAccount, float amount)
{
	//��֤ת���˺�
	if(toAccount == ba->account)
		return true;
	BankAccount *toBa = checkAccount(bas, baslen, toAccount);
	if(toBa == NULL)
		return false;
	if(amount <= 0 || ba->amount < amount)
		return false;
	toBa->amount += amount;
	return true;
}
//��ѯ
void accountInfo(BankAccount *ba)
{
	//��ӡ�˻���Ϣ
	cout<<"**************�� �� �� Ϣ**************"<<endl;
	cout<<"**�˺ţ�"<<setw(29)<<ba->account<<"**"<<endl;
	cout<<"**������"<<setw(29)<<ba->name<<"**"<<endl;
	cout<<"**���֤�ţ�"<<setw(25)<<ba->idCard<<"**"<<endl;
	cout<<"**��"<<setw(29)<<ba->amount<<"**"<<endl;
	cout<<"***************************************";
}
//��ӡ�û�����
void printInterface(BankAccount *ba)
{
	cout<<"�𾴵�"<<ba->name<<"����/Ůʿ"<<endl;
	cout<<"������ѡ�����²�����"<<endl;
	cout<<"1��ѯ"<<endl;
	cout<<"2ȡ��"<<endl;
	cout<<"3���"<<endl;
	cout<<"4ת��"<<endl;
	cout<<"5�˿�"<<endl;
	cout<<"����������ѡ��--->"<<flush;
}
//ģ�������Զ�ȡ�����������
int main()
{
	//ģ��������ʼ�������˻�
	BankAccount bas[2];
	bas[0].account = 123456;
	bas[0].amount = 0;
	bas[0].idCard = "13012019820621003x";
	bas[0].name = "Tianyi";
	bas[0].password = "abcdef";
	bas[1].account = 456789;
	bas[1].amount = 0;
	bas[1].idCard = "13062019830602852x";
	bas[1].name = "ZhangSan";
	bas[1].password = "uvwxyz";
	int account;
	char password[7];
	char choise = '0';	//�����û�ѡ��
	bool exit = false;	//��ʶ�Ƿ��˿�
	float amount = 0;	//����ݴ�
	while(1)
	{
		password[0] = '\n';
		//�û���¼����
		system("cls");
		cout<<"�������˺ţ�";
		cin>>account;
		cout<<"���������룺";
		cin>>password;
		BankAccount *ba = checkAccount(bas, 2, account, password);
		if(ba!=NULL)
		{
			while(1)
			{
				system("cls");
				printInterface(ba);
				cin>>choise;
				switch(choise)
				{
				case '1'://ѡ���ѯ
					accountInfo(ba);
					cout<<"!!!�����������..."<<endl;
					system("pause");
					break;
				case '2'://ѡ��ȡ��
					system("cls");
					cout<<"������ȡ���";
					cin>>amount;
					amount = drawMoney(ba, amount);
					if(amount == 0)
						cout<<"ȡ��ʧ�ܣ�"<<endl;
					else
						cout<<"����ȡ������"<<amount<<endl;
					cout<<"!!!�����������..."<<endl;
					system("pause");
					break;
				case '3'://ѡ����
					system("cls");
					cout<<"���������";
					cin>>amount;
					if(saveMoney(ba, amount))
						cout<<"���Ѵ������"<<amount<<endl;
					else
						cout<<"���ʧ�ܣ�"<<endl;
					cout<<"!!!�����������..."<<endl;
					system("pause");
					break;
				case '4'://ѡ��ת��
					system("cls");
					cout<<"������ת���˺ţ�";
					cin>>account;
					cout<<"������ת�˽�";
					cin>>amount;
					if(transferMoney(bas, 2, ba, account, amount))
						cout<<"�������˻�"<<account<<"ת�ˣ�"<<amount<<endl;
					else
						cout<<"ת��ʧ�ܣ�"<<endl;
					cout<<"!!!�����������..."<<endl;
					system("pause");
					break;
				case '5'://ѡ���˿�
					system("cls");
					exit = true;
					cout<<"�˿��ɹ���"<<endl;
					cout<<"!!!�����������..."<<endl;
					system("pause");
					break;
				default://��Ч��ѡ��
					cout<<"��Ч��ѡ��"<<endl;
					cout<<"!!!�����������..."<<endl;
					system("pause");
					break;
				}
				if(exit)
					break;
				else
					continue;
			}
		}
	}
	system("pause");
	return 0;
}