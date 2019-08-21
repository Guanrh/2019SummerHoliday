#include <bits/stdc++.h>

using namespace std;

int a[1100],T,n,k,cnt;

int main()
{
	//freopen("test.out","r",stdin);
	scanf("%d",&T);
	while(T--)
	{
		cnt=0;
		scanf("%d%d",&k,&n);
		for (int i=1;i<=n;i++) scanf("%d",&a[i]),a[i]%=k;
		for (int i=2;i<=n;i++) a[i]+=a[i-1];
		for (int i=1;i<n;i++)
			for (int j=i+1;j<=n;j++)
				if ((a[j]-a[i-1])%k==0)
					cnt++;
		printf("%d\n",cnt);
	}
}