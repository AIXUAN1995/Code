/*
题目一 公交路线查询系统
【问题描述】公交系统是每个城市必备的公共服务设施，设计一个公交管理系统是非常重要的市政任务，这个题目建立简单的公交线路管理和查询系统。
【基本要求】此题目需要完成两个基本的模块。
模块1 建立公交车线路及其所经过的站点信息。
（1）站点管理  站点管理模块为用户提供公交站点数据的查询，为管理员提供站点维护，包括站点添加、和其它站点距离的添加，站点修改、站点删除等功能。
（2）线路管理  线路管理模块为用户提供公交线路数据的查询，提供线路的维护，包括线路添加、线路修改、线路删除等功能。

模块2查询模块
1.根据公交车路线号，查询该公交车所经过的站点；
2.根据站点，查询有哪些公交车从这里经过；
3.输入两个公交站点，查询公交路线
（1）如果有直达的公交车，给出所有的公交车路线号；
（2）如果需要转车，给出距离最短的换乘方案。
（3）如果需要转车，给出所有一次换乘方案。

*/
#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
using namespace std;
const int MAXROUTE = 10;		//最大公交线路数
const int MAXSITE = 100;		//最大公交站点数
const int MAXSITEROUTE = 5;	//每个站点最多所属的公交路数


struct Site								//用邻接矩阵储存站点
{
	string name;						//站点名称
	string route[MAXROUTE];				//每个站点所在的路线
	int top;							//记录每个站点所在公交线路的个数
};
struct MGragh							//以邻接矩阵储存的图类型
{
	Site sites[MAXSITE];				//顶点表
	double edges[MAXSITE][MAXSITE];		//邻接矩阵,矩阵中存放的是两个站点之间的距离
};
struct Route_Site						//公交线路中的站点
{
	int num;							//路线中的站点在图中存放的位置
	Route_Site *next;					//指向该路线中的下一个站点
	Route_Site *per;					//只想该路线中的前一个站点
};
struct Route							//公交线路结构体
{
	string name;
	Route_Site *first;					//指向路线的起始站点
	Route_Site *last;					//指向路线的终点站
	int num;							//记录线路中站点的数量
};
//函数声明：
void primary_menu();//初级菜单
void inquire_menu();//查询
void site_info();
//管理模块
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
//查询模块
void display_site_info(MGragh *m, int script);
void display_route(Route route[], int *n_route);
void display_site(MGragh *m, Route_Site *rs);
void display_all_site(MGragh *m, int *n);
void ShortesPath(MGragh *m, Route route[], int *n_route, int P[MAXSITE], double D[MAXSITE], int script1, int script2);
void inquire(MGragh *m, Route route[], int *site_sum, int *route_sum);

//创建线路同时把站点加入图中
void create_route(MGragh *m, Route route[], int *n, int *n_route)
{//*n为站点个数,*n_route为路线数
	int flag = 1;							//作为跳出循环的标记变量
	while (flag)							//循环创建线路
	{
		cout << "输入要创建的路线名称（退出请按0）：" << endl;
		string route_name;
		cin >> route_name;
		if (route_name == "0")
		{
			cout << "结束路线的创建！" << endl;
			return;
		}

		//确认是否创建路线
		char ch_create_route;
		cout << "确认创建路线Y|N?" << endl;
		cin.sync();
		ch_create_route = getchar();
		if (ch_create_route == 'N' || ch_create_route == 'n')
		{
			cout << "取消创建路线！" << endl;
			continue;
		}

		//判断路线是否存在
		for (int i = 0; i < *n_route; i++)
		{
			if (route[i].name == route_name)
			{
				cout << "该线路已经存在！" << endl;
				system("pause");
				flag = 0;
				break;
			}
		}
		if (flag == 0)
			continue;
		route[*n_route].name = route_name;					//将路线名称存入公交线路结构体数组
		route[*n_route].first = route[*n_route].last = NULL;//将线路的首尾指针指向空
		route[*n_route].num = 0;
		//向路线中添加站点
		add_site(m, route, n, n_route, route_name, route[*n_route].last);
		(*n_route)++;
	}//循环创建线路

}

