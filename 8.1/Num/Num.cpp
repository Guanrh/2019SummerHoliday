#include <bits/stdc++.h>

using namespace std;

int a[50100],T,n,k,cnt[1000010];

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		memset(cnt,0,sizeof cnt);
		scanf("%d%d",&k,&n);
		for (int i=1;i<=n;i++) scanf("%d",&a[i]),a[i]+=a[i-1],a[i]%=k;
		for (int i=1;i<=n;i++) cnt[a[i]]++;
		int ans=0;
		for (int i=0;i<k;i++) ans+=(cnt[i]-1)*cnt[i]/2;
		ans+=cnt[0];
		printf("%d\n",ans);
	}
}