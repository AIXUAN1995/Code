#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int n, sumage, aveage;
	sumage = 0;
	cout<<"������Ҫ���������n=";
	cin>>n;
	vector<int>age(n);              //������̬����
	cout<<endl<<"������n������ֵ��";
	for(int i=0; i<n; i++)
	{
		cin>>age[i];
		sumage += age[i];
	}
	//sumage = 0;                    //����д����һ��ѭ����
	//for(int i=0; i<n; i++)
	//{
	//	sumage += age[i];
	//}
	aveage = sumage/n;
	cout<<aveage<<endl;

	system("pause");
	return 0;
}