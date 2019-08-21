#pragma GCC optimize(3)
#pragma G++ optimize(3)
#include <bits/stdc++.h>

using namespace std;

struct photo
{
	int s,t;
}a[110000];

int n,m,q[110000],h=1,t,cant[110000];

struct edge
{int v,fr,w;}e[110000*2]; int tail[101000],tot,vis[110000],can[110000],cnt,f[210000];
void add(int u,int v)
{
	e[++tot].v=v;
	e[tot] . fr = tail[u];
	tail[u] = tot;
}

int cmp(photo a,photo b){return ((a.s<b.s) || (a.s==b.s && a.t>b.t));}

int main()
{
	//freopen("photo.in","r",stdin);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++) scanf("%d%d",&a[i].s,&a[i].t);
	sort(a+1,a+1+m,cmp);
 	for (int i=1;i<=m;i++) add(a[i].s,i),add(a[i].t,i),f[a[i].s]++,f[a[i].t+1]--;
 	for (int i=1;i<=n;i++)
 	{
 		for (int p=tail[i];p;p=e[p].fr)
 			if (!vis[e[p].v])
 			{
 				q[++t]=e[p].v;
				vis[e[p].v]=1;
 			}
 			else
 			{
 				if (cant[e[p].v]) continue;
 				if (q[h]!=e[p].v) 
 				{
 					while (q[h]!=e[p].v) cant[q[h]]=1,h++;
 					h++;
 				}
 				else
 				{
 					h++;
 				}
 			}
 	}
 	/*for (int i=1;i<=m;i++)
 		if (!cant[i])
 		{
 			printf("%d %d : YES\n",a[i].s,a[i].t);
 		}
 		else printf("%d %d : NO\n",a[i].s,a[i].t);*/
 	memset(tail,0,sizeof tail);
 	memset(vis,0,sizeof vis);
 	memset(q,0,sizeof q);
 	tot=0;
 	h=1;
 	t=0;
 	cnt=0;
 	int ans=0;
 	for (int i=1;i<=m;i++) if (!cant[i]) add(a[i].s,i),add(a[i].t+1,i);
 	for (int i=1;i<=n;i++)
 	{
 		for (int p=tail[i];p;p=e[p].fr)
 			if (!vis[e[p].v])
 			{
 				q[++t]=e[p].v;
				vis[e[p].v]=1;
				cnt++;
 			}
 			else
 			{
 				h++;
 				cnt--;
 			}
 		if (cnt==1) can[q[h]]=1;
 	}
 	for (int i=1;i<=m;i++) if (can[i]) ans++;
 	cnt=0;
 	for (int i=1;i<=n;i++){
 		cnt+=f[i];
 		if (cnt==0) ans++;
 	}
 	printf("%d\n",ans);
}