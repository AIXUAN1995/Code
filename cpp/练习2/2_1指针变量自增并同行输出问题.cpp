#include<iostream>
using namespace std;
int main(){
	char s[] = "2468", *p;
	p = s;

	//�ر�ע�⣺*p++��ʾ����*p��p++������(*p)++

	//��������
	//cout<<*p++<<*p++<<*p++<<*p++<<endl;	//8642

	//��������
	//cout<<*p<<*p<<*p<<*p<<endl;//2222
	//cout<<*p+1<<*p<<*p<<*p<<endl;//51222   3��ASCII����51
	//cout<<*p+1<<*p+1<<*p<<*p<<endl;//515122
	//cout<<*p+1<<*p+1<<*p+1<<*p<<endl;//5151512
	//cout<<*p+1<<*p+1<<*p+1<<*p+1<<endl;//51515151

	//��������
	//cout<<char(*p)<<char(*p+1)<<char(*p+2)<<char(*p+3)<<endl;//2345

	//��������
	//cout<<char(*p+1)<<char(*p+1)<<char(*p+1)<<char(*p+1)<<endl;//3333

	//��������
	//cout<<*p<<" ";		//2
	//cout<<*p++<<" ";	//2
	//cout<<*p++<<" ";	//4
	//cout<<*p++<<" ";	//6
	//cout<<endl;
	
	//��������
	//cout<<*p<<" ";			//2
	//cout<<char(*p+1)<<" ";	//3
	//cout<<char(*p+2)<<" ";	//4
	//cout<<char(*p+3)<<" ";	//5
	//cout<<endl;
	int a[] = {2,8,6}, *p1;
	p1 = a;
	//�ر�ע�⣺*p++��ʾ����*p��p++������(*p)++
	cout<<*p++;		//2
	cout<<(*p1)++;	//2
	cout<<*p1;		//3
	cout<<*p1++;	//3
	cout<<*p1;		//8
	cout<<*p1++;	//8
	cout<<*p1;		//6  ���Ӧ����δ֪�ڴ��е�ĳһ����
	system("pause");
	return 0;
}