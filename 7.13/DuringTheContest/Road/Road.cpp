#include<bits/stdc++.h>
#define MAXN 110
#define MAXM 11000

using namespace std;

struct edge
{int v,fr,w;}e[MAXM]; 
int tail[MAXN],tot,dis[MAXN],q[5100000],h,t,vis[MAXN],pre[MAXN],id[MAXN][MAXN],D,u[MAXM],v[MAXM],w[MAXM],A,B,is_broken[MAXN];

void add(int u,int v,int w)
{
	e[++tot].v=v;
	e[tot] . fr = tail[u];
	e[tot] .w = w;
	tail[u] = tot;
}

int n,m,S;

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
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++) scanf("%d%d%d",&u[i],&v[i],&w[i]),id[u[i]][v[i]]=i;
	scanf("%d",&D);
	for (int i=1;i<=D;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		int rd=id[x][y];
		add(u[rd],v[rd],w[rd]);
		add(v[rd],u[rd],w[rd]);
		is_broken[rd]=1;
	}
	for (int i=1;i<=m;i++)
		if (!is_broken[i])
		{
			add(u[i],v[i],0);
			add(v[i],u[i],0);
		}
	scanf("%d%d",&A,&B);
	S=A;
	spfa();
	//for (int i=2;i<=n;i++) printf("%d\n",dis[i]);
	printf("%d\n",dis[B]);
}
