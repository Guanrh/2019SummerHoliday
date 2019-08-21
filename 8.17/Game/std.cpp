#include<cstdio>
#include<cstring>
#include<iostream>
using std::min;

int n,m,r,c,i,j,ans;
bool bz1[15],bz2[15];
char s[15][15];
void dg(int t,int sum)
{
    int i,j;
    if(t>n)
    {
        memset(bz2,false,sizeof(bz2));
        for(j=1;j<=m;j++)
            for(i=1;i<=n;i++)
                if(!bz1[i]&&s[i][j]=='X') bz2[j]=true;
        for(i=1;i<=m;i++)
            if(bz2[i])
            {
                for(j=1;j<=c;j++) bz2[min(j+i-1,m)]=false;
                sum++;
            }   
        if(sum<ans) ans=sum;
        return;
    }
    if(!bz1[t])
    {
        for(i=1;i<=r;i++) bz1[min(i+t-1,n)]=true;
        dg(t+1,sum+1);
        for(i=1;i<=r;i++) bz1[min(i+t-1,m)]=false;   
    }
    dg(t+1,sum);
}
int main()
{
    scanf("%d%d\n",&n,&m);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++) scanf("%c",&s[i][j]);
        scanf("\n");
    }
    scanf("%d%d",&r,&c);
    ans=2147483647;
    dg(1,0);
    printf("%d",ans);  
}