#include <iostream>
using namespace std;
const int NUM = 9;			//������
int sign[NUM];				//sign��־�ڵ�����U�л�����V��
int lowcost[NUM];			//lowcost��ʾ�ܵ��õ�����·��
int per[NUM];				//��ʾ�õ�ĸ��ڵ�
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
	sign[0] = -1;//�����һ���㣬-1��ʾ�õ��ڼ���U�У������ڼ���V��
	int num = 0, len = 0, e = 0;//eΪ���¼��뼯�ϵĵ�
	while (num<m - 1)//����m-1����
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
	/*�����Ϊ0�Ķ��������������ͨ������С����������ά����G[NUM][NUM]�����ڽӾ���*/
	//����������Ϊ0..N-1����������С��������������tree�У���Ӧ�ı�ֵ��cost��

	//��¼�ڵ�����U�л�����V��,0��ʾ��V��,1��ʾ��U��
	int flag[NUM] = { 0 };
	int k,mincost = INT_MAX;
	for (int i = 0; i < NUM; i++)
	{
		cost[i] = G[0][i];
		tree[i] = 0;
	}
	tree[0] = -1;
	flag[0] = 1;
	//N-1��ѭ����Ѱ�ҵ�ǰ��СȨֵ�ı�
	for (int i = 1; i < NUM; i++)
	{
		mincost = INT_MAX;
		for (int j = 1; j < NUM; j++)
		{
			if (flag[j] == 0 && cost[j] < mincost)
			{
				mincost = cost[j];
				k = j;				//��¼��С�ı�
			}
		}
		flag[k] = 1;				//��k����U
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
	//�ڽӾ���
	int G[NUM][NUM];
	//����ͨͼ���г�ʼ��
	for (int i = 0; i<NUM; i++)
	{
		for (int j = 0; j<NUM; j++)
		{
			G[i][j] = INT_MAX;		//��ʼ��ֵΪ��������
		}
	}
	//ȷ����ͨ�ĵ�֮��ľ���
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