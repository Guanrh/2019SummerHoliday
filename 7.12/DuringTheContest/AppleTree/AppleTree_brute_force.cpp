#include<bits/stdc++.h>

using namespace std;

int n,m,coli[51000],vis[51000],bz[51000],pre[110];

struct edge
{int v,fr;}e[210000]; int tail[21000],tot,T;

void add(int u,int v)
{
	e[++tot].v=v;
	e[tot] . fr = tail[u];
	tail[u] = tot;
}

void dg(int x)
{
	if (x==T) return;
	for (int i=tail[x];i;i=e[i].fr)
		if(!vis[e[i].v])
		{
			pre[e[i].v]=x;
			vis[e[i].v]=1;
			dg(e[i].v);
		}
}

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&coli[i]);
	for (int i=1;i<=n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v),add(v,u);
	}
	for (int i=1;i<=m;i++)
	{
		int u,v,a,b;
		scanf("%d%d%d%d",&u,&v,&a,&b);
		memset(vis,0,sizeof vis);
		memset(bz,0,sizeof bz);
		memset(pre,0,sizeof pre);
		T=v;
		pre[u]=-1;
		vis[u]=1;
		dg(u);
		while (v!=-1)
		{
			bz[coli[v]]=1;
			v=pre[v];
		}
		bz[b]=bz[a];
		bz[a]=0;
		int cnt=0;
		for (int i=1;i<=n;i++) if (bz[i]) cnt++;
		printf("%d\n",cnt);
	}
}
