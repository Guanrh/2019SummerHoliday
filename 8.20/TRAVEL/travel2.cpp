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

int n,m,a[1010][1010],b[1100][1100],tot,st[1000010],en[1000010],cnt,head,tail,nxt[1000100],dis[1100000];
long long ans;

long long max(long long x,long long y){return x>y?x:y;}

struct node
{
    int a,b,x,y;
}x[1000010];

int cmp(node a,node b){return a.a<b.a;}

void init()
{
    head=1;
    for (int i=1;i<=tot;i++)
    {
    	if (x[i].a!=x[1].a) return;
    	d[++tail].sum=x[i].b;
    	d[tail].a=x[i].a;
    	d[tail].x=x[i].x;
    	d[tail].y=x[i].y;
	}
}

void bfs()
{
    init();
    int aa;
    while (head<=tail)
    {
        aa=nxt[d[head].a];
        if (aa==-2)
        {
            head++;
            continue;
        }
        for (int i=st[aa];i<=en[aa];i++)
        {
            tail++;
            d[tail].x=x[i].x;
            d[tail].y=x[i].y;
            d[tail].a=aa;
            d[tail].sum=d[head].sum+x[i].b+abs(x[i].x-d[head].x)+abs(x[i].y-d[head].y);
            if (aa==x[tot].a)
            {
                ans=max(ans,d[tail].sum);
            }
        }
        head++;
    }
}

int main()
{
    //freopen("travel.in","r",stdin);
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