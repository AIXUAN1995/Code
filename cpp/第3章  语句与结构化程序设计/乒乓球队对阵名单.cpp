#include <iostream>
using namespace std;
int main()
{
	char i, j, k;				//i,j,k分别表示A,B,C的对手
	for(i='X'; i<='Z'; i++)
	{
		for(j='X'; j<='Z'; j++)
		{
			if(i!=j)
			{
				for(k='X'; k<='Z'; k++)
				{
					if(i!=k && j!=k && i!='X' && k!='X' && k!='Z')
					{
						cout<<'A'<<"--"<<i<<endl;
						cout<<'B'<<"--"<<j<<endl;
						cout<<'C'<<"--"<<k<<endl;
					}
				}
			}
		}
	}
	system("pause");
	return 0;
}
