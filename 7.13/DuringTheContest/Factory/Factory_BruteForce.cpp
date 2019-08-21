#include<bits/stdc++.h>
#define MAXN 1100

using namespace std;

int a[MAXN],tmp[MAXN],n,c,Q;
char op,k,opp;

void paint(int l,int r,int co)
{
	for (int i=l;i!=r;i++)
	{
		if (i==n+1) i=1;
		a[i]=co;
	}
}

void swp(int l,int r)
{
	int tmp=a[l];
	a[l]=a[r];
	a[r]=tmp;
}

int cnt()
{
	int sum=0;
	for (int i=1;i<=n;i++)
	{
		sum++;
		while (a[i]==a[i+1] && i<=n) i++;
	}
	if (a[1]==a[n]) sum--;
	return sum;
}

int cs(int l,int r)
{
	int sum=0;
	for (int i=l;i!=r;i++)
	{
		if (i==n+1) i=1;
		while (a[i]==a[i+1] && i<=n) i++; 
	}
	if (a[1]==a[n]) sum--;
	return sum;
}

void flip()
{
	tmp[1]=a[1];
	for (int i=2;i<=n/2+n%2;i++) tmp[i]=a[n-i+2],tmp[n-i+2]=a[i];
	if (n%2==0) tmp[n/2+1]=a[n/2+1];
	memcpy(a,tmp,sizeof a);
}

void rotate(int k)
{
	int cur=k;
	cur=cur%n;
	for (int i=1;i<=n;i++)
	{
		cur++;
		if (cur==n+1) cur=1;
		tmp[cur]=a[i];
	}
	memcpy(a,tmp,sizeof a);
}

int main()
{
	freopen("test.in","r",stdin);
	scanf("%d%d",&n,&c);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	scanf("%d",&Q);
	for (int i=1;i<=Q;i++)
	{
		op=getchar();
		while (!(op=='R' || op=='F' || op=='S' || op=='C' || op=='P'))
			op=getchar();
		opp=getchar();
		if (op=='C')
		{
			if (opp=='S')	
			{
				int l,r;
				scanf("%d%d",&l,&r);
				printf("%d\n",cs(l,r));
			}
			else
				printf("%d\n",cnt());
		}
		if (op=='R')
		{
			int k;
			scanf("%d",&k);
			rotate(k);
		}
		if (op=='F') flip();
		if (op=='S')
		{
			int l,r;
			scanf("%d%d",&l,&r);
			swp(l,r);
		}
		if (op=='P')
		{
			int l,r,co;
			scanf("%d%d%d",&l,&r,&co);
			paint(l,r,co);
		}
	}
}
