/*
��Ҫ����Ĵ���
1.��ͣ����������ʱ�����ڽ���ͣ������ʱ��
2.��һ��������ͣ������ʱ���������ǰһ��������ͣ������ʱ��
3.������ͣ������ʱ���������ͣ���������һ��������ͣ������ʱ��
4.�����ظ��ĳ��ƺ���

*/
#include <iostream>
#include <string>
#define MAX_STOP 5			//�趨ͣ��λ�ܴ�ŵ�������
#define MAX_PAVE 100		//���������ͣ�ų�������Ŀ����Ϊ�㹻��
using namespace std;
typedef struct
{
	string license_plate;	//�������պ���
	char state;				//������ǰ״̬���ַ�s��ʾͣ����ͣ��λ�ϣ�
	//�ַ�p��ʾͣ���ڱ���ϣ�ÿ�����ĳ�ʼ��״̬���ַ�i����ʾ
	int hour;				//����ͣ������ʱ�䣺ʱ
	int minute;				//����ͣ������ʱ�䣺��
}CAR;

typedef struct
{
	CAR STOP[MAX_STOP];		//��������Ϣ�Ĵ洢�ռ�
	int top;				//������ʾջ��λ�õľ�ָ̬��
	int lasthour;			//���һ�����б䶯�ĳ�����ʱ��-ʱ
	int lastminute;			//���һ�����б䶯�ĳ�����ʱ��-��
}STOPPING;

typedef struct
{
	CAR PAVE[MAX_PAVE];		//��������Ϣ�Ĵ洢�ռ�
	int front, rear;		//����ָʾ��ͷ�Ͷ�βλ�õľ�ָ̬��
}PAVEMENT;

typedef struct				//����ջ
{
	CAR BUFFER[MAX_STOP];	//��������Ϣ�Ĵ洢�ռ�
	int top;				//����ָʾջ��λ�õľ�ָ̬��
}BUFFER;

