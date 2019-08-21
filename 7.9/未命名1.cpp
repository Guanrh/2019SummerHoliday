#include <stdio.h>
#include <queue>
using namespace std;
struct status
{
    int x,k;
};
queue<status>q;
bool v[1001][1001];
int dis[1001][1001],f[1001][1001],a[1001][1001];
int main()
{
	freopen("travel10.in","r",stdin);
	freopen("2.out","w",stdout);
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for (int i=0;i<=n;i++)
        for (int j=0;j<=n;j++)
        {
            f[i][j]=1<<28-1;
            a[i][j]=1<<28-1;
        }
    for (int i=1;i<=m;i++)
    {
        int x,y,w;
        scanf("%d%d%d",&x,&y,&w);
        if (a[x][y]>w)
            a[x][y]=w;
        f[x][y]=a[x][y];
    }
    
    for (int k=1;k<=n;k++)
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
                if (i!=j&&i!=k&&i!=k&&f[i][k]+f[k][j]<f[i][j])
                    f[i][j]=f[i][k]+f[k][j];
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            if (f[j][i]==f[0][0]&&a[i][j]!=a[0][0])
                a[i][j]*=2;
                
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
			printf("%d ",f[i][j]);
		printf("\n");
	}
    for (int i=0;i<=n;i++)
        for (int j=0;j<=k;j++)
            dis[i][j]=1<<28-1;
    dis[1][0]=0;
    q.push((status){1,0});
    v[1][0]=true;
    while (q.size())
    {
        status s=q.front();
        int now=s.x;
        int tmp=s.k;
        q.pop();
        for (int i=1;i<=n;i++)
            if (a[now][i]!=a[0][0])
            {
                if (f[i][now]==f[0][0])
                if (dis[now][tmp]+a[now][i]<dis[i][tmp+1]&&tmp<k)
                {
                    dis[i][tmp+1]=dis[now][tmp]+a[now][i];
                    if (!v[i][tmp+1])
                    {
                        v[i][tmp+1]=true;
                        q.push((status){i,tmp+1});
                    }
                }
                if (f[i][now]!=f[0][0])
                if (a[now][i]+dis[now][tmp]<dis[i][tmp])
                {
                    dis[i][tmp]=a[now][i]+dis[now][tmp];
                    if (!v[i][tmp])
                    {
                        v[i][tmp]=true;
                        q.push((status){i,tmp});
                    }
                }
            }
        v[now][tmp]=false;
    }
    int ans=1<<28-1;
    for (int i=0;i<=k;i++)
        if (dis[n][i]<ans)
            ans=dis[n][i];
    if (ans>=a[0][0])
        ans=-1;
    printf("%d\n",ans);
    return 0;
}
