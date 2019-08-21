#include<bits/stdc++.h>
#define MAXN 1100
#define MAXM 110000

using namespace std;

struct edge
{int v,fr,w;}e[MAXM]; int tail[MAXN],tot,dis[MAXN],q[5100000],h,t,vis[MAXN],pre[MAXN];

void add(int u,int v,int w)
{
	e[++tot].v=v;
	e[tot] . fr = tail[u];
	e[tot] .w = w;
	tail[u] = tot;
}

int n,m,S,T;

void spfa()
{
	memset(dis,127,sizeof dis);
	memset(vis,0,sizeof vis);
	dis[S]=0;
	vis[S]=1;
	q[1]=S;
	h=t=1;
	while (h<=t)
	{
		int now=q[h];
		for (int i=tail[now];i;i=e[i].fr)
		{
			int v=e[i].v;
			if (dis[v]>dis[now]+e[i].w)
			{
				dis[v]=dis[now]+e[i].w;
				pre[v]=now;
				if (!vis[v])
				{
					vis[v]=1;
					q[++t]=v;
				}
			}
		}
		vis[now]=0;
		h++;
	}
}

int main()
{
	//freopen("spfa.in","r",stdin);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w);
		//add(v,u,w);
	}
	S=1;
	T=n;
	spfa();
	for (int i=2;i<=n;i++) printf("%d\n",dis[i]);
}
