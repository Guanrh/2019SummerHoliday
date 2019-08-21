#pragma GCC optimize(3)
#pragma G++ optimize(3)
#include <bits/stdc++.h>

using namespace std;

short n,f[310][310][310],a[310][310],g[310][310][310];
char mp[310][310];
int i,tot,h[310][310];

int max(int x,int y){return x>y?x:y;}

int main()
{
	//freopen("8.in","r",stdin);
	//freopen("mine.out","w",stdout);
	scanf("%d",&n);
	tot=0;
	for (i=1;i<=n;i++) 
	{
		scanf("%s",mp[i]+1);
		for (int j=1;j<=n;j++) tot+=(mp[i][j]=='*'),a[i][j]=tot;
	}
	for (i=1;i<=n;i++)
		for (int l=1;l<=n;l++)
		{
			int clear=(mp[i][l]=='.');
			for (int r=l+1;r<=n;r++)
			{
				clear&=(mp[i][r]=='.');
				if (mp[i][l]=='.' && mp[i][r]=='.')
				{
					if (i>1 && f[i-1][l][r]!=-1)
						f[i][l][r]=f[i-1][l][r]+1;
					else
						f[i][l][r]=(clear)?0:-1;
				}
				else
					f[i][l][r]=-1;
			}
		}

	for (i=n;i>=1;i--)
		for (int l=1;l<=n;l++)
		{
			int clear=(mp[i][l]=='.');
			for (int r=l+1;r<=n;r++)
			{
				clear&=(mp[i][r]=='.');
				if (mp[i][l]=='.' && mp[i][r]=='.')
				{
					if (i<n && g[i+1][l][r]!=-1)
						g[i][l][r]=g[i+1][l][r]+1;
					else
						g[i][l][r]=(clear)?0:-1;
				}
				else
					g[i][l][r]=-1;
			}
		}

	int ans=0;

	for (i=1;i<=n;i++)
	{
		memset(h,0,sizeof h);
		for (int len=1;len<=n;len++)
			for (int l=1;l+len<=n;l++)
			{
				int r=l+len;
				if (mp[i][l]=='.' && mp[i][r]=='.')
				{
					h[l][r]=(f[i][l][r]<2?-1:(f[i][l][r]-1)*(r-l-1));
					if (len>1)
						h[l][r]=max(h[l][r],max(h[l+1][r],h[l][r-1]));
				}
				else
					h[l][r]=-1;
				//printf("%d\n",h[i][l][r]);

				if (a[i][r]-a[i][l]==0&&h[l][r]!=-1&&g[i][l][r]>=2)
					ans=max(ans,h[l][r]*(g[i][l][r]-1)*(r-l-1))/*,printf("!!!\n")*/;
			}
	}

	if (ans==0) ans=-1;
	printf("%d\n",ans);
}
