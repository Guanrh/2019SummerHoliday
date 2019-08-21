#include<bits/stdc++.h>

using namespace std;

int T,k,n,flag;
int a[1100][1100],dp[1100][1100][2],bz[1100][1100][2],hr[1100][1100],hc[1100][1100];

int dg(int r,int c,int who)
{
	if (r==0 || c==0) return 0;
	if (bz[r][c][who]) return dp[r][c][who];
	if (hr[r][c]%2==0) dp[r][c][who]=!dg(r-1,c,who^1);
	if (hc[r][c]%2==0) dp[r][c][who]|=!dg(r,c-1,who^1);
	bz[r][c][who]=1;
	return dp[r][c][who];
}

int main()
{
	//freopen("game10.in","r",stdin);
	scanf("%d",&T);
	while (T--)
	{
		memset(bz,0,sizeof bz);
		memset(hr,0,sizeof hr);
		memset(hc,0,sizeof hc);
		memset(dp,0,sizeof dp);
		scanf("%d",&n);
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++)
				scanf("%d",&a[i][j]),hr[i][j]=hr[i][j-1]+a[i][j],hc[i][j]=hc[i-1][j]+a[i][j];
		if (dg(n,n,0)) printf("W\n");
		else printf("L\n");
	}
}
