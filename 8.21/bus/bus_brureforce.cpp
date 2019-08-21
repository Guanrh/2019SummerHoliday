#include <cstdio>
#include <cstring>

using namespace std;

int w[20][20],f[20][20],n,m,K,flag,bz[20];

int min(int x,int y){return x<y?x:y;}

void check()
{
	memcpy(f,w,sizeof f);
	for (int k=1;k<=n;k++)
		if (!bz[k])
			for (int i=1;i<=n;i++)
				if (!bz[i])
					for (int j=1;j<=n;j++)
						if (!bz[j])
							f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
							
	if (f[1][n]>K) flag=1;
	return;
}

void dg(int t,int cnt,int C)
{
	if (cnt==C)
	{
		check();
		return;
	}
	if (t>n) return;
	if (flag) return;
	dg(t+1,cnt,C);
	if (t==1 || t==n) return;
	bz[t]=1;
	dg(t+1,cnt+1,C);
	bz[t]=0;
}

int main()
{
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
	scanf("%d%d%d",&n,&m,&K);
	memset(w,0x3f,sizeof w);
	for (int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		w[u][v]=1;
	}
	for (int i=1;i<=n;i++)
	{
		flag=0;
		dg(1,0,i);
		if (flag)
		{
			printf("%d\n",i);
			return 0;
		}
	}
}
