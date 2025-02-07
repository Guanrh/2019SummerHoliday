#include<bits/stdc++.h>

using namespace std;

int tree[1100000],M,n,a[110000],ans,m;

int max(int x,int y){return x>y?x:y;}

void query(int s,int t)
{
	s--,t++;
	s+=M;t+=M;
	while (!((s^t)==1))
	{
		if ((s&1)==0) ans=max(ans,tree[s+1]);
		if ((t&1)==1) ans=max(ans,tree[t-1]);
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
	M=131071;
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&tree[M+i]);
	for (int i=M;i>=1;i--) tree[i]=max(tree[2*i],tree[2*i+1]);
	scanf("%d",&m);
	for (int i=1;i<=m;i++)
	{
		int op,x,y;
		scanf("%d%d%d",&op,&x,&y);
		if (op==1) change(x,y);
		else 
		{
			ans=-999999999;
			query(x,y);
			printf("%d\n",ans);
		}
	}
}
