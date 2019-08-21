#include<bits/stdc++.h>

using namespace std;

int total,n,a[210],x,flag,ans,win,l[110],r[110];

int f[110][2],bz[110][2];

int get(int TIME,int WHO)
{
	if (TIME==0) TIME=n;
	if (bz[TIME][WHO]) return dp[TIME][WHO];
	else 
		return get(TIME-2,WHO)+
}

void sol(int st)
{
	
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) 
	{
		scanf("%d",&x);
		if (x%2==1) a[i]=1,total++;
		a[i+n]=a[i];
	}
	for (int i=2;i<n;i++) l[i]=i-1,r[i]=i+1;
	l[1]=n,r[1]=2;
	l[n]=n-1,r[n]=1;
	win=total/2+total%2;
	for (int i=1;i<=n;i++)
	{
		memset(f,0,sizeof f);
		f[1][0]=a[i];
		sol(i);
	}

	printf("%d\n",ans);
}