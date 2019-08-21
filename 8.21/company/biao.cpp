#include <cstdio>

using namespace std;

int a[110],b[110],l,r,mid,n,m,f[110][110],ans;

int max(int x,int y){return x>y?x:y;}

int check()
{
	for (int i=0;i<=100;i++) for(int j=0;j<=100;j++) f[i][j]=-715827882;
	for (int i=0;i<=n;i++) f[i][0]=0;

	for (int i=1;i<=n;i++)
		for (int j=0;j<=m;j++)
			for (int k=0;k<=j;k++)
				if (k*a[i]<=mid)
					f[i][j]=max(f[i][j],f[i-1][j-k]+(mid-a[i]*k)/b[i]);
	return f[n][m]>=m;
}

int main()
{
	//freopen("company.in","r",stdin);
	//freopen("company.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d%d",&a[i],&b[i]);
	
	l=1;
	r=10000;
	while (l<=r)
	{
		mid=(l+r)>>1;
		if (check())
		{
			ans=mid;
			r=mid-1;
		}
		else l=mid+1;
	}

	printf("%d\n",ans);
	return 0;
}
