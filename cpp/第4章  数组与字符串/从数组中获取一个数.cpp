#include <iostream>
using namespace std;
int main()
{
	int n;
	int a[] = {12, 34, 45, 56 , 76, 56};
	cout<<"������Ҫ��ѯ������"<<endl;
	cin>>n;
	bool flag = true;
	for(int i=0; i<sizeof(a)/sizeof(a[0]); i++)
	{
		if(n==a[i])
		{
			cout<<"��Ҫ�ҵ��������ڵ�λ���ǣ�"<<i+1<<endl;
			flag = false;
			
		}
	}
	if(flag)
	{
		cout<<"�Բ�������������ֲ�����"<<endl;
	}
	return 0;
}