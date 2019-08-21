#include <cstdio>
#include <algorithm>

using namespace std;

struct node
{
	int e,id;
}a[1100];

int n,ans,fa[1100],w[1100];

int cmp(node a,node b){return a.e<b.e;}

int main()
{
	scanf("%d",&n);
	for (int i =1;i<=n;i++) scanf("%d%d%d",&fa[i],&a[i].e,&w[i]),a[i].id=i;
	sort(a+1,a+1+n,cmp);
	
	for (int i=1;i<=n;i++)
	{
		int j;
		for (j=a[i].id;j && w[j]>=a[i].e;j=fa[j]);
		if (j) continue; 
		for (j=a[i].id;j;j=fa[j]) w[j]-=a[i].e;
		ans++;	
	}	
	printf("%d\n",ans);
}
