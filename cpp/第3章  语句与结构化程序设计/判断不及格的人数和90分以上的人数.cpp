#include <iostream>
using namespace std;
int main()
{
	int i=0, j=0;
	float score=0;
	cout<<"请输入成绩(0到100之间)，输入完成绩之后输入-1"<<endl;
	
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
	cout<<"不及格的人数："<<i<<endl<<"90分以上的人数："<<j<<endl;
	//cout<<"90分以上的人数："<<j<<endl;
	return 0;
}