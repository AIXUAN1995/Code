//û���ƻ����ԭ�ж���ʽ�������½���һ������������������ӵ�ֵ
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
LinkList sort(LinkList L);//��һԪ����ʽ������������
void exchange(LNode *q);//�����ڵ������ڵ��е�Ԫ�ؽ��н���
LinkList creat_List(int n)	//����һԪ����ʽ����
{
	LinkList L = NULL;
	LNode *newNode = NULL;
	LNode *tail;
	double x;
	int y;				//����ϵ����ָ��
	cout << "������ϵ����ָ����" << endl;
	cin >> x >> y;
	L = new LNode();
	L->ratio = x;
	L->exponent = y;
	L->next = NULL;
	tail = L;
	for (int i = 1; i < n; i++)
	{
		cout << "������ϵ����ָ����" << endl;
		cin >> x >> y;
		newNode = new LNode();
		newNode->ratio = x;
		newNode->exponent = y;
		newNode->next = NULL;
		tail->next = newNode;
		tail = newNode;
	}
	L = sort(L);
	return L;
}
LinkList insert_List(LinkList L, LNode *p, LNode **tail)//�������
{
	if (L == NULL)
	{
		LNode *newNode = new LNode();
		newNode->ratio = p->ratio;
		newNode->exponent = p->exponent;
		newNode->next = NULL;
		L = newNode;
		*tail = newNode;
		return L;
	}
	LNode *newNode = new LNode();
	newNode->ratio = p->ratio;
	newNode->exponent = p->exponent;
	newNode->next = NULL;
	(*tail)->next = newNode;
	*tail = newNode;
	return L;
}
LinkList add_List(LinkList L, LinkList L1, LinkList L2, LNode **tail)
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
						L = insert_List(L, pb, tail);
					pb = pb->next;
				}
				else
				{
					if (pa->ratio != 0)
						L = insert_List(L, pa, tail);
					pa = pa->next;
				}
			}
			else //ָ�����
			{
				if (pa->ratio + pb->ratio != 0)
				{
					LNode temp;
					temp.ratio = pa->ratio + pb->ratio;
					temp.exponent = pa->exponent;
					temp.next = NULL;
					L = insert_List(L, &temp, tail);
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
			L = insert_List(L, pb, tail);
			pb = pb->next;
		}
		while (pa != NULL)
		{
			L = insert_List(L, pa, tail);
			pa = pa->next;
		}
	}
	return L;
}
void ergodic_List(LinkList L)//��������
{
	LNode *curNode = L;
	if (curNode == NULL)//�ж������Ƿ�Ϊ��
	{
		cout << 0 << endl;
		return;
	}
	else//�Ե�һ���ڵ���в���
	{
		if (curNode->exponent == 0)//ָ��Ϊ��
			cout << curNode->ratio;
		else						//ָ����Ϊ��
		{
			if (curNode->ratio == -1)
				cout << "-x^" << curNode->exponent;
			else if (curNode->ratio == 1)
				cout << "x^" << curNode->exponent;
			else
				cout << curNode->ratio << "x^" << curNode->exponent;
		}
		curNode = curNode->next;
	}
	while (curNode)//�Եڶ������Ժ�Ľڵ�Ĳ���
	{
		if (curNode->ratio == -1)
			cout << "-x^" << curNode->exponent;
		else if (curNode->ratio == 1)
			cout << "+" << "x^" << curNode->exponent;
		else if (curNode->ratio < 0)
			cout << curNode->ratio << "x^" << curNode->exponent;
		else
			cout << "+" << curNode->ratio << "x^" << curNode->exponent;
		curNode = curNode->next;

	}
}
LinkList sort(LinkList L)//��һԪ����ʽ������������
{
	LNode *p = L;
	LNode *q = p;
	while (p->next)
	{
		q = p;
		bool flag = true;
		while (q->next)
		{
			if (q->next->exponent < q->exponent)
			{
				exchange(q);
				flag = false;
			}
			q = q->next;
		}
		if (flag)
			break;
		p = p->next;
	}
	return L;
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
	LNode *tail = NULL;
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
	L = add_List(L, L1, L2, &tail);
	ergodic_List(L);
	system("pause");
	return 0;
}
