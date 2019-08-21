#include<bits/stdc++.h>

using namespace std;

struct node
{
	int x,w,c;
}f[1100000];

int n,m,c,b[110][1100],ans;

struct edge
{
	int v,fr,w;
}e[1100]; int tail[110],tot;

void add(int u,int v,int w)
{
	e[++tot].v=v;
	e[tot].fr=tail[u];
	e[tot].w=w;
	tail[u]=tot;
}

void solve()
{
	int head=0,tail=1;
	f[1]=(node){1,0,0};
	memset(b,127,sizeof b);
	while (head<tail)
	{
		++head;
		node now=f[head];
		for (int i=tail[now.x],i;i=e[i].fr)
		{
			int v=e[i].v;
		}
	}
}

int main()
{
	scanf("%d%d%d",&n,&m,&c);
	for (int i=1;i<=m;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w),add(v,u,w);
	}
	ans=999999999;
	solve();
	printf("%d\n",ans);
}
