#include <cstdio>

using namespace std;

int a[6100],n,tail[6100],tot,f[6100],g[6100],bz[6100],ans;

int max(int x,int y){return x>y?x:y;}

struct edge
{
	int fr,v;
}e[6100];

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
	{
		if (!bz[e[i].v]) dg(e[i].v);
		f[t]+=max(g[e[i].v],0);
		g[t]+=max(f[e[i].v],max(g[e[i].v],0));
	}
	ans=max(ans,max(f[t],g[t]));
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	while (1)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		if (u==0 && v==0) break;
		add(v,u);
	}
	for (int i=1;i<=n;i++)
		if (!bz[i])
			dg(i);
	printf("%d\n",ans);
}