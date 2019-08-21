//#pragma GCC optimize(3)
//#pragma G++ optimize(3)
#include<bits/stdc++.h>

using namespace std;

int n,m,c,l,r,mid,ans,flag,cnt,f[110][1100],d[11000000];

struct edge
{
	int v,fr,w;
}e[1100]; 
int tail[1100],tot;

void add(int u,int v,int w)
{
	e[++tot].v=v;
	e[tot].fr=tail[u];
	e[tot].w=w;
	tail[u]=tot;
}

int max(int x,int y){return x>y?x:y;}
int min(int x,int y){return x<y?x:y;}

int cmp(int a,int b){return a>b;}


void spfa(int x)
{
	memset(f,127,sizeof f);
	d[1]=1;
	for (int i=0;i<=x;i++) f[1][i]=0;
	int h=0,t=1;
	while (h++<t)
	{
		int now=d[h];
		for (int i=tail[now];i;i=e[i].fr)
		{
			int v=e[i].v,flag=0;
			for (int cnt=0;cnt<=x;cnt++)
			{
				if (f[now][cnt]+e[i].w<f[v][cnt]) f[v][cnt]=f[now][cnt]+e[i].w,flag=1;
				if (cnt+1<=x && f[now][cnt]<f[v][cnt+1]) f[v][cnt+1]=f[now][cnt],flag=1;
			}
			if (flag) d[++t]=v;
		}
	}
	return;
}

int main()
{
	scanf("%d%d%d",&n,&m,&c);
	for (int i=1;i<=m;i++)
	{
		int u,v,W;
		scanf("%d%d%d",&u,&v,&W);
		add(u,v,W);
	}
	l=1;
	r=m;
	ans=m;
	while (l<=r)
	{
		mid=(l+r)/2;
		spfa(mid);
		int len=999999999;
		for (int i=0;i<=mid;i++) len=min(len,f[n][i]);
		if (len<=c)
		{
			r=mid-1;
			ans=min(ans,mid);
		}
		else l=mid+1;
	}
	printf("%d\n",ans);
}
