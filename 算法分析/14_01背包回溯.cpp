//��һ������Ʒ�������ڵ���30ʱ���������
#include <iostream>
using namespace std;
const int NUM = 4;		//��Ʒ����
int flag[NUM+1]={0};		//�����Ʒ�Ƿ���뱳��
int vMax[NUM+1]={0};		//��ֵ���ķ���
int V[NUM+1] = {0,40,42,12,25};			//��Ʒ�ļ�ֵ
int W[NUM+1] = {0,4,7,3,5};			//��Ʒ������
int bag=10;				//����������
int value=0;			//��ǰ��Ʒ��ֵ
int weight=0;			//��ǰ����
int bestp=0;			//����ֵ
void backTrack(int k)
{//k��ʾ��ǰ�ݹ�Ĳ���
	if(k>NUM)
	{
		if(value>bestp)
		{
			bestp = value;
			for(int i=1; i<=NUM; i++)
				vMax[i] = flag[i];

		}
	}
	else
	{
		//ÿ����Ʒ���з��뱳���Ͳ����뱳������״̬��
		//������״̬�ֱ���н��еݹ�,���ȡ���ֵ
		for(int j=1;j>=0;j--)  
        {
            flag[k]=j;
            if(weight+flag[k]*W[k]<=bag)  
            {
                weight+=flag[k]*W[k];
                value+=flag[k]*V[k];
                backTrack(k+1);
                weight-=flag[k]*W[k];
                value-=flag[k]*V[k];
            }
        }
	}
}
int main()
{
	backTrack(1);
	cout << "ѡȡ����(0��ʾδѡȡ��1��ʾѡȡ):" << endl;
	for(int i=1; i<=NUM; i++)
		cout << vMax[i] << " ";
	cout << endl;
	cout << "����ֵ=" << bestp << endl;
	system("pause");
	return 0;
}
//���� knapsack()��������ʡ��
#include <iostream>
#include <time.h>
using namespace std;
const int NUM = 200;//��Ʒ����
double c;//��������
double v[NUM + 1];//������Ʒ�ļ�ֵ
double w[NUM + 1];//������Ʒ������
double cw = 0.0;//��ǰ��������
double cp = 0.0;//��ǰ��������Ʒ��ֵ
double bestp = 0.0;//��ǰ���ż�ֵ
double perp[NUM + 1];//��λ��Ʒ��ֵ�����
int put[NUM + 1];//�����Ƿ�װ��
int n = 0;//װ�뱳���е���Ʒ����
//����λ��ֵ����
void knapsack()
{
	double temporder = 0;
	double temp = 0;

	for (int i = 1; i <= NUM; i++)
		perp[i] = v[i] / w[i];
	for (int i = 1; i <= NUM - 1; i++)
	{
		for (int j = i + 1; j <= NUM; j++)
		if (perp[i]<perp[j])//ð������perp[],order[],sortv[],sortw[]
		{
			temp = perp[i];
			perp[i] = perp[j];
			perp[j] = temp;

			temp = v[i];
			v[i] = v[j];
			v[j] = temp;

			temp = w[i];
			w[i] = w[j];
			w[j] = temp;
		}
	}
}
//���ݺ���
void backtrack(int i)
{
	double bound(int i);
	if (i>NUM)
	{
		bestp = cp;
		return;
	}
	if (cw + w[i] <= c)
	{
		cw += w[i];
		cp += v[i];
		put[i] = 1;
		n++;
		backtrack(i + 1);
		cw -= w[i];
		cp -= v[i];
	}
	if (bound(i + 1)>bestp)//������������������
		backtrack(i + 1);
}
//�����Ͻ纯��
double bound(int i)
{
	double leftw = c - cw;
	double b = cp;
	while (i <= NUM&&w[i] <= leftw)
	{
		leftw -= w[i];
		b += v[i];
		i++;
	}
	if (i <= NUM)
		b += v[i] / w[i] * leftw;
	return b;
}
int main()
{
	srand((unsigned)time(NULL));
	for (int i = 1; i <= NUM; i++)
	{
		v[i] = rand() % NUM + 1;
		w[i] = rand() % NUM + 1;
	}
	c = rand() % 1000 + 1001;		//��������
	cout << "�����뱳��������" << c << endl;
	cout << "��Ʒ������" << NUM << endl;
	knapsack();			//����ʡ��
	backtrack(1);
	cout << "����ֵ��" << bestp << endl;
	cout << "װ�뱳���е���Ʒ������" << n << endl;
	cout << "��Ʒ����:" << endl;
	for (int i = 1; i <= NUM; i++)
	{
		cout << w[i] << " ";
	}
	cout << endl;
	cout << "��Ʒ��ֵ:" << endl;
	for (int i = 1; i <= NUM; i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
	cout << "װ�����Ʒ:" << endl;
	for (int i = 1; i <= NUM; i++)
	{
		cout << put[i] << " ";
	}
	system("pause");
	return 0;
}