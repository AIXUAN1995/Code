#include <iostream>
#include <string>
using namespace std;
const int MAXVALUE = 10000;
const int N = 26;//���Ҷ������
typedef struct
{
	int weight;
	int parent;
	int lchild;
	int rchild;
}HNodeType;
typedef struct
{
	int bit[N];//NΪҶ������
	int start;
}HCodeType;
struct char_count
{
	char ch;
	int num;//��¼���ֵĴ���
};

//�������ַ����и�����ĸ�ĸ���
void count(string s, char_count ch_count[], int *n)// nΪβָ��
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
//������������
void Create_HuffMTree(HNodeType HFMTree[], int n, char_count ch_count[])
{
	int m1, x1, m2, x2;//x1��x2������С�ʹ�СȨֵ��m1��m2������λ��
	for (int i = 0; i<2 * n - 1; i++)//HFMTree�ĳ�ʼ��
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
	for (int i = 0; i < n - 1; i++)//�����������
	{
		x1 = x2 = MAXVALUE;
		m1 = m2 = 0;
		for (int j = 0; j < n + i; j++)
		{
			if (HFMTree[j].parent == -1 && HFMTree[j].weight < x1)
			{
				//�ҳ����ڵ������С�ʹ���СȨֵ��������
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

//����������
void HaffmanCode(HNodeType HFMTree[], int n, HCodeType HuffCode[])
{
	HCodeType cd;//�ַ�����Ļ������
	int c, p;
	for (int i = 0; i <= n; i++)
	{
		cd.start = n - 1;
		c = i;
		p = HFMTree[c].parent;//��i�����˫�׽ڵ��λ��
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
	int n = 0;							//����ͳ���ָ�����βָ��
	string s;							//����ĵ���
	cout << "��������ģ�" << endl;
	cin >> s;

	//�����г��ֵ��ַ��Լ����ֵĴ���
	char_count ch_count[N];
	for (int i = 0; i < N; i++)
		ch_count[i].num = 0;
	cout << "�����г��ֵ��ַ��Լ����ֵĴ�����" << endl;
	count(s, ch_count, &n);
	for (int i = 0; i <= n; i++)
		cout << ch_count[i].ch << ":" << ch_count[i].num << endl;

	HCodeType HuffCode[N];
	HNodeType HFMTree[2 * N - 1];
	Create_HuffMTree(HFMTree, n + 1, ch_count);
	HaffmanCode(HFMTree, n, HuffCode);

	cout << "�����ַ���Ӧ�Ĺ���������:" << endl;
	for (int i = 0; i <= n; i++)
	{
		cout << ch_count[i].ch << ':';
		for (int j = HuffCode[i].start; j < n; j++)//Ϊʲôû�е��ں�
			cout << HuffCode[i].bit[j];
		cout << endl;
	}

	HCodeType *trans = new HCodeType[s.length()];		//�������͹��������������

	cout << "���Ķ�Ӧ�ı���Ϊ��" << endl;
	for (int i = 0; i < s.length(); i++)
	{
		for (int j = 0; j <= n; j++)
			if (s[i] == ch_count[j].ch)
			{
				for (int k = HuffCode[j].start; k < n; k++)//Ϊʲôû�е��ں�
				{
					cout << HuffCode[j].bit[k];
				}
				cout << ' ';
				trans[i] = HuffCode[j];
			}
	}
	int len = s.length();								//���������ַ����ĳ���

	
	cout << "\n\n����ת��Ϊ����Ϊ��" << endl;
	int p = 2 * n;								//���ڵ������
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

	cout << "������0��1���루�м䲻�üӿո񣩣�" << endl;
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
