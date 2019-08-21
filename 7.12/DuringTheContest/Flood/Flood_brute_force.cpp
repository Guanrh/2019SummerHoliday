#include <bits/stdc++.h>

using namespace std;

struct edge
{int v,fr;}e[210000]; int tail[21000],tot;

void add(int u,int v)
{
	e[++tot].v=v;
	e[tot] . fr = tail[u];
	tail[u] = tot;
}

struct food
{
	int x,y,z;
}a[110000];

int n,m,tmp[110000],cnt,T,pre[2100],vis[2100],f[2100][2100],mx1[2100],mx2[2100];

int cmp(food a,food b){return a.z<b.z;}

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

void doit(int x,int y,int z)
{
	T=y;
	memset(vis,0,sizeof vis);
	memset(pre,0,sizeof pre);
	pre[x]=-1;
	vis[x]=1;
	dg(x);
	while (y!=-1)
	{
		f[y][z]++;
		y=pre[y];
	}
}

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n-1;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v),add(v,u);
	}
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
		//tmp[i]=a[i].z
	}
	sort(a+1,a+1+m,cmp);
	cnt=0;
	for (int i=1;i<=m;i++)
	{
		if (a[i].z>a[i-1].z) cnt++;
		tmp[cnt]=a[i].z;
		doit(a[i].x,a[i].y,cnt);
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
			if (f[i][j]>mx1[i])
			{
				mx1[i]=f[i][j];
				mx2[i]=j;
			}
	}
	for (int i=1;i<=n;i++) printf("%d\n",tmp[mx2[i]]);
}
