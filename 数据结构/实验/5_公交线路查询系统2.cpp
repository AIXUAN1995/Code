/*
��Ŀһ ����·�߲�ѯϵͳ
����������������ϵͳ��ÿ�����бر��Ĺ���������ʩ�����һ����������ϵͳ�Ƿǳ���Ҫ���������������Ŀ�����򵥵Ĺ�����·����Ͳ�ѯϵͳ��
������Ҫ�󡿴���Ŀ��Ҫ�������������ģ�顣
ģ��1 ������������·������������վ����Ϣ��
��1��վ�����  վ�����ģ��Ϊ�û��ṩ����վ�����ݵĲ�ѯ��Ϊ����Ա�ṩվ��ά��������վ����ӡ�������վ��������ӣ�վ���޸ġ�վ��ɾ���ȹ��ܡ�
��2����·����  ��·����ģ��Ϊ�û��ṩ������·���ݵĲ�ѯ���ṩ��·��ά����������·��ӡ���·�޸ġ���·ɾ���ȹ��ܡ�

ģ��2��ѯģ��
1.���ݹ�����·�ߺţ���ѯ�ù�������������վ�㣻
2.����վ�㣬��ѯ����Щ�����������ﾭ����
3.������������վ�㣬��ѯ����·��
��1�������ֱ��Ĺ��������������еĹ�����·�ߺţ�
��2�������Ҫת��������������̵Ļ��˷�����
��3�������Ҫת������������һ�λ��˷�����

*/
#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
using namespace std;
const int MAXROUTE = 10;		//��󹫽���·��
const int MAXSITE = 100;		//��󹫽�վ����
const int MAXSITEROUTE = 5;	//ÿ��վ����������Ĺ���·��


struct Site								//���ڽӾ��󴢴�վ��
{
	string name;						//վ������
	string route[MAXROUTE];				//ÿ��վ�����ڵ�·��
	int top;							//��¼ÿ��վ�����ڹ�����·�ĸ���
};
struct MGragh							//���ڽӾ��󴢴��ͼ����
{
	Site sites[MAXSITE];				//�����
	double edges[MAXSITE][MAXSITE];		//�ڽӾ���,�����д�ŵ�������վ��֮��ľ���
};
struct Route_Site						//������·�е�վ��
{
	int num;							//·���е�վ����ͼ�д�ŵ�λ��
	Route_Site *next;					//ָ���·���е���һ��վ��
	Route_Site *per;					//ֻ���·���е�ǰһ��վ��
};
struct Route							//������·�ṹ��
{
	string name;
	Route_Site *first;					//ָ��·�ߵ���ʼվ��
	Route_Site *last;					//ָ��·�ߵ��յ�վ
	int num;							//��¼��·��վ�������
};
//����������
void primary_menu();//�����˵�
void inquire_menu();//��ѯ
void site_info();
//����ģ��
bool land(string pw);
void manage_menu();
void site_manage_menu();
void route_manage_menu();
void create_route(MGragh *m, Route route[], int *n, int *n_route);
void add_site(MGragh *m, Route route[], int *n, int *n_route, string route_name, Route_Site *p, int r_num = -1);
int judge_site(MGragh *m, int *n, string name);
char judge_site(MGragh *m, int *n, string route_name, string site_name, int *site_script);
void site_relation(MGragh *m, Route_Site *rs1, Route_Site *rs2);
int judge_route(Route route[], int *n_route, string route_name);
Route_Site *insert_position(MGragh *m, Route route[], int r_num);
void revise_site_info(MGragh *m, int script);
void update_route_site_script(Route *route, int script);
void del_site(MGragh *m, Route route[], int *n, int *n_route, int script);
void revise_route(MGragh *m, Route route[], int *n, int *n_route);
void del_route_site(MGragh *m, Route *route, int del_site_num);
void del_route(MGragh *m, Route route[], int *n_route);
//��ѯģ��
void display_site_info(MGragh *m, int script);
void display_route(Route route[], int *n_route);
void display_site(MGragh *m, Route_Site *rs);
void display_all_site(MGragh *m, int *n);
void ShortesPath(MGragh *m, Route route[], int *n_route, int P[MAXSITE], double D[MAXSITE], int script1, int script2);
void inquire(MGragh *m, Route route[], int *site_sum, int *route_sum);

//������·ͬʱ��վ�����ͼ��
void create_route(MGragh *m, Route route[], int *n, int *n_route)
{//*nΪվ�����,*n_routeΪ·����
	int flag = 1;							//��Ϊ����ѭ���ı�Ǳ���
	while (flag)							//ѭ��������·
	{
		cout << "����Ҫ������·�����ƣ��˳��밴0����" << endl;
		string route_name;
		cin >> route_name;
		if (route_name == "0")
		{
			cout << "����·�ߵĴ�����" << endl;
			return;
		}

		//ȷ���Ƿ񴴽�·��
		char ch_create_route;
		cout << "ȷ�ϴ���·��Y|N?" << endl;
		cin.sync();
		ch_create_route = getchar();
		if (ch_create_route == 'N' || ch_create_route == 'n')
		{
			cout << "ȡ������·�ߣ�" << endl;
			continue;
		}

		//�ж�·���Ƿ����
		for (int i = 0; i < *n_route; i++)
		{
			if (route[i].name == route_name)
			{
				cout << "����·�Ѿ����ڣ�" << endl;
				system("pause");
				flag = 0;
				break;
			}
		}
		if (flag == 0)
			continue;
		route[*n_route].name = route_name;					//��·�����ƴ��빫����·�ṹ������
		route[*n_route].first = route[*n_route].last = NULL;//����·����βָ��ָ���
		route[*n_route].num = 0;
		//��·�������վ��
		add_site(m, route, n, n_route, route_name, route[*n_route].last);
		(*n_route)++;
	}//ѭ��������·

}

