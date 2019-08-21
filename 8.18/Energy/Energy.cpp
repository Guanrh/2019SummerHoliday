#include <cstdio>

using namespace std;

int f[1100][110],n,a[1100],mx[1100];

struct edge
{int v,fr,w;}e[1100*2]; int tail[1100],tot;

void add(int u,int v,int w)
{
	e[++tot].v=v;
	e[tot] .w = w;
	e[tot] . fr = tail[u];
	tail[u] = tot;
}

int min(int x,int y){return x<y?x:y;}
int max(int x,int y){return x>y?x:y;}

void dfs(int x,int rest)
{
	if (rest>=a[x] && x!=0)
		f[x][rest]=max(1,f[x][rest]);
	for (int i=tail[x];i;i=e[i].fr)
	{
		for (int j=1;j<=min(rest,e[i].w);j++)
			dfs(e[i].v,j);
		for (int k=mx[x];k>=1;k--)
			for (int j=1;j<=min(rest,e[i].w) && j<=k;j++)
					f[x][k]=max(f[x][k],f[x][k-j]+f[e[i].v][j]);
	}
	return;
}

int main()
{
	//freopen("test.in","r",stdin);
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		int u,w;
		scanf("%d%d%d",&u,&a[i],&w);
		add(u,i,w);
		mx[u]+=w;
	}
	a[0]=105;
	dfs(0,999999999);
	int ans=0;
	for (int i=1;i<=mx[0];i++) ans=max(ans,f[0][i]);
	printf("%d",ans);
	//printf("%d\n",f[0][mx[0]]);
}
