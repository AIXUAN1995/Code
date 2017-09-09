#include <iostream>
using namespace std;
int main()
{
	const int rows = 3, cols = 4;
	int a[rows][cols];
	int row, col, num;					//储存鞍点的行列以及数值
	bool flag = false;					//用于标记
	cout<<"输入3行4列的数组"<<endl;
	for(int i=0; i<rows; i++)			//输入数组元素
	{
		for(int j=0; j<cols; j++)
		{
			cin>>a[i][j];
		}
	}
	//代码一：
	for(int i=0; i<rows; i++)
	{
		num = a[i][0];
		for(int j=0; j<cols; j++)		//找出行中最大数
		{
			
			if(num<a[i][j])
			{
				num = a[i][j];
				row = i;
				col = j;
			}
		}
		for(int x=0; x<rows; x++)		//将找出来的数在其所在列中进行比较
		{
			if(num>a[x][col])
			{
				break;
			}
			else
			{
				while(x == rows-1)		//直到与最后一列比较完之后才能输出
				{
					cout<<"鞍点为"<<num<<endl;
					cout<<"鞍点所在的位置为：第"<<row+1<<"行，第"<<col+1<<"列"<<endl;
					flag = true;
					break;
				}
				
			}
		}

	}
	
	//代码二：
	/*int max, maxj, min, mini;
	for(int i=0; i<rows; i++)
	{
		max = a[i][0];
		maxj = 0;
		for(int j=0; j<cols; j++)
			if(max<a[i][j])
			{
				max = a[i][j];
				maxj = j;
			}
		min = a[0][maxj];
		mini = 0;
		for(int k=0; k<rows; k++)
			if(min>a[k][maxj])
			{
				min = a[i][maxj];
				mini = k;
			}
		if(min == max)
		{
			cout<<"鞍点为"<<max<<endl;
			cout<<"鞍点所在的位置为：第"<<mini+1<<"行，第"<<maxj+1<<"列"<<endl;
			flag = true;
		}
	}*/
	if(flag == false)
	{
		cout<<"该数组中没有鞍点"<<endl;
	}
	system("pause");
	return 0;
}