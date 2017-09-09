#include <iostream>
using namespace std;
//效率太低
int fib1(int n)
{
	if (n <= 2)
		return 1;
	return fib1(n - 1) + fib1(n - 2);
}//效率O((3/2)^N)

long fib2 (int n)
{
     long x = 0, y = 1;
     for (int j = 1; j < n; j++)
     {
         y = x + y;
         x = y - x;
     }
     return y;
}//效率O(N)

//用矩阵乘法，二分法
class Matrix
{
public:
       long matr[2][2];
 
       Matrix(const Matrix&rhs);
       Matrix(long a, long b, long c, long d);
       Matrix& operator=(const Matrix&);
       friend Matrix operator*(const Matrix& lhs, const Matrix& rhs)
       {
              Matrix ret(0,0,0,0);
              ret.matr[0][0] = lhs.matr[0][0]*rhs.matr[0][0] + lhs.matr[0][1]*rhs.matr[1][0];
              ret.matr[0][1] = lhs.matr[0][0]*rhs.matr[0][1] + lhs.matr[0][1]*rhs.matr[1][1];
              ret.matr[1][0] = lhs.matr[1][0]*rhs.matr[0][0] + lhs.matr[1][1]*rhs.matr[1][0];
              ret.matr[1][1] = lhs.matr[1][0]*rhs.matr[0][1] + lhs.matr[1][1]*rhs.matr[1][1];
              return ret;
       }
};
 
Matrix::Matrix(long a, long b, long c, long d)
{
       this->matr[0][0] = a;
       this->matr[0][1] = b;
       this->matr[1][0] = c;
       this->matr[1][1] = d;
}
 
Matrix::Matrix(const Matrix &rhs)
{
       this->matr[0][0] = rhs.matr[0][0];
       this->matr[0][1] = rhs.matr[0][1];
       this->matr[1][0] = rhs.matr[1][0];
       this->matr[1][1] = rhs.matr[1][1];
}
 
Matrix& Matrix::operator =(const Matrix &rhs)
{
       this->matr[0][0] = rhs.matr[0][0];
       this->matr[0][1] = rhs.matr[0][1];
       this->matr[1][0] = rhs.matr[1][0];
       this->matr[1][1] = rhs.matr[1][1];
       return *this;
}
 
Matrix power(const Matrix& m, int n)
{
       if (n == 1)
              return m;
       if (n%2 == 0)
              return power(m*m, n/2);
       else
              return power(m*m, n/2) * m;
}
 
long fib3 (int n)
{
       Matrix matrix0(1, 1, 1, 0);
       matrix0 = power(matrix0, n-1);
       return matrix0.matr[0][0];
}//效率O(log(N))

int main()
{
	int n = 0, x = 1, y = 1, z = 0;
	cout<<"请输出的斐波那契数的个数"<<endl;
	cin>>n;
	cout<<x<<'\t'<<y<<'\t';
	for(int i=3; i<=n; i++)
	{
		z = x + y;
		cout<<z<<'\t';
		x = y;
		y = z;
			
	}

	system("pause");
	return 0;
}