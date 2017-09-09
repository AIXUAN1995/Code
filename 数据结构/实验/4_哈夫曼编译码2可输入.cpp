#include <iostream>
#include <string>
using namespace std;
const int MAXVALUE = 10000;
const int N = 26;//最多叶结点个数
typedef struct
{
	int weight;
	int parent;
	int lchild;
	int rchild;
}HNodeType;
typedef struct
{
	int bit[N];//N为叶结点个数
	int start;
}HCodeType;
struct char_count
{
	char ch;
	int num;//记录出现的次数
};

//求输入字符串中各个字母的个数
void count(string s, char_count ch_count[], int *n)// n为尾指针
{
	ch_count[*n].ch = s[0];
	ch_count[*n].num++;
	for (int i = 1; i < s.length(); i++)
	{

		for (int j = 0; j <= *n; j++)
		if (ch_count[j].ch == s[i])
		{
			ch_count[j].num++;
			goto exit;
		}
		(*n)++;
		ch_count[*n].ch = s[i];
		ch_count[*n].num++;
	exit:;
	}
}
//哈夫曼树构造
void Create_HuffMTree(HNodeType HFMTree[], int n, char_count ch_count[])
{
	int m1, x1, m2, x2;//x1和x2储存最小和次小权值，m1和m2储存其位置
	for (int i = 0; i<2 * n - 1; i++)//HFMTree的初始化
	{
		HFMTree[i].weight = 0;
		HFMTree[i].parent = -1;
		HFMTree[i].lchild = -1;
		HFMTree[i].rchild = -1;
	}
	for (int i = 0; i < n; i++)
	{
		HFMTree[i].weight = ch_count[i].num;
	}
	for (int i = 0; i < n - 1; i++)//构造哈夫曼树
	{
		x1 = x2 = MAXVALUE;
		m1 = m2 = 0;
		for (int j = 0; j < n + i; j++)
		{
			if (HFMTree[j].parent == -1 && HFMTree[j].weight < x1)
			{
				//找出根节点具有最小和次最小权值的两棵树
				x2 = x1;
				m2 = m1;
				x1 = HFMTree[j].weight;
				m1 = j;
			}
			else if (HFMTree[j].parent == -1 && HFMTree[j].weight < x2)
			{
				x2 = HFMTree[j].weight;
				m2 = j;
			}
		}
		HFMTree[m1].parent = n + i;
		HFMTree[m2].parent = n + i;
		HFMTree[n + i].weight = HFMTree[m1].weight + HFMTree[m2].weight;
		HFMTree[n + i].lchild = m1;
		HFMTree[n + i].rchild = m2;
	}
}

//哈夫曼编码
void HaffmanCode(HNodeType HFMTree[], int n, HCodeType HuffCode[])
{
	HCodeType cd;//字符编码的缓冲变量
	int c, p;
	for (int i = 0; i <= n; i++)
	{
		cd.start = n - 1;
		c = i;
		p = HFMTree[c].parent;//第i个结点双亲节点的位置
		while (p != -1)
		{
			if (HFMTree[p].lchild == c)
				cd.bit[cd.start] = 0;
			else
				cd.bit[cd.start] = 1;
			cd.start--;
			c = p;
			p = HFMTree[c].parent;
		}
		for (int j = cd.start + 1; j <= n; j++)
			HuffCode[i].bit[j] = cd.bit[j];
		HuffCode[i].start = cd.start + 1;
	}
}

int main()
{
	int n = 0;							//定义统计字个数的尾指针
	string s;							//输入的电文
	cout << "请输入电文：" << endl;
	cin >> s;

	//电文中出现的字符以及出现的次数
	char_count ch_count[N];
	for (int i = 0; i < N; i++)
		ch_count[i].num = 0;
	cout << "电文中出现的字符以及出现的次数：" << endl;
	count(s, ch_count, &n);
	for (int i = 0; i <= n; i++)
		cout << ch_count[i].ch << ":" << ch_count[i].num << endl;

	HCodeType HuffCode[N];
	HNodeType HFMTree[2 * N - 1];
	Create_HuffMTree(HFMTree, n + 1, ch_count);
	HaffmanCode(HFMTree, n, HuffCode);

	cout << "出现字符对应的哈夫曼编码:" << endl;
	for (int i = 0; i <= n; i++)
	{
		cout << ch_count[i].ch << ':';
		for (int j = HuffCode[i].start; j < n; j++)//为什么没有等于号
			cout << HuffCode[i].bit[j];
		cout << endl;
	}

	HCodeType *trans = new HCodeType[s.length()];		//用来传送哈夫曼编码的数组

	cout << "电文对应的编码为：" << endl;
	for (int i = 0; i < s.length(); i++)
	{
		for (int j = 0; j <= n; j++)
			if (s[i] == ch_count[j].ch)
			{
				for (int k = HuffCode[j].start; k < n; k++)//为什么没有等于号
				{
					cout << HuffCode[j].bit[k];
				}
				cout << ' ';
				trans[i] = HuffCode[j];
			}
	}
	int len = s.length();								//用来传递字符串的长度

	
	cout << "\n\n编码转化为电文为：" << endl;
	int p = 2 * n;								//根节点的索引
	int k;
	for (int j = 0; j < len; j++)
	{
		p = 2 * n;
		k = trans[j].start;
		while (HFMTree[p].lchild != -1 && HFMTree[p].rchild != -1)
		{
			if (trans[j].bit[k] == 0)
				p = HFMTree[p].lchild;
			else
				p = HFMTree[p].rchild;
			k++;
		}
		cout << ch_count[p].ch << ' ';
			
	}
	cout << endl;

	cout << "请输入0、1编码（中间不用加空格）：" << endl;
	string s2;
	cin >> s2;
	for (int j = 0; j < s2.length();)
	{
		p = 2 * n;
		while (HFMTree[p].lchild != -1 && HFMTree[p].rchild != -1)
		{
			if ((int)s2[j++]-48 == 0)
				p = HFMTree[p].lchild;
			else
				p = HFMTree[p].rchild;
		}
		cout << ch_count[p].ch << ' ';

	}
	cout << endl;
	system("pause");
	return 0;
}




//#include <iostream>
//#include <string>
//using namespace std;
//int main()
//{
//	int p[10];
//	for (int i = 0; i < 10; i++)
//	{
//		cout << p[i] << " ";
//	}
//	string s;
//	cin >> s;
//	cout << sizeof(s) << endl;
//	cout << s.length() << endl;
//	cout << s.size() << endl;
//	system("pause");
//	return 0;
//}
