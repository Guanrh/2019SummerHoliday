#include <cstdio>

using namespace std;

struct edge
{int v,fr;}e[31000*2]; int tail[31000],tot;

void add(int u,int v)
{
	e[++tot].v=v;
	e[tot] . fr = tail[u];
	tail[u] = tot;
}

int n,m,ans,bz[11000];

void dg(int x)
{
	if (x==2)
	{
		ans++;
		return;
	}
	for (int i=tail[x];i;i=e[i].fr)
		if (!bz[e[i].v])
		{
			bz[e[i].v]=1;
			dg(e[i].v);
			bz[e[i].v]=0;
		}
}

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
	}
	dg(1);
	printf("%d\n",ans);
}