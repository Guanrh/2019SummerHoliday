#include <cstdio>
#define ll long long

using namespace std;

ll f[200][1100];
int bz[1100],tot,p[200],n;

void LA_DING_WEI()
{
	f[0][0]=1;
	for (int i=1;i<=tot;i++)
	{
		for (int j=0;j<=n;j++) f[i][j]=f[i-1][j];
		for (int j=1;j<=n;j++)
			for (int k=p[i];j>=k;k*=p[i]) f[i][j]+=f[i-1][j-k];
	}
}

int main()
{
	scanf("%d",&n);
	for (int i=2;i<=n;i++)
		if (!bz[i])
		{
			p[++tot]=i;
			int k=i;
			while (k<=n)
			{
				bz[k]=1;
				k+=i;
			}
		}
	LA_DING_WEI();
	ll ans=0;
	for (int i=0;i<=n;i++) ans+=f[tot][i];
	printf("%lld\n",ans);
}
