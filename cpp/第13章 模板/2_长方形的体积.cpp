#include <iostream>
using namespace std;
template <class T>//����ģ������
T volume(T, T, T);
int main()
{
	int ilen, iw, ih;
	double dlen, dw, dh;
	cout << "���������͵ĳ���ߣ�";
	cin >> ilen >> iw >> ih;
	cout << "��� = " << volume(ilen, iw, ih) << endl;
	cout << "���븡���͵ĳ���ߣ�";
	cin >> dlen >> dw >> dh;
	cout << "��� = " << volume(dlen, dw, dh) << endl;
	system("pause");
	return 0;
}
template <class T>//����ģ�嶨��
T volume(T len, T w, T h)
{
	T vol;
	vol = len*w*h;
	return vol;
}
