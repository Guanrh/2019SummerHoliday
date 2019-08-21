#include<cstdio>
#include<cstring>
#define mo 1000000007
#define fo(i,a,b) for (register int i=a;i<=b;i++)

using namespace std;

int n,f[210][210],m;

struct matrix
{
	long long a[110][110];
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

matrix qpow(matrix a,int b)
{
	matrix res;
	memset(res.a,0,sizeof res.a);
	fo(i,1,m/2) res.a[i][i]=1;
	while (b)
	{
		if (b&1) res*=a;
		a*=a;
		b>>=1;
	}
	return res;
}

void predo()
{
	for (int i=2;i<=m/2;i++) mat.a[i][i-1]=1;
	f[1][1]=1;f[1][2]=0;f[1][3]=1;
	int cur=m/2;
	mat.a[cur][m/2]=2;
	for (int i=2;i<=m;i++)
	{
		for (int j=1;j<=i+2;j++) f[i][j]=(f[i-1][j]+f[i-1][j-1])%mo;
		if (i%2)
		{
			mat.a[--cur][m/2]=f[i][(i+2)/2+1];
			printf("%d\n",f[i][(i+2)/2+1]);
			f[i][(i+2)/2+1]=0;
		}
	}
}
 
int main()
{
	scanf("%d%d",&n,&m);
	if (m>n) m=n;
	predo();
	mat=qpow(mat,n/2);
	printf("%d\n",mat.a[m/2][m/2]);
}
