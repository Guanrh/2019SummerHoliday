#include <cstdio>
#include <algorithm>

using namespace std;

int a[110000],n,c,mx,l,r,mid,ans;

int max(int x,int y){return x>y?x:y;}

int check()
{
	int cnt=1,last=1;
	for (int i=2;i<=n;i++)
		if (a[i]-a[last]>=mid)
		{
			last=i;
			cnt++;
		}
	if (cnt>=c) return 1;
	return 0;
}

int main()
{
	freopen("aggr.in","r",stdin);
	freopen("aggr.out","w",stdout);
	scanf("%d%d",&n,&c);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]),mx=max(mx,a[i]);
	sort(a+1,a+1+n);
	l=1;
	r=mx;
	while (l<=r)
	{
		mid=(l+r)>>1;
		if (check())
		{
			ans=max(ans,mid);
			l=mid+1;
		}
		else r=mid-1;
	}
	printf("%d\n",ans);
}