#include <bits/stdc++.h>
#define N 3100

int f[N][N],g[N],lim,n,w[N],ans=0;

struct edge
{int v,fr;}e[N*2]; int tail[N*2],tot;

void add(int u,int v)
{
	e[++tot].v=v;
	e[tot] . fr = tail[u];
	tail[u] = tot;
}

int max(int x,int y){return x>y?x:y;}

void dg(int x,int fa)
{
	for (int i=tail[x];i;i=e[i].fr)
		if (e[i].v!=fa)
		{
			memcpy(f[e[i].v],f[x],sizeof f[x]);
			dg(e[i].v,x);
			for (int j=1;j<=lim;j++) f[x][j]=max(f[x][j],f[e[i].v][j-1]+w[e[i].v]);
		}
}

int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%d%d",&n,&lim);
	for (int i=1;i<=n;i++) scanf("%d",&w[i]);
	for (int i=1;i<=n-1;i++) 
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v),add(v,u);
	}
	dg(1,0);
	for (int i=0;i<lim;i++) ans=max(ans,f[1][i]);
	printf("%d\n",ans+w[1]);
}