//���վ�㹦��
void add_site(MGragh *m, Route route[], int *n, int *n_route, string route_name, Route_Site *p, int r_num)
{//��ͼ�����վ�㣬*nΪվ�����,*n_routeΪ·������ route_nameΪ·�����ƣ�*p��¼Ҫ����λ�õ�ǰ���ڵ�
	int site_script1 = 0, site_script2 = 0;						//���Ҫ������ϵ������ű�
	while (1)
	{
		char ch_change = 'C';					//�ж��Ƿ��޸�ԭ��վ����Ϣ
		string site_name;
		cout << "����վ�����ƣ�" << endl;
		cin >> site_name;

		//�ж�վ���Ƿ����
		ch_change = judge_site(m, n, route_name, site_name, &site_script1);

		if (ch_change == 'Y' || ch_change == 'y')//ͼ���и�վ�㣬�Ը�վ�����Ϣ���и���
		{
			m->sites[site_script1].route[m->sites[site_script1].top++] = route_name;
		}
		else if (ch_change == 'N' || ch_change == 'n')//����ԭ����Ϣ�����޸�
			break;
		else if (ch_change == 'A')//·�������и�վ�㣬��������
			continue;
		else if (ch_change == 'B')//����0���˳����վ��
			break;
		else if (ch_change == 'C')//ͼ��û�и�վ�㣬�½�վ��
		{
			//�ж��Ƿ��������վ��
			char ch_create_site;
			cout << "ȷ�ϴ���վ��Y|N?" << endl;
			cin.sync();
			ch_create_site = getchar();
			if (ch_create_site == 'N' || ch_create_site == 'n')
			{
				cout << "�˳�����վ�㣡" << endl;
				break;
			}

			m->sites[*n].name = site_name;
			m->sites[*n].route[m->sites[*n].top++] = route_name;	//��¼����·������
			site_script1 = *n;
			(*n)++;
		}
		else
		{
			cout << "�����������������룡" << endl;
			continue;
		}
		Route_Site *rs = new Route_Site;
		rs->num = site_script1;
		rs->per = rs->next = NULL;
		if (!route[*n_route].first)							//��·���м����һ��վ��
		{
			route[*n_route].last = route[*n_route].first = rs;
			rs->next = rs->per = NULL;
			p = route[*n_route].first;
			route[*n_route].num++;
		}
		else if (!p)		//�����վ����Ϊ��һվ
		{
			rs->next = route[r_num].first;
			route[r_num].first = rs;
			route[r_num].num++;
			site_relation(m, rs, rs->next);
		}
		else
		{
			rs->per = p;										//��β������
			if (p->next)			//���pָ��ջᱨ��
			{
				rs->next = p->next;
				p->next->per = rs;
				site_relation(m, rs, rs->next);
			}
			p->next = rs;
			p = p->next;
			route[*n_route].num++;
			site_relation(m, rs, rs->per);
		}
	}//ѭ������վ��
}

int judge_site(MGragh *m, int *n, string name)
{
	for (int i = 0; i < *n; i++)
	{
		if (m->sites[i].name == name)
			return i;
	}
	return -1;
}

//�ж�վ���Ƿ���ں��Ƿ��޸���Ϣ
char judge_site(MGragh *m, int *n, string route_name, string site_name, int *site_script)
{
	char ch_change = 'C';
	if (site_name == "0")
		return 'B';
	for (int i = 0; i < *n; i++)
	{
		if (site_name == m->sites[i].name)//���ͼ���Ѿ���վ��
		{
			for (int j = 0; j < m->sites[i].top; j++)
			{
				if (m->sites[i].route[j] == route_name)
				{
					cout << "��·�����Ѿ����ڸ�վ�㣡" << endl;
					ch_change = 'A';
					return ch_change;
				}
			}

			cout << "��վ���Ѵ��ڣ��Ƿ�Ҫ�޸�վ����ϢY|N?" << endl;
			*site_script = i;
			cin.sync();
			ch_change = getchar();
			return ch_change;
		}
	}
	return ch_change;
}

//��������վ��֮��Ĺ�ϵ
void site_relation(MGragh *m, Route_Site *rs1, Route_Site *rs2)
{
	cout << "������" << m->sites[rs1->num].name << "վ��" << m->sites[rs2->num].name << "վ֮��ľ��룺" << endl;
	int distance;
	cin >> distance;
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
			cin >> distance;
		}
	}
	m->edges[rs1->num][rs2->num] = m->edges[rs2->num][rs1->num] = distance;
}

