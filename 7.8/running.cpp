#include<cstdio>
#include<cstring>
#include <algorithm>
#define MAXN (int)(1e7)

using namespace std;

int flag[MAXN]/*标记是否为素数*/,p[MAXN]/*素数数组*/,cnt/*素数个数*/;

int n,m,a[60],ans;

void Get()
{
	for (int i=2;i*i<=n;i++)
		if (!(n%i))
		{
			p[++cnt]=i;
			if (i^n/i) p[++cnt]=n/i;
		}
	p[++cnt]=n;
}

int phi(int x)
{
	int res=x;
	for (int i=1;i<=cnt&&x!=1;i++)
	{
		if (!(x%p[i])) res=res/p[i]*(p[i]-1);
		while (!(x%p[i])) x/=p[i];
	}
	return res;
}

int main()
{
	freopen("running.in","r",stdin);
	freopen("running.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++) scanf("%d",&a[i]),a[i]=__gcd(a[i],n);
	Get();
	sort(p+1,p+1+cnt);
	for (int i=1;i<=cnt;i++)
		for (int j=1;j<=m;j++)
			if (!(p[i]%a[j])){
				ans+=phi(n/p[i]);
				break;
			}
	printf("%d\n",n-ans);
}
