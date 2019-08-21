#include <cstdio>
#include <cstring>

using namespace std;

int a[20],n,bz[20],f[10000],ans,vis[20],num;

int gcd(int a, int b){ return a == 0 ? b : gcd(b % a, a); }
int lcm(int a,int b){return (a*b/gcd(a,b));}

void check()
{
	ans=1;
	memset(vis,0,sizeof vis);
	for (int i=1;i<=n;i++)
		if (!vis[i])
		{
			vis[i]=1;
			if (a[i]==i) continue;
			int now=a[i],cnt=2;
			while (now!=i)
			{
				now=a[now];
				cnt++;
			}
			ans=lcm(ans,cnt-1);
		}
	//printf("Case %d:\n",ans);
	//for (int i=1;i<=n;i++) printf("%d ",a[i]);
	//printf("\n");
	f[ans]=1;
}

void dg(int t)
{
	if (t>n)
	{
		check();
		return;
	}
	for (int i=1;i<=n;i++)
		if (!bz[i])
		{
			bz[i]=1;
			a[t]=i;
			dg(t+1);
			bz[i]=0;
		}
}

int main()
{
	freopen("test.out","w",stdout);
	scanf("%d",&n);
	dg(1);
	int anss=0;
	for (int i=1;i<=1000;i++) if (f[i]) anss++,printf("!%d\n",i);
	printf("%d\n",anss);
}
