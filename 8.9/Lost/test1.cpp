//这里写代码片
#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

const int INF=1e9+1;
const int p=2009;
int n,T,mp[10][10],f[20];
char s[10];
struct node{
    int H[100][100];
    node operator *(const node &a) const
    {
        node ans;
        for (int i=1;i<=S;i++)
            for (int j=1;j<=S;j++)
            {
                ans.H[i][j]=0;
                for (int k=1;k<=S;k++)
                    ans.H[i][j]=(ans.H[i][j]+H[i][k]*a.H[k][j]%p)%p;
            }
        return ans;
    }
    void clear()
    {
        memset(H,0,sizeof(H));
    }
    node KSM(int pp)
    {
        node ans=(*this),a=(*this);
        pp--;
        while (pp)
        {
            if (pp&1)
               ans=ans*a;
            a=a*a;
            pp>>=1;
        }
        return ans;
    }
};
node H,ans;

void build()
{
    int i,j;
    H.clear();
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
        {
            if (!mp[i][j]) continue;
            int f1=(i-1)*9;
            int f2=(j-1)*9;
            H.H[f1+mp[i][j]][f2+1]=1;
        }
    for (int i=1;i<=n;i++)
        for (int j=2;j<=9;j++)
            H.H[(i-1)*9+j-1][(i-1)*9+j]=1;
}

int main()
{
    scanf("%d%d",&n,&T);
    for (int i=1;i<=n;i++)
    {
        scanf("%s",s+1);
        for (int j=1;j<=n;j++)
            mp[i][j]=s[j]-'0';      
    }
    build();
    ans=H.KSM(T);
    printf("%d",ans.H[1][(n-1)*9+1]%p);
    return 0;
}