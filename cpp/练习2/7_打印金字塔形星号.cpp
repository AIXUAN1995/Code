//��ӡ���������Ǻ�
#include <iostream>
using namespace std;
int main()
{
	int n;
	cout<<"�������������"<<endl;
	cin>>n;
	for(int i=0; i<n; i++)//i���������εĵ�i��
	{
		for (int j = i+1; j < n; j++)//j�����ڵ�i����ߵĵ�j���հ��ַ�for(int j=n-1-i; j>=0; j--)
			cout<<" ";
		for(int k=0; k<2*i+1; k++)//k��ʾ��i�еĵ�k���Ǻ��ַ�
			cout<<"*";
		cout<<endl;
	}
	system("pause");
	return 0;
}