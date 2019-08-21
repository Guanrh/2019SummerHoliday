#pragma GCC optimize (3)
#pragma G++ optimize (3)
#include <bits/stdc++.h>
#define MAXN 51000
#define MAXM 110000

using namespace std;

int n,m,coli[MAXN],block_siz;

int main()
{
	scanf("%d%d",&n,&m);
	block_siz=n*sqrt(m*2/3);
	for (int i=1;i<=n;i++) scanf("%d",&coli[i]);
	for (int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v),add(v,u);
	}
}