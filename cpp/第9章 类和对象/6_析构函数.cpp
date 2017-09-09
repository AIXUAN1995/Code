//#include <iostream>
//using namespace std;
//class Information
//{
//public:
//	Information(string, int);
//	~Information();
//	int average(int);
//private:
//	string stuName;
//	int *stuScore;
//};
//Information::Information(string name, int n)
//{
//	cout << "构造函数被调用！" << endl;
//	stuName = name;
//	stuScore = new int[n];
//	cout << "请输入" << n << "个成绩值：";
//	for (int i = 0; i < n; i++)
//		cin >> stuScore[i];
//}
//int Information::average(int n)
//{
//	int sum = 0;
//	for (int i = 0; i < n; i++)
//		sum += stuScore[i];
//	return sum / n;
//}
//Information::~Information()
//{
//	cout << "析构函数被调用！" << endl;
//	delete[]stuScore;
//}
//int main()
//{
//	Information info1("zhang", 3);
//	cout << info1.average(3) << endl;
//	Information info2("li", 5);
//	cout << info2.average(5) << endl;
//	system("pause");
//	return 0;
//}

//#include <iostream>
//using namespace std;
//class A
//{
//public:
//	A()
//	{
//		cout << "构造函数A被调用！\n";
//		pi = new int;
//	}
//	~A()
//	{
//		cout << "析构函数～A被调用！\n";
//		delete pi;
//	}
//private:
//	int *pi;
//};
//class B
//{
//public:
//	B(int n)
//	{
//		cout << "构造函数B被调用！\n";
//		parr = new int[n];
//	}
//	~B()
//	{
//		cout << "析构函数B被调用！\n";
//		delete[]parr;
//	}
//private:
//	int *parr;
//};
//void function()
//{
//	A fa;
//	static B fb(5);
//}
//int main()
//{
//	A ma;
//	B mb(10);
//	function();
//	system("pause");
//	return 0;
//}