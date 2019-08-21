#include<bits/stdc++.h>

using namespace std;

int n,a[510],b[510],ans,f[2][110000][510];
bool vis[510][510];

int main()
{
	scanf("%d",&n);
	int tmp;
	for (int i=1;i<=n;i++) scanf("%d",&tmp),a[tmp]=i;
	for (int i=1;i<=n;i++) scanf("%d",&tmp),b[tmp]=i;
	for (int i=1;i<=n-1;i++)
		for (int j=i+1;j<=n;j++)
			if ((a[j]<a[i] && b[j]>b[i]) || (a[j]>a[i] && b[j]<b[i]))
				vis[i][j]=vis[j][i]=1,ans=2;
				
	for (int i=1;i<=n-2;i++)
		for (int j=i+1;j<=n-1;j++)
			if (vis[i][j])
				for (int k=j+1;k<=n;k++)
					if (vis[i][k] && vis[j][k])
					{
						f[1][0][0]++;
						f[1][f[1][0][0]][1]=i;
						f[1][f[1][0][0]][2]=j;
						f[1][f[1][0][0]][3]=k;
						ans=3;
					}
					
	for (int i=4;i<=n;i++)
	{
		
		int now=i%2;
		f[now][0][0]=0;
		int last=(now==1)?0:1;
		int ok=0;
		for (int j=1;j<=f[last][0][0];j++)
		{
			for (int k=1;k<=n;k++)
			{
				bool check=1;
				for (int l=1;l<=i-1;l++)
				{
					if (k==f[last][j][l]) check=0;
					if (!vis[k][f[last][j][l]]) check=0;
				}								
				if (check)
				{
					f[now][0][0]++;
					for (int l=1;l<=i-1;l++) f[now][f[now][0][0]][l]=f[last][j][l];
					f[now][f[now][0][0]][i]=k;
					ok=1;
					ans=i;
				}
			}
		}
		if (!ok) break;
	}
	printf("%d\n",ans);
	return 0;
}
