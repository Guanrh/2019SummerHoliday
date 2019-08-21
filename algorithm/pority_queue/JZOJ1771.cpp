#include <bits/stdc++.h>

using namespace std;

int n,m,a[110000],f[110000];

int q[110000],head,tail;

int min(int x,int y){return x<y?x:y;}

int main()
{
	//freopen("beacon.in","r",stdin);
	//freopen("beacon.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);

	memset(f,127,sizeof f);
	f[0]=0;
	head=1;tail=0;
	for (int i=1;i<=n;i++) 
	{
		while (tail>=head && f[q[tail]]>=f[i-1]) tail--;
		q[++tail]=i-1;
		if (q[head]<i-m) head++;
		f[i]=f[q[head]]+a[i];
	}

	int ans=999999999;
	for (int i=n-m+1;i<=n;i++) ans=min(ans,f[i]);
	printf("%d\n",ans); 
}