//�ж�·���Ƿ����
int judge_route(Route route[], int *n_route, string route_name)
{
	for (int i = 0; i < *n_route; i++)
	{
		if (route[i].name == route_name)
			return i;
	}
	return -1;

}

//�ҵ�Ҫ����ڵ��λ��
Route_Site *insert_position(MGragh *m, Route route[], int r_num)
{//����ֵΪҪ����λ�õ�ǰһ��վ���ָ��
	int per;
add_s:
	cout << "��ѡ����Ҫ��ӵ�վ���λ�ã�ѡ��Ҫ���վ���ǰһվ�ı�ż��ɣ����뵽��ǰ������0����" << endl;
	display_site(m, route[r_num - 1].first);
	cout << "ǰһվ�ı�ţ�";
	cin >> per;
	if (per<0 || per > route[r_num - 1].num)
	{
		cout << "û����Ҫ�����λ��,��ȷ�Ϻ����������룡" << endl;
		goto add_s;
	}
	Route_Site *rs = route[r_num - 1].first;
	for (int i = 1; i < per; i++)
	{
		rs = rs->next;
	}
	if (per == 0)
		return NULL;
	return rs;
}

//�޸�վ����Ϣ
void revise_site_info(MGragh *m, int script)
{//numΪҪ�޸���Ϣ��վ��ı��
	cout << "�������޸�֮������֣�" << endl;
	string name;
	cin >> name;
	while (1)
	{
		cout << "ȷ��Ҫ�޸�վ����ϢY|N?" << endl;
		cin.sync();
		char ch_revise_site_info = getchar();
		if (ch_revise_site_info == 'Y' || ch_revise_site_info == 'y')
		{
			m->sites[script - 1].name = name;
			cout << "�޸ĳɹ���" << endl;
			break;
		}
		else if (ch_revise_site_info == 'N' || ch_revise_site_info == 'n')
		{
			cout << "�˳��޸�վ����Ϣ��" << endl;
			break;
		}
	}

}

//ɾ��ͼ��վ��
void del_site(MGragh *m, Route route[], int *n, int *n_route, int script)
{//scriptΪҪɾ����վ����ͼ�еĽű�
	for (int i = 0; i < m->sites[script].top; i++)//����·�н�վ��ɾ��
	{
		for (int j = 0; j < *n_route; j++)
		{
			if (m->sites[script].route[i] == route[j].name)
			{
				int del_site_num = 1;
				Route_Site *rs = route[j].first;
				while (rs->num != script)
				{
					del_site_num++;
					rs = rs->next;
				}
				del_route_site(m, &route[j], del_site_num);//��·���н�վ��ɾ��
				route[j].num--;
			}
		}
	}

	for (int i = script; i < (*n) - 1; i++)//����վ��Ӵ���վ���������ɾ��
		m->sites[i] = m->sites[i + 1];
	for (int i = 0; i < *n; i++)//���ڵ���ڽӾ�����ɾ��
	{
		for (int j = script; j < (*n) - 1; j++)
		{
			m->edges[i][j] = m->edges[i][j + 1];
		}
	}
	for (int i = 0; i < (*n) - 1; i++)//���ڵ���ڽӾ�����ɾ��
	{
		for (int j = script; j < (*n) - 1; j++)
		{
			m->edges[j][i] = m->edges[j + 1][i];
		}
	}
	for (int i = 0; i < *n; i++)//���ù����ڴ�ռ�����Ϊ���ֵ
	{
		m->edges[i][*n] = m->edges[*n][i] = INFINITY;
	}
	(*n)--;//վ������һ
	for (int i = 0; i < *n_route; i++)
		update_route_site_script(&route[i], script);
}


//�޸�·�߹���
void revise_route(MGragh *m, Route route[], int *n, int *n_route)
{
	display_route(route, n_route);
	cout << "��ѡ��Ҫ������·��" << endl;
	int r_num;											//���Ҫ������·��id
	cin >> r_num;
	if (r_num <= 0 || r_num > *n_route)
	{
		cout << "û��Ҫ������·�ߣ�" << endl;
		system("pause");
		return;
	}
	cout << "��ѡ�����" << route[r_num - 1].name << "��·��" << endl;
	cout << "��ѡ������Ҫ�Ĳ���" << endl;
	cout << "1.���վ��" << endl;
	cout << "2.ɾ��վ��" << endl;
	char ch_rev_route;
	cin.sync();
	ch_rev_route = getchar();
	if (ch_rev_route == '1')
	{
		Route_Site *rs = insert_position(m, route, r_num);
		add_site(m, route, n, n_route, route[r_num - 1].name, rs, r_num - 1);
	}
	else if (ch_rev_route == '2')
	{
		cout << "ѡ����Ҫɾ����վ��:" << endl;
		display_site(m, route[r_num - 1].first);
		int del_site_num;
		cin >> del_site_num;
		if (del_site_num > 0 && del_site_num <= route[r_num - 1].num)
		{
			cout << "ȷ��ɾ��վ��Y|N?" << endl;
			cin.sync();
			char ch_del_route_site = getchar();
			if (ch_del_route_site == 'Y' || ch_del_route_site == 'y')
			{
				del_route_site(m, &route[r_num - 1], del_site_num);
			}
			else
			{
				cout << "�˳�ɾ��վ�������" << endl;
				system("pause");
			}
		}
		else
		{
			cout << "û����Ҫɾ����վ�㣡" << endl;
			system("pause");
		}
	}

}

