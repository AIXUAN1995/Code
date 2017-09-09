*
需要解决的错误：
1.从停车场出来的时间早于进入停车场的时间
2.后一辆车进入停车场的时间必须晚于前一辆车进入停车场的时间
3.车辆出停车场的时间必须晚于停车场中最后一辆车进入停车场的时间
4.输入重复的车牌号码

*/
#include <iostream>
#include <string>
#define MAX_STOP 5			//设定停车位能存放的汽车数
#define MAX_PAVE 100		//便道不限制停放车辆的数目，设为足够大
using namespace std;
typedef struct
{
	string license_plate;	//汽车牌照号码
	char state;				//汽车当前状态，字符s表示停放在停车位上，
	//字符p表示停放在便道上，每辆车的初始化状态用字符i来表示
}CAR;
typedef struct				//存放停车场中车牌和进入时间的结构体
{
	string lic;
	int hour;				//进入停车场的时间：时
	int minute;				//进入停车场的时间：分
}STOP_LICENSE;
typedef struct				//只存放便道中车牌的结构体
{
	string lic;
}PAVE_LICENSE;
typedef struct
{
	CAR STOP[MAX_STOP];		//各汽车信息的存储空间
	int top;				//用来表示栈顶位置的静态指针
	int lasthour;			//最后一个进行变动的车辆的时刻-时
	int lastminute;			//最后一个进行变动的车辆的时刻-分
}STOPPING;

typedef struct
{
	CAR PAVE[MAX_PAVE];		//各汽车信息的存储空间
	int front, rear;		//用来指示队头和队尾位置的静态指针
}PAVEMENT;

typedef struct				//辅助栈
{
	CAR BUFFER[MAX_STOP];	//各汽车信息的存储空间
	int top;				//用来指示栈顶位置的静态指针
}BUFFER;

