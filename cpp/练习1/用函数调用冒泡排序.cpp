#include <iostream>
#include <algorithm>
using namespace std;
//���ú�������ð������
void arr_print(int arr[], int length);
int cmp(int a, int b);
int main()
{
	int arr[] = {23, 345, 465, 78, 90, 34, 12, 45, 5, 56};
	const int len = sizeof(arr)/sizeof(int);
	sort(arr, arr+len, cmp);//cmp��������ǿ��п��޵ģ���cmpʱ�ǽ������У�û��ʱ����������
	arr_print(arr, len);
	system("pause");
	return 0;
}
void arr_print(int arr[], int length)
{
	for(int i=0; i<length; ++i)
	{
		cout<<arr[i]<<endl;
	}
}
int cmp(int a, int b)
{
	return a>b;
}