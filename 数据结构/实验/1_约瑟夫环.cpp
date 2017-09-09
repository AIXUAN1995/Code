#include <iostream>
#include <vector>
using namespace std;
typedef struct Node//��װԪ��
{
	int num;
	struct Node* next;
}Person, *LinkList;
LinkList creat_List(int n)//�����ڵ���Ϊn������
{
	LinkList L = NULL;
	Person *curNode, *tail = NULL;
	//��һ�ִ�������ķ�ʽ
	/*curNode = new Person;
	curNode->num = 1;
	curNode->next = L;
	L = tail = curNode;

	for (int i = 2; i<=n; i++)
	{
		curNode = new Person;
		curNode->num = i;
		curNode->next = L;
		tail->next = curNode;
		tail = curNode;
	}*/

	//�ڶ��ִ�������ķ�ʽ
	int i = 1;
	while (i <= n)
	{
		curNode = new Person;
		curNode->num = i;
		if (L == NULL)
			L = curNode;
		else
			tail->next = curNode;
		tail = curNode;
		i++;
	}
	if (tail != NULL)
		tail->next = L;
	return tail;//����βָ��
}
void del_List(LinkList delNode)
{
	Person *temp = NULL;
	//ɾ��Ԫ��
	temp = delNode->next;
	delNode->next = delNode->next->next;
	delete temp;
}
int main()
{
	int n, x, j = 1, i = 0, num;//����n�����������ֵx��ѭ������j������Ǳ�i,��һ���������˵ı��num
	cout << "������μӻ��������" << endl;
	cin >> n;
	vector<int>p(n);
	cout << "�����뱨�������ֵ" << endl;
	cin >> x;
	cout << "�������һ���������˵ı�ţ�" << endl;
	cin >> num;
	LinkList L = creat_List(n);//ָ����������β��
	Person *curNode = L;
	for (int k = 1; k < num; k++)
	{
		curNode = curNode->next;//ָ��ָ�����˵�ǰһ���ڵ�
	}
	while (i<n && L!=NULL)
	{
		if (x == j)
		{
			p[i++] = curNode->next->num;
			del_List(curNode);
			j = 1;
		}
		else
		{
			curNode = curNode->next;
			j++;
		}
	}
	cout << "����˳��Ϊ��" << endl;
	for (int k = 0; k<n; k++)
	{
		cout << p[k] << " ";
	}
	system("pause");
	return 0;
}