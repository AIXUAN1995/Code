#include <iostream>
using namespace std;
int main()
{
	int i=0, j=0;
	float score=0;
	cout<<"������ɼ�(0��100֮��)��������ɼ�֮������-1"<<endl;
	
	do
	{
		cin>>score;
		if(score<60 && score>=0)
		{
			++i;
		}
		if(score>90 && score<=100)
		{
			++j;
		}

	}while(score!=-1);
	cout<<"�������������"<<i<<endl<<"90�����ϵ�������"<<j<<endl;
	//cout<<"90�����ϵ�������"<<j<<endl;
	return 0;
}