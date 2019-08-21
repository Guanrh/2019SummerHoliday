#include <bits/stdc++.h>

using namespace std;

int n,m,u[1100],v[1100],w[1100][1100],W,b[1100],dis[1100][1100],dis2[1100][1100],ans;

void dfs(int x,int left)
{
	if (x>m)
	{
		if (left!=0) return;
		memcpy(dis2,w,sizeof w);
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++)
				for (int k=1;k<=n;k++)
					if (i!=j && j!=k && i!=k && dis2[i][k]+dis2[k][j]<dis2[i][j])
						dis2[i][j]=dis2[i][k]+dis2[j][k];
		int flag=1;
		for (int i=1;i<=n;i++) if (dis[1][i]!=dis2[1][i]) flag=0;
		if (flag) ans++;
		return;
	}
	else
	{
		dfs(x+1,left);
		int tmp=w[u[x]][v[x]];
		w[u[x]][v[x]]=w[v[x]][u[x]]=1<<29;
		dfs(x+1,left-1);
		w[u[x]][v[x]]=w[v[x]][u[x]]=tmp;
	}
}

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) w[i][j]=1<<29;
	for (int i=1;i<=n;i++) scanf("%d%d%d",&u[i],&v[i],&W),w[u[i]][v[i]]=w[v[i]][u[i]]=W;
	memcpy(dis,w,sizeof w);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			for (int k=1;k<=n;k++)
				if (i!=j && j!=k && i!=k && dis[i][k]+dis[k][j]<dis[i][j])
					dis[i][j]=dis[i][k]+dis[j][k];
					
	memset(b,true,sizeof b);
	dfs(1,m-n+1);
	printf("%d\n",ans);
}
