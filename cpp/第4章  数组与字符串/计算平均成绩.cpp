#include <iostream>
using namespace std;
int main()
{
	const int n = 4;
	float score[n];
	float sum = 0, ave = 0;
	cout<<"������ɼ���"<<endl;
	for(int i=0; i<n; i++)
	{
		cin>>score[i];
		sum  += score[i];
	}
	ave = sum / n;
	cout<<"ƽ���ɼ�="<<ave<<endl;
	for(int j=0; j<n; j++)
	{
		if(ave<score[j])
			cout<<"����ƽ��ֵ������"<<score[j]<<endl;
	}
	system("pause");
	return 0;
}