#include<iostream>
#include<string>
using namespace std;
struct GradeNode
{
	string name;
	int grade;
	GradeNode *next;
};
//创建链表
GradeNode * createList(int n)
{
	GradeNode *head = NULL, *tail = NULL, *temp = NULL;//定义头指针，尾指针和临时指针
	string stuName;
	int stuGrade;
	cout<<"按照成绩由高到低输入学生成绩："<<endl;
	cout<<"请输入一个学生的姓名和成绩："<<endl;
	cin>>stuName>>stuGrade;
	head = new GradeNode;
	head->name = stuName;
	head->grade = stuGrade;
	head->next = NULL;
	tail = head;
	for(int i=2; i<=n; i++)
	{
		cout<<"请输入一名学生的姓名和成绩："<<endl;
		cin>>stuName>>stuGrade;
		cout<<endl;
		temp = new GradeNode;
		temp->name = stuName;
		temp->grade = stuGrade;
		temp->next = NULL;
		tail->next = temp;
		tail = temp;
	}
	return head;
}
//链表的遍历
void dispList(GradeNode * head)
{
	cout<<"链表的信息如下："<<endl;
	GradeNode * curNode = head;//定义游动指针
	while(curNode)
	{
		cout<<"("<<curNode->name<<","<<curNode->grade<<")";
		if(curNode->next)
			cout<<"->";
		else
			cout<<endl;
		curNode = curNode->next;
	}
}
//插入节点
GradeNode * insertGradeNode(string stuName, int stuGrade, GradeNode * head)
{
	GradeNode * curNode = head;//游动指针
	GradeNode * preNode = NULL;//前驱结点
	GradeNode * newNode = NULL;//要插入的结点
	newNode = new GradeNode;
	newNode->name = stuName;
	newNode->grade = stuGrade;
	while((curNode!=NULL) && (curNode->grade>stuGrade))//要求创建链表时的数据必须是从小到大排列的
	{
		preNode = curNode;
		curNode = curNode->next;
	}
	if(preNode == NULL)
	{
		newNode->next = curNode;
		head = newNode;
		return head;
	}
	else
	{
		newNode->next = curNode;
		preNode->next = newNode;
		return head;
	}
}
//删除结点
GradeNode * delGradeNode(string stuName, int stuGrade, GradeNode * head)//不考虑重名
{
	GradeNode * curNode = head;
	GradeNode * preNode = NULL;
	while((curNode)!=NULL && (curNode->name!=stuName) && (curNode->grade!=stuGrade))
	{
		preNode = curNode;
		curNode = curNode->next;
	}
	if(curNode == NULL)
	{
		cout<<"没有找到要删除的结点！"<<endl;
		return head;
	}
	if(preNode == NULL)
		head = head->next;
	else
		preNode->next = preNode->next->next;
	delete curNode;
	return head;
}
//查找结点
GradeNode * findGradeNode(string stuName, GradeNode * head)
{
	GradeNode * curNode = head;
	while((curNode!=NULL) && (curNode->name!=stuName))
		curNode = curNode->next;
	if(curNode == NULL)
		return NULL;
	else
		return curNode;
}

int main()
{
	int listLen;
	
	GradeNode * listHead = NULL;
	//dispList(listHead);			//遍历链表
	int flag = 1;
	while(flag!=0)
	{
		cout<<endl;
		cout<<"请选择要执行的内容："<<endl;
		cout<<"1.插入学生成绩"<<endl;
		cout<<"2.删除学生成绩"<<endl;
		cout<<"3.显示内容更改后的链表内容"<<endl;
		cout<<"4.创建链表"<<endl;
		cout<<"0.退出"<<endl;
		cin>>flag;
		//插入节点
		if(flag == 1)
		{
			string name;
			int grade;
			cout<<"请输入要插入的学生的姓名和成绩："<<endl;
			cin>>name>>grade;
			listHead = insertGradeNode(name, grade, listHead);
		}
		//删除节点
		else if(flag == 2)
		{
			string name;
			int grade;
			cout<<"请输入要删除的学生的姓名和成绩："<<endl;
			cin>>name>>grade;
			listHead = delGradeNode(name, grade, listHead);
		}
		//遍历链表
		else if(flag == 3)
		{
			dispList(listHead);
		}
		//创建链表
		else if(flag == 4)
		{
			cout<<"请输入学生人数：";
			cin>>listLen;
			listHead = createList(listLen);

		}
		else if(flag == 0)
			cout<<"程序结束！"<<endl;
		else
			cout<<"没有您要的操作内容，请重新输入！"<<endl;
	}
	system("pause");
	return 0;
}