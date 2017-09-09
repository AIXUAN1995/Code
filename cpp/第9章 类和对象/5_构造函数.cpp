/*
��Ȼ�������Ĺ��캯��Rectangle()�͸�ֵ��Ա����set()����ʽ�빦���ϻ�����ͬ��
�������ڳ����е������ǲ�ͬ�ģ�Ҳ�����໥�����
���캯��ֻ���ڶ������ʱ��ִ�У��������Զ�ִ�У�����Ҫ��д������䣩��Ϊ�½����Ķ���ֵ��
��ֵ��Ա�����Ĺ��ܾ��Ǹı�����ȡֵ��������Ҫ����ʱ����ͨ����������������ִ�С�

��Ĭ�ϲ����Ĺ��캯�����������캯��ͬʱ����ʱ���׳��ֶ����ԣ�
Rectangle(int len = 1, int w = 1);
Rectangle();
Rectangle(int);

Rectangle r1;
Rectangle r2(8);

�������r1ʱ������û�и����κβ����������Ե����޲ι��캯����Ҳ���Ե���ȫ����������Ĭ��ֵ�Ĺ��캯����
�������r2�ǣ����ڸ�����һ���������ȿ��Ե��ô�1�������Ĺ��캯����Ҳ���Ե���ȫ����������Ĭ��ֵ�Ĺ��캯����
�����������������ֶ����ԣ�����ϵͳ���﷨����ָ���˶��Ĭ�Ϲ��캯����
*/
#include <iostream>
using namespace std;
class Rectangle
{
public:
	Rectangle();//�޲ι��캯��
	Rectangle(int, int);//�вι��캯��
	//Rectangle(int len = 1, int w = 3);//��Ĭ��ֵ�Ĺ��캯��
	void set(int len, int w);
	int area();
private:
	int length;
	int width;
};
Rectangle::Rectangle()
{
	length = 3;
	width = 5;
}
Rectangle::Rectangle(int len, int w)//����������Ĺ��캯��
{
	length = len;
	width = w;
}
void Rectangle::set(int len, int w)
{
	length = len;
	width = w;
}
int Rectangle::area()
{
	return (length*width);
}
int main()
{
	Rectangle rec1;
	cout << rec1.area() << endl;
	Rectangle rec2;
	rec2.set(6, 8);
	cout << rec2.area() << endl;
	Rectangle rec3(5, 6);
	cout << rec3.area() << endl;
	rec3.set(7, 8);
	cout << rec3.area() << endl;
	system("pause");
	return 0;
}