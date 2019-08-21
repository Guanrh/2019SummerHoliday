#include <bits/stdc++.h>

using namespace std;

int a[210000],tot,n;

int main()
{
	freopen("linear.in","r",stdin),freopen("linear.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d%d",&a[++tot],&a[++tot]);
	sort(a+1,a+1+tot);
	printf("%d %d\n",a[tot/2],a[tot/2+1]);
}