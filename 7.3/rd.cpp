#include<bits/stdc++.h>

using namespace std;

int n,a[110000],b[110000],tmp,f[110000],tot;

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&tmp),a[tmp]=i;
	for (int i=1;i<=n;i++) scanf("%d",&tmp),b[a[tmp]]=i;
	//for (int i=1;i<=n;i++) printf("%d ",b[i]);
	f[0]=999999;
	tot=0;
	for (int i=1;i<=n;i++)
		if (b[i]<f[tot]) f[++tot]=b[i];
		else
		{
			int cur=tot;
			while (f[cur]<b[i] && cur>=1) cur--;
			cur++;
			f[cur]=b[i];
		}
	printf("%d\n",tot);
}
