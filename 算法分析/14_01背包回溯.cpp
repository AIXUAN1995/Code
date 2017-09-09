//法一：当物品个数大于等于30时会出现问题
#include <iostream>
using namespace std;
const int NUM = 4;		//物品个数
int flag[NUM+1]={0};		//标记物品是否放入背包
int vMax[NUM+1]={0};		//价值最大的方案
int V[NUM+1] = {0,40,42,12,25};			//商品的价值
int W[NUM+1] = {0,4,7,3,5};			//商品的重量
int bag=10;				//背包的容量
int value=0;			//当前商品价值
int weight=0;			//当前重量
int bestp=0;			//最大价值
void backTrack(int k)
{//k表示当前递归的层数
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
		//每个物品都有放入背包和不放入背包两种状态，
		//对两种状态分别进行进行递归,最后取最大值
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
	cout << "选取方案(0表示未选取，1表示选取):" << endl;
	for(int i=1; i<=NUM; i++)
		cout << vMax[i] << " ";
	cout << endl;
	cout << "最大价值=" << bestp << endl;
	system("pause");
	return 0;
}
//法二 knapsack()函数可以省略
#include <iostream>
#include <time.h>
using namespace std;
const int NUM = 200;//物品数量
double c;//背包容量
double v[NUM + 1];//各个物品的价值
double w[NUM + 1];//各个物品的重量
double cw = 0.0;//当前背包重量
double cp = 0.0;//当前背包中物品价值
double bestp = 0.0;//当前最优价值
double perp[NUM + 1];//单位物品价值排序后
int put[NUM + 1];//设置是否装入
int n = 0;//装入背包中的物品个数
//按单位价值排序
void knapsack()
{
	double temporder = 0;
	double temp = 0;

	for (int i = 1; i <= NUM; i++)
		perp[i] = v[i] / w[i];
	for (int i = 1; i <= NUM - 1; i++)
	{
		for (int j = i + 1; j <= NUM; j++)
		if (perp[i]<perp[j])//冒泡排序perp[],order[],sortv[],sortw[]
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
//回溯函数
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
	if (bound(i + 1)>bestp)//符合条件搜索右子数
		backtrack(i + 1);
}
//计算上界函数
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
	c = rand() % 1000 + 1001;		//背包容量
	cout << "请输入背包容量：" << c << endl;
	cout << "物品个数：" << NUM << endl;
	knapsack();			//可以省略
	backtrack(1);
	cout << "最大价值：" << bestp << endl;
	cout << "装入背包中的物品个数：" << n << endl;
	cout << "物品重量:" << endl;
	for (int i = 1; i <= NUM; i++)
	{
		cout << w[i] << " ";
	}
	cout << endl;
	cout << "物品价值:" << endl;
	for (int i = 1; i <= NUM; i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
	cout << "装入的物品:" << endl;
	for (int i = 1; i <= NUM; i++)
	{
		cout << put[i] << " ";
	}
	system("pause");
	return 0;
}