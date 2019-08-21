#include <cstdio>
#define ll long long

using namespace std;

int T;
ll b,a,n,e[70],ans;

ll f(ll a,ll b,ll c,ll n)
{
	ll val=(n+1)*(b/c);
	if (n&1) val+=(n+1)/2*n*(a/c);
	else val+=n/2*(n+1)*(a/c);
	a%=c;
	b%=c;
	ll m=(a*n+b)/c;
	if (m==0) return val;
	return val+n*m-f(c,c-b-1,a,m-1);
}

int main()
{
	e[0]=1;
	for (int i=1;i<=62;i++) e[i]=e[i-1]*2;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%lld%lld%lld",&a,&b,&n);
		ans=0;
		for (int i=0;i<=60;i++) if (b&e[i]) ans--;
		for (int i=0;i<=60;i++) ans+=(f(a,b,e[i],n)-2*f(a,b,e[i+1],n));
		printf("%lld\n",ans);
	}
}
