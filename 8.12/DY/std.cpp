#include<cstdio>
#include<cstdlib>
#include<cstring>
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fod(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
const int N=350,FAIL=2139062140;
int read(int &n)
{
    char ch=' ';int q=0,w=1;
    for(;(ch!='-')&&((ch<'0')||(ch>'9'));ch=getchar());
    if(ch=='-')w=-1,ch=getchar();
    for(;ch>='0' && ch<='9';ch=getchar())q=q*10+ch-48;n=q*w;return n;
}
int n,m,ans,L,K,m1,m2;
int a[N][N];
int s[N];
int b[N][N],de[N];
int d[N*N*100],d1[35][N],dd[N*N*100];
bool z[N][N];
int min(int a,int b){return a>b?b:a;}
int max(int a,int b){return a<b?b:a;}
void spfas(int q)
{
    int i=1,j=1;
    d[1]=q;z[0][q]=1;
    memset(s,60,sizeof(s));
    s[q]=m1;
    while(i<=j)
    {
        q=d[i++];
        fo(k,0,n)if(a[q][k]+s[q]<s[k])
        {
            s[k]=a[q][k]+s[q];
            if(!z[0][k])z[0][k]=1,d[++j]=k;
        }
        z[0][q]=0;
    }
    fod(i,n,1)s[i]-=s[i-1];
}
void spfa(int q)
{
    int i=1,j=1,w;
    d[1]=q;z[0][q]=1;
    memset(d1,60,sizeof(d1));
    d1[0][q]=0;
    while(i<=j)
    {
        q=d[i];w=dd[i++];
        fo(k,1,n)
        {
            if(b[q][k]+d1[w][q]<d1[w][k])
            {
                d1[w][k]=b[q][k]+d1[w][q];
                if(!z[w][k])z[w][k]=1,d[++j]=k,dd[j]=w;
            }
            if(b[q][k]<=L&&w<K&&d1[w][q]<d1[w+1][k])
            {
                d1[w+1][k]=d1[w][q];
                if(!z[w+1][k])z[w+1][k]=1,d[++j]=k,dd[j]=w+1;
            }
        }
        z[w][q]=0;
    }
}
int main()
{
    int q,w,e;
    memset(a,60,sizeof(a));memset(b,60,sizeof(b));
    read(n),read(m1),read(m),read(m2),read(L),read(K);
    fo(i,1,m)read(q),read(w),b[w][q]=b[q][w]=min(b[q][w],read(e));
    fo(i,1,n+1)a[i][i-1]=min(a[i][i-1],0),a[i-1][i]=min(a[i-1][i],1);
    fo(i,1,m2)read(q),read(w),a[w][q-1]=min(a[w][q-1],-read(e));
    spfas(n+1);
    fo(k,1,n)
        fo(i,1,n)if(i!=k)
            fo(j,1,n)if(j!=i&&j!=k&&!s[k])b[i][j]=min(b[i][j],b[i][k]+b[k][j]);
    spfa(1);
    ans=FAIL;
    fo(i,0,K)ans=min(ans,d1[i][n]);
    printf("%d\n",ans);
    for (int i=1;i<=n;i++) if (s[i]) printf("!%d\n",i);
    return 0;
}