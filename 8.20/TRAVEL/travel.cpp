#include <cstdio>
#include <algorithm>

using namespace std;

inline int read(int &n)
{
    char ch=' ';int q=0,w=1;
    for(;(ch!='-')&&((ch<'0')||(ch>'9'));ch=getchar());
    if(ch=='-')w=-1,ch=getchar();
    for(;ch>='0' && ch<='9';ch=getchar())q=q*10+ch-48;n=q*w;return n;
}

int abss(int x){return x>0?x:-x;}

int n,m,a[1010][1010],b[1100][1100],tot,st[1000010],en[1000010],cnt,head,tail,nxt[1000100],bz[1100000];
long long ans,dis[1100000];

long long max(long long x,long long y){return x>y?x:y;}

int d[11000000];

struct node
{
    int a,b,x,y;
}x[1000010];

int diss(int a,int b)
{
    return (abss(x[a].x-x[b].x)+abss(x[a].y-x[b].y));
}

int cmp(node a,node b){return a.a<b.a;}

void bfs()
{
    head=0,tail=1;
    int aa;
    while (head<=tail)
    {
       head++;
       aa=nxt[x[d[head]].a];
       bz[d[head]]=0;
       if (aa==-2) continue;
       for (int i=st[aa];i<=en[aa];i++)
       {
            long long val=(d[head]==0?0:diss(d[head],i))+x[i].b;
            if (dis[i]<dis[d[head]]+val)
            {
                dis[i]=dis[d[head]]+val;
                if (!bz[i])
                {
                    bz[i]=1;
                    d[++tail]=i;
                }
            }
       }
    }
    for (int i=0;i<=tot;i++) if (dis[i]>ans) ans=dis[i];
}

int main()
{
    freopen("travel.in","r",stdin);
    read(n),read(m);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            read(a[i][j]);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
        {
             read(b[i][j]);
             if (a[i][j] || b[i][j]) x[++tot]=(node){a[i][j],b[i][j],i,j};
        }
    sort(x+1,x+1+tot,cmp);

    x[0].a=-1;
    for (int i=1;i<=tot+1;i++) 
        if (x[i].a!=x[i-1].a)
            st[x[i].a]=i,en[x[i-1].a]=i-1,nxt[x[i-1].a]=x[i].a;
    nxt[x[tot].a]=-2;

    bfs();

    printf("%lld\n",ans);
}
