/*
C++综合实验
建立一个控制台动物园管理系统。
具体要求：
1、	至少可以引进5种动物（例如Dog,Cat,Sheep,Snake,…..）
2、	每种动物具有自己的属性，编号，姓名，年龄，信息介绍等。
3、	可以新建动物、删除动物，更改动物信息。并将信息存储到文件中
4、	可以查看单个动物信息，每类动物信息以及全部动物信息。
5、	控制台演示时，要求有文本菜单可以通过标号选择，添加删除要求有确认（Y|N?）。
6、	用面向对象的编程模式进行编程。
7、	注意程序的健壮性，对于非法输入可以进行处理。
8、	可以自己增加其他功能，如管理员等（可选）。
9、	程序界面上显示设计开发人员相关信息。
程序设计完毕，交给学委，学委为每一个学生建立一个目录，目录名为学号+姓名。将程序源码拷贝到目录中。
提交时间：12月6日之前。学委12月7日将所有作业交给我。
如有问题可以通过QQ联系我，号码：705410040 刘宇

*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
const int MAX_ANIMAL = 10;				//每类动物的最大容纳量
const int MAX_CLASS = 10;				//种类的最大数
//定义动物类
class Animal
{
public:
	Animal(){}
	Animal(string attribute1, string num1, string name1, int age1, string info1)
	{
		attribute = attribute1;
		num = num1;
		name = name1;
		age = age1;
		info = info1;
	}
	void set_att(string attribute1)
	{
		attribute = attribute1;
	}
	void set_num(string num1)
	{
		num = num1;
	}
	void set_name(string name1)
	{
		name = name1;
	}
	void set_age(int age1)
	{
		age = age1;
	}
	void set_info(string info1)
	{
		info = info1;
	}
	string get_num()
	{
		string s = num;
		return s;
	}
	string get_name()
	{
		return name;
	}
	void show()
	{
		cout << attribute << "\t" << num << "\t" << name << "\t" << age << "\t" << info << endl;
	}
	friend ostream &operator<<(ostream &out, Animal &ani);
	friend istream &operator>>(istream &in, Animal &ani);
protected:
	string attribute;	//属性
	string num;		//编号
	string name;		//姓名
	int age;		//年龄
	string info;		//信息介绍
};
ostream &operator<<(ostream &out, Animal &ani)
{
	out << ani.attribute << " " << ani.num << " " << ani.name << " " << ani.info << " " << ani.age << endl;
	return out;
}
istream &operator>>(istream &in, Animal &ani)
{
	in >> ani.attribute >> ani.num >> ani.name >> ani.info >> ani.age;
	return in;
}
//物种类
class Animal_class
{
public:
	Animal_class(){}
	Animal_class(string name1, Animal *p1)
	{
		class_name = name1;
		class_num = 1;
		p[class_num - 1] = p1;
	}
	void add(Animal *p1)//向该种类中增加动物
	{
		p[class_num] = p1;
		class_num++;
	}
	void del(int *ani_num_sum)			//从该种类中删除动物
	{
		cout << "请输入要删除的动物的编号：" << endl;
		string del_num;
		cin >> del_num;
		int i = 0;
		for (int i = 0; i < class_num; i++)
		if (del_num == p[i]->get_num())
		{
			cout << "确认要删除动物Y|N？" << endl;
			cin.sync();
			char ch_del_judge = getchar();
			while (1)
			{
				if (ch_del_judge == 'Y' || ch_del_judge == 'y')
				{
					for (int j = i; j < class_num - 1; j++)
						p[j] = p[j + 1];
					class_num--;
					(*ani_num_sum)--;
					cout << "删除成功！" << endl;
					break;
				}
				else if (ch_del_judge == 'N' || ch_del_judge == 'n')
				{
					cout << "结束删除动物任务！" << endl;
					break;
				}
				cin.sync();
				ch_del_judge = getchar();

			}
		}
		if (i >= class_num)
			cout << "没有找到您要删除的内容！" << endl;

	}
	void show()
	{
		cout << "物种名称：" << class_name << endl;
		cout << "动物数量：" << class_num << endl;
		cout << "属性" << "\t" << "编号" << "\t" << "名字" << "\t" << "年龄" << "\t" << "信息介绍" << endl;
		for (int i = 0; i < class_num; i++)
			p[i]->show();
	}
	void show_ani_outline()
	{
		cout << "该物种信息如下：" << endl;
		for (int i = 0; i < class_num; i++)
		{
			cout << "动物编号：" << get_ani_num(i) << '\t' << "物种名称：" << get_ani_name(i) << endl;
		}
	}
	string get_class_name()
	{
		return class_name;
	}
	int get_class_num()
	{
		return class_num;
	}
	string get_ani_num(int x)
	{
		return p[x]->get_num();
	}
	string get_ani_name(int x)
	{
		return p[x]->get_name();
	}
	int *get_class_num_address()
	{
		return &class_num;
	}
	Animal *get_class_p(int ani_num)
	{
		return p[ani_num];
	}
	void show_ani(int x)
	{
		p[x]->show();
	}
	void ani_set_att(string attribute1, int x)
	{
		p[x]->set_att(attribute1);
	}
	void ani_set_num(string num1, int x)
	{
		p[x]->set_num(num1);
	}
	void ani_set_name(string name1, int x)
	{
		p[x]->set_name(name1);
	}
	void ani_set_age(int age1, int x)
	{
		p[x]->set_age(age1);
	}
	void ani_set_info(string info1, int x)
	{
		p[x]->set_info(info1);
	}
	void new_p(int num)
	{
		for (int i = 0; i < num; i++)
			p[i] = new Animal();
	}
	friend ostream &operator<<(ostream &out, Animal_class & ani_cla);
	friend istream &operator>>(istream &in, Animal_class &ani_cla);
protected:
	Animal *p[MAX_ANIMAL];		//指向该种类动物的指针
	string class_name;		//种类名称
	int class_num;			//该种类动物的数量
};
ostream &operator<<(ostream &out, Animal_class & ani_cla)
{
	out << ani_cla.class_name << " " << ani_cla.class_num << endl;
	return out;
}
istream &operator>>(istream &in, Animal_class &ani_cla)
{
	in >> ani_cla.class_name >> ani_cla.class_num;
	return in;
}

//选择模式
void mode()
{
	cout << "**********************************" << endl;
	cout << "*本程序由20144137002艾轩开发*" << endl;
	cout << "请选择操作模式：" << endl;
	cout << "访客模式请按	【1】" << endl;
	cout << "管理员模式请按	【2】" << endl;
	cout << "退出程序请按	【3】" << endl;
	cout << "**********************************" << endl;
}
//欢迎信息
void welcome_admin()
{
	cout << "--------------------------------------" << endl;
	cout << "*欢迎使用动物园管理系统--管理员模式*" << endl;
	cout << "	请选择你要进行的操作：" << endl;
	cout << "	一下操作均不区分大小写！" << endl;
	cout << "	查看信息请按【S】" << endl;
	cout << "	增加动物请按【A】" << endl;
	cout << "	删除动物请按【D】" << endl;
	cout << "	修改动物信息【R】" << endl;
	cout << "	清屏动作请按【C】" << endl;
	cout << "	保存文件请按【P】" << endl;
	cout << "	退出操作请按【Q】" << endl;
	cout << "---------------------------------------" << endl;

}
void welcome_visitor()
{
	cout << "-----------------------------------" << endl;
	cout << "*欢迎使用动物园管理系统--访客模式*" << endl;
	cout << "	请选择你要进行的操作：" << endl;
	cout << "	一下操作均不区分大小写！" << endl;
	cout << "	查看信息请按【S】" << endl;
	cout << "	清屏动作请按【C】" << endl;
	cout << "	退出操作请按【Q】" << endl;
	cout << "------------------------------------" << endl;
}

//管理员登录
bool entry()
{
	//密码为123456
	string password;
	for (int i = 0; i < 3; i++)
	{
		cout << "请输入登录密码：" << endl;
		cin >> password;
		if (password == "123456")
		{
			system("cls");
			return true;
		}
		cout << "密码错误！您还有" << 2 - i << "次输入机会" << endl;
	}
	cout << "密码已输错三次！" << endl;
	return false;
}
void check_info()		//选择查看动物信息的类型
{
	cout << "请根据序号选择您要查看的信息类型：" << endl;
	cout << "1.单个动物信息" << endl;
	cout << "2.每类动物信息" << endl;
	cout << "3.全部动物信息" << endl;
}

//创建动物
Animal *create(Animal_class *ani_class[], int ani_class_num)
{
	string attribute;	//属性
	string num;			//编号
	string name;		//姓名
	int age;			//年龄
	string info;		//信息介绍
	cout << "请分别输入动物的属性，编号，名字，年龄，信息介绍:" << endl;
	cout << "属性：";
	cin >> attribute;

	int flag = 1;
	while (flag == 1)
	{
		cout << "编号：";
		cin >> num;
		for (int i = 0; i < ani_class_num; i++)
		{
			for (int j = 0; j < ani_class[i]->get_class_num(); j++)
			{
				if (num == ani_class[i]->get_ani_num(j))
				{
					cout << "动物园中有相同编号的动物！" << endl;
					flag = 0;
					break;
				}
			}
			if (flag == 0)
				break;
		}
		if (flag == 0)
			flag = 1;
		else
			break;
	}
	cout << "名字：";
	cin >> name;
	cout << "年龄(整数)：";
	cin >> age;
	while (1)
	{
		if (cin.good())
		{
			break;
		}
		else
		{
			cin.clear();
			cin.sync();
			cout << "请输入整数：" << endl;
			cin >> age;
		}
	}
	cout << "信息：";
	cin >> info;
	Animal *a = new Animal(attribute, num, name, age, info);
	return a;
}

//增加新种类的动物
Animal_class *create_class(string class_name, Animal_class *ani_class[], int ani_class_num)
{
	Animal *a = create(ani_class, ani_class_num);
	Animal_class *ac = new Animal_class(class_name, a);
	return ac;
}

//打印单个物种信息
void show_class(Animal_class *ani_class)
{
	cout << "该物种信息如下:" << endl;
	cout << "属性" << "\t" << "编号" << "\t" << "姓名" << "\t" << "年龄" << "\t" << "信息介绍" << endl;
	for (int j = 0; j < ani_class->get_class_num(); j++)
		ani_class->show_ani(j);
}

void show_class_outline(Animal_class *ani_class[], int ani_class_num)
{
	cout << "物种信息如下：" << endl;
	for (int i = 0; i < ani_class_num; i++)
	{
		cout << "物种编号：" << i + 1 << '\t' << "物种名称：" << ani_class[i]->get_class_name() << endl;
	}

}

//打印全部信息
void show_all(Animal_class *ani_class[], int *ani_class_num, int *ani_num_sum)
{
	cout << "属性" << "\t" << "编号" << "\t" << "姓名" << "\t" << "年龄" << "\t" << "信息介绍" << endl;
	for (int i = 0; i < *ani_class_num; i++)
	{
		for (int j = 0; j < ani_class[i]->get_class_num(); j++)
			ani_class[i]->show_ani(j);
	}

	cout << "现有动物总数：" << *ani_num_sum << endl;
	cout << "现有物种总数：" << *ani_class_num << endl;
}
int count_sum(Animal_class *ani_class[])
{
	int i = 0;
	while (ani_class[i] != NULL)
		i++;
	return i;
}

//查看动物信息
void search_fun(Animal_class *ani_class[], int *ani_class_num, int *ani_num_sum)
{
	if (*ani_class_num == 0)				//物种数目为0
	{
		cout << "动物园中没有动物！" << endl;
		return;
	}
	check_info();							//打印提示信息
	cin.sync();
	char ch_check = getchar();
	if (ch_check == '1')					//查看单个动物的信息
	{
		show_class_outline(ani_class, *ani_class_num);
		int flag = 1;
		while (flag == 1)
		{
			cout << "请输入要查询的物种编号：" << endl;
			int x;
			cin.sync();
			cin >> x;
			if (x >= 1 && x <= *ani_class_num)
			{
				ani_class[x - 1]->show_ani_outline();
				cout << "请输入要查询的动物编号：" << endl;
				string s_ani_num;
				cin >> s_ani_num;
				for (int i = 0; i < ani_class[x - 1]->get_class_num(); i++)
				{
					if (ani_class[x - 1]->get_ani_num(i) == s_ani_num)
					{
						cout << "属性" << "\t" << "编号" << "\t" << "姓名" << "\t" << "年龄" << "\t" << "信息介绍" << endl;
						ani_class[x - 1]->show_ani(i);
						flag = 0;
						break;
					}
				}
			}
			else
			{
				cout << "输入有误！" << endl;
				cout << "继续输入请按【1】" << endl;
				cout << "退出输入请按【2】" << endl;
				cin.sync();
				char ch_choice = getchar();
				if (ch_choice == '2')
					break;
			}
		}
	}
	if (ch_check == '2')				//查看每类动物的信息
	{
		show_class_outline(ani_class, *ani_class_num);
		while (1)
		{
			cout << "请输入要查询的物种编号：" << endl;
			int x;
			cin >> x;
			if (x >= 1 && x <= *ani_class_num)
			{
				ani_class[x - 1]->show();
				break;
			}
			else
			{
				cout << "输入有误！" << endl;
				cout << "继续输入请按【1】" << endl;
				cout << "退出输入请按【2】" << endl;
				cin.sync();
				char ch_choice = getchar();
				if (ch_choice == '2')
					break;
			}
		}

	}
	if (ch_check == '3')				//查看全部动物的信息
	{
		show_all(ani_class, ani_class_num, ani_num_sum);
	}
}

//增加动物
void add_fun(Animal_class *ani_class[], int *ani_class_num, int *ani_num_sum)
{
	cout << "新增物种添加动物请按【A】" << endl;
	cout << "在原有物种中添加请按【B】" << endl;
	cin.sync();
	char ch_add = getchar();
	if (ch_add == 'a' || ch_add == 'A')			//在新建物种里面添加动物
	{
		int flag = 1;
		string class_name;
		while (flag == 1 || flag == 2)
		{
			flag = 1;
			cout << "请输入物种的名称：" << endl;
			cin >> class_name;
			for (int i = 0; i < *ani_class_num; i++)
			{
				if (class_name == ani_class[i]->get_class_name())
				{
					cout << "动物园中有该物种是否继续输入Y/N" << endl;
					cin.sync();
					char c = getchar();
					if (c == 'Y' || c == 'y')
					{
						flag = 2;
						break;
					}
					else
					{
						flag = 0;
						break;
					}
				}
			}
			while (flag == 1)
			{
				cout << "确认要增加动物种类Y|N？" << endl;
				cin.sync();
				char ch_add_class = getchar();
				if (ch_add_class == 'Y' || ch_add_class == 'y')
				{
					ani_class[(*ani_class_num)++] = create_class(class_name, ani_class, *ani_class_num);
					(*ani_num_sum)++;
					cout << "添加成功！" << endl;
					flag = 0;
					break;
				}
				else if (ch_add_class == 'N' || ch_add_class == 'n')
				{
					delete ani_class[*ani_class_num];
					ani_class[*ani_class_num] = NULL;
					cout << "结束增加动物任务！" << endl;
					flag = 0;
					break;
				}
				else
					cout << "输入有误，请重新输入！" << endl;
			}

		}

	}
	else if (ch_add == 'b' || ch_add == 'B')		//在现有的物种里面添加动物
	{
		show_class_outline(ani_class, *ani_class_num);
		cout << "请选择要插入物种的编号：" << endl;
		int i;
		cin >> i;
		if (i >= 1 && i <= *ani_class_num)
		{
			Animal *a_add = create(ani_class, *ani_class_num);
			ani_class[i - 1]->add(a_add);
			cout << "确认要增加动物Y|N？" << endl;
			cin.sync();
			char ch_add_Animal = getchar();
			while (1)
			{
				if (ch_add_Animal == 'Y' || ch_add_Animal == 'y')
				{
					(*ani_num_sum)++;
					cout << "添加成功！" << endl;
					break;
				}
				else if (ch_add_Animal == 'N' || ch_add_Animal == 'n')
				{
					delete ani_class[i - 1];
					ani_class[i - 1] = NULL;
					cout << "结束增加动物任务！" << endl;
					break;
				}
				else
				{
					cout << "输入有误，请重新输入！" << endl;
					cout << "确认要增加动物种类Y|N？" << endl;
				}
				cin.sync();
				ch_add_Animal = getchar();
			}
		}
		else
		{
			cout << "没有您要找的物种！" << endl;
		}

	}
}

//删除动物
void del_fun(Animal_class *ani_class[], int *ani_class_num, int *ani_num_sum)
{
	if (*ani_class_num != 0)
	{
		show_class_outline(ani_class, *ani_class_num);				//显示物种信息
		cout << "删除动物请按【A】" << endl;
		cout << "删除整个物种【B】" << endl;
		cin.sync();
		int ch_del = getchar();
		if (ch_del == 'A' || ch_del == 'a')
		{
			cout << "请输入您要删除的动物所在的物种编号：" << endl;
			int x;
			cin.sync();
			cin >> x;
			if (x >= 1 && x <= *ani_class_num)
			{
				ani_class[x - 1]->show_ani_outline();
				ani_class[x - 1]->del(ani_num_sum);
				if (ani_class[x - 1]->get_class_num() == 0)
					(*ani_class_num)--;
			}
			else
				cout << "输入有误！" << endl;
		}
		else if (ch_del == 'B' || ch_del == 'b')
		{
			cout << "请输入您要删除的物种的编号：" << endl;
			int x;
			cin.sync();
			cin >> x;
			if (x >= 1 && x <= *ani_class_num)
			{
				cout << "确定要删除该物种吗Y/N?" << endl;
				cin.sync();
				char ch_del_judge = getchar();
				while (1)
				{
					if (ch_del_judge == 'Y' || ch_del_judge == 'y')
					{
						Animal_class *p_del_class = ani_class[x - 1];
						*ani_class_num = *ani_class_num - ani_class[x - 1]->get_class_num();
						delete p_del_class;
						ani_class[x - 1] = NULL;
						(*ani_class_num)--;
						(*ani_num_sum)--;
						break;
					}
					else if (ch_del_judge == 'N' || ch_del_judge == 'n')
					{
						cout << "结束删除动物任务！" << endl;
						break;
					}
					else
					{
						cout << "确定要删除该物种吗Y/N?" << endl;
						cin.sync();
						ch_del_judge = getchar();

					}

				}
			}
			else
				cout << "输入有误！" << endl;
		}//删除物种
	}//ani_class_num != 0
	else
	{
		cout << "动物园中没有动物，不能删除！" << endl;
	}
}

//修改动物信息
void revise_fun(Animal_class *ani_class[], int *ani_class_num, int *ani_num_sum)
{
	if (*ani_class_num == 0)
		cout << "动物园中没有动物！" << endl;
	else
	{
		show_all(ani_class, ani_class_num, ani_num_sum);
		cout << "请输入要修改的动物的编号：" << endl;
		string s_ani_num;
		cin >> s_ani_num;
		int flag = 1;
		int record_i;					//记录要修改的动物所在类的脚标
		int record_j;					//记录要修改的动物在类中的脚标
		for (int i = 0; i < *ani_class_num; i++)
		{
			for (int j = 0; j < ani_class[i]->get_class_num(); j++)
			{
				if (s_ani_num == ani_class[i]->get_ani_num(j))
				{
					record_i = i;
					record_j = j;
					flag = 0;
					break;
				}
			}
			if (flag == 0)
				break;
		}
		cout << "请输入要修改的项目的标号：" << endl;
		cout << "1.属性" << endl;
		cout << "2.编号" << endl;
		cout << "3.姓名" << endl;
		cout << "4.年龄" << endl;
		cout << "5.信息介绍" << endl;
		cin.sync();
		char ch_change = getchar();
		string attribute;
		string num;
		string name;
		int age;
		string info;
		switch (ch_change)
		{
		case '1':
			cout << "请输入更改后属性的内容:" << endl;
			cin >> attribute;
			ani_class[record_i]->ani_set_att(attribute, record_j);
			break;
		case '2':
		{
			int flag = 1;
			while (flag == 1)
			{
				cout << "请输入更改后编号的内容:";
				cin >> num;
				for (int i = 0; i < *ani_class_num; i++)
				{
					for (int j = 0; j < ani_class[i]->get_class_num(); j++)
					{
						if (num == ani_class[i]->get_ani_num(j))
						{
							cout << "动物园中有相同编号的动物！" << endl;
							flag = 0;
							break;
						}
					}
					if (flag == 0)
						break;
				}
				if (flag == 0)
					flag = 1;
				else
					break;
			}
			ani_class[record_i]->ani_set_num(num, record_j);
			break;
		}
		case '3':
			cout << "请输入更改后姓名的内容:" << endl;
			cin >> name;
			ani_class[record_i]->ani_set_name(name, record_j);
			break;
		case '4':
			cout << "请输入更改后年龄(整数)的内容:" << endl;
			cin >> age;
			ani_class[record_i]->ani_set_age(age, record_j);
			break;
		case '5':
			cout << "请输入更改后信息介绍的内容" << endl;
			cin >> info;
			ani_class[record_i]->ani_set_info(info, record_j);
			break;
		default:
			cout << "输入有误！" << endl;
		}
		cout << "修改成功！" << endl;
	}//动物园中有动物时
}

//保存功能
void save_fun(Animal_class *ani_class[], int *ani_class_num, int *ani_num_sum)
{
	*ani_num_sum = count_sum(ani_class);
	ofstream outfile_num;
	outfile_num.open("num.txt", ios::out);
	outfile_num << *ani_class_num << " " << *ani_num_sum << endl;
	for (int i = 0; i < *ani_class_num; i++)
	{
		outfile_num << ani_class[i]->get_class_num() << endl;
	}
	outfile_num.close();
	ofstream outfile;
	outfile.open("animal.txt", ios::out);
	for (int i = 0; i < *ani_class_num; i++)
	{
		outfile << *ani_class[i];
		for (int j = 0; j < ani_class[i]->get_class_num(); j++)
		{
			outfile << *(ani_class[i]->get_class_p(j));
		}
	}
	outfile.close();
	cout << "保存成功！" << endl;
}

//读入功能
void read_fun(Animal_class *ani_class[], int ani_num[], int *ani_num_sum, int *ani_class_num)
{
	ifstream infile_num;
	infile_num.open("num.txt", ios::in);
	infile_num >> *ani_class_num >> *ani_num_sum;
	for (int i = 0; i < *ani_class_num; i++)
	{
		infile_num >> ani_num[i];
	}
	infile_num.close();
	ifstream infile;
	infile.open("animal.txt", ios::in);
	for (int i = 0; i < *ani_class_num; i++)
	{
		ani_class[i] = new Animal_class();
		ani_class[i]->new_p(ani_num[i]);
		infile >> *ani_class[i];
		for (int j = 0; j < ani_class[i]->get_class_num(); j++)
		{
			infile >> *(ani_class[i]->get_class_p(j));
		}
	}
	infile.close();
}
int main()
{
	Animal_class *ani_class[MAX_CLASS];
	for (int i = 0; i < MAX_CLASS; i++)
		ani_class[i] = NULL;
	int ani_class_num = 0;						//记录类的个数
	int ani_num[MAX_ANIMAL] = { 0 };			//记录每类动物中有动物的个数
	int ani_num_sum = 0;						//记录动物总数

	//读入文件
	read_fun(ani_class, ani_num, &ani_num_sum, &ani_class_num);

	while (1)
	{
		system("cls");
		mode();
		cin.sync();
		char ch_mode = getchar();
		while (ch_mode == '1')
		{
			system("cls");
			welcome_visitor();
			cin.sync();
			char ch_visitor = getchar();
			if (ch_visitor == 's' || ch_visitor == 'S')
				search_fun(ani_class, &ani_class_num, &ani_num_sum);
			else if (ch_visitor == 'c' || ch_visitor == 'C')
				system("cls");
			else if (ch_visitor == 'q' || ch_visitor == 'Q')
			{
				cout << "退出访客模式，感谢您的使用！" << endl;
				break;
			}
			else
				cout << "输入有误，请重新输入！" << endl;
			system("pause");
		}
		if (ch_mode == '2' && entry())
		{
			while (1)
			{
				welcome_admin();
				cin.sync();
				char ch_admin = getchar();
				if (ch_admin == 'S' || ch_admin == 's')											//查看动物信息
				{
					search_fun(ani_class, &ani_class_num, &ani_num_sum);
				}
				else if (ch_admin == 'A' || ch_admin == 'a')									//增加动物
				{
					add_fun(ani_class, &ani_class_num, &ani_num_sum);
				}
				else if (ch_admin == 'D' || ch_admin == 'd')									//删除动物
				{
					del_fun(ani_class, &ani_class_num, &ani_num_sum);
				}
				else if (ch_admin == 'R' || ch_admin == 'r')									//修改信息
				{
					revise_fun(ani_class, &ani_class_num, &ani_num_sum);
				}
				else if (ch_admin == 'P' || ch_admin == 'p')									//保存信息
				{
					save_fun(ani_class, &ani_class_num, &ani_num_sum);
				}
				else if (ch_admin == 'Q' || ch_admin == 'q')									//退出
				{
					while (1)
					{
						cout << "是否保存当前内容Y|N？" << endl;
						cin.sync();
						char ch_q = getchar();
						if (ch_q == 'Y' || ch_q == 'y')
						{
							save_fun(ani_class, &ani_class_num, &ani_num_sum);
							break;
						}
						else if (ch_q == 'N' || ch_q == 'n')
						{
							read_fun(ani_class, ani_num, &ani_num_sum, &ani_class_num);
							break;
						}
						else
							cout << "输入有误！" << endl;
					}
					cout << "退出管理员模式，感谢您的使用！" << endl;
					break;
				}
				else if (ch_admin == 'C' || ch_admin == 'c')
				{
					system("cls");
				}
				else
				{
					cout << "输入有误，请重新输入！" << endl;
				}
			}
		}
		while (ch_mode == '3')
		{
			cout << "感谢您的使用！再见！" << endl;
			return 0;
		}
		if (ch_mode != '1' && ch_mode != '2' && ch_mode != '3')
		{
			cout << "输入有误，请重新输入！" << endl;
		}
		system("pause");
	}
	system("pause");
	return 0;
}
