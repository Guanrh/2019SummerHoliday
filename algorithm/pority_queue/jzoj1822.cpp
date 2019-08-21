#include <cstdio>

using namespace std;

int a[110000],n,tail[110000],tot,f[110000],g[110000],bz[110000],ans;

int min(int x,int y){return x<y?x:y;}

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
	f[t]=1;
	for (int i=tail[t];i;i=e[i].fr)
		if (!bz[e[i].v]) 
		{
			dg(e[i].v);
			f[t]+=min(f[e[i].v],g[e[i].v]);
			g[t]+=f[e[i].v];
		}
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v),add(v,u);
	}
	dg(1);
	printf("%d\n",min(f[1],g[1]));
}