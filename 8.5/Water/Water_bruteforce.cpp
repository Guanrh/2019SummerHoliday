#include <cstdio>

using namespace std;

int n,h,a[25][25],num;

char s[25][25];

long long ans,f[25][1100];

int main()
{
	scanf("%d%d",&n,&h);
	for (int i=1;i<=n;i++)
	{
		scanf("%s",s[i]+1);
		for (int j=1;j<=n;j++)
			a[i][j]=(s[i][j]=='1');
	}

	for (int i=1;i<=n;i++) if (a[1][i]) f[1][i]=1,ans++;

	for (int i=2;i<=h;i++)
	{
		for (int j=1;j<=n;j++)
		{
			if (f[i-1][j]%2==0) num=2; else num=1;
			for (int k=1;k<=n;k++)
				if (a[j][k]) f[i][k]+=num,ans+=num;
		}
	}
	printf("%lld\n",ans);
}