////用邻接多重表储存
//typedef struct node						//定义边结点类型
//{
//	int mark;							//访问标记，0表示为访问，1表示访问过
//	int ivex, jvex;						//该边依附的两个顶点位置
//	struct node *ilink, *jlink;			//分别指向依附这两个顶点的下一跳边
//	struct node *perilink, *perjlink;	//指向依附这两个顶点的前一条边
//	double distance;					//两个站点之间的距离
//}EdgeNode;
//typedef struct vnode					//定义顶点节点类型
//{
//	string name;						//站点名称
//	EdgeNode *firstdge;					//指向第一条依附该顶点的边
//	EdgeNode *lastdge;					//指向最后一条依附顶点的边
//	string route[MAXROUTE];				//每个站点所在的路线
//	int top;							//记录每个站点所在公交线路的个数
//}Site;
//struct Route_Site						//公交线路中的站点
//{
//	int num;							//路线中的站点在图中存放的位置
//	Route_Site *next;					//指向该路线中的下一个站点
//	Route_Site *per;					//只想该路线中的前一个站点
//};
//struct Route							//公交线路指针
//{
//	string name;
//	Route_Site *first;					//指向路线的起始站点
//	Route_Site *last;					//指向路线的终点站
//	int num;							//记录线路中站点的数量
//};
//
////函数声明
//void create_route(Site AdjList[], Route route[], int *n, int *n_route);	//创建路线同时添加站点到图中
//void add_site(Site AdjList[], Route route[], int *n, int *n_route, string route_name);	//添加站点
//void del_site(Site AdjList[], Route *route);											//删除路线中的站点
//char judge_site(Site AdjList[], int *n, string route_name, string site_name, int *site_script);//判断站点是否存在
//void site_relation(Site AdjList[], Route_Site *rs);						//建立两个站点之间的联系
//void display_all_site_num(Site AdjList[], Route route[], int *n_route);//打印出站点对应的编号
//
////打印路线名称
//void display_route(Site AdjList[], Route route[], int *n_route)
//{
//	for (int i = 0; i < *n_route; i++)
//		cout << i + 1 << "." << route[i].name << " ";
//}
//
////打印路线中的站点名称
//void display_site(Site AdjList[], Route_Site *rs)
//{
//
//	int site_num = 1;
//	while (rs)
//	{
//		cout << site_num++ << "." << AdjList[rs->num].name << " ";
//	}
//}
////打印出所有路线包含的站点
//void display_all_site(Site AdjList[], Route route[], int *n_route)
//{
//	Route_Site *rs;
//	cout << "线路名称以及线路经过的站点如下：" << endl;
//	for (int i = 0; i < *n_route; i++)
//	{
//		rs = route[i].first;
//		int n = 1;				//循环计数
//		cout << i + 1 << "."<< route[i].name << endl;
//		while (rs)
//		{
//			cout << n << "." << AdjList[rs->num].name << " ";
//		}
//	}
//}
//
////建立两个站点之间的关系
//void site_relation(Site AdjList[], Route_Site *rs)
//{
//	EdgeNode *s, *p;
//	int i, j, distance;
//	if (!rs)
//	{
//		cout << "路线不存在！" << endl;
//		return;
//	}
//	while (rs->next)													//建立两个站点之间的关系
//	{
//		i = rs->num;
//		j = rs->next->num;
//		s = new EdgeNode;
//		cout << "输入两个站点之间的距离：" << endl;
//		cin >> s->distance;
//		s->ivex = i;
//		s->jvex = j;	
//		if (!AdjList[i].firstdge)					//插入第一个站点
//		{
//			s->ilink = s->perilink = NULL;
//			p = AdjList[i].firstdge = AdjList[i].lastdge = s;
//		}
//		s->perilink = AdjList[i].lastdge;
//		AdjList[i].lastdge->ilink = s;				//将新边表插入到顶点边表的尾部
//		AdjList[i].lastdge = s;
//
//		if (!AdjList[j].firstdge)					//插入第一个站点
//		{
//			s->jlink = s->perjlink = NULL;
//			p = AdjList[j].firstdge = AdjList[j].lastdge = s;
//		}
//		s->perjlink = AdjList[j].lastdge;
//		AdjList[j].lastdge->jlink = s;				//将新边表插入到顶点边表的尾部
//		AdjList[j].lastdge = s;
//	}
//}
//
////判断站点是否存在
//char judge_site(Site AdjList[], int *n, string route_name, string site_name, int *site_script)
//{
//	char ch_change = 'C';
//	for (int i = 0; i < *n; i++)
//	{
//		if (site_name == AdjList[i].name)
//		{
//			for (int j = 0; j < AdjList[i].top; j++)
//			{
//				if (AdjList[i].route[j] == route_name)
//				{
//					cout << "该路线中已经存在该站点！" << endl;
//					ch_change = 'A';
//					return ch_change;
//				}
//			}
//
//			cout << "该站点已存在，是否要修改站点信息Y|N?" << endl;
//			*site_script = i;
//			ch_change = getchar();
//			cin.sync();
//			return ch_change;
//		}
//	}
//	return ch_change;
//}
//
////图中站点的删除
//void del_site
//{
//	
//}
//
////创建线路同时把站点加入图中
//void create_route(Site AdjList[], Route route[], int *n, int *n_route)
//{//*n为站点个数,*n_route为路线数
//	int flag = 1;							//作为跳出循环的标记变量
//	while (flag)							//循环创建线路
//	{
//		cout << "输入要创建的路线名称（退出请按0）：" << endl;
//		string route_name;
//		cin >> route_name;
//		if (route_name == "0")
//		{
//			cout << "结束路线的创建！" << endl;
//			return;
//		}
//
//		//确认是否创建路线
//		char ch_create_route;
//		cout << "确认创建路线Y|N?" << endl;
//		ch_create_route = getchar();
//		cin.sync();
//		if (ch_create_route == 'N' || ch_create_route == 'n')
//		{
//			cout << "退出创建路线！" << endl;
//			return;
//		}
//
//		//判断路线是否存在
//		for (int i = 0; i < *n_route; i++)
//		{
//			if (route[i].name == route_name)
//			{
//				cout << "该线路已经存在！" << endl;
//				flag = 0;
//				break;
//			}
//		}
//		if (flag == 0)
//			continue;
//		route[*n_route].name = route_name;
//
//		//向路线中添加站点
//		add_site(AdjList, route, n, n_route, route_name);
//	}//循环创建线路
//
//}
//
//
//
////修改路线功能
//void revise_route(Site AdjList[], Route route[], int *n,  int *n_route)
//{
//	display_route(AdjList, route, n_route);
//	cout << "请选择要操作的路线" << endl;
//	int r_num;											//存放要操作的路线id
//	cin >> r_num;
//	cout << "您选择的是" << route[r_num - 1].name << "号路线" << endl;
//	cout << "请选择您需要的操作" << endl;
//	cout << "1.添加站点" << endl;
//	cout << "2.删除站点" << endl;
//	char ch_rev_route;
//	ch_rev_route = getchar();
//	cin.sync();
//	if (ch_rev_route == '1')
//		add_site(AdjList, route, n, n_route, route[r_num - 1].name);
//	else if (ch_rev_route == '2')
//		del_route_site(AdjList, &route[r_num - 1]);
//
//	EdgeNode *p, *del_p;
//	display_all_site_num(AdjList, n);					//显示所有站点编号
//	cout << "请输入要删除的站点：" << endl;
//	int del_num;
//	cin >> del_num;
//	p = AdjList[del_num - 1].firstdge;
//	if (del_num <= 0 || del_num > *n || p == NULL)
//	{
//		cout << "没有找到您要删除的站点！" << endl;
//		return;
//	}
//	while (AdjList[del_num - 1].firstdge != AdjList[del_num - 1].lastdge)
//	{
//		del_p = p;
//		if (del_num == p->ivex)
//			p = p->ilink;
//		else
//			p = p->jlink;
//		del_p->perilink->ilink = del_p->ilink;
//		del_p->ilink->perilink = del_p->perilink;
//		del_p->perjlink->jlink = del_p->jlink;
//		del_p->jlink->perjlink = del_p->perilink;
//
//	}
//	AdjList[del_num - 1].firstdge = AdjList[del_num - 1].lastdge = NULL;
//	delete p;
//}
////添加站点功能
//void add_site(Site AdjList[], Route route[], int *n, int *n_route, string route_name)
//{//向建好的图中添加站点，*n为站点个数
//	int site_script = 0;						//当想要存放的站点已经存在时，记录该站点在数组中的角标
//	while (1)
//	{
//		char ch_change = 'C';					//判断是否修改原有站点信息
//		string site_name;
//		cout << "输入站点名称：" << endl;
//		cin >> site_name;
//
//		//判断站点是否存在
//		ch_change = judge_site(AdjList, n, route_name, site_name, &site_script);
//
//		if (ch_change == 'Y' || ch_change == 'y')//图中有该站点，对该站点的信息进行更改
//		{
//			AdjList[site_script].route[AdjList[site_script].top++] = route_name;
//		}
//		else if (ch_change == 'N' || ch_change == 'n')//不对原有信息进行修改
//			break;
//		else if (ch_change == 'A')//路线中已有该站点，不做操作
//			continue;
//		else if (ch_change == 'C')//图中没有该站点，新建站点
//		{
//			//判断是否继续创建站点
//			char ch_create_site;
//			cout << "确认创建站点Y|N?" << endl;
//			ch_create_site = getchar();
//			cin.sync();
//			if (ch_create_site == 'N' || ch_create_site == 'n')
//			{
//				cout << "退出创建站点！" << endl;
//				break;
//			}
//
//			AdjList[*n].name = site_name;
//			AdjList[*n].route[AdjList[*n].top++] = route_name;	//记录所在路线名称
//			AdjList[*n].firstdge = NULL;					//将指向第一条边和最后一条边的指针置为空
//			AdjList[*n].lastdge = NULL;
//			site_script = *n;
//			*n++;
//		}
//		else
//		{
//			cout << "输入有误请重新输入！" << endl;
//			continue;
//		}
//		Route_Site *rs = new Route_Site;
//		rs->num = site_script;
//		rs->per = rs->next = NULL;
//		if (!route[*n_route].first)							//在路线中加入第一个站点
//		{
//			route[*n_route].last = route[*n_route].first = rs;
//			rs->next = rs->per = NULL;
//		}
//		else
//		{
//			rs->per = route[*n_route].last;
//			route[*n_route].last->next = rs;
//			route[*n_route].last = rs;
//		}
//		site_relation(AdjList, route[*n_route].first);
//		(*n_route)++;
//	}//循环创建站点
//}
//
////删除路线中的站点
//void del_route_site(Site AdjList[], Route *route)
//{
//	Route_Site *rs, *p;
//	rs = p = route->first;
//	cout << "选择您要删除的站点:" << endl;
//	display_site(AdjList, rs);
//	int del_site_num;
//	cin >> del_site_num;
//	for (int i = 1; i < del_site_num; i++)
//	{
//		p = p->next;
//	}
//	rs = p;
//	rs->next = p->next;
//	p->next->per = rs;
//	delete p;			//仍然存在问题，这只是把路线中的删除了，图中的关系并没有解除？？？？
//}
