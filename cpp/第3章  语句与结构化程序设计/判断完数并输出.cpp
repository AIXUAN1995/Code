#include <iostream>
using namespace std;
//�ж��ǲ�������
bool f(int n)
{
	int sum=0;
	for(int i=1;i<n;i++)
	{
		if(n%i==0)
		{
			sum += i;
		}
	}
	if(sum==n)
	{
		return true;
	}
	else
	{
		return false;
	}
	
}
//������д����ʽ��ӵ���ʽ���
void res(int n)
{
	cout<<n<<" = 1";
	for(int i=2;i<n;++i)
	{
		if(n%i==0)
		{
			cout<<" + "<<i;
		}
	}
	cout<<endl;
}
int main()
{
	int a;
	cout<<"������һ����a�����ж�1��a�е�����";
	cin>>a;
	for(int i=1;i<a;++i)
	{
		if(f(i))
		{
			res(i);
		}
	}
	system("pause");
	return 0;
}