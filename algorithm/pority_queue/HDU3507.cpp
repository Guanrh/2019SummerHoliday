#include <cstdio>
#define ll long long

using namespace std;

ll n,M,a[510000],f[510000],sum[510000],q[510000],head,tail;

double slope(ll i,ll j)
{
	return (double)((f[i]+sum[i]*sum[i])-(f[j]+sum[j]*sum[j]))*1.0/(2*sum[i]-2*sum[j]);
}

int main()
{
	scanf("%lld%lld",&n,&M);
	for (int i=1;i<=n;i++) scanf("%lld",&a[i]),sum[i]=sum[i-1]+a[i];

	head=tail=1;
	for (int i=1;i<=n;i++)
	{
		while (head<tail && slope(q[head],q[head]+1)<=sum[i]) head++;
		f[i]=f[q[head]]+(sum[i]-sum[q[head]])*(sum[i]-sum[q[head]]);
		while (head<tail && slope(q[tail-1],q[tail])>=slope(q[tail],i)) tail--;
		q[++tail]=i;
	}

	printf("%lld\n",f[n]);

	return 0;
}
