#include <iostream> 
using namespace std;
int add(int x, int y)
{
	return x + y;
}
int main()
{
	int a, b;
	int(*fp)(int, int);//���庯��ָ��
	fp = add;
	cout << "����������������" << endl;
	cin >> a >> b;

	//������������ͬ
	cout << "a+b=" << add(a, b) << endl;
	cout << "a+b=" << (*fp)(a, b) << endl;
	cout << "a+b=" << fp(a, b) << endl;

	cout << fp << endl;
	cout << *fp << endl;//fp��*fp����Ķ��ǵ�ַ������ͬ
	system("pause");
	return 0;
}