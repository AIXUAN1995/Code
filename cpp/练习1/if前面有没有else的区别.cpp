#include<iostream>
using namespace std;

int main(){
	const int M=10;
	int a[M],max,num;
	cout<<"������ʮ������"<<endl;
	for(int i=0;i<M;++i)
		cin>>a[i];
	max=a[0];
	num=1;
	for(int i=1;i<M;++i){
		if(a[i]>max){
		max=a[i];
		num=1;					//��a[5] = 2ʱ��num = 1��������Ȼ���ж�
  		}
		
		if (a[i]==max)			//���û��else��һ��if�ж���֮�����û��жϵڶ���if
			++num;				//��Ϊmax�Ѿ���ֵΪ2�����Դ�ʱi = 5��num = 2��
	}
	cout<<"��߷�"<<max<<endl<<"num="<<num<<endl;
	system("pause");
	return 0;
}