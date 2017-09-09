//#include <iostream>
//#include <vector>
//using namespace std;
//void matrix(void);
//int main()
//{
//	matrix();
//	system("pause");
//	return 0;
//}
//void matrix()
//{
//	int rows1, cols1, rows2, cols2;
//	cout<<"请输入矩阵的行列数：\n";
//	cout<<"第一个矩阵的行列数：\n";
//	cin>>rows1>>cols1;
//	cout<<"第二个矩阵的行列数：\n";
//	cin>>rows2>>cols2;
//	if(cols1 != rows2)
//		cout<<"您输入的行列式无法进行计算！"<<endl;
//	else
//	{
//		cout<<"请输入第一个矩阵："<<endl;
//		vector<vector<double>>a(rows1, vector<double>(cols1));
//		for(int i=0; i<rows1; i++)
//			for(int j=0; j<cols1; j++)
//				cin>>a[i][j];
//		cout<<"请输入第二个矩阵："<<endl;
//		vector<vector<double>>b(rows2, vector<double>(cols2));
//		for(int i=0; i<rows2; i++)
//			for(int j=0; j<cols2; j++)
//				cin>>b[i][j];
//		//矩阵乘法运算
//		vector<vector<double>>multiply(rows1, vector<double>(cols2));
//		for(int i=0; i<rows1; i++)
//			for(int j=0; j<cols2; j++)
//				for(int k=0; k<cols1; k++)
//					multiply[i][j] += a[i][k] * b[k][j];
//		for(int i=0; i<rows1; i++)
//		{
//			for(int j=0; j<cols2; j++)
//				cout<<multiply[i][j]<<"\t";
//			cout<<endl;
//		}
//	}	
//}

//怎么能把二位数组在两个函数之间传递
//#include<iostream>
//using namespace std;
//const int M=3,N=2,P=3;
//void result(int **c, int **d,int **e ,int m, int n,int p );
//int main(){
//	int a[M][N],b[N][P],ab[M][P];
//	cout<<"请输入一个三行二列的行列式"<<endl;
//	for( int i=0;i<M;++i)
//		for( int j=0;j<N;++j)
//			cin>>a[i][j];
//	cout<<"请输入一个二行三列的行列式"<<endl;
//	for( int  i=0;i<N;++i)
//		for(int j=0;j<P;++j)
//			cin>>b[i][j];
//	for( int i=0;i<M;++i)
//		for( int j=0;j<N;++j)
//	result(a,b,ab,M,N,P);
//	return 0;
//}
//void result(int a[], int **d,int **e ,int m,int n,int p ){
//	for( int i=0;i<m;++i)
//		for( int j=0;j<n;++j)
//			for( int k=0;j<p;++k)
//				e[i][k]+= c[i][j]*d[j][k];
//	for( int i=0;i<m;++i)
//			for( int k=0;k<p;++k)
//	  cout<<e[i][k]<<'\t';
//	cout<<endl;
//}

#include<iostream>
using namespace std;
const int M=3,N=2,P=4;
float a[M][N],b[N][P],c[M][P];
int main(){
	int i=0,j;
void result();
cout<<"请输入一个3行2列的矩阵"<<endl;
for(i=0;i<M;i++)
for(j=0;j<N;j++)
 cin>>a[i][j];
cout<<"请输入一个2行4列的矩阵"<<endl;
for(i=0;i<N;i++)
for(j=0;j<P;j++)
 cin>>b[i][j];
cout<<"两矩阵乘积为"<<endl;
result();
for(i=0;i<M;i++)
{
	for(j=0;j<P;j++)
    cout<<c[i][j]<<" ";
	cout<<endl;
}
system("pause");
return 0;
}
void result(){
	int i,j,k;
	for(i=0;i<M;i++)
	for(j=0;j<P;j++)
	for(k=0;k<N;k++)
	c[i][j]+=a[i][k]*b[k][j];
	
}
