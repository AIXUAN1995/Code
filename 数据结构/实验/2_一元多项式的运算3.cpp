//�ڽ�������Ĺ���������
#include <iostream>
using namespace std;
typedef struct Node
{
	double ratio;			//ϵ��
	int exponent;			//ָ��
	struct Node *next;
}*LinkList, LNode;
LinkList creat_List(int n);//��������
LinkList insert_List(LinkList L, LNode *p, LNode **tail);//����ڵ�
LinkList add_List(LinkList L, LinkList L1, LinkList L2, LNode **tail);//�������
void ergodic_List(LinkList L);//��������
void exchange(LNode *q);//�����ڵ������ڵ��е�Ԫ�ؽ��н���
LinkList creat_List(int n)	//����һԪ����ʽ����
{
	LinkList L = NULL;
	LNode *newNode = NULL;
	LNode *tail, *pre;						//βָ��tail�����ڲ����ָ��pre
	double x;
	int y;										//����ϵ����ָ��
	cout << "������ϵ����ָ����" << endl;
	cin >> x >> y;
	L = new LNode();
	L->ratio = x;
	L->exponent = y;
	L->next = NULL;
	pre = tail = L;
	for (int i = 1; i < n; i++)
	{
		cout << "������ϵ����ָ����" << endl;
		cin >> x >> y;
		newNode = new LNode();
		newNode->ratio = x;
		newNode->exponent = y;
		if (y <= pre->exponent)					//���һ���������ж�
		{
			newNode->next = pre;
			pre = newNode;
			L = pre;
			continue;
		}
		while (pre->next != NULL)
		{
			if (y <= pre->next->exponent)
			{
				newNode->next = pre->next;
				pre->next = newNode;
				pre = L;
				break;
			}
			pre = pre->next;
		}
	}
	return L;
}
LinkList add_List(LinkList L, LinkList L1, LinkList L2, LNode *tail)
{
	LNode *curNode = L, *pa = L1, *pb = L2;
	while (pa != NULL || pb != NULL)
	{
		while (pa != NULL && pb != NULL)
		{
			if (pa->exponent != pb->exponent)//ָ�������
			{
				if (pa->exponent > pb->exponent)
				{
					if (pb->ratio != 0)
					{
						tail->next = pb;
						tail = pb;
					}
					pb = pb->next;
				}
				else
				{
					if (pa->ratio != 0)
					{
						tail->next = pa;
						tail = pa;
					}
					pa = pa->next;
				}
			}
			else //ָ�����
			{
				if (pa->ratio + pb->ratio != 0)
				{
					pa->ratio = pa->ratio + pb->ratio;
					tail->next = pa;
					tail = pa;
					pa = pa->next;
					pb = pb->next;
				}
				else
				{
					pa = pa->next;
					pb = pb->next;
				}

			}
		}
		while (pb != NULL)
		{
			tail->next = pb;
			tail = pb;
			pb = pb->next;
		}
		while (pa != NULL)
		{
			tail->next = pa;
			tail = pa;
			pa = pa->next;
		}
	}
	return L;
}
void ergodic_List(LinkList L)//��������
{
	LNode *curNode = L->next;
	if (curNode == NULL)//�ж������Ƿ�Ϊ��
	{
		cout << 0 << endl;
		return;
	}
	else//�Ե�һ���ڵ���в���
	{
		if (curNode->exponent == 0)//ָ��Ϊ��
			cout << curNode->ratio;
		else if(curNode->exponent == 1)//ָ��Ϊ1
		{
			if (curNode->ratio == -1)
				cout << "-x";
			else if (curNode->ratio == 1)
				cout << "x";
			else
				cout << curNode->ratio << "x";
		}
		else						//ָ����Ϊ��
		{
			if (curNode->ratio == -1)
				cout << "-x^" << curNode->exponent;
			else if (curNode->ratio == 1)
				cout << "x^" << curNode->exponent;
			else
				cout << curNode->ratio << "x";
		}
		curNode = curNode->next;
	}
	while (curNode)//�Եڶ������Ժ�Ľڵ�Ĳ���
	{
		if(curNode->exponent == 1)			//ָ������1
		{
			if (curNode->ratio == -1)
				cout << "-x";
			else if (curNode->ratio == 1)
				cout << "+" << "x";
			else if (curNode->ratio < 0)
				cout << curNode->ratio << "x";
			else
				cout << "+" << curNode->ratio << "x";
		}
		else								//ָ��������1
		{
			if (curNode->ratio == -1)
				cout << "-x^" << curNode->exponent;
			else if (curNode->ratio == 1)
				cout << "+" << "x^" << curNode->exponent;
			else if (curNode->ratio < 0)
				cout << curNode->ratio << "x^" << curNode->exponent;
			else
				cout << "+" << curNode->ratio << "x^" << curNode->exponent;
		}
		curNode = curNode->next;

	}
}
void exchange(LNode *q)//�����ڵ������ڵ��е�Ԫ�ؽ��н���
{
	double tempratio = q->ratio;
	int tempexponent = q->exponent;
	q->ratio = q->next->ratio;
	q->exponent = q->next->exponent;
	q->next->ratio = tempratio;
	q->next->exponent = tempexponent;
}
int main()
{
	LinkList L = NULL, L1 = NULL, L2 = NULL;
	L = new LNode();
	LNode *tail = L;
	int n1 = 0, n2 = 0;
	//�����һ������ʽ
	cout << "������һԪ����ʽ��������" << endl;
	cin >> n1;
	while (n1 <= 0)
	{
		cout << "��������, ���������룡" << endl;
		cout << "������һԪ����ʽ��������" << endl;
		cin >> n1;
	}
	L1 = creat_List(n1);

	//����ڶ�������ʽ
	cout << "������һԪ����ʽ��������" << endl;
	cin >> n2;
	while (n2 <= 0)
	{
		cout << "��������, ���������룡" << endl;
		cout << "������һԪ����ʽ��������" << endl;
		cin >> n2;
	}
	L2 = creat_List(n2);
	L = add_List(L, L1, L2, tail);
	ergodic_List(L);
	system("pause");
	return 0;
}