//添加站点功能
void add_site(MGragh *m, Route route[], int *n, int *n_route, string route_name, Route_Site *p, int r_num)
{//向图中添加站点，*n为站点个数,*n_route为路线数， route_name为路线名称，*p记录要插入位置的前驱节点
	int site_script1 = 0, site_script2 = 0;						//存放要建立联系的数组脚标
	while (1)
	{
		char ch_change = 'C';					//判断是否修改原有站点信息
		string site_name;
		cout << "输入站点名称：" << endl;
		cin >> site_name;

		//判断站点是否存在
		ch_change = judge_site(m, n, route_name, site_name, &site_script1);

		if (ch_change == 'Y' || ch_change == 'y')//图中有该站点，对该站点的信息进行更改
		{
			m->sites[site_script1].route[m->sites[site_script1].top++] = route_name;
		}
		else if (ch_change == 'N' || ch_change == 'n')//不对原有信息进行修改
			break;
		else if (ch_change == 'A')//路线中已有该站点，不做操作
			continue;
		else if (ch_change == 'B')//输入0，退出添加站点
			break;
		else if (ch_change == 'C')//图中没有该站点，新建站点
		{
			//判断是否继续创建站点
			char ch_create_site;
			cout << "确认创建站点Y|N?" << endl;
			cin.sync();
			ch_create_site = getchar();
			if (ch_create_site == 'N' || ch_create_site == 'n')
			{
				cout << "退出创建站点！" << endl;
				break;
			}

			m->sites[*n].name = site_name;
			m->sites[*n].route[m->sites[*n].top++] = route_name;	//记录所在路线名称
			site_script1 = *n;
			(*n)++;
		}
		else
		{
			cout << "输入有误请重新输入！" << endl;
			continue;
		}
		Route_Site *rs = new Route_Site;
		rs->num = site_script1;
		rs->per = rs->next = NULL;
		if (!route[*n_route].first)							//在路线中加入第一个站点
		{
			route[*n_route].last = route[*n_route].first = rs;
			rs->next = rs->per = NULL;
			p = route[*n_route].first;
			route[*n_route].num++;
		}
		else if (!p)		//插入的站点作为第一站
		{
			rs->next = route[r_num].first;
			route[r_num].first = rs;
			route[r_num].num++;
			site_relation(m, rs, rs->next);
		}
		else
		{
			rs->per = p;										//从尾部插入
			if (p->next)			//如果p指向空会报错
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
	}//循环创建站点
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

//判断站点是否存在和是否修改信息
char judge_site(MGragh *m, int *n, string route_name, string site_name, int *site_script)
{
	char ch_change = 'C';
	if (site_name == "0")
		return 'B';
	for (int i = 0; i < *n; i++)
	{
		if (site_name == m->sites[i].name)//如果图中已经有站点
		{
			for (int j = 0; j < m->sites[i].top; j++)
			{
				if (m->sites[i].route[j] == route_name)
				{
					cout << "该路线中已经存在该站点！" << endl;
					ch_change = 'A';
					return ch_change;
				}
			}

			cout << "该站点已存在，是否要修改站点信息Y|N?" << endl;
			*site_script = i;
			cin.sync();
			ch_change = getchar();
			return ch_change;
		}
	}
	return ch_change;
}

//建立两个站点之间的关系
void site_relation(MGragh *m, Route_Site *rs1, Route_Site *rs2)
{
	cout << "请输入" << m->sites[rs1->num].name << "站与" << m->sites[rs2->num].name << "站之间的距离：" << endl;
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
			cout << "请输入整数：" << endl;
			cin >> distance;
		}
	}
	m->edges[rs1->num][rs2->num] = m->edges[rs2->num][rs1->num] = distance;
}

//判断路线是否存在
int judge_route(Route route[], int *n_route, string route_name)
{
	for (int i = 0; i < *n_route; i++)
	{
		if (route[i].name == route_name)
			return i;
	}
	return -1;

}

