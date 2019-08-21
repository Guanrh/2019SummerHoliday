#include<cstdio>
#include<cstring>
#define mo 2009
#define fo(i,a,b) for (register int i=a;i<=b;i++)
#define tot 99

using namespace std;

int n,T,mp[20][20];
char st[20];

struct matrix
{
	int a[120][120];
	matrix &operator*=(const matrix &o)
	{
		matrix res;
		memset(res.a,0,sizeof a);
		fo(i,1,tot)
			fo(j,1,tot)
				fo(k,1,tot)
					res.a[i][j]=(res.a[i][j]+a[i][k]*o.a[k][j])%mo;
		memcpy(a,res.a,sizeof a);
		return *this;
	}
}mat;

matrix qpow(matrix a,int b)
{
	matrix res;
	memset(res.a,0,sizeof res.a);
	fo(i,1,tot) res.a[i][i]=1;
	while (b)
	{
		if (b&1) res*=a;
		a*=a;
		b>>=1;
	}
	return res;
}
 
int main()
{
	scanf("%d%d",&n,&T);
	fo(i,1,n)
		fo(j,1,8)
			mat.a[i*9+j-1][i*9+j]=1;
	for (int i=1;i<=n;i++)
	{
		scanf("%s",st+1);
		for (int j=1;j<=n;j++)
			if (st[j]>'0')
				mat.a[i*9+st[j]-'0'-1][j*9]=1;
	}
	mat=qpow(mat,T);
	printf("%d\n",mat.a[9][n*9]);
}
