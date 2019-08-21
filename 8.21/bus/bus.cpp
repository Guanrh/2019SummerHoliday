#include <cstdio>
#include <cstring>

using namespace std;

struct edge
{int v,fr;}e[5000]; int tail[65],tot;

void add(int u,int v)
{
	e[++tot].v=v;
	e[tot] . fr = tail[u];
	tail[u] = tot;
}

int n,m,K,flag,bz[65],dis[65],pre[65],d[100000],ex[65],ans,h,t;

int min(int x,int y){return x<y?x:y;}

void spfa()
{
	memset(bz,0,sizeof bz);
	memset(dis,0x3f,sizeof dis);
	memset(pre,0,sizeof pre);
	h=t=1;
	d[h]=1;bz[1]=1;dis[1]=0;

	while (h<=t)
	{
		int now=d[h];
		bz[now]=0;
		for (int i=tail[now];i;i=e[i].fr)
			if (ex[e[i].v] && dis[now]+1<dis[e[i].v])
			{
				dis[e[i].v]=dis[now]+1;
				pre[e[i].v]=now;
				if (!bz[e[i].v])
				{
					d[++t]=e[i].v;
					bz[e[i].v]=1;
				}
			}
		h++;
	}
}

void dfs(int cnt)
{
	if (cnt>=ans) return;
	spfa();
	if (dis[n]>K)
	{
		ans=cnt;
		return;
	}
	int cur=pre[n],route[65],count=0;;
	
	while (cur!=0)
	{
		route[++count]=cur;
		cur=pre[cur];
	}
	for (int i=1;i<=count;i++)
		if (route[i]!=1)
		{
			ex[route[i]]=0;
			dfs(cnt+1);
			ex[route[i]]=1;
		}
	return;
}

int main()
{
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
	scanf("%d%d%d",&n,&m,&K);
	for (int i=1;i<=n;i++) ex[i]=1;
	for (int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
	}
	ans=999999999;
	dfs(0);
	printf("%d\n",ans);
	return 0;
}