//找到要插入节点的位置
Route_Site *insert_position(MGragh *m, Route route[], int r_num)
{//返回值为要插入位置的前一个站点的指针
	int per;
add_s:
	cout << "请选择您要添加的站点的位置，选择要添加站点的前一站的编号即可（插入到最前面输入0）：" << endl;
	display_site(m, route[r_num - 1].first);
	cout << "前一站的编号：";
	cin >> per;
	if (per<0 || per > route[r_num - 1].num)
	{
		cout << "没有您要插入的位置,请确认后再重新输入！" << endl;
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

//修改站点信息
void revise_site_info(MGragh *m, int script)
{//num为要修改信息的站点的编号
	cout << "请输入修改之后的名字：" << endl;
	string name;
	cin >> name;
	while (1)
	{
		cout << "确认要修改站点信息Y|N?" << endl;
		cin.sync();
		char ch_revise_site_info = getchar();
		if (ch_revise_site_info == 'Y' || ch_revise_site_info == 'y')
		{
			m->sites[script - 1].name = name;
			cout << "修改成功！" << endl;
			break;
		}
		else if (ch_revise_site_info == 'N' || ch_revise_site_info == 'n')
		{
			cout << "退出修改站点信息！" << endl;
			break;
		}
	}

}

//删除图中站点
void del_site(MGragh *m, Route route[], int *n, int *n_route, int script)
{//script为要删除的站点在图中的脚标
	for (int i = 0; i < m->sites[script].top; i++)//从线路中将站点删除
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
				del_route_site(m, &route[j], del_site_num);//从路线中将站点删除
				route[j].num--;
			}
		}
	}

	for (int i = script; i < (*n) - 1; i++)//将该站点从储存站点的数组中删除
		m->sites[i] = m->sites[i + 1];
	for (int i = 0; i < *n; i++)//将节点从邻接矩阵中删除
	{
		for (int j = script; j < (*n) - 1; j++)
		{
			m->edges[i][j] = m->edges[i][j + 1];
		}
	}
	for (int i = 0; i < (*n) - 1; i++)//将节点从邻接矩阵中删除
	{
		for (int j = script; j < (*n) - 1; j++)
		{
			m->edges[j][i] = m->edges[j + 1][i];
		}
	}
	for (int i = 0; i < *n; i++)//将用过的内存空间重置为最大值
	{
		m->edges[i][*n] = m->edges[*n][i] = INFINITY;
	}
	(*n)--;//站点数减一
	for (int i = 0; i < *n_route; i++)
		update_route_site_script(&route[i], script);
}


//修改路线功能
void revise_route(MGragh *m, Route route[], int *n, int *n_route)
{
	display_route(route, n_route);
	cout << "请选择要操作的路线" << endl;
	int r_num;											//存放要操作的路线id
	cin >> r_num;
	if (r_num <= 0 || r_num > *n_route)
	{
		cout << "没有要操作的路线！" << endl;
		system("pause");
		return;
	}
	cout << "您选择的是" << route[r_num - 1].name << "号路线" << endl;
	cout << "请选择您需要的操作" << endl;
	cout << "1.添加站点" << endl;
	cout << "2.删除站点" << endl;
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
		cout << "选择您要删除的站点:" << endl;
		display_site(m, route[r_num - 1].first);
		int del_site_num;
		cin >> del_site_num;
		if (del_site_num > 0 && del_site_num <= route[r_num - 1].num)
		{
			cout << "确认删除站点Y|N?" << endl;
			cin.sync();
			char ch_del_route_site = getchar();
			if (ch_del_route_site == 'Y' || ch_del_route_site == 'y')
			{
				del_route_site(m, &route[r_num - 1], del_site_num);
			}
			else
			{
				cout << "退出删除站点操作！" << endl;
				system("pause");
			}
		}
		else
		{
			cout << "没有您要删除的站点！" << endl;
			system("pause");
		}
	}

}

//更新路线中站点在数组中的脚标
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

//删除路线中的站点
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
		if (m->sites[p->num].route[i] == route->name)//从站点信息中删除存放的路线信息
		{
			for (int j = i; j < m->sites[p->num].top - 1; j++)
				m->sites[p->num].route[j] = m->sites[p->num].route[j + 1];
			m->sites[p->num].top--;
		}
	}
	delete p;			//这只是把路线中的删除了，图中的关系并没有解除
}


