#include <cstdio>

using namespace std;

int n,m,a[110000],x,y,sum;

int max(int x,int y){return x>y?x:y;}

int solve()
{
	int mx=-999999999;
	for (int i=1;i<=n;i++)
	{
		sum=0;
		for (int j=i;j<=i+n-2;j++)
			sum+=a[j],mx=max(mx,sum);
	}
	return mx;
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]),a[n+i]=a[i];
	scanf("%d",&m);
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		a[x]=a[n+x]=y;
		printf("%d\n",solve());
	}
}