#include <iostream>
using namespace std;
int main()
{
	int age;
	while (1)
	{
		if (cin.good())
		{
			break;
		}
		else
		{
			cin.clear();
			cin.sync();
			cout << "������������" << endl;
			cin >> age;
		}
	}
	return 0;
}