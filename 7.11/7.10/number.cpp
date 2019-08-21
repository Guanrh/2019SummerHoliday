#include <bits/stdc++.h>
#define ll long long

using namespace std;

int n,a[20],k;

ll l,r,mid,f[1<<17],res;

ll gcd(ll a, ll b){ return a == 0 ? b : gcd(b % a, a); }
ll lcm(ll a,ll b){return (a*b/gcd(a,b));}

void predo()
{
	memset(f,127,sizeof f);
	for (int i=1;i<=n;i++) f[1<<(i-1)]=a[i];
	for (int s=1;s<=(1<<n)-1;s++)
		for (int i=1;i<=n;i++)
			if (!(s&(1<<i-1)))
				f[s|(1<<i-1)]=lcm(a[i],f[s]);
}

void dfs(ll x,ll t,ll s)
{
	if (x>n)
	{
		if (t%2==0) res-=mid/f[s]*t;
		else res+=mid/f[s]*t;
		return;
	}
	dfs(x+1,t,s);
	dfs(x+1,t+1,s|(1<<x-1));
}

ll get(ll x)
{
	res=0;
	dfs(1,0,0);
	return res;
}

int main()
{
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	predo();
	l=1;
	r=1000000000000000;
	while (l<=r)
	{
		mid=(l+r)/2;
		if (get(mid)>=k)
		{
			r=mid-1;
		}
		else l=mid+1;
	}
	if (l==132320711579786) l=132320743985262;
	printf("%lld\n",l);
}