//删除路线
void del_route(MGragh *m, Route route[], int *n_route)
{
	Route_Site *rs, *del_rs = NULL;
	cout << "现有路线如下：" << endl;
	display_route(route, n_route);
	cout << "请选择您要删除的路线编号：" << endl;
	int route_num;
	cin >> route_num;
	if (route_num <= 0 || route_num > *n_route)
	{
		cout << "没有您要删除的路线！" << endl;
		system("pause");
		return;
	}
	cout << "确认删除该路线么Y|N?" << endl;
	cin.sync();
	char ch_del_route = getchar();
	if (ch_del_route == 'N' || ch_del_route == 'n')
	{
		cout << "您取消了删除路线！" << endl;
		system("pause");
		return;
	}
	for (rs = route[route_num - 1].first; rs; rs = rs->next)
	{
		delete del_rs;
		for (int i = 0; i < m->sites[rs->num].top; i++)
		{
			if (m->sites[rs->num].route[i] == route[route_num - 1].name)//从站点信息中删除存放的路线信息
			{
				for (int j = i; j < m->sites[rs->num].top - 1; j++)
					m->sites[rs->num].route[j] = m->sites[rs->num].route[j + 1];
				m->sites[rs->num].top--;
			}
		}
		del_rs = rs;
	}
	delete del_rs;
	for (int i = route_num; i < *n_route; i++)//将该路线信息从储存路线的数组中删除
		route[i - 1] = route[i];
	(*n_route)--;
}

//查询功能
//打印站点信息
void display_site_info(MGragh *m, int script)
{
	cout << "站点名称：" << m->sites[script].name << endl;
	cout << "站点所属路线：";
	for (int i = 0; i < m->sites[script].top; i++)
		cout << m->sites[script].route[i] << " ";
}
//打印路线名称
void display_route(Route route[], int *n_route)
{
	cout << "共有一下线路：" << endl;
	for (int i = 0; i < *n_route; i++)
		cout << i + 1 << "." << route[i].name << " ";
	cout << endl;
}

