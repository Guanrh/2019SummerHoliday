#include<bits/stdc++.h>
#define N 110000
#define mod 10081

using namespace std;

struct edge
{int v,fr;}e[N*2]; int tail[N],tot;

void add(int u,int v)
{
	e[++tot].v=v;
	e[tot] . fr = tail[u];
	tail[u] = tot;
}

int n,f[N],g[N];

void sol(int x,int fa)
{
	f[x]=g[x]=1;
	for (int i=tail[x];i;i=e[i].fr)
		if (e[i].v!=fa)
		{
			sol(e[i].v,x);
			f[x]=(f[x]*g[e[i].v])%mod;
			g[x]=(g[x]*(f[e[i].v]+g[e[i].v]))%mod;
		}
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n-1;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v),add(v,u);
	}
	sol(1,0);
	printf("%d\n",(f[1]+g[1])%mod);
}
