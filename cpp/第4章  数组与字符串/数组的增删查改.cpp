#include <iostream>
using namespace std;
int main()
{
	int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int length = sizeof(a)/sizeof(a[0]);
	for(int i=0; i<10; i++)
		cout<<a[i]<<endl;
	//����
	//cout<<"����"<<endl;
	//a[10] = 11;						//������������Ԫ�غܿ��ܻ����
	//for(int i=0; i<length+1; i++)
	//	cout<<a[i]<<endl;
	//cout<<a<<endl;
	//ɾ��
	cout<<"ɾ��"<<endl;
	cout<<"������Ҫɾ��������"<<endl;
	int num;
	cin>>num;
	bool flag = false;
	for(int i=0; i<length; i++)
	{
		
		if(a[i] == num)
		{
			for(int j=i; j<length-1; j++)
				a[j] = a[j+1];
			for(int i=0; i<length-1; i++)
			{
				cout<<a[i]<<endl;
			}
			flag = true;
			break;
		}		
	}
	if(flag == false)
	{
		cout<<"û���ҵ���Ҫɾ����ֵ"<<endl;
	}
	
	system("pause");
	//
	return 0;
}