//��������
int getCar(STOPPING *stop, string license_plate);				//��ȡҪ������������ͣ������λ��
void display(STOPPING *stop, BUFFER *buffer, PAVEMENT *pave);	//�鿴ͣ����ͣ��״̬�Ĳ�ѯģ��
void getTime(STOPPING *stop);									//��������ͣ������ʱ��
void welcome()
{
	cout << "����ӭʹ�ñ�����" << endl;
	cout << "������Ϊͣ������ģ���������г�����ʱ�밴��C������" << endl;
	cout << "Ȼ�������Ļ��ʾ������ز������г�Ҫ��ʱ�밴��L������" << endl;
	cout << "Ȼ�������Ļ��ʾ������ز�����Ҫ��ʾ��Ϣ�밴��D������" << endl;
	cout << "Ȼ�������Ļ��ʾ������ز�����Ҫ�˳������밴��Q������" << endl;
	cout << "��ѡ����Ҫ�Ĳ�����" << endl;
}
void come(STOPPING *stop, CAR *car, BUFFER *buffer, PAVEMENT *pave)//��������ͣ��λģ�����
{
exit:
	cout << "����Ҫ���복���ĳ��ƣ�" << endl;
	cin >> car->license_plate;

	if (stop->top < MAX_STOP - 1)
	{
		//�ж�ͣ�������Ƿ�����ͬ���յĳ���
		for (int i = 0; i <= stop->top; i++)
		{
			if (car->license_plate == stop->STOP[i].license_plate)
			{
				cout << "ͣ����������ͬ�����յĳ��������������Ƿ���ȷ��" << endl;
				goto exit;
			}
		}

		stop->top++;
		(stop->STOP[stop->top]).license_plate = car->license_plate;
		(stop->STOP[stop->top]).state = car->state = 's';

		getTime(stop);
		//����ͣ������ʱ������������һ�����䶯��ʱ��
		while ((stop->lasthour > stop->STOP[stop->top].hour) || ((stop->lasthour == stop->STOP[stop->top].hour) && (stop->lastminute > stop->STOP[stop->top].minute)))
		{
			cout << "����ʱ��������˶Ժ��������룡" << endl;
			getTime(stop);
		}
		cout << "����Ϊ��" << car->license_plate << "�ĳ�����ͣ����" << stop->top + 1 << "�ų�λ��" << endl;
		cout << "�����ʱ��Ϊ��" << (stop->STOP[stop->top]).hour << "ʱ" << (stop->STOP[stop->top]).minute << "�֡�" << endl;
		stop->lasthour = stop->STOP[stop->top].hour;
		stop->lastminute = stop->STOP[stop->top].minute;
	}
	else
	{
		//�жϱ�����Ƿ�����ͬ���յĳ���
		for (int j = pave->front + 1; j <= pave->rear; j++)
		{
			if (car->license_plate == pave->PAVE[j].license_plate)
			{
				cout << "���������ͬ�����յĳ��������������Ƿ���ȷ��" << endl;
				goto exit;
			}
		}

		pave->rear++;
		pave->PAVE[pave->rear].license_plate = car->license_plate;
		pave->PAVE[pave->rear].state = car->state = 'p';
		cout << "����Ϊ��" << car->license_plate << "�ĳ�������" << pave->rear + 1 << "�ų�λ��" << endl;
	}
	display(stop, buffer, pave);
}
void leave(STOPPING *stop, BUFFER *buffer, PAVEMENT *pave)//�����뿪ͣ��������ģ��
{
	cout << "����Ҫ�뿪�����ĳ��ƣ�" << endl;
	string license_plate;
	cin >> license_plate;
	int n = getCar(stop, license_plate);		//��ͣ����������������λ�ã����򷵻�-1
	if (n == -1)
	{
		cout << "ͣ������û���������������º˶Ժ������ˣ�";
		return;
	}
	while (stop->top > n)
	{
		buffer->top++;
		cout << "����Ϊ" << stop->STOP[stop->top].license_plate << "��������ʱ�˳�ͣ��λ��" << endl;
		buffer->BUFFER[buffer->top] = stop->STOP[stop->top--];
	}
	int hour, minute, sumhour, summinute, cost = 0;
	cout << "�����뿪ͣ������ʱ�䣺" << endl;
	cout << "����ͣ������ʱ��-ʱ(24Сʱ��)��" << endl;
	cin >> hour;
	cout << "����ͣ������ʱ��-�֣�" << endl;
	cin >> minute;
	//�뿪ͣ������ʱ�䲻���������һ�����䶯��ʱ��
	while ((hour < stop->lasthour) || ((hour == stop->lasthour) && (minute < stop->lastminute)))
	{
		cout << "����ʱ����������ϸ�˶Ժ��ڽ������룡" << endl;
		cout << "�����뿪ͣ������ʱ�䣺" << endl;
		cout << "����ͣ������ʱ��-ʱ(24Сʱ��)��" << endl;
		cin >> hour;
		cout << "����ͣ������ʱ��-�֣�" << endl;
		cin >> minute;
	}

	stop->lasthour = hour;
	stop->lastminute = minute;

	//����ʱ�����շ����
	if (minute <= stop->STOP[n].minute)
		sumhour = hour - stop->STOP[n].hour;
	else
		sumhour = hour - stop->STOP[n].hour + 1;
	if (sumhour > 2)
		cost = sumhour * 2;
	cout << "����Ϊ" << stop->STOP[n].license_plate << "��������ͣ�������ߣ�" << endl;
	cout << "�����ʱ��Ϊ��" << stop->STOP[n].hour << "ʱ" << stop->STOP[n].minute << "��" << endl;
	cout << "�뿪��ʱ��Ϊ��" << hour << "ʱ" << minute << "��" << endl;
	cout << "��Ҫ���ɵķ��ã�" << cost << endl;
	stop->top--;
	while (buffer->top > -1)
	{
		stop->top++;
		cout << "����Ϊ" << buffer->BUFFER[buffer->top].license_plate << "������ͣ��ͣ��λ��" << stop->top + 1 << "��λ" << endl;
		stop->STOP[stop->top] = buffer->BUFFER[buffer->top--];
	}
	if (pave->rear > -1)			//�������������������ñ���ϵ���������ͣ����
	{
		stop->top++;
		cout << "����ϵĳ���Ϊ" << pave->PAVE[pave->front + 1].license_plate << "�ĳ���������ͣ����" << endl;
		getTime(stop);
		//����ͣ������ʱ������������һ�����䶯��ʱ��
		while ((stop->STOP[stop->top].hour < stop->lasthour) || ((stop->STOP[stop->top].hour == stop->lasthour) && (stop->STOP[stop->top].minute < stop->lastminute)))
		{
			cout << "����ʱ��������˶Ժ��������룡" << endl;
			getTime(stop);
		}

		cout << "����ϳ���Ϊ" << pave->PAVE[pave->front + 1].license_plate << "�ĳ�����ͣ����" << stop->top + 1 << "�ų�λ��" << endl;
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
	cout << "�������ͣ������ʱ�䣨��Ϊʱ�ͷ������֣���" << endl;
	do
	{
		cout << "����ͣ������ʱ��-ʱ��" << endl;
		cin >> stop->STOP[stop->top].hour;
	} while (stop->STOP[stop->top].hour < 0 || stop->STOP[stop->top].hour >= 24);

	do
	{
		cout << "����ͣ������ʱ��-�֣�" << endl;
		cin >> stop->STOP[stop->top].minute;
	} while (stop->STOP[stop->top].minute < 0 || stop->STOP[stop->top].minute >= 60);
}
void display(STOPPING *stop, BUFFER *buffer, PAVEMENT *pave)//�鿴ͣ����ͣ��״̬�Ĳ�ѯģ��
{
	//��ʾÿ����λ�ͱ����Ӧ�ĳ�������
	if (stop->top == -1)
	{
		cout << "ͣ���������޳�����" << endl;
	}
	else
	{
		cout << "ͣ�����еĳ�����Ϣ���£�" << endl;
		for (int i = 0; i <= stop->top; i++)
			cout << i + 1 << "�ų�λ------" << stop->STOP[i].license_plate << endl;
		if (pave->rear > pave->front)
		{
			cout << "����еĳ�����Ϣ���£�" << endl;
			for (int i = pave->front + 1, j = 1; i <= pave->rear; i++)
				cout << j++ << "��λ��------" << pave->PAVE[i].license_plate << endl;
		}

	}
	cout << "����Enter����������������У�" << endl;
	getchar();
}
int getCar(STOPPING *stop, string license_plate)//��ȡҪ������������ͣ������λ��
{
	for (int i = 0; i <= stop->top; i++)
	{
		if (stop->STOP[i].license_plate == license_plate)
			return i;
	}
	return -1;
}
int main()
{
	STOPPING stop;//����ͣ����
	PAVEMENT pave;//������
	BUFFER buffer;//���帨��ջ
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
			come(&stop, &car, &buffer, &pave);
		else if (key == 'L' || key == 'l')
			leave(&stop, &buffer, &pave);
		else if (key == 'D' || key == 'd')
			display(&stop, &buffer, &pave);
		else if (key == '\n')
			welcome();
		else if (!(key == 'Q' || key == 'q'))
			cout << "�����������������룡" << endl;
	} while ((key != 'Q') && (key != 'q'));
	system("pause");
	return 0;
}