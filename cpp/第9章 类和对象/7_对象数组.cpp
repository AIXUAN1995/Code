#include <iostream>
#include <string>
using namespace std;
class Teacher
{
public:
	Teacher(string name, char sex, int age)
	{
		teacName = name;
		teacSex = sex;
		teacAge = age;
	}
	void display()
	{
		cout<<"����="<<teacName<<"\t"<<"�Ա�"<<teacSex<<"\t";
		cout<<"����="<<teacAge<<"\t\n";
	}
private:
	string teacName;
	char teacSex;
	int teacAge;
};
int main()
{
	Teacher teac[3] = {Teacher("Zhou", 'M', 35),
						Teacher("Wang", 'F', 42),
						Teacher("Zheng", 'M', 56)};
	for(int i=0; i<3; i++)
		teac[i].display();
	system("pause");
	return 0;
}