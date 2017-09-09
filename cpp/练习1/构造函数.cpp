#include <iostream>
using namespace std;
class Rectangle
{
	public:
		Rectangle();
		void set(int len,int w);
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
void Rectangle::set(int len,int w)
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
	cout<<rec1.area()<<endl;
	Rectangle rea2;
	rea2.set(6,8);
	cout<<rea2.area()<<endl;
	system("pause");
	return 0;
}