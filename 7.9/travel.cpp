#include<bits/stdc++.h>

using namespace std;

int can[110][110],n,m,k,f[110][20],d[15000000],w[110][110],vis[110],ww[110][110];
struct edge
{int v,fr,w;}e[11000]; int tail[110],tot;

int max(int x,int y){return x>y?x:y;}
int min(int x,int y){return x<y?x:y;}

void add(int u,int v,int w)
{
	e[++tot].v=v;
	e[tot] . fr = tail[u];
	e[tot]  .w=w;
	tail[u] = tot;
}

void spfa()
{
	memset(f,127,sizeof f);
	d[1]=1;
	for (int i=0;i<=k;i++) f[1][i]=0;
	//f[1][0]=0;
	int h=0,t=1;
	while (h++<t)
	{
		int now=d[h];
		vis[now]=1;
		for (int i=tail[now];i;i=e[i].fr)
		{
			int v=e[i].v,flag=0;
			for (int cnt=0;cnt<=k;cnt++)
			{
				if (can[now][v] && f[now][cnt]+e[i].w<f[v][cnt]) f[v][cnt]=f[now][cnt]+e[i].w,flag=1;
				if (cnt<k && !can[now][v] && f[now][cnt]+e[i].w*2<f[v][cnt+1]) f[v][cnt+1]=f[now][cnt]+e[i].w*2,flag=1;
			}
			if (flag) d[++t]=v;
		}
	}
	return;
}

void predo()
{
	memset(can,true,sizeof can);
	for (int k=1;k<=n;k++)
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++)
				if (w[i][k]+w[k][j]<w[i][j])
						w[i][j]=w[i][k]+w[k][j];
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			if (w[j][i]==w[0][0] && ww[i][j]!=ww[0][0])
				can[i][j]=can[j][i]=0;
}

int main()
{
	//freopen("travel10.in","r",stdin);
	//freopen("1.out","w",stdout);
	memset(w,0x3f,sizeof w);
	memset(ww,0x3f,sizeof ww);
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1;i<=m;i++) 
	{
		int u,v,W;
		scanf("%d%d%d",&u,&v,&W);
		w[u][v]=min(w[u][v],W);
		ww[u][v]=w[u][v];
		add(u,v,W);
	}
	predo();
	spfa();
	int ans=2139062143;
	for (int i=0;i<=k;i++) ans=min(ans,f[n][i]);
	if (ans!=2139062143) printf("%d\n",ans);
	else printf("-1\n");
}
