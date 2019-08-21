#include <cstdio>
#include <cstring>
const int mo=1e9;

using namespace std;

struct edge
{int v,fr;}e[110000]; int tail[11000],tot,flag;

void add(int u,int v)
{
	e[++tot].v=v;
	e[tot] . fr = tail[u];
	tail[u] = tot;
}

int n,m;
int f[11000]; 

int dfs(int x)
{
	if (f[x]!=-1) return f[x];
	f[x]=0;
	for (int i=tail[x];i;i=e[i].fr)
	{
		f[x]+=dfs(e[i].v);
		if (f[x]>=mo) f[x]%=mo,flag=1;
	}
	return f[x];
}

int main()
{
	flag=0;
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
	}
	memset(f,-1,sizeof f);
	f[2]=1;
	dfs(1);
	if (!flag) printf("%d\n",f[1]);
	else printf("%09d",f[1]);
}