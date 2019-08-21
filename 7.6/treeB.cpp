#include<bits/stdc++.h>

using namespace std;

struct edge
{int v,fr,w;}e[1100000*2]; int tail[1010000],tot,vis[1100000],tag[1100000];

int min(int x,int y){return x<y?x:y;}

void add(int u,int v,int w)
{
	e[++tot].v=v;
	e[tot] . fr = tail[u];
	e[tot]  .w=w;
	tail[u] = tot;
}

int n,m,x[1100000],ans,f[1100000];

void dg(int now,int fa)
{
	//printf("%d\n",now);
	int cur;
		vis[now]=1;
	for (int i=tail[now];i;i=e[i].fr)
		if (e[i].v!=fa)
			dg(e[i].v,now);
		else cur=i;
	if (tag[now])
		f[fa]+=e[cur].w;
	else
		f[fa]+=min(f[now],e[cur].w);
}

int main()
{
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	ans=999999999;
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n-1;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w),add(v,u,w);	
		//if (u==1 || v==1)printf("!!!! %d\n",i);
	} 
	
	for (int i=1;i<=m;i++) scanf("%d",&x[i]),tag[x[i]]=1;;
	
	dg(1,0);
	printf("%d\n",f[1]);
}
