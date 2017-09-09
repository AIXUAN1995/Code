#include <iostream>
#include <vector>
using namespace std;
typedef struct Node//封装元素
{
	int num;
	struct Node* next;
}Person, *LinkList;
LinkList creat_List(int n)//创建节点数为n的链表
{
	LinkList L = NULL;
	Person *curNode, *tail = NULL;
	//第一种创建链表的方式
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

	//第二种创建链表的方式
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
	return tail;//返回尾指针
}
void del_List(LinkList delNode)
{
	Person *temp = NULL;
	//删除元素
	temp = delNode->next;
	delNode->next = delNode->next->next;
	delete temp;
}
int main()
{
	int n, x, j = 1, i = 0, num;//人数n，报数的最大值x，循环计数j，数组角标i,第一个报数的人的编号num
	cout << "请输入参加活动的人数：" << endl;
	cin >> n;
	vector<int>p(n);
	cout << "请输入报数的最大值" << endl;
	cin >> x;
	cout << "请输入第一个报数的人的编号：" << endl;
	cin >> num;
	LinkList L = creat_List(n);//指向的是链表的尾部
	Person *curNode = L;
	for (int k = 1; k < num; k++)
	{
		curNode = curNode->next;//指针指向报数人的前一个节点
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
	cout << "出队顺序为：" << endl;
	for (int k = 0; k<n; k++)
	{
		cout << p[k] << " ";
	}
	system("pause");
	return 0;
}