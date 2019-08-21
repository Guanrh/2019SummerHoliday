#include <bits/stdc++.h>
#define MAXWZ 1000000
#define INF 999999999

using namespace std;

struct node
{
	int x,y;
}a[110000];

int n,f[110000],M,tree[3100000],wz;

int cmp(node a,node b){return (a.x<b.x || (a.x==b.x && a.y>b.y));}

void query(int s,int t)
{
	s--,t++;
	s+=M;t+=M;
	while (!((s^t)==1))
	{
		if ((s&1)==0) wz=max(wz,tree[s+1]);
		if ((t&1)==1) wz=max(wz,tree[t-1]);
		s>>=1;t>>=1;
	}
}

void change(int dot,int newval)
{
	dot+=M;
	tree[dot]=newval;
	while (dot>1)
	{
		dot>>=1;
		tree[dot]=max(tree[2*dot],tree[2*dot+1]);
	}
}

int main()
{
	M=1048576;
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d%d",&a[i].x,&a[i].y);
	sort(a+1,a+1+n,cmp);
	for (int i=1;i<=n;i++)
	{
		wz=0;
		query(a[i].y,MAXWZ);
		f[i]=wz+1;
		change(a[i].y,f[i]);
	}

	int ans=-1;
	for (int i=1;i<=n;i++) ans=max(ans,f[i]);

	printf("%d\n",ans);
}