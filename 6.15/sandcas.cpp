#include<bits/stdc++.h>

using namespace std;

int n,x,y,m[26000],b[26000],ans;

int main()
{	
	freopen("sandcas.in","r",stdin);
	freopen("sandcas.out","w",stdout);
	scanf("%d%d%d",&n,&x,&y);
	for (int i=1;i<=n;i++) scanf("%d%d",&m[i],&b[i]);
	sort(m+1,m+1+n);
	sort(b+1,b+1+n);
	for (int i=1;i<=n;i++)
		if (m[i]>b[i]) ans+=(m[i]-b[i])*y;
		else ans+=(b[i]-m[i])*x;
	printf("%d\n",ans);
}
