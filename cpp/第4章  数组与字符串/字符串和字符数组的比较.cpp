#include <iostream>
#include <string>
using namespace std;
int main()
{
	const char name1[5] = {'z','h','a','n','g'};
	const char name2[6] = "zhang";//�������������ȣ���Ȼ�ᱨ��
	//string name3 = "zhang";
	//string name5 = name2;
	////char name4[6] = name3;			//���ܸ�ֵ
	//for(int i=0; i<5; i++)
	//	cout<<name1[i];
	//cout<<endl;
	//cout<<sizeof(name1);
	//cout<<endl;
	//for(int j=0; j<6; j++)
	//{
	//	cout<<name2[j];
	//}
	//cout<<endl;
	//cout<<sizeof(name2);
	//cout<<endl;
	///*for(int k=0; k<6; k++)			//Ҳ�ܽ�string�͵���ֱ����ѭ����ɵ����ַ����
	//{
	//	cout<<name3[k];
	//}
	//cout<<endl;
	//cout<<sizeof(name3)<<endl;*/
	//cout<<"name5="<<name5<<endl;


	////�ַ�����ĳ��ú���ԭ�ͼ�����
	////strlen  ԭ�ͣ�int strlen(const char[]);
	////���ܣ������������ַ��ĸ���
	//int len1;
	//len1 = strlen(name2);				//������'\0'
	//cout<<"��strlen����name2�ĳ��ȣ�������\\0��"<<endl;
	//cout<<len1<<endl;

	////strcpy  ԭ�ͣ�char * strcpy(char[],const char[]);
	////���ܣ����ڶ��������е��ַ����Ƶ���һ���β�������
	//char name6[6];
	//strcpy(name6,name1);
	//cout<<"��strcpy��name1�е�ֵcopy��name6��"<<endl;
	//for(int i=0; i<6; i++)
	//	cout<<name6[i];
	//cout<<endl;


	////strcat  ԭ�ͣ�char * strcat(char[],const char[]);
	////���ܣ����ڶ��������е��ַ�ƴ�ӵ���һ���β��������ַ��ĺ���
	////strcat(name1,name2);//��ʱname1�ĳ���Ӧ����������name1��name2�����ĳ��ȷ���ͻ�������
	////cout<<"��strcat��name2ƴ�ӵ�name1�ĺ���"<<endl;
	////cout<<name1<<endl;


	//strcmp  ԭ�ͣ�int strcmp(const char[],const char[]);
	//���ܣ��Ƚ������β�����Ĵ�С����ȵĽ��Ϊ�㣬��һ���ַ�����Ľ��Ϊ1���ڶ����ַ�����Ľ��Ϊ-1
	int n;
	n = strcmp(name1, name2);
	cout<<"��strmp�Ƚ�name1��name2�Ĵ�С"<<endl;
	cout<<n<<endl;
	//Ϊʲôname1[5] = {'z','h','a','n','g'}��name2[6] = "zhang"�Ƚϻ����
	//��name1[6] = ��zhang����name2 = "zhang"�ȽϾͲ�������أ�
	//ԭ�򣺲����ǳ�������name2���һλ��'\0'����name1û��'\0'��
	//���ں�name1��'\0'�Ƚϵ���һ�����ֵ�������ֵ��'\0'�Ŀ����Ժ�С������һ����������ֵΪ1
	//�����name1��ĩβ���Ͻ�����Ƿ�'\0',�򲻻�����������
	system("pause");
	return 0;
}