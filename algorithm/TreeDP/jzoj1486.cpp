#include <cstdio>

using namespace std;

int n,m,a[1100],f[1100][1100],tail[1100],tot;

int max(int x,int y){return x>y?x:y;}

struct edge
{
	int fr,v;
}e[3100];

void add(int u,int v)
{
	e[++tot].fr=tail[u];
	e[tot].v=v;
	tail[u]=tot;
}

void dg(int t)
{
	for (int i=tail[t];i;i=e[i].fr)
	{
		dg(e[i].v);
		for (int j=m;j>=1;j--)
			for (int k=1;k<j;k++)
				f[t][j]=max(f[t][j],f[t][j-k]+f[e[i].v][k]);
	}
}

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
	{
		int u;
		scanf("%d%d",&u,&a[i]);
		add(u,i);
	}
	for (int i=1;i<=n;i++) f[i][1]=a[i];
	m++;
	dg(0);
	printf("%d\n",f[0][m]);
}