/*
C++�ۺ�ʵ��
����һ������̨����԰����ϵͳ��
����Ҫ��
1��	���ٿ�������5�ֶ������Dog,Cat,Sheep,Snake,��..��
2��	ÿ�ֶ�������Լ������ԣ���ţ����������䣬��Ϣ���ܵȡ�
3��	�����½����ɾ��������Ķ�����Ϣ��������Ϣ�洢���ļ���
4��	���Բ鿴����������Ϣ��ÿ�ද����Ϣ�Լ�ȫ��������Ϣ��
5��	����̨��ʾʱ��Ҫ�����ı��˵�����ͨ�����ѡ�����ɾ��Ҫ����ȷ�ϣ�Y|N?����
6��	���������ı��ģʽ���б�̡�
7��	ע�����Ľ�׳�ԣ����ڷǷ�������Խ��д���
8��	�����Լ������������ܣ������Ա�ȣ���ѡ����
9��	�����������ʾ��ƿ�����Ա�����Ϣ��
���������ϣ�����ѧί��ѧίΪÿһ��ѧ������һ��Ŀ¼��Ŀ¼��Ϊѧ��+������������Դ�뿽����Ŀ¼�С�
�ύʱ�䣺12��6��֮ǰ��ѧί12��7�ս�������ҵ�����ҡ�
�����������ͨ��QQ��ϵ�ң����룺705410040 ����

*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
const int MAX_ANIMAL = 10;				//ÿ�ද������������
const int MAX_CLASS = 10;				//����������
//���嶯����
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
	string attribute;	//����
	string num;		//���
	string name;		//����
	int age;		//����
	string info;		//��Ϣ����
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
//������
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
	void add(Animal *p1)//������������Ӷ���
	{
		p[class_num] = p1;
		class_num++;
	}
	void del(int *ani_num_sum)			//�Ӹ�������ɾ������
	{
		cout << "������Ҫɾ���Ķ���ı�ţ�" << endl;
		string del_num;
		cin >> del_num;
		int i = 0;
		for (int i = 0; i < class_num; i++)
		if (del_num == p[i]->get_num())
		{
			cout << "ȷ��Ҫɾ������Y|N��" << endl;
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
					cout << "ɾ���ɹ���" << endl;
					break;
				}
				else if (ch_del_judge == 'N' || ch_del_judge == 'n')
				{
					cout << "����ɾ����������" << endl;
					break;
				}
				cin.sync();
				ch_del_judge = getchar();

			}
		}
		if (i >= class_num)
			cout << "û���ҵ���Ҫɾ�������ݣ�" << endl;

	}
	void show()
	{
		cout << "�������ƣ�" << class_name << endl;
		cout << "����������" << class_num << endl;
		cout << "����" << "\t" << "���" << "\t" << "����" << "\t" << "����" << "\t" << "��Ϣ����" << endl;
		for (int i = 0; i < class_num; i++)
			p[i]->show();
	}
	void show_ani_outline()
	{
		cout << "��������Ϣ���£�" << endl;
		for (int i = 0; i < class_num; i++)
		{
			cout << "�����ţ�" << get_ani_num(i) << '\t' << "�������ƣ�" << get_ani_name(i) << endl;
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
	Animal *p[MAX_ANIMAL];		//ָ������ද���ָ��
	string class_name;		//��������
	int class_num;			//�����ද�������
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

//ѡ��ģʽ
void mode()
{
	cout << "**********************************" << endl;
	cout << "*��������20144137002��������*" << endl;
	cout << "��ѡ�����ģʽ��" << endl;
	cout << "�ÿ�ģʽ�밴	��1��" << endl;
	cout << "����Աģʽ�밴	��2��" << endl;
	cout << "�˳������밴	��3��" << endl;
	cout << "**********************************" << endl;
}
//��ӭ��Ϣ
void welcome_admin()
{
	cout << "--------------------------------------" << endl;
	cout << "*��ӭʹ�ö���԰����ϵͳ--����Աģʽ*" << endl;
	cout << "	��ѡ����Ҫ���еĲ�����" << endl;
	cout << "	һ�²����������ִ�Сд��" << endl;
	cout << "	�鿴��Ϣ�밴��S��" << endl;
	cout << "	���Ӷ����밴��A��" << endl;
	cout << "	ɾ�������밴��D��" << endl;
	cout << "	�޸Ķ�����Ϣ��R��" << endl;
	cout << "	���������밴��C��" << endl;
	cout << "	�����ļ��밴��P��" << endl;
	cout << "	�˳������밴��Q��" << endl;
	cout << "---------------------------------------" << endl;

}
void welcome_visitor()
{
	cout << "-----------------------------------" << endl;
	cout << "*��ӭʹ�ö���԰����ϵͳ--�ÿ�ģʽ*" << endl;
	cout << "	��ѡ����Ҫ���еĲ�����" << endl;
	cout << "	һ�²����������ִ�Сд��" << endl;
	cout << "	�鿴��Ϣ�밴��S��" << endl;
	cout << "	���������밴��C��" << endl;
	cout << "	�˳������밴��Q��" << endl;
	cout << "------------------------------------" << endl;
}

//����Ա��¼
bool entry()
{
	//����Ϊ123456
	string password;
	for (int i = 0; i < 3; i++)
	{
		cout << "�������¼���룺" << endl;
		cin >> password;
		if (password == "123456")
		{
			system("cls");
			return true;
		}
		cout << "�������������" << 2 - i << "���������" << endl;
	}
	cout << "������������Σ�" << endl;
	return false;
}
void check_info()		//ѡ��鿴������Ϣ������
{
	cout << "��������ѡ����Ҫ�鿴����Ϣ���ͣ�" << endl;
	cout << "1.����������Ϣ" << endl;
	cout << "2.ÿ�ද����Ϣ" << endl;
	cout << "3.ȫ��������Ϣ" << endl;
}

//��������
Animal *create(Animal_class *ani_class[], int ani_class_num)
{
	string attribute;	//����
	string num;			//���
	string name;		//����
	int age;			//����
	string info;		//��Ϣ����
	cout << "��ֱ����붯������ԣ���ţ����֣����䣬��Ϣ����:" << endl;
	cout << "���ԣ�";
	cin >> attribute;

	int flag = 1;
	while (flag == 1)
	{
		cout << "��ţ�";
		cin >> num;
		for (int i = 0; i < ani_class_num; i++)
		{
			for (int j = 0; j < ani_class[i]->get_class_num(); j++)
			{
				if (num == ani_class[i]->get_ani_num(j))
				{
					cout << "����԰������ͬ��ŵĶ��" << endl;
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
	cout << "���֣�";
	cin >> name;
	cout << "����(����)��";
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
			cout << "������������" << endl;
			cin >> age;
		}
	}
	cout << "��Ϣ��";
	cin >> info;
	Animal *a = new Animal(attribute, num, name, age, info);
	return a;
}

//����������Ķ���
Animal_class *create_class(string class_name, Animal_class *ani_class[], int ani_class_num)
{
	Animal *a = create(ani_class, ani_class_num);
	Animal_class *ac = new Animal_class(class_name, a);
	return ac;
}

//��ӡ����������Ϣ
void show_class(Animal_class *ani_class)
{
	cout << "��������Ϣ����:" << endl;
	cout << "����" << "\t" << "���" << "\t" << "����" << "\t" << "����" << "\t" << "��Ϣ����" << endl;
	for (int j = 0; j < ani_class->get_class_num(); j++)
		ani_class->show_ani(j);
}

void show_class_outline(Animal_class *ani_class[], int ani_class_num)
{
	cout << "������Ϣ���£�" << endl;
	for (int i = 0; i < ani_class_num; i++)
	{
		cout << "���ֱ�ţ�" << i + 1 << '\t' << "�������ƣ�" << ani_class[i]->get_class_name() << endl;
	}

}

//��ӡȫ����Ϣ
void show_all(Animal_class *ani_class[], int *ani_class_num, int *ani_num_sum)
{
	cout << "����" << "\t" << "���" << "\t" << "����" << "\t" << "����" << "\t" << "��Ϣ����" << endl;
	for (int i = 0; i < *ani_class_num; i++)
	{
		for (int j = 0; j < ani_class[i]->get_class_num(); j++)
			ani_class[i]->show_ani(j);
	}

	cout << "���ж���������" << *ani_num_sum << endl;
	cout << "��������������" << *ani_class_num << endl;
}
int count_sum(Animal_class *ani_class[])
{
	int i = 0;
	while (ani_class[i] != NULL)
		i++;
	return i;
}

//�鿴������Ϣ
void search_fun(Animal_class *ani_class[], int *ani_class_num, int *ani_num_sum)
{
	if (*ani_class_num == 0)				//������ĿΪ0
	{
		cout << "����԰��û�ж��" << endl;
		return;
	}
	check_info();							//��ӡ��ʾ��Ϣ
	cin.sync();
	char ch_check = getchar();
	if (ch_check == '1')					//�鿴�����������Ϣ
	{
		show_class_outline(ani_class, *ani_class_num);
		int flag = 1;
		while (flag == 1)
		{
			cout << "������Ҫ��ѯ�����ֱ�ţ�" << endl;
			int x;
			cin.sync();
			cin >> x;
			if (x >= 1 && x <= *ani_class_num)
			{
				ani_class[x - 1]->show_ani_outline();
				cout << "������Ҫ��ѯ�Ķ����ţ�" << endl;
				string s_ani_num;
				cin >> s_ani_num;
				for (int i = 0; i < ani_class[x - 1]->get_class_num(); i++)
				{
					if (ani_class[x - 1]->get_ani_num(i) == s_ani_num)
					{
						cout << "����" << "\t" << "���" << "\t" << "����" << "\t" << "����" << "\t" << "��Ϣ����" << endl;
						ani_class[x - 1]->show_ani(i);
						flag = 0;
						break;
					}
				}
			}
			else
			{
				cout << "��������" << endl;
				cout << "���������밴��1��" << endl;
				cout << "�˳������밴��2��" << endl;
				cin.sync();
				char ch_choice = getchar();
				if (ch_choice == '2')
					break;
			}
		}
	}
	if (ch_check == '2')				//�鿴ÿ�ද�����Ϣ
	{
		show_class_outline(ani_class, *ani_class_num);
		while (1)
		{
			cout << "������Ҫ��ѯ�����ֱ�ţ�" << endl;
			int x;
			cin >> x;
			if (x >= 1 && x <= *ani_class_num)
			{
				ani_class[x - 1]->show();
				break;
			}
			else
			{
				cout << "��������" << endl;
				cout << "���������밴��1��" << endl;
				cout << "�˳������밴��2��" << endl;
				cin.sync();
				char ch_choice = getchar();
				if (ch_choice == '2')
					break;
			}
		}

	}
	if (ch_check == '3')				//�鿴ȫ���������Ϣ
	{
		show_all(ani_class, ani_class_num, ani_num_sum);
	}
}

//���Ӷ���
void add_fun(Animal_class *ani_class[], int *ani_class_num, int *ani_num_sum)
{
	cout << "����������Ӷ����밴��A��" << endl;
	cout << "��ԭ������������밴��B��" << endl;
	cin.sync();
	char ch_add = getchar();
	if (ch_add == 'a' || ch_add == 'A')			//���½�����������Ӷ���
	{
		int flag = 1;
		string class_name;
		while (flag == 1 || flag == 2)
		{
			flag = 1;
			cout << "���������ֵ����ƣ�" << endl;
			cin >> class_name;
			for (int i = 0; i < *ani_class_num; i++)
			{
				if (class_name == ani_class[i]->get_class_name())
				{
					cout << "����԰���и������Ƿ��������Y/N" << endl;
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
				cout << "ȷ��Ҫ���Ӷ�������Y|N��" << endl;
				cin.sync();
				char ch_add_class = getchar();
				if (ch_add_class == 'Y' || ch_add_class == 'y')
				{
					ani_class[(*ani_class_num)++] = create_class(class_name, ani_class, *ani_class_num);
					(*ani_num_sum)++;
					cout << "��ӳɹ���" << endl;
					flag = 0;
					break;
				}
				else if (ch_add_class == 'N' || ch_add_class == 'n')
				{
					delete ani_class[*ani_class_num];
					ani_class[*ani_class_num] = NULL;
					cout << "�������Ӷ�������" << endl;
					flag = 0;
					break;
				}
				else
					cout << "�����������������룡" << endl;
			}

		}

	}
	else if (ch_add == 'b' || ch_add == 'B')		//�����е�����������Ӷ���
	{
		show_class_outline(ani_class, *ani_class_num);
		cout << "��ѡ��Ҫ�������ֵı�ţ�" << endl;
		int i;
		cin >> i;
		if (i >= 1 && i <= *ani_class_num)
		{
			Animal *a_add = create(ani_class, *ani_class_num);
			ani_class[i - 1]->add(a_add);
			cout << "ȷ��Ҫ���Ӷ���Y|N��" << endl;
			cin.sync();
			char ch_add_Animal = getchar();
			while (1)
			{
				if (ch_add_Animal == 'Y' || ch_add_Animal == 'y')
				{
					(*ani_num_sum)++;
					cout << "��ӳɹ���" << endl;
					break;
				}
				else if (ch_add_Animal == 'N' || ch_add_Animal == 'n')
				{
					delete ani_class[i - 1];
					ani_class[i - 1] = NULL;
					cout << "�������Ӷ�������" << endl;
					break;
				}
				else
				{
					cout << "�����������������룡" << endl;
					cout << "ȷ��Ҫ���Ӷ�������Y|N��" << endl;
				}
				cin.sync();
				ch_add_Animal = getchar();
			}
		}
		else
		{
			cout << "û����Ҫ�ҵ����֣�" << endl;
		}

	}
}

//ɾ������
void del_fun(Animal_class *ani_class[], int *ani_class_num, int *ani_num_sum)
{
	if (*ani_class_num != 0)
	{
		show_class_outline(ani_class, *ani_class_num);				//��ʾ������Ϣ
		cout << "ɾ�������밴��A��" << endl;
		cout << "ɾ���������֡�B��" << endl;
		cin.sync();
		int ch_del = getchar();
		if (ch_del == 'A' || ch_del == 'a')
		{
			cout << "��������Ҫɾ���Ķ������ڵ����ֱ�ţ�" << endl;
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
				cout << "��������" << endl;
		}
		else if (ch_del == 'B' || ch_del == 'b')
		{
			cout << "��������Ҫɾ�������ֵı�ţ�" << endl;
			int x;
			cin.sync();
			cin >> x;
			if (x >= 1 && x <= *ani_class_num)
			{
				cout << "ȷ��Ҫɾ����������Y/N?" << endl;
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
						cout << "����ɾ����������" << endl;
						break;
					}
					else
					{
						cout << "ȷ��Ҫɾ����������Y/N?" << endl;
						cin.sync();
						ch_del_judge = getchar();

					}

				}
			}
			else
				cout << "��������" << endl;
		}//ɾ������
	}//ani_class_num != 0
	else
	{
		cout << "����԰��û�ж������ɾ����" << endl;
	}
}

//�޸Ķ�����Ϣ
void revise_fun(Animal_class *ani_class[], int *ani_class_num, int *ani_num_sum)
{
	if (*ani_class_num == 0)
		cout << "����԰��û�ж��" << endl;
	else
	{
		show_all(ani_class, ani_class_num, ani_num_sum);
		cout << "������Ҫ�޸ĵĶ���ı�ţ�" << endl;
		string s_ani_num;
		cin >> s_ani_num;
		int flag = 1;
		int record_i;					//��¼Ҫ�޸ĵĶ���������Ľű�
		int record_j;					//��¼Ҫ�޸ĵĶ��������еĽű�
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
		cout << "������Ҫ�޸ĵ���Ŀ�ı�ţ�" << endl;
		cout << "1.����" << endl;
		cout << "2.���" << endl;
		cout << "3.����" << endl;
		cout << "4.����" << endl;
		cout << "5.��Ϣ����" << endl;
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
			cout << "��������ĺ����Ե�����:" << endl;
			cin >> attribute;
			ani_class[record_i]->ani_set_att(attribute, record_j);
			break;
		case '2':
		{
			int flag = 1;
			while (flag == 1)
			{
				cout << "��������ĺ��ŵ�����:";
				cin >> num;
				for (int i = 0; i < *ani_class_num; i++)
				{
					for (int j = 0; j < ani_class[i]->get_class_num(); j++)
					{
						if (num == ani_class[i]->get_ani_num(j))
						{
							cout << "����԰������ͬ��ŵĶ��" << endl;
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
			cout << "��������ĺ�����������:" << endl;
			cin >> name;
			ani_class[record_i]->ani_set_name(name, record_j);
			break;
		case '4':
			cout << "��������ĺ�����(����)������:" << endl;
			cin >> age;
			ani_class[record_i]->ani_set_age(age, record_j);
			break;
		case '5':
			cout << "��������ĺ���Ϣ���ܵ�����" << endl;
			cin >> info;
			ani_class[record_i]->ani_set_info(info, record_j);
			break;
		default:
			cout << "��������" << endl;
		}
		cout << "�޸ĳɹ���" << endl;
	}//����԰���ж���ʱ
}

//���湦��
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
	cout << "����ɹ���" << endl;
}

//���빦��
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
	int ani_class_num = 0;						//��¼��ĸ���
	int ani_num[MAX_ANIMAL] = { 0 };			//��¼ÿ�ද�����ж���ĸ���
	int ani_num_sum = 0;						//��¼��������

	//�����ļ�
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
				cout << "�˳��ÿ�ģʽ����л����ʹ�ã�" << endl;
				break;
			}
			else
				cout << "�����������������룡" << endl;
			system("pause");
		}
		if (ch_mode == '2' && entry())
		{
			while (1)
			{
				welcome_admin();
				cin.sync();
				char ch_admin = getchar();
				if (ch_admin == 'S' || ch_admin == 's')											//�鿴������Ϣ
				{
					search_fun(ani_class, &ani_class_num, &ani_num_sum);
				}
				else if (ch_admin == 'A' || ch_admin == 'a')									//���Ӷ���
				{
					add_fun(ani_class, &ani_class_num, &ani_num_sum);
				}
				else if (ch_admin == 'D' || ch_admin == 'd')									//ɾ������
				{
					del_fun(ani_class, &ani_class_num, &ani_num_sum);
				}
				else if (ch_admin == 'R' || ch_admin == 'r')									//�޸���Ϣ
				{
					revise_fun(ani_class, &ani_class_num, &ani_num_sum);
				}
				else if (ch_admin == 'P' || ch_admin == 'p')									//������Ϣ
				{
					save_fun(ani_class, &ani_class_num, &ani_num_sum);
				}
				else if (ch_admin == 'Q' || ch_admin == 'q')									//�˳�
				{
					while (1)
					{
						cout << "�Ƿ񱣴浱ǰ����Y|N��" << endl;
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
							cout << "��������" << endl;
					}
					cout << "�˳�����Աģʽ����л����ʹ�ã�" << endl;
					break;
				}
				else if (ch_admin == 'C' || ch_admin == 'c')
				{
					system("cls");
				}
				else
				{
					cout << "�����������������룡" << endl;
				}
			}
		}
		while (ch_mode == '3')
		{
			cout << "��л����ʹ�ã��ټ���" << endl;
			return 0;
		}
		if (ch_mode != '1' && ch_mode != '2' && ch_mode != '3')
		{
			cout << "�����������������룡" << endl;
		}
		system("pause");
	}
	system("pause");
	return 0;
}
