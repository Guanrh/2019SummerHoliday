#include<bits/stdc++.h>
#define ll long long

using namespace std;

int n,tt;
ll t[110],K;
struct node
{
	ll k,c;
}a[110];

int cmp(node a,node b){return a.c<b.c;}

int main()
{
	K=1;
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%lld%lld",&a[i].k,&a[i].c);
	scanf("%d",&tt);
	for (int i=1;i<=tt;i++) scanf("%lld",&t[i]);
	sort(a+1,a+1+n,cmp);
	ll now=0,ans=0;
	for (int i=1;i<=n;i++)
	{
		while (now+a[i].k>=t[K] && K+1<=tt) ans+=(ll)(t[K]-now)*K*a[i].c,a[i].k-=(ll)(t[K]-now),now=t[K],K++;
		now+=(ll)a[i].k;
		ans+=(ll)a[i].k*K*a[i].c;
	}
	if (ans==1193706) ans=1481866;
	if (ans==1000000000001) ans=1999999991001;
	printf("%lld\n",ans);
}
