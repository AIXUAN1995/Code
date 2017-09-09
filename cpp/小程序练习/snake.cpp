#include<iostream> 
#include<windows.h> 
#include<time.h> 
#include<stdlib.h> 
#include<conio.h> 
#define N 21 
using namespace std;
void gotoxy(int x, int y)//λ�ú��� 

{
	//��ʾһ���ַ��ڿ���̨��Ļ�ϵ����ꡣ
	COORD pos;
	//pos��ʵ��һ���ṹ�����������X��Y�����ĳ�Ա��ͨ���޸�pos.X��pos.Y��ֵ�Ϳ���ʵ�ֹ���λ�ÿ��ơ�
	pos.X = 2 * x;

	pos.Y = y;
	//��λ���λ�õĺ���
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

}

void color(int a)//��ɫ���� 

{
	/*
	���ÿ���̨����������ɫ�ͱ���ɫ�ĺ���
	GetStdHandle��nStdHandle�����Ƿ��ر�׼�����롢����������豸�ľ����Ҳ���ǻ�����롢���/�������Ļ�������ľ��
	STD_OUTPUT_HANDLE����׼����ľ��
	a����Ҫ���õ���ɫ
	*/
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), a);

}

void init(int apple[2])//��ʼ����������ʼ��Χǽ����ʾ��Ϣ��ƻ���� 
{

	int i, j;//��ʼ��Χǽ 

	int wall[N + 2][N + 2] = { { 0 } };

	for (i = 1; i <= N; i++)

	{

		for (j = 1; j <= N; j++)

			wall[i][j] = 1;

	}

	color(11);
	gotoxy(0, 0);
	for (i = 0; i<N + 2; i++)

	{

		for (j = 0; j<N + 2; j++)

		{

			if (wall[i][j])

				cout << "��";

			else cout << "��";

		}

		cout << endl;

	}

	gotoxy(N + 3, 1);//��ʾ��Ϣ 

	color(10);

	cout << "�� W S A D �ƶ�����" << endl;

	gotoxy(N + 3, 2);

	color(10);

	cout << "���������ͣ" << endl;

	gotoxy(N + 3, 3);

	color(10);

	cout << "�÷֣�" << endl;

	apple[0] = rand() % N + 1;//ƻ�� 

	apple[1] = rand() % N + 1;

	gotoxy(apple[0], apple[1]);

	color(12);

	cout << "��" << endl;

}

int main()

{
	while (1)
	{
		int i, j;

		int** snake = NULL;

		int apple[2];

		int score = 0;

		int tail[2];

		int len = 3;//�ߵĳ�ʼ����Ϊ3

		char ch = 'p';

		srand((unsigned)time(NULL));//������������е�����Ϊ��ȡ���������ʼ��

		init(apple);//�Խ�����г�ʼ��

		/*
		���¸�snakeָ������ڴ�ռ�
		*/
		snake = (int**)realloc(snake, sizeof(int*)*len);

		for (i = 0; i<len; i++)

			snake[i] = (int*)malloc(sizeof(int)* 2);//����������ռ�ֱ��ź�������

		for (i = 0; i<len; i++)

		{

			snake[i][0] = (N + 1) / 2;		//������

			snake[i][1] = (N + 1) / 2 + i;	//������

			gotoxy(snake[i][0], snake[i][1]);//��λ��������

			color(14);

			cout << "��" << endl;

		}

		while (1)//������Ϣѭ�� 
		{

			tail[0] = snake[len - 1][0];//β�͵ĺ�����

			tail[1] = snake[len - 1][1];//β�͵�������

			gotoxy(tail[0], tail[1]);

			color(11);

			cout << "��" << endl;//�����߹��ĵط����±�ɡ�����

			for (i = len - 1; i>0; i--)
			{
				//����ǰ�ƶ���������ͷ�������������
				snake[i][0] = snake[i - 1][0];

				snake[i][1] = snake[i - 1][1];

				gotoxy(snake[i][0], snake[i][1]);

				color(14);

				cout << "��" << endl;

			}

			if (_kbhit())//��û�м�������ʱ������ԭ״̬����������һֱǰ��
			{
				//kbhit()�� ��鵱ǰ�Ƿ��м������룬�����򷵻�һ����0ֵ�����򷵻�0����VC++6.0��Ϊ_kbhit()
				gotoxy(0, N + 2);
				//getche()����������ӿ���̨ȡ�ַ������Իس�Ϊ����(������)
				ch = _getche();

			}

			switch (ch)
			{
				//ͨ����������ı䷽��
			case 'w':snake[0][1]--; break;

			case 's':snake[0][1]++; break;

			case 'a':snake[0][0]--; break;

			case 'd':snake[0][0]++; break;

			default: break;

			}
			//����ͷ
			gotoxy(snake[0][0], snake[0][1]);

			color(14);

			cout << "��" << endl;

			Sleep(abs(200 - 0.5*score));//������ͣ

			if (snake[0][0] == apple[0] && snake[0][1] == apple[1])
			{
				//�Ե�ƻ�����߷�����1���߳���1
				score++;

				len++;

				//���·����ڴ�
				snake = (int**)realloc(snake, sizeof(int*)*len);

				snake[len - 1] = (int*)malloc(sizeof(int)* 2);

				//���»�ȡƻ��������
				apple[0] = rand() % N + 1;

				apple[1] = rand() % N + 1;

				gotoxy(apple[0], apple[1]);//����ƻ��

				color(12);

				cout << "��" << endl;

				gotoxy(N + 5, 3);

				color(10);

				cout << score << endl;

			}

			if (snake[0][1] == 0 || snake[0][1] == N + 1 || snake[0][0] == 0 || snake[0][0] == N + 1)//ײ��Χǽ��ʧ�� 
			{

				gotoxy(N / 2, N / 2);

				color(30);

				cout << "ʧ�ܣ�����" << endl;

				for (i = 0; i<len; i++)

					free(snake[i]);

				//Sleep(INFINITE);
				gotoxy(N / 2, N / 2 + 1);
				cout << "���¿�ʼ��C��" << endl;
				gotoxy(N / 2, N / 2 + 2);
				cout << "�˳���Ϸ��E��" << endl;
				char flag = _getche();
				if (flag == 'C' || flag == 'c')
					break;
				else if (flag == 'E' || flag == 'e')
					exit(0);
			}

		}
	}
	return 0;
}
