#include<iostream>
#include<stack>
#define N 200
using namespace std;
class HeapNode
{
    public:
        double uprofit,profit,weight;
        int level,x[N];
};
stack<HeapNode> H;
double w[N],v[N];	//��Ʒ�������ͼ�ֵ
double cw,cv,c;		//��������Ʒ��������������Ʒ��ֵ����������
int n;				//��Ʒ����
double Bound(int i)
{
    double cleft=c-cw,b=cv;
	//���Բ����յ�λ��ֵ�ɸߵ�������
    while(i<=n&&w[i]<=cleft)
    {
        cleft-=w[i];
        b+=v[i];
        i++;
    }
    if(i<=n)  
		b+=v[i]/w[i]*cleft;
    return b;
}
void AddLiveNode(double ub,double cv,double cw,int level)
{
    HeapNode nod;
    nod.uprofit=ub;
    nod.profit=cv;
    nod.weight=cw;
    nod.level=level;
    if(level<=n)  
		H.push(nod);
}
double Knap()
{
    int i=1;
    cw=cv=0;
    double bestp=0,ub=Bound(1);//���ż�ֵ�ͽ���
    while(1)
    {
        double wt=cw+w[i];//���ϵ�i����Ʒ�������
        if(wt<=c)
        {
            if(cv+v[i]>bestp)
				bestp=cv+v[i];
            AddLiveNode(ub,cv+v[i],cw+w[i],i+1);//���ϵ�i��Ԫ�صĻ�ڵ�
        }
        ub=Bound(i+1);
        if(ub>=bestp)
             AddLiveNode(ub,cv,cw,i+1);			//���ӵ�i��Ԫ�صĻ�ڵ�
        if(H.empty())
			return bestp;
        HeapNode node=H.top();
        
        cw=node.weight;
        cv=node.profit;
        ub=node.uprofit;
        i=node.level;
		H.pop();
    }
}
int main()
{
    cout<<"��������Ʒ�����ͱ�������:";  cin>>n>>c;
    for(int i=1;i<=n;i++)
	{
		cout << "�������" << i << "����Ʒ��������";
		cin>>w[i];
		cout << "�������" << i << "����Ʒ�ļ�ֵ��";
		cin>>v[i];
	}
    cout<<"����ֵ�ǣ�"<<Knap()<<endl;
	system("pause");
return 0;
}