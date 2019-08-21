#include <bits/stdc++.h>

using namespace std;

int n,m;
long long f[20][30],ans;

int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d%d",&n,&m);
	f[1][0]=1;
	f[0][0]=1;
	for (int i=1;i<n;i++)
	{
		for (int j=i;j>=1;j--)
			f[i%2][j]+=f[i%2][j-1]*(i-j+1);
		for (int j=i;j>=1;j--)
			f[i%2][j]+=f[i%2][j-1]*(i-j+1);
	}
	for (int i=n;i>=1;i--)
		f[n%2][i]+=f[n%2][i-1]*(n-i+1);

	for (int i=0;i<=m;i++) ans+=f[1][i]*f[0][m-i];

	printf("%lld\n",ans);
}