#include<cstdio>
#include<cstring>
#define mo 1000000007LL
#define fo(i,a,b) for (register int i=a;i<=b;i++)

using namespace std;

int n,m;
long long f[210][210];

struct matrix
{
	long long a[300][30];
	matrix &operator*=(const matrix &o)
	{
		matrix res;
		memset(res.a,0,sizeof a);
		fo(i,1,m/2)
			fo(j,1,m/2)
				fo(k,1,m/2)
					res.a[i][j]=(res.a[i][j]+a[i][k]*o.a[k][j])%mo;
		memcpy(a,res.a,sizeof a);
		return *this;
	}
}mat;
 
int main()
{
	mat a,b,c;
	for (int i=1;i<=50;i++)
		for (int j=1;j<=50;j++)
			scanf("%d",&a.a[i][j]);
	for (int i=1;i<=50;i++)
		for (int j=1;j<=50;j++)
			scanf("%d",&a.a[i][j]);
}
