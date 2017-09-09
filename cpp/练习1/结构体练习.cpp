#include <iostream>
const float PI = 3.14;
using namespace std;
struct circle
{
	float radios;
	float circunference()
	{
		return 2 * PI * this ->radios;
	}
	float area()
	{
		return PI * this ->radios * this ->radios;
	}
	void input()
	{
		cout<<"ÇëÊäÈë°ë¾¶"<<endl;
		cin>>radios;
	}
};
struct rectangle
{
	float width, height;
	float zhouchang()
	{
		return 2 * (width + height);
	}
	float mianji()
	{
		return width * height;
	}
	void input()
	{
		cout<<"ÇëÊäÈë¿íºÍ³¤"<<endl;
		cin>>width>>height;
	}
};
int main()
{
	circle c;
	c.input();
	cout<<c.circunference()<<endl;
	cout<<c.area()<<endl;

	rectangle r;
	r.input();
	cout<<r.zhouchang()<<endl;
	cout<<r.mianji()<<endl;
	system("pause");
	return 0;
}