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
double w[N],v[N];	//物品的重量和价值
double cw,cv,c;		//背包中物品重量，背包中物品价值，背包容量
int n;				//物品个数
double Bound(int i)
{
    double cleft=c-cw,b=cv;
	//可以不按照单位价值由高到低输入
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
    double bestp=0,ub=Bound(1);//最优价值和界限
    while(1)
    {
        double wt=cw+w[i];//加上第i个物品后的质量
        if(wt<=c)
        {
            if(cv+v[i]>bestp)
				bestp=cv+v[i];
            AddLiveNode(ub,cv+v[i],cw+w[i],i+1);//加上第i个元素的活节点
        }
        ub=Bound(i+1);
        if(ub>=bestp)
             AddLiveNode(ub,cv,cw,i+1);			//不加第i个元素的活节点
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
    cout<<"请输入物品个数和背包容量:";  cin>>n>>c;
    for(int i=1;i<=n;i++)
	{
		cout << "请输入第" << i << "个物品的重量：";
		cin>>w[i];
		cout << "请输入第" << i << "个物品的价值：";
		cin>>v[i];
	}
    cout<<"最优值是："<<Knap()<<endl;
	system("pause");
return 0;
}