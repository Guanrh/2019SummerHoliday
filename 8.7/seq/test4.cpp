#include<cstdio>
#include<cstring>
#define mo 998244353

using namespace std;

int n,K;
long long ans[410][410],mat[410][410],c[410][410],res[410][410],f[10][410],anss;

long long qpow(int a,int b)
{
	if (b == 0) return 1;
	long long res = qpow(a,b>>1);
	res = (res*res) % mo;
	if ( b % 2 ) res*=a;
	return res % mo;
}

void mpow(int x)
{
	if (x==0) 
	{
		//res[2][2]=res[1][1]=1;
		for (int i=1;i<=K;i++) res[i][i]=1;
		return;
	}
	mpow(x>>1);
	//mul(res,res);
	memset(c,0,sizeof c);
	for (int i=1;i<=K;i++)
		for (int j=1;j<=K;j++)
			for (int k=1;k<=K;k++)
				c[i][j]=(c[i][j]+(res[i][k]*res[j][k])%mo)%mo;
	memcpy(res,c,sizeof c);
	if (x%2)
	{
		memset(c,0,sizeof c);
		for (int i=1;i<=K;i++)
			for (int j=1;j<=K;j++)
				for (int k=1;k<=K;k++)
					c[i][j]=(c[i][j]+(res[i][k]*mat[j][k])%mo)%mo;
		memcpy(res,c,sizeof c);
	}
	
}

long long get(int x)
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
				long long poww=qpow(f[i][k],res[k][j]);
				ans[i][j]*=poww;
				ans[i][j]%=mo;
			}
	return ans[1][K];
}
 
int main()
{
	//freopen("seq.in","r",stdin);
	memset(mat,0,sizeof mat);
	scanf("%d%d",&n,&K);
	for (int i=1;i<=K;i++) scanf("%d",&mat[K-i+1][K]);
	for (int i=1;i<=K;i++) scanf("%d",&f[1][i]);
	for (int i=1;i<K;i++) mat[i+1][i]=1;
	/**for (int i=1;i<=K;i++)
	{
		for (int j=1;j<=K;j++) printf("%d ",mat[i][j]);
		printf("\n");
	}**/
	anss =get(n-K);
	printf("%lld\n",anss);
}
