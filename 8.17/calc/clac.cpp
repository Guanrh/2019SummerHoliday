#include <cstdio>
#include <cstring>
#define mo 1000000009

using namespace std;

int p[1100],tot,f[1100][110][200],n,k,bz[1100];

int main()
{
	scanf("%d%d",&n,&k);

	for (int i=2;i<=n;i++)
		if (!bz[i])
		{
			p[++tot]=i;
			int K=i;
			while (K<=n)
			{
				bz[K]=1;
				K+=i;
			}
		}
	
	memset(f,0,sizeof f);
	for (int i=2;i<=n;i++)
	{
		int x=i;
		for (int j=1;p[j]<=i && j<=tot;j++)
			while (x%p[j]==0)
			{
				x/=p[j];
				f[i][0][j]++;
			}
	}

	for (int i=1;i<=n;i++)
		for (int j=1;j<=k;j++)
			for (int l=1;l<=tot;l++)
				f[i][j][l]=(f[i-1][j][l]+f[i][j-1][l])%mo;

	long long ans=1;
	for (int i=1;i<=tot;i++) ans=(ans*(f[n][k][i]+1))%mo;
	printf("%lld\n",ans);
}
