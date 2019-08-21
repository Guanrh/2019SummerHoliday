#include<cstdio>
#include<cstring>
#define mo 998244353
#define ll long long

using namespace std;

int n,K;
long long ans[410][410],mat[410][410],c[410][410],res[410][410],f[10][410],anss;

long long qpow(ll a,ll b)
{
	if (b == 0) return 1;
	long long res = (ll)qpow(a,b>>1);
	res = (ll)(res*res) % mo;
	if ( b % 2 ) res*=a;
	return res % mo;
}

void mpow(ll x)
{
	if (x==0) 
	{
		for (int i=1;i<=K;i++) res[i][i]=1;
		return;
	}
	mpow(x>>1);
	memset(c,0,sizeof c);
	for (int i=1;i<=K;i++)
		for (int j=1;j<=K;j++)
			for (int k=1;k<=K;k++)
				c[i][j]=(ll)(c[i][j]+(res[i][k]*res[k][j]))%(mo-1);
				
	memcpy(res,c,sizeof c);
	if (x%2)
	{
		memset(c,0,sizeof c);
		for (int i=1;i<=K;i++)
			for (int j=1;j<=K;j++)
				for (int k=1;k<=K;k++)
					c[i][j]=(ll)(c[i][j]+(res[k][j]*mat[i][k]))%(mo-1);
					
		memcpy(res,c,sizeof c);
	}
	
}

long long get(ll x)
{
	mpow(x);
	for (int i=1;i<=K;i++)
		for (int j=1;j<=K;j++)
			ans[i][j]=1;
	for (int i = 1;i <= 1;i ++)
		for (int j = 1;j <= K;j ++)
			for (int k = 1;k <= K;k ++)
			{
				//ans[i][j] *= qpow(f[i][k],res[k][j]),ans[i][j] %= mo;	
				long long poww=(ll)qpow(f[i][k],res[k][j]);
				ans[i][j]=(ll)ans[i][j]*poww;
				ans[i][j]=(ll)ans[i][j]%mo;
			}
	return (ll)ans[1][K];
}
 
int main()
{
	freopen("seq.in","r",stdin);
	freopen("seq.out","w",stdout);
	memset(mat,0,sizeof mat);
	scanf("%d%d",&n,&K);
	for (int i=1;i<=K;i++) scanf("%lld",&mat[K-i+1][K]);
	for (int i=1;i<=K;i++) scanf("%lld",&f[1][i]);
	for (int i=1;i<K;i++) mat[i+1][i]=1;
	/**for (int i=1;i<=K;i++)
	{
		for (int j=1;j<=K;j++) printf("%d ",mat[i][j]);
		printf("\n");
	}**/
	if (n>K)
		anss =get(n-K);
	else anss=f[1][n];
	printf("%lld\n",anss);
}
