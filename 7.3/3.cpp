#include<set>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
#define MAXN 110000
int a[MAXN],ans,vis[MAXN],n,t,fa[MAXN],inde[MAXN],tim,op,opp,que[MAXN],f[MAXN][20];
struct line
{
	int u,v;
}ln[MAXN*2];
struct edge
{int v,fr;}e[MAXN*2]; int tail[MAXN],tot;
void add(int u,int v)
{
	e[++tot].v=v;
	e[tot] . fr = tail[u];
	tail[u] = tot;
}
int max(int x,int y){return x>y ? x:y; }
set<int> s;
void dfs(int now)
{
	vis[now]=1;
	for (int i=tail[now];i;i=e[i].fr)
		if (!vis[e[i].v])
		f[e[i].v][0]=now,dfs(e[i].v);
	inde[now]=++tim;
	que[tim]=now;
}
void predo()
{
	for (int j=1;j<=19;j++)
		for (int i=1;i<=n;i++)
			f[i][j]=f[f[i][j-1]][j-1];
}
int cmp(line a,line b){return a.v>b.v;}
int main()
{
	scanf("%d%d",&n,&t);
	for (int i=1;i<=n-1;i++) scanf("%d%d",&ln[i].u,&ln[i].v);
	for (int i=n;i<=n*2-2;i++) ln[i].u=ln[i-n+1].v , ln[i].v=ln[i-n+1].u;
	sort(ln+1,ln+1+2*n-2,cmp);
	for (int i=1;i<=2*n-2;i++) add(ln[i].u,ln[i].v);
	dfs(1);
	predo();
	for (int i=1;i<=n;i++) s.insert(i);
	memset(vis,0,sizeof vis);
	for (int i=1;i<=t;i++)
	{
		scanf("%d%d",&op,&opp);
		if (op==1)
		{
			int tmp=0;
			for (int j=1;j<=opp;j++)
				tmp=*s.begin(),vis[que[tmp]]=1,s.erase(tmp);
			printf("%d\n",que[tmp]);
		}
		else
		{
			int now=opp,tot=0;
			for (int j=19;j>=0;j--)
				if (f[now][j] && vis[f[now][j]]) 
					now=f[now][j],tot+=(1<<j);
			
			printf("%d\n",tot);
			s.insert(inde[now]);
			vis[now]=0;
		}
	}
	return 0;
}
