#include <iostream>
#include <cmath>
using namespace std;
class Prime
{
private:
	int num;
public:
	void set(int);
	bool primejudge();
};
void Prime::set(int n)
{
	num = n;
}
bool Prime::primejudge()
{
	for (int i = 2; i < sqrt(num); i++)
	{
		if (num % i == 0)
			return false;
	}
	return true;
}
int main()
{
	int num;
	cout << "������һ����Ȼ����" << endl;
	cin >> num;
	Prime p;
	p.set(num);
	if (p.primejudge())
		cout << num << "������" << endl;
	else
		cout << num << "��������" << endl;
	system("pause");
	return 0;
}