//����·����վ���������еĽű�
void update_route_site_script(Route *route, int script)
{
	Route_Site *rs = route->first;
	for (int i = 0; i < route->num; i++)
	{
		if (rs->num > script)
			rs->num--;
		rs = rs->next;
	}
}

//ɾ��·���е�վ��
void del_route_site(MGragh *m, Route *route, int del_site_num)
{
	Route_Site *rs, *p;
	p = route->first;
	if (del_site_num == 1)
	{
		route->first = route->first->next;
		delete p;
		return;
	}
	for (int i = 1; i < del_site_num - 1; i++)
	{
		p = p->next;
	}
	rs = p;
	p = p->next;
	rs->next = p->next;
	if (p->next)
		p->next->per = rs;
	for (int i = 0; i < m->sites[p->num].top; i++)
	{
		if (m->sites[p->num].route[i] == route->name)//��վ����Ϣ��ɾ����ŵ�·����Ϣ
		{
			for (int j = i; j < m->sites[p->num].top - 1; j++)
				m->sites[p->num].route[j] = m->sites[p->num].route[j + 1];
			m->sites[p->num].top--;
		}
	}
	delete p;			//��ֻ�ǰ�·���е�ɾ���ˣ�ͼ�еĹ�ϵ��û�н��
}


//ɾ��·��
void del_route(MGragh *m, Route route[], int *n_route)
{
	Route_Site *rs, *del_rs = NULL;
	cout << "����·�����£�" << endl;
	display_route(route, n_route);
	cout << "��ѡ����Ҫɾ����·�߱�ţ�" << endl;
	int route_num;
	cin >> route_num;
	if (route_num <= 0 || route_num > *n_route)
	{
		cout << "û����Ҫɾ����·�ߣ�" << endl;
		system("pause");
		return;
	}
	cout << "ȷ��ɾ����·��ôY|N?" << endl;
	cin.sync();
	char ch_del_route = getchar();
	if (ch_del_route == 'N' || ch_del_route == 'n')
	{
		cout << "��ȡ����ɾ��·�ߣ�" << endl;
		system("pause");
		return;
	}
	for (rs = route[route_num - 1].first; rs; rs = rs->next)
	{
		delete del_rs;
		for (int i = 0; i < m->sites[rs->num].top; i++)
		{
			if (m->sites[rs->num].route[i] == route[route_num - 1].name)//��վ����Ϣ��ɾ����ŵ�·����Ϣ
			{
				for (int j = i; j < m->sites[rs->num].top - 1; j++)
					m->sites[rs->num].route[j] = m->sites[rs->num].route[j + 1];
				m->sites[rs->num].top--;
			}
		}
		del_rs = rs;
	}
	delete del_rs;
	for (int i = route_num; i < *n_route; i++)//����·����Ϣ�Ӵ���·�ߵ�������ɾ��
		route[i - 1] = route[i];
	(*n_route)--;
}

//��ѯ����
//��ӡվ����Ϣ
void display_site_info(MGragh *m, int script)
{
	cout << "վ�����ƣ�" << m->sites[script].name << endl;
	cout << "վ������·�ߣ�";
	for (int i = 0; i < m->sites[script].top; i++)
		cout << m->sites[script].route[i] << " ";
}
//��ӡ·������
void display_route(Route route[], int *n_route)
{
	cout << "����һ����·��" << endl;
	for (int i = 0; i < *n_route; i++)
		cout << i + 1 << "." << route[i].name << " ";
	cout << endl;
}

