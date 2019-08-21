#include <cstdio>
#include <cstring>

using namespace std;

int n,h,a[25][25],num,bz[23],date[1600000],cnt[1600000],tmp[23];

char st[25][25];

long long ans,f[25][1100];

int main()
{
	scanf("%d%d",&n,&h);
	for (int i=1;i<=n;i++)
	{
		scanf("%s",st[i]+1);
		for (int j=1;j<=n;j++)
			a[i][j]=(st[i][j]=='1');
	}

	for (int i=1;i<=n;i++) if (a[1][i]) bz[i]=1,ans++;

	for (int k=1;k<h;k++)
	{
		int s=0;
		for (int i=1;i<=n;i++) if (bz[i]) s+=1<<(i-1);
		if(!date[s])
		{
			date[s]=k;
			cnt[k]=ans;
		}
		else
		{
			cnt[k]=ans;
			int count=(h-k)/(k-date[s]);
			int rest=(h-k)%(k-date[s]);

			int ANSWER=count*(cnt[k]-cnt[date[s]])+cnt[date[s]+rest]-cnt[date[s]]+cnt[k];
			printf("%d\n",ANSWER);

			return 0;
		}

		memset(tmp,0,sizeof tmp);
		for (int i=1;i<=n;i++)
			if (bz[i])
			{
				for (int j=1;j<=n;j++)
					if (a[i][j]) tmp[j]^=1,ans++;
			}
			else
			{
				for (int j=1;j<=n;j++)
					if (a[i][j]) ans+=2;
			}

		memcpy(bz,tmp,sizeof bz);
	}

	printf("%lld\n",ans);
}