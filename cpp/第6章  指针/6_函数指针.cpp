#include <iostream> 
using namespace std;
int add(int x, int y)
{
	return x + y;
}
int main()
{
	int a, b;
	int(*fp)(int, int);//定义函数指针
	fp = add;
	cout << "请输入两个加数：" << endl;
	cin >> a >> b;

	//三者输出结果相同
	cout << "a+b=" << add(a, b) << endl;
	cout << "a+b=" << (*fp)(a, b) << endl;
	cout << "a+b=" << fp(a, b) << endl;

	cout << fp << endl;
	cout << *fp << endl;//fp和*fp输出的都是地址，且相同
	system("pause");
	return 0;
}