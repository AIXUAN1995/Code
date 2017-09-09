#include <iostream>
using namespace std;
const int NUM = 9;			//结点个数
int sign[NUM];				//sign标志节点是在U中还是在V中
int lowcost[NUM];			//lowcost表示能到该点的最短路径
int per[NUM];				//表示该点的父节点
int prim1(int G[][NUM], int m)
{
	for (int i = 0; i<m; i++)
	{
		lowcost[i] = INT_MAX;
	}
	for (int i = 0; i<m; i++)
	{
		sign[i] = 0;
	}
	sign[0] = -1;//加入第一个点，-1表示该点在集合U中，否则在集合V中
	int num = 0, len = 0, e = 0;//e为最新加入集合的点
	while (num<m - 1)//加入m-1条边
	{
		int mincost = INT_MAX, minedge = -1;
		for (int i = 0; i<m; i++)
		if (sign[i] != -1)
		{
			int temp = G[e][i];
			if (temp<lowcost[i])
			{
				lowcost[i] = temp;
				per[i] = e;
			}
			if (lowcost[i]<mincost)
				mincost = lowcost[minedge = i];
		}
		len += mincost;
		sign[e = minedge] = -1;
		num++;
	}
	return len;
}

void prim(int G[][NUM], int tree[], int cost[])
{
	/*从序号为0的顶点出发，建立连通网的最小生成树，二维数组G[NUM][NUM]是其邻接矩阵*/
	//顶点编号依次为0..N-1，建立的最小生成树存于数组tree中，对应的边值在cost中

	//记录节点是在U中还是在V中,0表示在V中,1表示在U中
	int flag[NUM] = { 0 };
	int k,mincost = INT_MAX;
	for (int i = 0; i < NUM; i++)
	{
		cost[i] = G[0][i];
		tree[i] = 0;
	}
	tree[0] = -1;
	flag[0] = 1;
	//N-1次循环，寻找当前最小权值的边
	for (int i = 1; i < NUM; i++)
	{
		mincost = INT_MAX;
		for (int j = 1; j < NUM; j++)
		{
			if (flag[j] == 0 && cost[j] < mincost)
			{
				mincost = cost[j];
				k = j;				//记录最小的边
			}
		}
		flag[k] = 1;				//将k加入U
		for (int j = 1; j < NUM; j++)
		{
			if (G[k][j] < cost[j] && flag[j]==0)
			{
				cost[j] = G[k][j];
				tree[j] = k;
			}
		}
	}

}
int main()
{
	//邻接矩阵
	int G[NUM][NUM];
	//对连通图进行初始化
	for (int i = 0; i<NUM; i++)
	{
		for (int j = 0; j<NUM; j++)
		{
			G[i][j] = INT_MAX;		//初始赋值为最大的整数
		}
	}
	//确定连通的点之间的距离
	G[0][1] = G[1][0] = 4;
	G[0][7] = G[7][0] = 8;
	G[1][2] = G[2][1] = 8;
	G[1][7] = G[7][1] = 11;
	G[2][3] = G[3][2] = 7;
	G[2][5] = G[5][2] = 4;
	G[2][8] = G[8][2] = 2;
	G[3][4] = G[4][3] = 9;
	G[3][5] = G[5][3] = 14;
	G[4][5] = G[5][4] = 10;
	G[5][6] = G[6][5] = 2;
	G[6][7] = G[7][6] = 1;
	G[6][8] = G[8][6] = 6;
	G[7][8] = G[8][7] = 7;
	/*int n = prim1(G, NUM);
	cout << n << endl;
	for (int i = 0; i<NUM; i++)
		cout << sign[i] << " ";
	cout << endl;
	for (int i = 0; i<NUM; i++)
		cout << lowcost[i] << " ";
	cout << endl;
	for (int i = 0; i<NUM; i++)
		cout << per[i] << " ";
	cout << endl;*/

	int tree[NUM];
	int cost[NUM];
	prim(G, tree, cost);
	for (int i = 0; i < NUM; i++)
		cout << tree[i] << " ";
	cout << endl;
	for (int i = 0; i < NUM; i++)
		cout << cost[i] << " ";
	cout << endl;
	system("pause");
	return 0;
}