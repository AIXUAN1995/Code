#include<iostream>
#include<string>
using namespace std;
struct GradeNode
{
	string name;
	int grade;
	GradeNode *next;
};
//��������
GradeNode * createList(int n)
{
	GradeNode *head = NULL, *tail = NULL, *temp = NULL;//����ͷָ�룬βָ�����ʱָ��
	string stuName;
	int stuGrade;
	cout<<"���ճɼ��ɸߵ�������ѧ���ɼ���"<<endl;
	cout<<"������һ��ѧ���������ͳɼ���"<<endl;
	cin>>stuName>>stuGrade;
	head = new GradeNode;
	head->name = stuName;
	head->grade = stuGrade;
	head->next = NULL;
	tail = head;
	for(int i=2; i<=n; i++)
	{
		cout<<"������һ��ѧ���������ͳɼ���"<<endl;
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
//����ı���
void dispList(GradeNode * head)
{
	cout<<"�������Ϣ���£�"<<endl;
	GradeNode * curNode = head;//�����ζ�ָ��
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
//����ڵ�
GradeNode * insertGradeNode(string stuName, int stuGrade, GradeNode * head)
{
	GradeNode * curNode = head;//�ζ�ָ��
	GradeNode * preNode = NULL;//ǰ�����
	GradeNode * newNode = NULL;//Ҫ����Ľ��
	newNode = new GradeNode;
	newNode->name = stuName;
	newNode->grade = stuGrade;
	while((curNode!=NULL) && (curNode->grade>stuGrade))//Ҫ�󴴽�����ʱ�����ݱ����Ǵ�С�������е�
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
//ɾ�����
GradeNode * delGradeNode(string stuName, int stuGrade, GradeNode * head)//����������
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
		cout<<"û���ҵ�Ҫɾ���Ľ�㣡"<<endl;
		return head;
	}
	if(preNode == NULL)
		head = head->next;
	else
		preNode->next = preNode->next->next;
	delete curNode;
	return head;
}
//���ҽ��
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
	//dispList(listHead);			//��������
	int flag = 1;
	while(flag!=0)
	{
		cout<<endl;
		cout<<"��ѡ��Ҫִ�е����ݣ�"<<endl;
		cout<<"1.����ѧ���ɼ�"<<endl;
		cout<<"2.ɾ��ѧ���ɼ�"<<endl;
		cout<<"3.��ʾ���ݸ��ĺ����������"<<endl;
		cout<<"4.��������"<<endl;
		cout<<"0.�˳�"<<endl;
		cin>>flag;
		//����ڵ�
		if(flag == 1)
		{
			string name;
			int grade;
			cout<<"������Ҫ�����ѧ���������ͳɼ���"<<endl;
			cin>>name>>grade;
			listHead = insertGradeNode(name, grade, listHead);
		}
		//ɾ���ڵ�
		else if(flag == 2)
		{
			string name;
			int grade;
			cout<<"������Ҫɾ����ѧ���������ͳɼ���"<<endl;
			cin>>name>>grade;
			listHead = delGradeNode(name, grade, listHead);
		}
		//��������
		else if(flag == 3)
		{
			dispList(listHead);
		}
		//��������
		else if(flag == 4)
		{
			cout<<"������ѧ��������";
			cin>>listLen;
			listHead = createList(listLen);

		}
		else if(flag == 0)
			cout<<"���������"<<endl;
		else
			cout<<"û����Ҫ�Ĳ������ݣ����������룡"<<endl;
	}
	system("pause");
	return 0;
}