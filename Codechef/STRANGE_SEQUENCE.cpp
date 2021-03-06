#include<iostream>
#define MOD 10000007
using namespace std;
/* Optimized version of power() in method 4 */
/* function that returns nth Fibonacci number */
int A[2][1]={5,1};
void multiply(long long int F[2][2], long long int M[2][2])
{
  long long int x =  F[0][0]*M[0][0]%MOD + F[0][1]*M[1][0]%MOD;
  long long int y =  F[0][0]*M[0][1]%MOD + F[0][1]*M[1][1]%MOD;
  long long int z =  F[1][0]*M[0][0]%MOD + F[1][1]*M[1][0]%MOD;
  long long int w =  F[1][0]*M[0][1]%MOD + F[1][1]*M[1][1]%MOD;

  F[0][0] = x%MOD;
  F[0][1] = y%MOD;
  F[1][0] = z%MOD;
  F[1][1] = w%MOD;
}
void power(long long int F[2][2],long long int n)
{
  if( n == 0 || n == 1)
      return;
  long long int M[2][2] = {{1,2},{1,0}};

  power(F, n/2);
  multiply(F, F);

  if (n%2 != 0)
     multiply(F, M);
}
int fib(long long int n)
{
  long long int F[2][2] = {{1,2},{1,0}};
  power(F, n-2);
  //now multiply by 2
  long long int x=F[0][0]*A[0][0]%MOD+F[0][1]*A[1][0]%MOD;
  long long int y=F[1][0]*A[0][0]%MOD;
  F[0][0]=x%MOD;
  F[1][0]=y%MOD;
  return F[0][0];
}
int main()
{
	int T,i;
	long long int N,x,y;
	cin>>T;
	while(T--)
	{
		cin>>N;
		if(N==1) cout<<"1"<<endl;
		else if(N==2) cout<<"5"<<endl;
		else cout<<fib(N)<<endl;
	}
}
