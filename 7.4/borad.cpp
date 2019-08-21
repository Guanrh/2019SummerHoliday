#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007

using namespace std;

ll ans,n,m;

ll qpow(ll x,ll y)
{
	ll res=1;
	while (y)
	{
		if (y%2) res=(res*x)%mod;
		x=(x*x)%mod;
		y/=2;
	}
	return res%mod;
}

int main()
{
	scanf("%lld%lld",&n,&m);
	//printf("%lld\n",qpow(n,m));
	ans=(qpow(2,n-2)+qpow(2,m-2)-1)%mod;
	ans=(ans*24)%mod;
	printf("%lld\n",ans);
}
