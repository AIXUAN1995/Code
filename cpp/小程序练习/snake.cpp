#include<iostream> 
#include<windows.h> 
#include<time.h> 
#include<stdlib.h> 
#include<conio.h> 
#define N 21 
using namespace std;
void gotoxy(int x, int y)//位置函数 

{
	//表示一个字符在控制台屏幕上的坐标。
	COORD pos;
	//pos其实是一个结构体变量，其中X和Y是它的成员，通过修改pos.X和pos.Y的值就可以实现光标的位置控制。
	pos.X = 2 * x;

	pos.Y = y;
	//定位光标位置的函数
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

}

void color(int a)//颜色函数 

{
	/*
	设置控制台窗口字体颜色和背景色的函数
	GetStdHandle（nStdHandle）：是返回标准的输入、输出或错误的设备的句柄，也就是获得输入、输出/错误的屏幕缓冲区的句柄
	STD_OUTPUT_HANDLE：标准输出的句柄
	a：需要设置的颜色
	*/
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), a);

}

void init(int apple[2])//初始化函数（初始化围墙、显示信息、苹果） 
{

	int i, j;//初始化围墙 

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

				cout << "■";

			else cout << "□";

		}

		cout << endl;

	}

	gotoxy(N + 3, 1);//显示信息 

	color(10);

	cout << "按 W S A D 移动方向" << endl;

	gotoxy(N + 3, 2);

	color(10);

	cout << "按任意键暂停" << endl;

	gotoxy(N + 3, 3);

	color(10);

	cout << "得分：" << endl;

	apple[0] = rand() % N + 1;//苹果 

	apple[1] = rand() % N + 1;

	gotoxy(apple[0], apple[1]);

	color(12);

	cout << "●" << endl;

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

		int len = 3;//蛇的初始长度为3

		char ch = 'p';

		srand((unsigned)time(NULL));//生成随机数序列的种子为获取随机数做初始化

		init(apple);//对界面进行初始化

		/*
		重新给snake指针分配内存空间
		*/
		snake = (int**)realloc(snake, sizeof(int*)*len);

		for (i = 0; i<len; i++)

			snake[i] = (int*)malloc(sizeof(int)* 2);//数组的两个空间分别存放横纵坐标

		for (i = 0; i<len; i++)

		{

			snake[i][0] = (N + 1) / 2;		//横坐标

			snake[i][1] = (N + 1) / 2 + i;	//纵坐标

			gotoxy(snake[i][0], snake[i][1]);//定位横纵坐标

			color(14);

			cout << "★" << endl;

		}

		while (1)//进入消息循环 
		{

			tail[0] = snake[len - 1][0];//尾巴的横坐标

			tail[1] = snake[len - 1][1];//尾巴的纵坐标

			gotoxy(tail[0], tail[1]);

			color(11);

			cout << "■" << endl;//将蛇走过的地方重新变成“■”

			for (i = len - 1; i>0; i--)
			{
				//蛇向前移动，画出出头以外的其他部分
				snake[i][0] = snake[i - 1][0];

				snake[i][1] = snake[i - 1][1];

				gotoxy(snake[i][0], snake[i][1]);

				color(14);

				cout << "★" << endl;

			}

			if (_kbhit())//当没有键盘输入时，保持原状态，不动或者一直前进
			{
				//kbhit()： 检查当前是否有键盘输入，若有则返回一个非0值，否则返回0，在VC++6.0下为_kbhit()
				gotoxy(0, N + 2);
				//getche()输入后立即从控制台取字符，不以回车为结束(带回显)
				ch = _getche();

			}

			switch (ch)
			{
				//通过键盘输入改变方向
			case 'w':snake[0][1]--; break;

			case 's':snake[0][1]++; break;

			case 'a':snake[0][0]--; break;

			case 'd':snake[0][0]++; break;

			default: break;

			}
			//画出头
			gotoxy(snake[0][0], snake[0][1]);

			color(14);

			cout << "★" << endl;

			Sleep(abs(200 - 0.5*score));//程序暂停

			if (snake[0][0] == apple[0] && snake[0][1] == apple[1])
			{
				//吃掉苹果后蛇分数加1，蛇长加1
				score++;

				len++;

				//重新分配内存
				snake = (int**)realloc(snake, sizeof(int*)*len);

				snake[len - 1] = (int*)malloc(sizeof(int)* 2);

				//重新获取苹果的坐标
				apple[0] = rand() % N + 1;

				apple[1] = rand() % N + 1;

				gotoxy(apple[0], apple[1]);//画出苹果

				color(12);

				cout << "●" << endl;

				gotoxy(N + 5, 3);

				color(10);

				cout << score << endl;

			}

			if (snake[0][1] == 0 || snake[0][1] == N + 1 || snake[0][0] == 0 || snake[0][0] == N + 1)//撞到围墙后失败 
			{

				gotoxy(N / 2, N / 2);

				color(30);

				cout << "失败！！！" << endl;

				for (i = 0; i<len; i++)

					free(snake[i]);

				//Sleep(INFINITE);
				gotoxy(N / 2, N / 2 + 1);
				cout << "重新开始【C】" << endl;
				gotoxy(N / 2, N / 2 + 2);
				cout << "退出游戏【E】" << endl;
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
