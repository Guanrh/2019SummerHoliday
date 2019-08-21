#include<bits/stdc++.h>

using namespace std;

int n,m,w[31000],f[31000][25],vis[31000],dep[31000],ww[31000];

int max(int x,int y){return x>y?x:y;}
int min(int x,int y){return x<y?x:y;}

struct edge
{int v,fr;}e[31000*2]; int tail[31000],tot;

void add(int u,int v)
{
	e[++tot].v=v;
	e[tot] . fr = tail[u];
	tail[u] = tot;
}

void dg(int x)
{
	vis[x]=1;
	for (int i=tail[x];i;i=e[i].fr)
		if (!vis[e[i].v])
		{
			f[e[i].v][0]=x;
			w[e[i].v]+=w[x];
			dep[e[i].v]=dep[x]+1;
			dg(e[i].v);
		}
}

void predo()
{
	f[1][0]=1;
	for (int j=1;j<=21;j++)
		for (int i=1;i<=n;i++)
			f[i][j]=f[f[i][j-1]][j-1];
}

void change(int now,int val)
{
	w[now]+=val;
	for (int i=tail[now];i;i=e[i].fr)
		if (e[i].v!=f[now][0])
			change(e[i].v,val);
}

int lca(int x,int y)
{
	int tmp1=x,tmp2=y;
	if (dep[x]<dep[y]) x=tmp2,y=tmp1;
	for (int i=21;i>=0;i--)
		if (dep[f[x][i]]>=dep[y]) x=f[x][i];
	if (x==y) return x;
	for (int i=19;i>=0;i--)
		if (f[x][i]!=f[y][i])
			x=f[x][i],y=f[y][i];
	return f[x][0];
}

int main()
{
	memset(vis,0,sizeof vis);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n-1;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v),add(v,u);
	}
	for (int i=1;i<=n;i++) scanf("%d",&w[i]),ww[i]=w[i];
	dep[1]=1;
	dg(1);
	predo();
	for (int i=1;i<=m;i++)
	{
		int op,A,B;
		scanf("%d%d%d",&op,&A,&B);
		if (op==1)
		{
			change(A,B-ww[A]);
			ww[A]=B;
		}
		else
		{
			int wz=lca(A,B);
			printf("%d\n",w[A]+w[B]-2*w[wz]+ww[wz]);
		}
	}
}