//��ӡ·���е�վ������
void display_site(MGragh *m, Route_Site *rs)
{

	int site_num = 1;
	while (rs)
	{
		cout << site_num++ << "." << m->sites[rs->num].name << " ";
		rs = rs->next;
	}
	cout << endl;
}
//��ӡ��ͼ������վ��
void display_all_site(MGragh *m, int *n)
{
	for (int i = 0; i < *n; i++)
	{
		cout << i + 1 << "." << m->sites[i].name << " ";
	}
	cout << endl;
}
//���·��
void ShortesPath(MGragh *m, Route route[], int *n_route, int P[MAXSITE], double D[MAXSITE], int script1, int script2)
{
	/*
	��ԭ��Ϊ����0�������ඥ������·��
	D[v]��Ŵ�Դ�㶥�㵽�յ�v�����·������
	P[v]�����Ӧ�����·���յ��ǰ����
	script1Ϊ������ű�
	script2ΪĿ�ĵؽű�
	����INFINITY��Ϊ�ڽӾ����е�������
	*/
	int final[MAXSITE] = { 1, 0 };
	for (int i = 0; i < MAXSITE; i++)
	{
		D[i] = m->edges[script1][i];
		P[i] = script1;
	}
	D[script1] = 0;
	final[script1] = 1;
	P[script1] = -1;							//��ʼ����ԭ������s��
	for (int i = 1; i < MAXSITE; i++)
	{
		/*
		��ʼ��ѭ����ÿ�����Դ�㵽ĳ������k�����·��������k��s��
		*/
		double min = INFINITY + 1;
		int j = script1;
		for (int k = 0; k < MAXSITE; k++)
		{
			if (final[k] == 0 && D[k] < min)
			{
				j = k;
				min = D[k];
			}
		}
		final[j] = 1;						//������j���뵽s������
		for (int k = 0; k < MAXSITE; k++)	//��������û����s�ĵ�ĵ�ǰ���·��������
		{
			if (final[k] == 0 && D[j] + m->edges[j][k] < D[k])
			{
				D[k] = D[j] + m->edges[j][k];	//��D[k]�޸�Ϊ���̵�·�� 
				P[k] = j;						//�����Ӧ��·������k��ǰ������Ϊj
			}
		}
	}
	string route1, route2;						//�����Ⱥ��·��
	int change = -1;								//���˵�վ��
	int change_route;							//��¼�����Ժ��·�ߣ�����ȷ������ǰ��·��ѭ������
	int change_route1, change_route2;			//����ǰ�����·���ڻ���վ����·�������е�λ��
	int flag_change = 0;						//0��ʾû��һ�λ��˵�վ��
	int flag1 = 0, flag2 = 0;					//��¼�����Ⱥ��ǲ��Ƕ������·��
	for (int i = 0; i < m->sites[script2].top; i++)
	{
		int script = P[script2];					//��ʱ���ǰ��վ��ű�
		int flag = 0;
		while (script != -1)
		{
			int j;
			for (j = 0; j < m->sites[script].top; j++)
			{
				if (m->sites[script2].route[i] == m->sites[script].route[j])//�������·����˳��������ҵ����˵�վ��
				{
					flag = 1;
					change = script;
					change_route = j;
					break;
				}
			}
			if (j == m->sites[script].top)//����������վ���·�߽��бȽ��Ժ�û����ͬ��·�ߣ���һվӦ��Ϊ����վ��
				flag = 0;
			if (flag == 0)
			{
				route2 = m->sites[script2].route[i];//��¼�ӻ���վ�㵽Ŀ�ĵص�·��
				break;
			}
			script = P[script];
		}
		if (change == -1)//�յ�վ��ǰ��վ����û��m->sites[script2].route[i]վ
			continue;


		//����·�߶�Ӧ������
		change_route2 = judge_route(route, n_route, m->sites[script2].route[i]);
		//�ж��ǲ������·��
		Route_Site *p_rs = route[change_route2].first;
		int p_num = script2;
		while (1)		//�ҵ��յ�վ����·���е�λ��
		{
			if (p_rs->num == script2)
				break;
			p_rs = p_rs->next;
		}
		Route_Site *p_rs_record2 = p_rs;
		while (p_rs->per)
		{
			if (p_rs->per->num != P[p_num])
				break;
			p_rs = p_rs->per;
			p_num = P[p_num];

		}
		if (p_num != change)
		{
			p_num = script2;
			p_rs = p_rs_record2;
			while (1)
			{
				if (p_rs->next->num != P[p_num])
					break;
				p_rs = p_rs->next;
				p_num = P[p_num];

			}
		}


		for (int k = 0; k < m->sites[change].top; k++)
		{
			if (change_route == k)
				continue;
			while (script != -1)
			{
				int j;
				for (j = 0; j < m->sites[script].top; j++)
				{
					if (m->sites[change].route[k] == m->sites[script].route[j])
					{
						flag = 1;
						break;
					}
				}
				if (j == m->sites[script].top)
					flag = 0;
				if (flag == 0)
				{
					break;
				}
				route1 = m->sites[change].route[k];
				script = P[script];
			}

			if (script == -1)
			{
				//����·�߶�Ӧ������
				change_route1 = judge_route(route, n_route, m->sites[change].route[k]);
				Route_Site *p_rs1 = route[change_route1].first;
				int p_num1 = change;
				while (1)		//�ҵ�����վ����·���е�λ��
				{
					if (p_rs1->num == change)
						break;
					p_rs1 = p_rs1->next;
				}
				Route_Site *p_rs_record1 = p_rs1;
				while (p_rs1->per)
				{
					if (p_rs1->per->num != P[p_num1])
						break;
					p_rs1 = p_rs1->per;
					p_num1 = P[p_num1];

				}
				if (p_num1 != script1)
				{
					p_num1 = change;
					p_rs1 = p_rs_record1;
					while (p_rs1->next)
					{
						if (p_rs1->next->num != P[p_num1])
							break;
						p_rs1 = p_rs1->next;
						p_num1 = P[p_num1];

					}
				}
				if (p_num1 == script1 && p_num == change)//�����·��
				{
					cout << "��" << route1 << "·��" << m->sites[change].name << "վ����" << route2 << "·(���)" << endl;
				}
				else
					cout << "��" << route1 << "·��" << m->sites[change].name << "վ����" << route2 << "·" << endl;
				flag_change = 1;
			}
			script = P[change];
		}
	}
	if (flag_change == 0)
		cout << "û��ֱ���һ�λ��˵�·�ߣ�" << endl;
}


