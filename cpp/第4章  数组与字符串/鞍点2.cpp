#include<iostream>
using namespace std;
int main(){
    const int M=4,N=4;
    int a[M][N],max[M],min[N],b;
	cout<<"����4��4�еĶ�ά����"<<endl;
	for(int i=0;i<M;++i)
		for(int j=0;j<N;++j)
			cin>>a[i][j];
	for(int i=0;i<M;++i){				//�ҳ���i���е����ֵ
		max[i]=a[i][0];
		for(int j=0;j<N;++j)
			if(a[i][j]>max[i])
				max[i]=a[i][j];			//max[i]�д�ŵ��ǵ�i���е����ֵ
	
	}
	for(int j=0;j<N;++j){				//�ҳ���j���е���Сֵ
		min[j]=a[0][j];
		for(int i=0;i<M;++i)
		if(a[i][j]<min[j])
			min[j]=a[i][j];				//min[i]�д�ŵ��ǵ�j���е���Сֵ
	}
	b=0;
	for(int i=0;i<M;++i){
			for(int j=0;j<N;++j)
				if(max[i]==min[j]){
				    cout<<"����Ϊ"<<"a["<<i<<"]["<<j<<"]��"<<a[i][j]<<endl;
					b=1;}
	}
	if(b==0)						//���Ӧ�÷���forѭ������ߣ���Ȼ�������
	cout<<"���㲻����"<<endl;

	system("pause");
	return 0;
}