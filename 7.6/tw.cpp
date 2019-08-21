#include<bits/stdc++.h>
#define N 10010
#define inf 2147483647
#define mo 7000007
#pragma GCC optimize(2)
#define open(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout);
using namespace std;

struct edge
{int v,fr,d;}e[100010];
int n,m,k,s,t,i,j,ans,tot;
int f[N][15],tail[N],l[N*1000];

void spfa()
{
	memset(f,127,sizeof f);
	l[1]=s;
	for(i=0;i<=k;i++)f[s][i]=0;
	i=0,j=1;
	while(i++<j)
	{
		int u=l[i % mo];
		for(int p=tail[u];p;p=e[p].fr)
		{
			int v=e[p].v,d=e[p].d,flag=0;
			for(int cnt=0;cnt<=k;cnt++)
			{
				if(f[u][cnt]+d < f[v][cnt])
					f[v][cnt]=f[u][cnt]+d,flag=1;
					
				if(cnt<k && f[u][cnt] < f[v][cnt+1])
					f[v][cnt+1]=f[u][cnt],flag=1;
			}
			if(flag)l[++j % mo]=v;
		}
	}
	
	return ;
}
void add(int u,int v,int d)
{
	e[++tot].v=v;
	e[tot].d=d;
	e[tot].fr=tail[u];
	tail[u]=tot;
}
int main()
{
	//open("motor");
	scanf("%d%d%d",&n,&m,&k);
	scanf("%d %d",&s,&t);
	int u,v,d;
	for(i=1;i<=m;i++)scanf("%d%d%d",&u,&v,&d),add(u,v,d),add(v,u,d);
	spfa();
	ans=inf;
	for(i=0;i<=k;i++)ans=min(ans,f[t][i]);
	printf("%d",ans);
}
