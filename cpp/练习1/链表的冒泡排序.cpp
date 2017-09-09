#include <iostream>
#include <string>
using namespace std;
struct Node
{
	int Num;
	Node *next;
};
Node *Create()//´´½¨Á´±í
{
	int n=0;
	Node *p1, *p2, *head;
	p1 = p2 = new Node;
	cin>>p1->Num;
	head = NULL;
	while(p1->Num!=0)
	{
		if(n==1)
		{
			head = p1;
		}
		else
		{
			p2->next=p1;
			p2=p1;
			p1=new Node;
			cin>>p1->Num;
			n++;
		}
		p2->next=NULL;
		return head;
	}
};
int main()
{
	
	system("pause");
	return 0;
}