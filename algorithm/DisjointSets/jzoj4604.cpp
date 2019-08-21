#include <cstdio>

using namespace std;

struct edge
{
	int fr,next;
}e[210000];
int fa[110000],father[110000],n,tail[110000],tot,op[110000],c[110000],bz[110000],q;

void add(int u,int v)
{
	e[++tot].v=v;
	e[tot].fr=tail[u];
	tail[u]=tot;
}

int find(int x)   
{
    if (x != fa[x])
    {
        fa[x] = find(fa[x]); 
    }       
    return fa[x];
}

int main()
{
	scanf("%d%d",&n,&q);
	for (int i=1;i<=n-1;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v),add(v,u);
	}
	//for (int i=1;i<=n;i++) scanf("%d%d",&op[i],&c[i]);
}