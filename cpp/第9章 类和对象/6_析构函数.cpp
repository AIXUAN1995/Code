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
//	cout << "���캯�������ã�" << endl;
//	stuName = name;
//	stuScore = new int[n];
//	cout << "������" << n << "���ɼ�ֵ��";
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
//	cout << "�������������ã�" << endl;
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
//		cout << "���캯��A�����ã�\n";
//		pi = new int;
//	}
//	~A()
//	{
//		cout << "����������A�����ã�\n";
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
//		cout << "���캯��B�����ã�\n";
//		parr = new int[n];
//	}
//	~B()
//	{
//		cout << "��������B�����ã�\n";
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