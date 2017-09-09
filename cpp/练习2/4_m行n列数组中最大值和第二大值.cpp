#include<iostream>
#include<vector>
using namespace std;
int main(){
	int m, n;
	cout<<"输入数组的行列值："<<endl;
	cout<<"行数m=";
	cin>>m;
	cout<<"列数n=";
	cin>>n;
	vector<vector<double>>a(m,vector<double>(n));
	cout<<"输入"<<m<<"行"<<n<<"列的矩阵"<<endl;
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
	cout<<"值最大元素及其行号列号为"<<endl;
	for(int i=0;i<m;++i)
		for(int j=0;j<n;++j){
			if(a[i][j]==max1)
				cout<<"最大值为"<<max1<<"\t"<<"行号："<<i+1<<"列号："<<j+1<<endl;
			if(a[i][j]==max2)
				cout<<"第二大值为"<<max2<<"\t"<<"行号："<<i+1<<"列号："<<j+1<<endl;

		}
	system("pause");
	return 0;
}