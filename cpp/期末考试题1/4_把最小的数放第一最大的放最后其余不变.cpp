#include<iostream>
#include<vector>
using namespace std;
vector<int> in(int *max, int *min, int n)//����
{
	vector<int>num(n);
	cout<<"������"<<n<<"��������"<<endl;
	cin>>num[0];
	*max = *min = 0;
	for(int i=1; i<n; i++)
	{
		cin>>num[i];
		if(num[i]>num[*max])
			*max = i;
		else if(num[i]<num[*min])
			*min = i;
	}
	return num;
}
vector<int> exchange(vector<int> num, int *max, int *min, int n)
{
	if(0 != *min)
	{
		int temp1 = num[0];
		num[0] = num[*min];
		num[*min] = temp1;
	}
	if((n-1) != *max)
	{
		int temp2 = num[n-1];
		num[n-1] = num[*max];
		num[*max] = temp2;
	}
	return num;
}
void display(vector<int>num, int n)
{
	for(int i=0; i<n; i++)
		cout<<num[i]<<" ";
}
int main()
{
	int n, max=0, min=0;
	cout<<"�����������ĸ�����"<<endl;
	cin>>n;
	vector<int>num = in(&max, &min, n);
	num = exchange(num, &max, &min, n);
	display(num, n);
	system("pause");
	return 0;
}