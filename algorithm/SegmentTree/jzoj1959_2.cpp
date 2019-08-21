#include <cstdio>

using namespace std;

int n,m,x[110000],a[410000],op,X,Y;

int max(int x,int y){return x>y?x:y;}

void Pushup(int rt)
{
	a[rt]=max(a[rt<<1],a[rt<<1|1]);
}

void Build(int l,int r,int rt)
{
	if (l==r)
	{
		a[rt]=x[l];
		return;
	}
	int mid=(l+r)>>1;
	Build(l,mid,rt<<1);
	Build(mid+1,r,rt<<1|1);
	Pushup(rt);
}

void Update(int L,int newval,int l,int r,int rt)
{
	if (l==r)
	{
		a[rt]=newval;
		return;
	}
	int mid=(l+r)>>1;
	if (L<=mid) Update(L,newval,l,mid,rt<<1);
	else Update(L,newval,mid+1,r,rt<<1|1);
	Pushup(rt);
}

int Query(int L,int R,int l,int r,int rt)
{
	if (L<=l && r<=R) return a[rt];
	int mid=(l+r)>>1,ANS=0;
	if (L<=mid) ANS=max(ANS,Query(L,R,l,mid,rt<<1));
	if (R>mid) ANS=max(ANS,Query(L,R,mid+1,r,rt<<1|1));
	return ANS;
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&x[i]);
	Build(1,n,1);
	scanf("%d",&m);
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&op,&X,&Y);
		if (op==1) Update(X,Y,1,n,1);
		else printf("%d\n",Query(X,Y,1,n,1));
	}
}