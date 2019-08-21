#include<cstdio>

using namespace std;

int tree[1100000],M,n,a[110000],ans,m,wz[110000];

void query(int s,int t)
{
	s--,t++;
	s+=M;t+=M;
	while (!((s^t)==1))
	{
		if ((s&1)==0) ans+=tree[s+1];
		if ((t&1)==1) ans+=tree[t-1];
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
		tree[dot]=tree[2*dot]+tree[2*dot+1];
	}
}

int main()
{
	M=131071;
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]),wz[a[i]]=i;
	for (int i=1;i<=n;i++) tree[M+i]=1;
	for (int i=M;i>=1;i--) tree[i]=tree[2*i]+tree[2*i+1];
	int l=1,r=n;
	while (l<r)
	{
		ans=0;
		query(1,wz[l]-1);
		printf("%d\n",ans);
		change(wz[l],0);
		ans=0;
		query(wz[r]+1,n);
		printf("%d\n",ans);
		change(wz[r],0);
		l++,r--;
	}
	if (n%2) printf("0\n");
}

