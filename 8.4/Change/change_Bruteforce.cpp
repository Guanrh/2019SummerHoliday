#pragma GCC optimize(3)
#pragma G++ optimize(3)
#include <cstdio>
#include <cstring>

using namespace std;

int a[1100000][2],n,now;

int main()
{
	//freopen("test.out","w",stdout);
	
	//n=100000;
	scanf("%d",&n);
	now=1;
	for (register int i=1;i<=n;++i) a[i][now]=i;
	for (register int k=2;k<=n;++k)
	{
		//for (int i=1;i<=n;++i) printf("%d ",a[i]);
		//printf("\n");
		now^=1;
		for (register int i=1;i<=n/k;++i)
		{
			for (register int j=i*k-k+1;j<=i*k-1;++j) a[j][now]=a[j+1][now^1];
			a[i*k][now]=a[i*k-k+1][now^1];
		}
		if (n%k)
		{
			for (register int i=(n/k)*k+1;i<=n-1;++i) a[i][now]=a[i+1][now^1];
			a[n][now]=a[(n/k)*k+1][now^1];
		}

		//memcpy(a,tmp,sizeof a);
	}
	for (register int i=1;i<=n;++i) printf("%d ",a[i][now]);
	//printf("\n");
	//}
}