//�����˵�
void primary_menu()
{
	cout << "**********************" << endl;
	cout << "��ѡ������Ҫ�Ĳ�����" << endl;
	cout << "1.��ѯ" << endl;
	cout << "2.����" << endl;
	cout << "3.�˳�" << endl;
	cout << "**********************" << endl;
}
//��ѯģ��
void inquire_menu()
{
	cout << "*****************************" << endl;
	cout << "��ѡ������Ҫ�Ĳ�����" << endl;
	cout << "1.��ѯ��������·" << endl;
	cout << "2.��ѯվ����Ϣ" << endl;
	cout << "3.��ѯ����վ��֮��Ĺ�����·" << endl;
	cout << "4.�����ϼ��˵�" << endl;
	cout << "*****************************" << endl;
}
void site_info()
{
	cout << "*****************************" << endl;
	cout << "��ѡ������Ҫ�Ĳ�����" << endl;
	cout << "1.����Ų���" << endl;
	cout << "2.����������" << endl;
	cout << "3.�����ϼ��˵�" << endl;
	cout << "*****************************" << endl;
}

//����ģ��
bool land(string pw)
{
	cout << "����������:" << endl;
	string password;
	for (int i = 0; i < 3; i++)
	{
		cin >> password;
		if (password == pw)
		{
			system("cls");
			cout << "��½�ɹ���" << endl;
			Sleep(1000);
			system("cls");
			return true;
		}
		cout << "��������!" << endl;
		cout << "������" << 2 - i << "���������" << endl;
	}
	return false;
}
void manage_menu()
{
	cout << "*************************" << endl;
	cout << "��ѡ������Ҫ�Ĳ�����" << endl;
	cout << "1.��Ϣ��ѯ" << endl;
	cout << "2.վ�����" << endl;
	cout << "3.��·����" << endl;
	cout << "4.�޸�����" << endl;
	cout << "5.������Ϣ" << endl;
	cout << "6.�����ϼ��˵�" << endl;
	cout << "*************************" << endl;
}
void site_manage_menu()
{
	cout << "*************************" << endl;
	cout << "��ѡ������Ҫ�Ĳ�����" << endl;
	cout << "1.���վ��" << endl;
	cout << "2.�޸�վ��" << endl;
	cout << "3.ɾ��վ��" << endl;
	cout << "4.�����ϼ��˵�" << endl;
	cout << "*************************" << endl;
}
void route_manage_menu()
{
	cout << "**************************" << endl;
	cout << "��ѡ������Ҫ�Ĳ�����" << endl;
	cout << "1.�����·" << endl;
	cout << "2.�޸���·" << endl;
	cout << "3.ɾ����·" << endl;
	cout << "4.�����ϼ��˵�" << endl;
	cout << "**************************" << endl;
}

