#include <tchar.h>
#include <iostream>
#include <string>
#include <conio.h>
#include <iomanip>
using namespace std;
//银行账户结构体
struct BankAccount
{
	int account;		//账号（最多6位）
	char * password;	//密码（最多6位）
	char * name;		//姓名（最多10个字母）
	char * idCard;		//身份证号（最多18个字母）
	float amount;		//余额
};
//核对帐户
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
//取款
float drawMoney(BankAccount *ba, float amount)
{
	ba->amount-=amount;
	return amount;
}
//存款
bool saveMoney(BankAccount *ba, float amount)
{
	if(amount <= 0)
		return false;
	ba->amount += amount;
	return true;
}
//转账
bool transferMoney(BankAccount bas[], int baslen, BankAccount *ba, int toAccount, float amount)
{
	//验证转入账号
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
//查询
void accountInfo(BankAccount *ba)
{
	//打印账户信息
	cout<<"**************账 户 信 息**************"<<endl;
	cout<<"**账号："<<setw(29)<<ba->account<<"**"<<endl;
	cout<<"**姓名："<<setw(29)<<ba->name<<"**"<<endl;
	cout<<"**身份证号："<<setw(25)<<ba->idCard<<"**"<<endl;
	cout<<"**余额："<<setw(29)<<ba->amount<<"**"<<endl;
	cout<<"***************************************";
}
//打印用户界面
void printInterface(BankAccount *ba)
{
	cout<<"尊敬的"<<ba->name<<"先生/女士"<<endl;
	cout<<"您可以选择以下操作："<<endl;
	cout<<"1查询"<<endl;
	cout<<"2取款"<<endl;
	cout<<"3存款"<<endl;
	cout<<"4转账"<<endl;
	cout<<"5退卡"<<endl;
	cout<<"请输入您的选择：--->"<<flush;
}
//模拟银行自动取款机的主函数
int main()
{
	//模拟两个初始的银行账户
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
	char choise = '0';	//储存用户选择
	bool exit = false;	//标识是否退卡
	float amount = 0;	//金额暂存
	while(1)
	{
		password[0] = '\n';
		//用户登录界面
		system("cls");
		cout<<"请输入账号：";
		cin>>account;
		cout<<"请输入密码：";
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
				case '1'://选择查询
					accountInfo(ba);
					cout<<"!!!按任意键继续..."<<endl;
					system("pause");
					break;
				case '2'://选择取款
					system("cls");
					cout<<"请输入取款金额：";
					cin>>amount;
					amount = drawMoney(ba, amount);
					if(amount == 0)
						cout<<"取款失败！"<<endl;
					else
						cout<<"您已取出金额：￥"<<amount<<endl;
					cout<<"!!!按任意键继续..."<<endl;
					system("pause");
					break;
				case '3'://选择存款
					system("cls");
					cout<<"请输入存款金额：";
					cin>>amount;
					if(saveMoney(ba, amount))
						cout<<"您已存入金额：￥"<<amount<<endl;
					else
						cout<<"存款失败！"<<endl;
					cout<<"!!!按任意键继续..."<<endl;
					system("pause");
					break;
				case '4'://选择转账
					system("cls");
					cout<<"请输入转入账号：";
					cin>>account;
					cout<<"请输入转账金额：";
					cin>>amount;
					if(transferMoney(bas, 2, ba, account, amount))
						cout<<"您已向账户"<<account<<"转账￥"<<amount<<endl;
					else
						cout<<"转账失败！"<<endl;
					cout<<"!!!按任意键继续..."<<endl;
					system("pause");
					break;
				case '5'://选择退卡
					system("cls");
					exit = true;
					cout<<"退卡成功！"<<endl;
					cout<<"!!!按任意键继续..."<<endl;
					system("pause");
					break;
				default://无效的选择
					cout<<"无效的选择！"<<endl;
					cout<<"!!!按任意键继续..."<<endl;
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