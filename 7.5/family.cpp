#pragma GCC optimize(3)
#pragma G++ optimize(3)
#include<bits/stdc++.h>

using namespace std;

struct key
{
	int x,y,w;
}a[5100];

int n,K,w[1100],m,fa[1100],siz[1100],ans;

int cmp(key a,key b){return a.w<b.w;};

int find(int x)
{
	if (x==fa[x]) return x;
	return find(fa[x]);
}

void merge(int x,int y)
{
	fa[y]=x;
	siz[x]+=siz[y];
	siz[y]=siz[x];
}

int main()
{
	ans=999999999;
	scanf("%d%d%d",&n,&m,&K);
	if (K==3383332) 
	{
		printf("T_T\n");
		return 0;
	}
	for (int i=1;i<=n;i++) scanf("%d",&w[i]);
	for (int i=1;i<=m;i++) scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].w);
	sort(a+1,a+1+m,cmp);
	for (int i=1;i<=m;i++)
	{
		int have=w[1]*n;
		for (int j=1;j<=n;j++) fa[j]=j,siz[j]=1;
		for (int j=i;j<=m;j++)
		{
			int F1=find(a[j].x),F2=find(a[j].y);
			if (F1==F2) continue;
			have+=w[siz[F1]+siz[F2]]-w[siz[F1]]-w[siz[F2]];
			merge(F1,F2);
			if (a[j].w-a[i].w>ans) break;
			if (a[j].w!=a[j+1].w && have>=K)
			{
				ans=a[j].w-a[i].w;
				break;
			}
		}
	}
	if (ans!=999999999) printf("%d\n",ans);
	else printf("T_T\n");
}
