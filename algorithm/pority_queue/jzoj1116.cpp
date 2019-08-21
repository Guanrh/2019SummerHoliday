#include <cstdio>
#include <cstring>
#define ll long long

using namespace std;

int n,L;
ll c[51000],f[51000],q[51000],head,tail;

ll sqr(ll x){return (ll)x*x;}

ll min(ll x,ll y){return x<y?x:y;}

int main()
{
	scanf("%d%d",&n,&L);
	for (int i=1;i<=n;i++) scanf("%lld",&c[i]),c[i]+=c[i-1];

	memset(f,127,sizeof f);
	f[0]=0;
	for (int i=1;i<=n;i++)
	{
		for (int j=0;j<i;j++)
			f[i]=min(f[i],f[j]+sqr(i-j-1+c[i]-c[j]-L));
	}

	printf("%lld\n",f[n]);
}
