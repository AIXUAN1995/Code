#include <iostream>
using namespace std;
int main()
{
	const int rows = 3, cols = 4;
	int a[rows][cols];
	int row, col, num;					//���氰��������Լ���ֵ
	bool flag = false;					//���ڱ��
	cout<<"����3��4�е�����"<<endl;
	for(int i=0; i<rows; i++)			//��������Ԫ��
	{
		for(int j=0; j<cols; j++)
		{
			cin>>a[i][j];
		}
	}
	//����һ��
	for(int i=0; i<rows; i++)
	{
		num = a[i][0];
		for(int j=0; j<cols; j++)		//�ҳ����������
		{
			
			if(num<a[i][j])
			{
				num = a[i][j];
				row = i;
				col = j;
			}
		}
		for(int x=0; x<rows; x++)		//���ҳ������������������н��бȽ�
		{
			if(num>a[x][col])
			{
				break;
			}
			else
			{
				while(x == rows-1)		//ֱ�������һ�бȽ���֮��������
				{
					cout<<"����Ϊ"<<num<<endl;
					cout<<"�������ڵ�λ��Ϊ����"<<row+1<<"�У���"<<col+1<<"��"<<endl;
					flag = true;
					break;
				}
				
			}
		}

	}
	
	//�������
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
			cout<<"����Ϊ"<<max<<endl;
			cout<<"�������ڵ�λ��Ϊ����"<<mini+1<<"�У���"<<maxj+1<<"��"<<endl;
			flag = true;
		}
	}*/
	if(flag == false)
	{
		cout<<"��������û�а���"<<endl;
	}
	system("pause");
	return 0;
}