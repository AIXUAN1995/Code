#include<iostream>
using namespace std;
int main(){
    const int M=4,N=4;
    int a[M][N],max[M],min[N],b;
	cout<<"输入4行4列的二维数组"<<endl;
	for(int i=0;i<M;++i)
		for(int j=0;j<N;++j)
			cin>>a[i][j];
	for(int i=0;i<M;++i){				//找出第i行中的最大值
		max[i]=a[i][0];
		for(int j=0;j<N;++j)
			if(a[i][j]>max[i])
				max[i]=a[i][j];			//max[i]中存放的是第i行中的最大值
	
	}
	for(int j=0;j<N;++j){				//找出第j列中的最小值
		min[j]=a[0][j];
		for(int i=0;i<M;++i)
		if(a[i][j]<min[j])
			min[j]=a[i][j];				//min[i]中存放的是第j列中的最小值
	}
	b=0;
	for(int i=0;i<M;++i){
			for(int j=0;j<N;++j)
				if(max[i]==min[j]){
				    cout<<"鞍点为"<<"a["<<i<<"]["<<j<<"]："<<a[i][j]<<endl;
					b=1;}
	}
	if(b==0)						//这句应该放在for循环的外边，不然会多次输出
	cout<<"鞍点不存在"<<endl;

	system("pause");
	return 0;
}