//函数声明
int getCar(STOPPING *stop, string license_plate, STOP_LICENSE stop_license[]);				//获取要出来的汽车在停车场的位置
void display(STOPPING *stop, BUFFER *buffer, PAVEMENT *pave, STOP_LICENSE stop_license[], PAVE_LICENSE pave_license[]);	//查看停车场停车状态的查询模块
void getTime(STOPPING *stop);									//汽车进入停车场的时间
void welcome()
{
	cout << "·欢迎使用本程序·" << endl;
	cout << "本程序为停车场的模拟管理程序，有车到来时请按【C】键。" << endl;
	cout << "然后根据屏幕提示进行相关操作，有车要走时请按【L】键。" << endl;
	cout << "然后根据屏幕提示进行相关操作，要显示信息请按【D】键。" << endl;
	cout << "然后根据屏幕提示进行相关操作，要退出程序请按【Q】键。" << endl;
	cout << "请选择您要的操作！" << endl;
}
void come(STOPPING *stop, CAR *car, BUFFER *buffer, PAVEMENT *pave, STOP_LICENSE stop_license[], PAVE_LICENSE pave_license[])//汽车进入停车位模块管理
{
exit:
	cout << "输入要进入车辆的车牌：" << endl;
	cin >> car->license_plate;

	if (stop->top < MAX_STOP - 1)
	{
		//判断停车场中是否有相同牌照的车辆
		for (int i = 0; i <= stop->top; i++)
		{
			if (car->license_plate == stop_license[i].lic)
			{
				cout << "停车场中有相同的牌照的车辆，请检查输入是否正确！" << endl;
				goto exit;
			}
		}

		stop->top++;
		(stop->STOP[stop->top]).license_plate = car->license_plate;
		stop_license[stop->top].lic = car->license_plate;
		(stop->STOP[stop->top]).state = car->state = 's';

		getTime(stop);
		//进入停车场的时间必须晚于最后一辆车变动的时间
		while ((stop->lasthour > stop_license[stop->top].hour) || ((stop->lasthour == stop_license[stop->top].hour) && (stop->lastminute > stop_license[stop->top].minute)))
		{
			cout << "输入时间有误，请核对后重新输入！" << endl;
			getTime(stop);
		}
		cout << "牌照为：" << car->license_plate << "的车进入停车场" << stop->top + 1 << "号车位！" << endl;
		cout << "进入的时刻为：" << (stop->STOP[stop->top]).hour << "时" << (stop->STOP[stop->top]).minute << "分。" << endl;
		stop->lasthour = stop_license[stop->top].hour;
		stop->lastminute = stop_license[stop->top].minute;
	}
	else
	{
		//判断停车场中是否有相同牌照的车辆
		for (int i = 0; i <= stop->top; i++)
		{
			if (car->license_plate == stop_license[i].lic)
			{
				cout << "停车场中有相同的牌照的车辆，请检查输入是否正确！" << endl;
				goto exit;
			}
		}
		//判断便道中是否有相同牌照的车辆
		for (int j = pave->front + 1; j <= pave->rear; j++)
		{
			if (car->license_plate == pave_license[i].lic)
			{
				cout << "便道中有相同的牌照的车辆，请检查输入是否正确！" << endl;
				goto exit;
			}
		}

		pave->rear++;
		pave->PAVE[pave->rear].license_plate = car->license_plate;
		pave_license[pave->rear].lic = car->license_plate;
		pave->PAVE[pave->rear].state = car->state = 'p';
		cout << "牌照为：" << car->license_plate << "的车进入便道" << pave->rear + 1 << "号车位！" << endl;
	}
	display(stop, buffer, pave);
}
void leave(STOPPING *stop, BUFFER *buffer, PAVEMENT *pave, STOP_LICENSE stop_license[])//汽车离开停车场管理模块
{
	cout << "输入要离开车辆的车牌：" << endl;
	string license_plate;
	cin >> license_plate;
	int n = getCar(stop, license_plate, stop_license);		//若停车场中有汽车返回位置，否则返回-1
	if (n == -1)
	{
		cout << "停车场中没有这辆车，请重新核对后再输人！";
		return;
	}
	while (stop->top > n)
	{
		buffer->top++;
		cout << "牌照为" << stop->STOP[stop->top].license_plate << "的汽车暂时退出停车位；" << endl;
		buffer->BUFFER[buffer->top] = stop->STOP[stop->top--];
	}
	int hour, minute, sumhour, summinute, cost = 0;
	cout << "输入离开停车场的时间：" << endl;
	cout << "进入停车场的时间-时(24小时制)：" << endl;
	cin >> hour;
	cout << "进入停车场的时间-分：" << endl;
	cin >> minute;
	//离开停车场的时间不能早于最后一辆车变动的时间
	while ((hour < stop->lasthour) || ((hour == stop->lasthour) && (minute < stop->lastminute)))
	{
		cout << "输入时间有误，请仔细核对后在进行输入！" << endl;
		cout << "输入离开停车场的时间：" << endl;
		cout << "进入停车场的时间-时(24小时制)：" << endl;
		cin >> hour;
		cout << "进入停车场的时间-分：" << endl;
		cin >> minute;
	}

	stop->lasthour = hour;
	stop->lastminute = minute;

	//计算时长和收费情况
	if (minute <= stop->STOP[n].minute)
		sumhour = hour - stop->STOP[n].hour;
	else
		sumhour = hour - stop->STOP[n].hour + 1;
	if (sumhour > 2)
		cost = (sumhour-2) * 2;
	cout << "牌照为" << stop->STOP[n].license_plate << "的汽车从停车场开走；" << endl;
	cout << "进入的时刻为：" << stop->STOP[n].hour << "时" << stop->STOP[n].minute << "分" << endl;
	cout << "离开的时刻为：" << hour << "时" << minute << "分" << endl;
	cout << "需要交纳的费用：" << cost << endl;
	stop->top--;
	while (buffer->top > -1)
	{
		stop->top++;
		cout << "牌照为" << buffer->BUFFER[buffer->top].license_plate << "的汽车停回停车位的" << stop->top + 1 << "车位" << endl;
		stop->STOP[stop->top] = buffer->BUFFER[buffer->top--];
	}
	if (pave->rear > -1)			//如果便道上面有汽车，让便道上的汽车进入停车场
	{
		stop->top++;
		cout << "便道上的车牌为" << pave->PAVE[pave->front + 1].license_plate << "的车即将进入停车场" << endl;
		getTime(stop);
		//进入停车场的时间必须晚于最后一辆车变动的时间
		while ((stop->STOP[stop->top].hour < stop->lasthour) || ((stop->STOP[stop->top].hour == stop->lasthour) && (stop->STOP[stop->top].minute < stop->lastminute)))
		{
			cout << "输入时间有误，请核对后重新输入！" << endl;
			getTime(stop);
		}

		cout << "便道上车牌为" << pave->PAVE[pave->front + 1].license_plate << "的车进入停车场" << stop->top + 1 << "号车位！" << endl;
		stop->STOP[stop->top].license_plate = pave->PAVE[pave->front + 1].license_plate;
		stop->STOP[stop->top].state = 's';
		stop->lasthour = hour;
		stop->lastminute = minute;
		pave->front++;
	}
	
	display(stop, buffer, pave);
}
void getTime(STOPPING *stop)
{
	cout << "输入进入停车场的时间（分为时和分两部分）：" << endl;
	do
	{
		cout << "进入停车场的时间-时：" << endl;
		cin >> stop->STOP[stop->top].hour;
	} while (stop->STOP[stop->top].hour < 0 || stop->STOP[stop->top].hour >= 24);

	do
	{
		cout << "进入停车场的时间-分：" << endl;
		cin >> stop->STOP[stop->top].minute;
	} while (stop->STOP[stop->top].minute < 0 || stop->STOP[stop->top].minute >= 60);
}
void display(STOPPING *stop, BUFFER *buffer, PAVEMENT *pave, STOP_LICENSE stop_license[], PAVE_LICENSE pave_license[])//查看停车场停车状态的查询模块
{
	//显示每个车位和便道对应的车辆牌照
	if (stop->top == -1)
	{
		cout << "停车场中暂无车辆！" << endl;
	}
	else
	{
		cout << "停车场中的车辆信息如下：" << endl;
		for (int i = 0; i <= stop->top; i++)
			cout << i + 1 << "号车位------" << stop_license[i].lic << endl;
		if (pave->rear > pave->front)
		{
			cout << "便道中的车辆信息如下：" << endl;
			for (int i = pave->front + 1, j = 1; i <= pave->rear; i++)
				cout << j++ << "号位置------" << pave_license[i].lic << endl;
		}

	}
	cout << "按【Enter】键继续程序的运行！" << endl;
	getchar();
}
int getCar(STOPPING *stop, string license_plate, STOP_LICENSE stop_license[])//获取要出来的汽车在停车场的位置
{
	for (int i = 0; i <= stop->top; i++)
	{
		if (stop_license[i].lic == license_plate)
			return i;
	}
	return -1;
}
int main()
{
	STOPPING stop;//定义停车场
	PAVEMENT pave;//定义便道
	BUFFER buffer;//定义辅助栈
	STOP_LICENSE stop_license[MAX_STOP];//只存放停车场车牌
	PAVE_LICENSE pave_license[MAX_STOP];//至存放便道车牌
	cout << "输入string：" << endl;
	CAR car;
	stop.top = -1;
	stop.lasthour = 0;
	stop.lastminute = 0;
	pave.front = pave.rear = -1;
	buffer.top = -1;
	welcome();
	//flushall();
	char key;
	do
	{
		key = getchar();
		if (key == 'C' || key == 'c')
			come(&stop, &car, &buffer, &pave, stop_license, pave_license);
		else if (key == 'L' || key == 'l')
			leave(&stop, &buffer, &pave, stop_license);
		else if (key == 'D' || key == 'd')
			display(&stop, &buffer, &pave, stop_license, pave_license);
		else if (key == '\n')
			welcome();
		else if (!(key == 'Q' || key == 'q'))
			cout << "输入有误，请重新输入！" << endl;
	} while ((key != 'Q') && (key != 'q'));
	system("pause");
	return 0;
}
