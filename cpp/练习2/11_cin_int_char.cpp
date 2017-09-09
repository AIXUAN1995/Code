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
			cout << "ÇëÊäÈëÕûÊý£º" << endl;
			cin >> age;
		}
	}
	return 0;
}