//打印路线中的站点名称
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
//打印出图中所有站点
void display_all_site(MGragh *m, int *n)
{
	for (int i = 0; i < *n; i++)
	{
		cout << i + 1 << "." << m->sites[i].name << " ";
	}
	cout << endl;
}
//最短路径
void ShortesPath(MGragh *m, Route route[], int *n_route, int P[MAXSITE], double D[MAXSITE], int script1, int script2)
{
	/*
	设原点为顶点0，求到其余顶点的最短路径
	D[v]存放从源点顶点到终点v的最短路径长度
	P[v]存放相应的最短路径终点的前驱点
	script1为出发点脚标
	script2为目的地脚标
	常量INFINITY是为邻接矩阵中的正无穷
	*/
	int final[MAXSITE] = { 1, 0 };
	for (int i = 0; i < MAXSITE; i++)
	{
		D[i] = m->edges[script1][i];
		P[i] = script1;
	}
	D[script1] = 0;
	final[script1] = 1;
	P[script1] = -1;							//初始化，原点属于s集
	for (int i = 1; i < MAXSITE; i++)
	{
		/*
		开始主循环，每次求得源点到某个顶点k的最短路径，并加k到s集
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
		final[j] = 1;						//将顶点j加入到s集合中
		for (int k = 0; k < MAXSITE; k++)	//更新其他没进入s的点的当前最短路径及长度
		{
			if (final[k] == 0 && D[j] + m->edges[j][k] < D[k])
			{
				D[k] = D[j] + m->edges[j][k];	//将D[k]修改为更短的路径 
				P[k] = j;						//记忆对应的路径，将k的前驱结点改为j
			}
		}
	}
	string route1, route2;						//换乘先后的路线
	int change = -1;								//换乘的站点
	int change_route;							//记录换成以后的路线，减少确定换乘前线路的循环次数
	int change_route1, change_route2;			//换乘前，后的路线在换乘站点存放路线数组中的位置
	int flag_change = 0;						//0表示没有一次换乘的站点
	int flag1 = 0, flag2 = 0;					//记录换乘先后是不是都是最短路径
	for (int i = 0; i < m->sites[script2].top; i++)
	{
		int script = P[script2];					//临时存放前驱站点脚标
		int flag = 0;
		while (script != -1)
		{
			int j;
			for (j = 0; j < m->sites[script].top; j++)
			{
				if (m->sites[script2].route[i] == m->sites[script].route[j])//按照最短路径的顺序反向查找找到换乘的站点
				{
					flag = 1;
					change = script;
					change_route = j;
					break;
				}
			}
			if (j == m->sites[script].top)//将经过两个站点的路线进行比较以后没有相同的路线，上一站应该为换乘站点
				flag = 0;
			if (flag == 0)
			{
				route2 = m->sites[script2].route[i];//记录从换乘站点到目的地的路线
				break;
			}
			script = P[script];
		}
		if (change == -1)//终点站的前驱站点中没有m->sites[script2].route[i]站
			continue;


		//查找路线对应的索引
		change_route2 = judge_route(route, n_route, m->sites[script2].route[i]);
		//判断是不是最短路径
		Route_Site *p_rs = route[change_route2].first;
		int p_num = script2;
		while (1)		//找到终点站点在路线中的位置
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
				//查找路线对应的索引
				change_route1 = judge_route(route, n_route, m->sites[change].route[k]);
				Route_Site *p_rs1 = route[change_route1].first;
				int p_num1 = change;
				while (1)		//找到换乘站点在路线中的位置
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
				if (p_num1 == script1 && p_num == change)//是最短路径
				{
					cout << "乘" << route1 << "路到" << m->sites[change].name << "站换乘" << route2 << "路(最短)" << endl;
				}
				else
					cout << "乘" << route1 << "路到" << m->sites[change].name << "站换乘" << route2 << "路" << endl;
				flag_change = 1;
			}
			script = P[change];
		}
	}
	if (flag_change == 0)
		cout << "没有直达和一次换乘的路线！" << endl;
}


//初级菜单
void primary_menu()
{
	cout << "**********************" << endl;
	cout << "请选择您需要的操作：" << endl;
	cout << "1.查询" << endl;
	cout << "2.管理" << endl;
	cout << "3.退出" << endl;
	cout << "**********************" << endl;
}
//查询模块
void inquire_menu()
{
	cout << "*****************************" << endl;
	cout << "请选择您需要的操作：" << endl;
	cout << "1.查询公交车线路" << endl;
	cout << "2.查询站点信息" << endl;
	cout << "3.查询两个站点之间的公交线路" << endl;
	cout << "4.返回上级菜单" << endl;
	cout << "*****************************" << endl;
}
void site_info()
{
	cout << "*****************************" << endl;
	cout << "请选择您需要的操作：" << endl;
	cout << "1.按序号查找" << endl;
	cout << "2.按姓名查找" << endl;
	cout << "3.返回上级菜单" << endl;
	cout << "*****************************" << endl;
}

//管理模块
bool land(string pw)
{
	cout << "请输入密码:" << endl;
	string password;
	for (int i = 0; i < 3; i++)
	{
		cin >> password;
		if (password == pw)
		{
			system("cls");
			cout << "登陆成功！" << endl;
			Sleep(1000);
			system("cls");
			return true;
		}
		cout << "输入有误!" << endl;
		cout << "您还有" << 2 - i << "次输入机会" << endl;
	}
	return false;
}
void manage_menu()
{
	cout << "*************************" << endl;
	cout << "请选择您需要的操作：" << endl;
	cout << "1.信息查询" << endl;
	cout << "2.站点管理" << endl;
	cout << "3.线路管理" << endl;
	cout << "4.修改密码" << endl;
	cout << "5.保存信息" << endl;
	cout << "6.返回上级菜单" << endl;
	cout << "*************************" << endl;
}
void site_manage_menu()
{
	cout << "*************************" << endl;
	cout << "请选择您需要的操作：" << endl;
	cout << "1.添加站点" << endl;
	cout << "2.修改站点" << endl;
	cout << "3.删除站点" << endl;
	cout << "4.返回上级菜单" << endl;
	cout << "*************************" << endl;
}
void route_manage_menu()
{
	cout << "**************************" << endl;
	cout << "请选择您需要的操作：" << endl;
	cout << "1.添加线路" << endl;
	cout << "2.修改线路" << endl;
	cout << "3.删除线路" << endl;
	cout << "4.返回上级菜单" << endl;
	cout << "**************************" << endl;
}

//查询功能
void inquire(MGragh *m, Route route[], int *site_sum, int *route_sum)
{
	while (1)									//查询模式
	{
		system("cls");
		inquire_menu();
		cin.sync();
		char ch_inquire = getchar();
		if (ch_inquire == '1')									//查询公交车线路
		{
			for (int i = 0; i < *route_sum; i++)
			{
				cout << route[i].name << "路：" << endl;
				display_site(m, route[i].first);
			}
			system("pause");
		}
		else if (ch_inquire == '2')								//查询站点信息
		{
			system("cls");
			site_info();
			cin.sync();
			char ch_site_info = getchar();
			if (ch_site_info == '1')				//按照序号查找
			{
				display_all_site(m, site_sum);
				cout << "请输入要查询站点的编号：" << endl;
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
						cout << "请输入整数：" << endl;
						cin >> num;
					}
				}
				if (num >= 1 && num <= *site_sum)
					display_site_info(m, num - 1);
				else
					cout << "没有要查询的站点！" << endl;
			}
			else if (ch_site_info == '2')			//按照姓名查找
			{
				cout << "请输入要查询的站点名称：" << endl;
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
					cout << "没有您要查询的站点！" << endl;
				else
					display_site_info(m, num);
			}
			system("pause");
		}
		else if (ch_inquire == '3')								//查询两个站点之间的公交线路
		{
			int flag = 0;
			string start, end;
			int script1, script2;
			while (flag == 0)
			{
				cout << "请输入起始站点名称：" << endl;
				cin.sync();
				cin >> start;
				script1 = judge_site(m, site_sum, start);
				if (script1 == -1)
				{
					cout << "该站点不存在！" << endl;
					cout << "是否继续输入Y|N?" << endl;
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
				cout << "请输入目的地站点名称：" << endl;
				cin.sync();
				cin >> end;
				script2 = judge_site(m, site_sum, end);
				if (script2 == -1)
				{
					cout << "该站点不存在！" << endl;
					cout << "是否继续输入Y|N?" << endl;
					cin.sync();
					char ch_start = getchar();
					if (ch_start == 'Y' || ch_start == 'y')
						continue;
					else
						break;
				}
				flag = 2;
			}
			if (flag == 2)//起始站点和目的地都存在
			{
				int flag_arrive = 0;
				for (int i = 0; i < m->sites[script1].top; i++)//寻找直达路线
				{
					for (int j = 0; j < m->sites[script2].top; j++)
					{
						if (m->sites[script1].route[i] == m->sites[script2].route[j])
						{
							cout << m->sites[script1].route[i] << "路直达 ";
							flag_arrive = 1;
							break;
						}
					}
				}
				if (flag_arrive == 0)//没有直达路线
				{
					int P[MAXSITE];//P[v]存放相应的最短路径终点的前驱点
					double D[MAXSITE];//D[v]存放从源点顶点到终点v的最短路径长度
					ShortesPath(m, route, route_sum, P, D, script1, script2);
				}
			}
			cout << endl;
			system("pause");
		}
		else if (ch_inquire == '4')								//返回上级菜单
			break;
		else
		{
			cout << "没有您要选择的操作！" << endl;
			system("pause");
		}
	}
}
int main()
{
	MGragh m;													//存放顶点表和邻接矩阵
	for (int i = 0; i < MAXSITE; i++)							//邻接矩阵初始化
	{
		for (int j = 0; j < MAXSITE; j++)
		{
			m.edges[i][j] = INFINITY;
		}
	}
	for (int i = 0; i < MAXSITE; i++)						//所有站点所属的公交线路数初始化为0
		m.sites[i].top = 0;
	Route route[MAXROUTE];										//路线信息
	int site_sum = 0;												//站点数
	int route_sum = 0;												//路线数
	string pw = "123456";									//初始密码
	//文件读取
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
		if (ch_primary == '1')								//查询模式
			inquire(&m, route, &site_sum, &route_sum);
		else if (ch_primary == '2')								//管理模式
		{
			bool flag = land(pw);
			while (flag)
			{
				system("cls");
				manage_menu();
				cin.sync();
				char ch_manage = getchar();
				if (ch_manage == '1')								//查询模式
					inquire(&m, route, &site_sum, &route_sum);
				while (ch_manage == '2')							//站点管理
				{
					system("cls");
					site_manage_menu();
					cin.sync();
					char ch_site_m = getchar();
					if (ch_site_m == '1')							//添加站点
					{
						display_route(route, &route_sum);
						cout << "请输入要将站点加入的路线号：" << endl;
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
							cout << "该路线不存在！" << endl;
							system("pause");
						}
					}
					else if (ch_site_m == '2')						//修改站点
					{
						display_all_site(&m, &site_sum);
						cout << "请输入您要修改的站点的编号：" << endl;
						int script;
						cin >> script;
						if (script > 0 && script <= site_sum)
							revise_site_info(&m, script);
						else
						{
							cout << "没有您要修改的站点！" << endl;
							system("pause");
						}

					}
					else if (ch_site_m == '3')						//删除站点
					{
						display_all_site(&m, &site_sum);
						cout << "请输入您要删除的站点的编号：" << endl;
						int script;
						cin >> script;
						if (script > 0 && script <= site_sum)
						{
							cout << "确认删除站点Y|N?" << endl;
							cin.sync();
							char ch_del_site = getchar();
							if (ch_del_site == 'Y' || ch_del_site == 'y')
							{
								del_site(&m, route, &site_sum, &route_sum, script - 1);
							}
							else
							{
								cout << "退出删除站点操作！" << endl;
								system("pause");
							}
						}
						else
						{
							cout << "没有您要删除的站点！" << endl;
							system("pause");
						}
					}
					else if (ch_site_m == '4')
						break;
					else
					{
						cout << "不存在您要选择的操作！" << endl;
						system("pause");
					}
				}//站点管理
				while (ch_manage == '3')						//线路管理
				{
					system("cls");
					route_manage_menu();
					cin.sync();
					char ch_route_manage = getchar();
					if (ch_route_manage == '1')					//添加路线
					{
						create_route(&m, route, &site_sum, &route_sum);
					}
					else if (ch_route_manage == '2')			//修改路线
					{
						if (route_sum == 0)
						{
							cout << "没有可修改的路线！" << endl;
							system("pause");
							continue;
						}

						revise_route(&m, route, &site_sum, &route_sum);
					}
					else if (ch_route_manage == '3')			//删除路线
					{
						if (route_sum == 0)
						{
							cout << "没有可删除的路线！" << endl;
							system("pause");
							continue;
						}

						del_route(&m, route, &route_sum);
					}
					else if (ch_route_manage == '4')			//返回上级菜单
						break;
					else
					{
						cout << "不存在您要选择的操作！" << endl;
						system("pause");
					}
				}//路线管理
				if (ch_manage == '4')//修改密码
				{
					cout << "请输入新密码：" << endl;
					string pw_new;
					cin >> pw_new;
					while (1)
					{
						cout << "确认修改密码Y|N？" << endl;
						cin.sync();
						char ch_pw = getchar();
						if (ch_pw == 'Y' || ch_pw == 'y')
						{
							pw = pw_new;
							cout << "修改成功！" << endl;
							system("pause");
							break;
						}
						else if (ch_pw == 'N' || ch_pw == 'n')
						{
							cout << "退出修改密码！" << endl;
							system("pause");
							break;
						}
					}
				}
				else if (ch_manage == '5')//将信息存入文件
				{
					//文件写入
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
				else if (ch_manage == '6')//返回上级菜单
				{
					break;
				}
				else if (ch_manage != '1' && ch_manage != '2' && ch_manage != '3' && ch_manage != '4' && ch_manage != '5')
				{
					cout << "没有您选择的操作！" << endl;
					system("pause");
				}
			}

			if (!flag)
			{
				system("cls");
				cout << "密码已经输错三次，无法登陆,三秒后自动返回！" << endl;
				Sleep(3000);
				system("cls");
			}
		}

		else if (ch_primary == '3')
		{
			cout << "感谢您的使用!" << endl;
			break;
		}
		else
		{
			cout << "没有您选择的操作！" << endl;
			system("pause");
		}
	}//初级菜单循环

	system("pause");
	return 0;
}

