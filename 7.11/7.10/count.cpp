#include <bits/stdc++.h>
#define mo 2147483647

using namespace std;

struct edge
{int v,fr,w;}e[501000*2]; int tail[1010],tot,dis[1100];

void add(int u,int v,int w)
{
	e[++tot].v=v;
	e[tot] . fr = tail[u];
	e[tot]  .w=w;
	tail[u] = tot;
}

struct node
{
	int x,w;
}d[1100000];

int n,m;
long long ans,in[1100];

void spfa()
{
	memset(dis,127,sizeof dis);
	dis[1]=0;
	d[1].x=1;
	d[1].w=0;
	int h=0,t=1;
	while(h<t)
	{
		++h;
		for (int i=tail[d[h].x];i;i=e[i].fr)
		{
			if (dis[e[i].v]==d[h].w+e[i].w) in[e[i].v]++;
			if (dis[e[i].v]>d[h].w+e[i].w)
			{
				dis[e[i].v]=d[h].w+e[i].w;
				d[++t]=(node){e[i].v,dis[e[i].v]};
				in[e[i].v]=1;
			}
		}
	}
	ans=1;
	for (int i=2;i<=n;i++) ans=(ans*in[i])%mo;
}

int main()
{
	freopen("data10.in","r",stdin);
	freopen("c.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w),add(v,u,w);
	}
	spfa();
	printf("%d\n",ans);
}
