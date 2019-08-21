#include <bits/stdc++.h>

using namespace std;

int n,f1[100010],f2[100010],a[100010],b[100010],c[100010],ans;

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++) scanf("%d",&b[i]),f1[b[i]]++;
	for (int i=1;i<=n;i++) scanf("%d",&c[i]),f2[c[i]]++;
	while (1)
	{
		int flag=1;
		for (int i=1;i<=n;i++)
			if (a[i] && (f1[a[i]]==0 || f2[a[i]]==0))
			{
				flag=0;
				ans++;
				a[i]=0;
				f1[b[i]]--;
				f2[c[i]]--;
			}
		if(flag) break;
	}
	printf("%d\n",ans);
}