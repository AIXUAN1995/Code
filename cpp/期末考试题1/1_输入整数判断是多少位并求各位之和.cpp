//��һ
#include <iostream>
using namespace std;
int main()
{
	int num, len = 0, n, sum = 0;
	cout<<"������һ��������";
	cin>>num;
	while(num!=0)
	{
		n = num % 10;
		num /= 10;
		sum += n;
		len++;
	}
	cout<<"λ����"<<len<<"��λ����֮�ͣ�"<<sum;
	system("pause");
	return 0;
}
//����
#include<iostream>
#include<string>
using namespace std;
int main()
{
	int n, m=0, sum = 0, m1;
	cin>>n;
	for(int i=1; i<=n; i=i*10)
		m++;				//�ж�λ��
	for(int i=0; i<m; i++)
	{
		sum = sum+n%10;
		n /= 10;
	}
	cout<<m<<endl;
	cout<<sum;
	system("pause");
	return 0;
}