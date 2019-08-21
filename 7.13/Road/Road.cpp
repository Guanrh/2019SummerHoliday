#include<bits/stdc++.h>
#define MAXN 110
#define MAXM 11000

using namespace std;

int D,u[MAXM],v[MAXM],w[MAXN][MAXN],A,B,f[MAXN][MAXN];

int min(int x,int y){return x<y?x:y;}

int n,m,S;

int main()
{
	//freopen("spfa.in","r",stdin);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d",&n,&m);
	memset(f,0x3f,sizeof f);
	int wei,x,y;
	for (int i=1;i<=m;i++) scanf("%d%d%d",&x,&y,&wei),w[x][y]=w[y][x]=wei,f[x][y]=f[y][x]=0;
	scanf("%d",&D);
	for (int i=1;i<=D;i++)
	{
		scanf("%d%d",&x,&y);
		f[x][y]=f[y][x]=w[x][y];
	}

	for (int k=1;k<=n;k++)
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++)
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);

	scanf("%d%d",&A,&B);
	printf("%d\n",f[A][B]);
}
