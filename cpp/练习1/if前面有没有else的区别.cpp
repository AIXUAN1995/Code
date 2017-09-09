#include<iostream>
using namespace std;

int main(){
	const int M=10;
	int a[M],max,num;
	cout<<"请输入十个整数"<<endl;
	for(int i=0;i<M;++i)
		cin>>a[i];
	max=a[0];
	num=1;
	for(int i=1;i<M;++i){
		if(a[i]>max){
		max=a[i];
		num=1;					//当a[5] = 2时，num = 1；下面仍然会判断
  		}
		
		if (a[i]==max)			//如果没有else第一个if判断完之后仍让会判断第二个if
			++num;				//因为max已经赋值为2，所以此时i = 5，num = 2；
	}
	cout<<"最高分"<<max<<endl<<"num="<<num<<endl;
	system("pause");
	return 0;
}