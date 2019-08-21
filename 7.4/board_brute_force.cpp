#include<bits/stdc++.h>
#define mod 1000000007

using namespace std;

int n,m,a[20][20],ans;

void check()
{
	for (int i=2;i<=n;i++)
		for (int j=2;j<=m;j++)
			if (a[i][j]+a[i-1][j]+a[i-1][j-1]+a[i][j-1]!=15) return;
	ans++;
}

void dfs(int x,int y)
{
	if (y>m) x++,y=1;
	if (x>n)
	{
		check();
		return;
	}
	for (int i=0;i<=3;i++)
	{
		a[x][y]=(1<<i);
		//if (a[x][y]==a[x-1][y-1] || a[x][y]==a[x-1][y] || a[x][y]==a[x][y-1]) continue;
		dfs(x,y+1);
	}
}

int main()
{
	scanf("%d%d",&n,&m);
	dfs(1,1);
	printf("%d\n",ans);
}
