#include <bits/stdc++.h>

using namespace std;

struct photo
{
	int s,t;
}a[110000];

int n,m,cant[110000],q[210000],cnt=0,ans=0,f[210000],now,h,t;

struct edge
{int v,fr,w;}e[110000*2]; int tail[101000],tot,vis[110000];
void add(int u,int v)
{
	e[++tot].v=v;
	e[tot] . fr = tail[u];
	tail[u] = tot;
}

int cmp(photo a,photo b){return ((a.s<b.s) || (a.s==b.s && a.t>b.t));}

int main()
{
	freopen("photo.in","r",stdin);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++) scanf("%d%d",&a[i].s,&a[i].t);
	sort(a+1,a+1+m,cmp);
 	for (int i=1;i<=m;i++) add(a[i].s,i),add(a[i].t,i);
	h=1;
	t=0;
	for (int i=1;i<=n;i++)
	{
		int flag=1;
		for (int p=tail[i];p;p=e[p].fr) 
			if (!vis[e[p].v])
			{
				vis[e[p].v]=1;
				q[++t]=e[p].v;
				cnt++;
				flag=0;
			}
			else
			{
				while (cant[h]) ++h,--cnt;
				if (q[h]!=e[p].v) cant[e[p].v]=1;
				flag=0;
			}
		if (cnt==0 && flag) ans++;
	}
	for (int i=1;i<=m;i++) if (!cant[i]) ans++;
	printf("%d\n",ans);
}
