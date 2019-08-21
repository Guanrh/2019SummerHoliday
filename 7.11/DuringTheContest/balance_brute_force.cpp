#include<bits/stdc++.h>

using namespace std;

int n,m,w[31000],f[31000][25],vis[31000],dep[31000],ww[31000],ans,stk[31000],top;

int max(int x,int y){return x>y?x:y;}
int min(int x,int y){return x<y?x:y;}

struct edge
{int v,fr,w;}e[31000*2]; int tail[31000],tot;

void add(int u,int v,int w)
{
	e[++tot].v=v;
	e[tot].w=w;
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
			w[e[i].v]=w[x]+e[i].w;
			dep[e[i].v]=dep[x]+1;
			dg(e[i].v);
		}
}

int main()
{
	memset(vis,0,sizeof vis);
	scanf("%d",&n);
	for (int i=1;i<=n-1;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		if(w==0) w=-1;
		add(u,v,w),add(v,u,w);
	}
	dep[1]=1;
	dg(1);
	for (int i=1;i<=n-1;i++)
		for (int j=i+1;j<=n;j++)
		{
			int now1,now2;
			top=0;
			if (dep[i]>dep[j]) now1=i,now2=j;
			else now1=j,now2=i;
			while (dep[now1]>dep[now2]) now1=f[now1][0],stk[++top]=now1;
			while (now1!=now2) now1=f[now1][0],now2=f[now2][0],stk[++top]=now1,stk[++top]=now2;
			int lca=now1;
			
			int w1=w[i]+w[j]-2*w[lca];
			if (w1!=0) continue;
			for (int k=1;k<=top;k++)
			{
				if (stk[k]==i || stk[k]==j) continue;
				int w2=w[i]+w[stk[k]]-2*w[lca];
				if (w2==0) ans++;
			}
		}
	printf("%d\n",ans);
	//for (int i=1;i<=n;i++) printf("%d\n",w[i]);
}
