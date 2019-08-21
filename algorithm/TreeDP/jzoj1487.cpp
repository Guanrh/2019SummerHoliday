#pragma GCC optimize("O3")
#pragma G++ optimize("O3")
#include <cstdio>

using namespace std;

int a[110000],n,tail[110000],tot,f[110000],g[110000],bz[110000],ans;

int max(int x,int y){return x>y?x:y;}

struct edge
{
	int fr,v;
}e[210000];

void add(int u,int v)
{
	e[++tot].fr=tail[u];
	e[tot].v=v;
	tail[u]=tot;
}

void dg(int t)
{
	bz[t]=1;
	f[t]=a[t];
	for (int i=tail[t];i;i=e[i].fr)
		if (!bz[e[i].v]) 
		{
			dg(e[i].v);
			f[t]+=g[e[i].v];
			g[t]+=max(f[e[i].v],g[e[i].v]);
		}
}

int main()
{
	freopen("profit.in","r",stdin);
	freopen("profit.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(v,u);
		add(u,v);
	}
	dg(1);
	printf("%d\n",max(f[1],g[1]));
}