//��ѯ����
void inquire(MGragh *m, Route route[], int *site_sum, int *route_sum)
{
	while (1)									//��ѯģʽ
	{
		system("cls");
		inquire_menu();
		cin.sync();
		char ch_inquire = getchar();
		if (ch_inquire == '1')									//��ѯ��������·
		{
			for (int i = 0; i < *route_sum; i++)
			{
				cout << route[i].name << "·��" << endl;
				display_site(m, route[i].first);
			}
			system("pause");
		}
		else if (ch_inquire == '2')								//��ѯվ����Ϣ
		{
			system("cls");
			site_info();
			cin.sync();
			char ch_site_info = getchar();
			if (ch_site_info == '1')				//������Ų���
			{
				display_all_site(m, site_sum);
				cout << "������Ҫ��ѯվ��ı�ţ�" << endl;
				cin.sync();
				int num;
				cin >> num;
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
						cin >> num;
					}
				}
				if (num >= 1 && num <= *site_sum)
					display_site_info(m, num - 1);
				else
					cout << "û��Ҫ��ѯ��վ�㣡" << endl;
			}
			else if (ch_site_info == '2')			//������������
			{
				cout << "������Ҫ��ѯ��վ�����ƣ�" << endl;
				string name;
				cin >> name;
				int num = -1;
				for (int i = 0; i < *site_sum; i++)
				{
					if (m->sites[i].name == name)
					{
						num = i;
						break;
					}
				}
				if (num == -1)
					cout << "û����Ҫ��ѯ��վ�㣡" << endl;
				else
					display_site_info(m, num);
			}
			system("pause");
		}
		else if (ch_inquire == '3')								//��ѯ����վ��֮��Ĺ�����·
		{
			int flag = 0;
			string start, end;
			int script1, script2;
			while (flag == 0)
			{
				cout << "��������ʼվ�����ƣ�" << endl;
				cin.sync();
				cin >> start;
				script1 = judge_site(m, site_sum, start);
				if (script1 == -1)
				{
					cout << "��վ�㲻���ڣ�" << endl;
					cout << "�Ƿ��������Y|N?" << endl;
					cin.sync();
					char ch_start = getchar();
					if (ch_start == 'Y' || ch_start == 'y')
						continue;
					else
						break;
				}
				flag = 1;
			}
			while (flag == 1)
			{
				cout << "������Ŀ�ĵ�վ�����ƣ�" << endl;
				cin.sync();
				cin >> end;
				script2 = judge_site(m, site_sum, end);
				if (script2 == -1)
				{
					cout << "��վ�㲻���ڣ�" << endl;
					cout << "�Ƿ��������Y|N?" << endl;
					cin.sync();
					char ch_start = getchar();
					if (ch_start == 'Y' || ch_start == 'y')
						continue;
					else
						break;
				}
				flag = 2;
			}
			if (flag == 2)//��ʼվ���Ŀ�ĵض�����
			{
				int flag_arrive = 0;
				for (int i = 0; i < m->sites[script1].top; i++)//Ѱ��ֱ��·��
				{
					for (int j = 0; j < m->sites[script2].top; j++)
					{
						if (m->sites[script1].route[i] == m->sites[script2].route[j])
						{
							cout << m->sites[script1].route[i] << "·ֱ�� ";
							flag_arrive = 1;
							break;
						}
					}
				}
				if (flag_arrive == 0)//û��ֱ��·��
				{
					int P[MAXSITE];//P[v]�����Ӧ�����·���յ��ǰ����
					double D[MAXSITE];//D[v]��Ŵ�Դ�㶥�㵽�յ�v�����·������
					ShortesPath(m, route, route_sum, P, D, script1, script2);
				}
			}
			cout << endl;
			system("pause");
		}
		else if (ch_inquire == '4')								//�����ϼ��˵�
			break;
		else
		{
			cout << "û����Ҫѡ��Ĳ�����" << endl;
			system("pause");
		}
	}
}
int main()
{
	MGragh m;													//��Ŷ������ڽӾ���
	for (int i = 0; i < MAXSITE; i++)							//�ڽӾ����ʼ��
	{
		for (int j = 0; j < MAXSITE; j++)
		{
			m.edges[i][j] = INFINITY;
		}
	}
	for (int i = 0; i < MAXSITE; i++)						//����վ�������Ĺ�����·����ʼ��Ϊ0
		m.sites[i].top = 0;
	Route route[MAXROUTE];										//·����Ϣ
	int site_sum = 0;												//վ����
	int route_sum = 0;												//·����
	string pw = "123456";									//��ʼ����
	//�ļ���ȡ
	ifstream infile;
	infile.open("route_manage.txt");
	infile >> site_sum >> route_sum;
	infile >> pw;
	for (int i = 0; i < route_sum; i++)
	{
		infile >> route[i].name;
		infile >> route[i].num;
		Route_Site *rs1 = new Route_Site;
		infile >> rs1->num;
		rs1->next = rs1->per = NULL;
		route[i].first = rs1;
		for (int j = 1; j < route[i].num; j++)
		{
			Route_Site *rs2 = new Route_Site;
			infile >> rs2->num;
			rs2->next = NULL;
			rs1->next = rs2;
			rs2->per = rs1;
			rs1 = rs2;
		}
	}
	for (int i = 0; i < site_sum; i++)
	{
		infile >> m.sites[i].name >> m.sites[i].top;
		for (int j = 0; j < m.sites[i].top; j++)
		{
			infile >> m.sites[i].route[j];
		}
	}
	for (int i = 0; i < site_sum; i++)
	{
		for (int j = 0; j < site_sum; j++)
		{
			infile >> m.edges[i][j];
		}
	}

	infile.close();


	while (1)
	{
		system("cls");
		primary_menu();
		cin.sync();
		char ch_primary = getchar();
		if (ch_primary == '1')								//��ѯģʽ
			inquire(&m, route, &site_sum, &route_sum);
		else if (ch_primary == '2')								//����ģʽ
		{
			bool flag = land(pw);
			while (flag)
			{
				system("cls");
				manage_menu();
				cin.sync();
				char ch_manage = getchar();
				if (ch_manage == '1')								//��ѯģʽ
					inquire(&m, route, &site_sum, &route_sum);
				while (ch_manage == '2')							//վ�����
				{
					system("cls");
					site_manage_menu();
					cin.sync();
					char ch_site_m = getchar();
					if (ch_site_m == '1')							//���վ��
					{
						display_route(route, &route_sum);
						cout << "������Ҫ��վ������·�ߺţ�" << endl;
						int route_num;
						cin >> route_num;
						//int route_num = judge_route(route, &route_sum, route_name);
						if (route_num > 0 && route_num <= route_sum)
						{
							Route_Site *rs = insert_position(&m, route, route_num);
							add_site(&m, route, &site_sum, &route_sum, route[route_num - 1].name, rs, route_num - 1);
						}
						else
						{
							cout << "��·�߲����ڣ�" << endl;
							system("pause");
						}
					}
					else if (ch_site_m == '2')						//�޸�վ��
					{
						display_all_site(&m, &site_sum);
						cout << "��������Ҫ�޸ĵ�վ��ı�ţ�" << endl;
						int script;
						cin >> script;
						if (script > 0 && script <= site_sum)
							revise_site_info(&m, script);
						else
						{
							cout << "û����Ҫ�޸ĵ�վ�㣡" << endl;
							system("pause");
						}

					}
					else if (ch_site_m == '3')						//ɾ��վ��
					{
						display_all_site(&m, &site_sum);
						cout << "��������Ҫɾ����վ��ı�ţ�" << endl;
						int script;
						cin >> script;
						if (script > 0 && script <= site_sum)
						{
							cout << "ȷ��ɾ��վ��Y|N?" << endl;
							cin.sync();
							char ch_del_site = getchar();
							if (ch_del_site == 'Y' || ch_del_site == 'y')
							{
								del_site(&m, route, &site_sum, &route_sum, script - 1);
							}
							else
							{
								cout << "�˳�ɾ��վ�������" << endl;
								system("pause");
							}
						}
						else
						{
							cout << "û����Ҫɾ����վ�㣡" << endl;
							system("pause");
						}
					}
					else if (ch_site_m == '4')
						break;
					else
					{
						cout << "��������Ҫѡ��Ĳ�����" << endl;
						system("pause");
					}
				}//վ�����
				while (ch_manage == '3')						//��·����
				{
					system("cls");
					route_manage_menu();
					cin.sync();
					char ch_route_manage = getchar();
					if (ch_route_manage == '1')					//���·��
					{
						create_route(&m, route, &site_sum, &route_sum);
					}
					else if (ch_route_manage == '2')			//�޸�·��
					{
						if (route_sum == 0)
						{
							cout << "û�п��޸ĵ�·�ߣ�" << endl;
							system("pause");
							continue;
						}

						revise_route(&m, route, &site_sum, &route_sum);
					}
					else if (ch_route_manage == '3')			//ɾ��·��
					{
						if (route_sum == 0)
						{
							cout << "û�п�ɾ����·�ߣ�" << endl;
							system("pause");
							continue;
						}

						del_route(&m, route, &route_sum);
					}
					else if (ch_route_manage == '4')			//�����ϼ��˵�
						break;
					else
					{
						cout << "��������Ҫѡ��Ĳ�����" << endl;
						system("pause");
					}
				}//·�߹���
				if (ch_manage == '4')//�޸�����
				{
					cout << "�����������룺" << endl;
					string pw_new;
					cin >> pw_new;
					while (1)
					{
						cout << "ȷ���޸�����Y|N��" << endl;
						cin.sync();
						char ch_pw = getchar();
						if (ch_pw == 'Y' || ch_pw == 'y')
						{
							pw = pw_new;
							cout << "�޸ĳɹ���" << endl;
							system("pause");
							break;
						}
						else if (ch_pw == 'N' || ch_pw == 'n')
						{
							cout << "�˳��޸����룡" << endl;
							system("pause");
							break;
						}
					}
				}
				else if (ch_manage == '5')//����Ϣ�����ļ�
				{
					//�ļ�д��
					ofstream outfile;
					outfile.open("route_manage.txt");
					outfile << site_sum << " " << route_sum << endl;
					outfile << pw << endl;
					for (int i = 0; i < route_sum; i++)
					{
						outfile << route[i].name << " " << route[i].num << endl;
						Route_Site *rs;
						rs = route[i].first;
						for (int j = 0; j < route[i].num; j++)
						{
							outfile << rs->num << " ";
							rs = rs->next;
						}
						outfile << endl;
					}
					for (int i = 0; i < site_sum; i++)
					{
						outfile << m.sites[i].name << " " << m.sites[i].top << endl;
						for (int j = 0; j < m.sites[i].top; j++)
						{
							outfile << m.sites[i].route[j] << " ";
						}
						outfile << endl;
					}
					for (int i = 0; i < site_sum; i++)
					{
						for (int j = 0; j < site_sum; j++)
						{
							outfile << m.edges[i][j] << " ";
						}
						outfile << endl;
					}
					outfile.close();

				}
				else if (ch_manage == '6')//�����ϼ��˵�
				{
					break;
				}
				else if (ch_manage != '1' && ch_manage != '2' && ch_manage != '3' && ch_manage != '4' && ch_manage != '5')
				{
					cout << "û����ѡ��Ĳ�����" << endl;
					system("pause");
				}
			}

			if (!flag)
			{
				system("cls");
				cout << "�����Ѿ�������Σ��޷���½,������Զ����أ�" << endl;
				Sleep(3000);
				system("cls");
			}
		}

		else if (ch_primary == '3')
		{
			cout << "��л����ʹ��!" << endl;
			break;
		}
		else
		{
			cout << "û����ѡ��Ĳ�����" << endl;
			system("pause");
		}
	}//�����˵�ѭ��

	system("pause");
	return 0;
}

