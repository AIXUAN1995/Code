#include<iostream>
#include<vector>
using namespace std;
int main(){
	int m, n;
	cout<<"�������������ֵ��"<<endl;
	cout<<"����m=";
	cin>>m;
	cout<<"����n=";
	cin>>n;
	vector<vector<double>>a(m,vector<double>(n));
	cout<<"����"<<m<<"��"<<n<<"�еľ���"<<endl;
	for(int i=0;i<m;++i)
		for(int j=0;j<n;++j)
			cin>>a[i][j];
	int max1,max2;
	max1=max2=a[0][0];
	for(int i=0;i<m;++i)
		for(int j=0;j<n;++j)
			if(a[i][j]>max1)
				max1=a[i][j];
	for(int i=0; i<m; ++i)
		for(int j=0; j<n; ++j)
			if(a[i][j]>=max2 && a[i][j]<max1)
				max2=a[i][j];
	cout<<"ֵ���Ԫ�ؼ����к��к�Ϊ"<<endl;
	for(int i=0;i<m;++i)
		for(int j=0;j<n;++j){
			if(a[i][j]==max1)
				cout<<"���ֵΪ"<<max1<<"\t"<<"�кţ�"<<i+1<<"�кţ�"<<j+1<<endl;
			if(a[i][j]==max2)
				cout<<"�ڶ���ֵΪ"<<max2<<"\t"<<"�кţ�"<<i+1<<"�кţ�"<<j+1<<endl;

		}
	system("pause");
	return 0;
}