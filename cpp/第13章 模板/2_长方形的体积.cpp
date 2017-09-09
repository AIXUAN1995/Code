#include <iostream>
using namespace std;
template <class T>//函数模板声明
T volume(T, T, T);
int main()
{
	int ilen, iw, ih;
	double dlen, dw, dh;
	cout << "请输入整型的长宽高：";
	cin >> ilen >> iw >> ih;
	cout << "体积 = " << volume(ilen, iw, ih) << endl;
	cout << "输入浮点型的长宽高：";
	cin >> dlen >> dw >> dh;
	cout << "体积 = " << volume(dlen, dw, dh) << endl;
	system("pause");
	return 0;
}
template <class T>//函数模板定义
T volume(T len, T w, T h)
{
	T vol;
	vol = len*w*h;
	return vol;
}
