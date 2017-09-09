#include <iostream>
using namespace std;
const int NUM = 6;
class Traveling{
private:
	friend int TSP(int**, int*, int, int);
	void backTrack(int i);
	int city;
	int* x;//��ǰ���в���
	int* bestx;//�������в���
	int** a;
	int current_cost;//��ǰ����
	int bestc;//�����С����ֵ
	int NoEdge;//����ͨ�ı�־��������Ϊ-1
};

void Traveling::backTrack(int i)
{
	if (i == city){
		if (a[x[city - 1]][x[city]] != NoEdge && a[x[city]][x[1]] != NoEdge && (current_cost + a[x[city - 1]][x[city]] + a[x[city]][1]<bestc || bestc == NoEdge))
		{
			bestc = current_cost + a[x[city - 1]][x[city]] + a[x[city]][x[1]];
			for (int j = 1; j <= city; j++)
				bestx[j] = x[j];
		}
	}
	else{
		for (int j = i; j <= city; j++)
			if (a[x[i - 1]][x[j]] != NoEdge && (current_cost + a[x[i - 1]][x[i]]<bestc || bestc == NoEdge))
			{
				//���������������·����Ϊ��x[i-1]��x[j],Ϊ������λ�����ڽ�x[i]��x[j]����λ��
				swap(x[i], x[j]);
				current_cost += a[x[i - 1]][x[i]];
				backTrack(i + 1);
				//��һ����㲻����ʱ���л���
				current_cost -= a[x[i - 1]][x[i]];
				swap(x[i], x[j]);
			}
	}
}
int TSP(int** a, int* bestPath, int city, int NoEdge)
{//aΪ�ڽӾ���bestPathΪ���·����cityΪ������Ŀ��NoEdge��ʾδ��ͨ
	Traveling Y;
	Y.x = new int[city + 1];
	for (int i = 1; i <= city; i++)
		Y.x[i] = i;
	Y.a = a;
	Y.city = city;
	Y.bestc = NoEdge;
	Y.bestx = bestPath;
	Y.current_cost = 0;
	Y.NoEdge = NoEdge;
	Y.backTrack(2);
	delete[] Y.x;


	for (int i = 0; i<NUM; i++)
	{
		for (int j = 0; j<NUM; j++)
		{
			cout << a[i][j] << "\t";
		}
		cout << endl;
	}
	cout << "The path: ";
	for (int i = 1; i <= city; i++)
	{
		cout << " " << Y.bestx[i];
	}
	cout << endl;
	return Y.bestc;
}

void main()
{
	int **map;
	int * bestpath;

	map = new int*[NUM];
	for (int i = 0; i<NUM; i++)
	{
		map[i] = new int[NUM];
	}
	//�����ڽӾ���
	int a[NUM][NUM] =
	{ 
	0, 1, 2, 3, 4, 5,
	1, -1, 3, 6, 7, 6,
	2, 12, -1, 2, 8, 7,
	3, 8, 6, -1, 2, 8,
	4, 3, 7, 6, -1, 50,
	5, 9, 6, 3, 7, -1};
	for (int i = 0; i<NUM; i++)
	{
		for (int j = 0; j<NUM; j++)
		{
			map[i][j] = a[i][j];
		}
	}
	bestpath = new int[NUM];
	memset(bestpath, 0, sizeof(bestpath));
	cout << "The min cost: " << TSP(map, bestpath, NUM-1, -1) << endl;
	system("pause");
}