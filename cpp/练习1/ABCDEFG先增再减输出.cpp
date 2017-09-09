#include <iostream>
using namespace std;
int main()
{
	char a[7][7];
	for(int i=0; i<7; i++)
		for(int j=0; j<7; j++)
			a[i][j] = ' ';
	for(int i=0; i<7; i++)
	{
		/*a[i][i] = char('A' + i);
		a[i][7-i-1] = char('A' + i);
		a[0][4] = 'A';
		a[6][2] = 'G';
		for(int j=0;j<3;j++)
			a[j][j+2] = char('A' + j);
		for(int j=7; j>4; j--)
			a[j][j-2] = char('A'+j);*/
		for(int i=0; i<4; i++)
			for(int j=0; j<4-i; j++)
				a[i][i+2*j] = char('A'+i);
		for(int i=6; i>3; i--)
			for(int j=0; j<i-2; j++)
				a[i][i-2*j] = char('A'+i);
	}
	for(int i=0; i<7; i++)
	{
		for(int j=0; j<7; j++)
			cout<<a[i][j];		
		cout<<endl;
	}
	system("pause");
	return 0;
}