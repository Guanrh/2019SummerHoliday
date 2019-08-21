#include <bits/stdc++.h>

using namespace std;

int f[110][110],a[110],n;

int max(int x,int y){return x>y?x:y;}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]),a[i]&=1;
	for (int len=n-1;len>=0;len--)
		for (int i=1;i<=n;i++)
		{
			int j=(i+len+n)%n+1;
			f[i][j]=max(a[i]-f[(i-2+n)%n+1][j],a[j]-f[i][j%n+1]);
		}

	int ans=0;
	for (int i=1;i<=n;i++)
		if (a[i]-f[(n+i-2)%n+1][i%n+1]>0) ans++;
	printf("%d\n",ans);
	printf("\n");
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
			printf("%d ",f[i][j]);
		printf("\n");
	}
}