#include<bits/stdc++.h>

using namespace std;

int total,n,a[210],x,flag,ans,win,l[110],r[110];

int f[110][2];

void sol(int st)
{
	int cnt=1;
	for (int left=l[st],right=r[st],who=1;left!=st;left=l[left],right=r[right],who^=1)
	{
		f[left][who]=f[r[r[left]]][who]+a[left];
		f[right][who]=f[l[l[right]]][who]+a[right];
	}
	for (int left=l[st],right=r[st],who=0;left!=st;left=l[left],right=r[right],who^=1)
	{
		f[left][who]=f[r[r[left]]][who]+a[left];
		f[right][who]=f[l[l[right]]][who]+a[right];
	}
}

int main()
{
	freopen("test.in","r",stdin);
	scanf("%d",&n);
	for (int i=1;i<=n;i++) 
	{
		scanf("%d",&x);
		if (x%2==1) a[i]=1,total++;
		//a[i+n]=a[i];
	}
	for (int i=2;i<n;i++) l[i]=i-1,r[i]=i+1;
	l[1]=n,r[1]=2;
	l[n]=n-1,r[n]=1;
	win=total/2+total%2;
	for (int i=1;i<=n;i++)
	{
		memset(f,0,sizeof f);
		f[i][0]=a[i];
		sol(i);
		for (int j=1;j<=n;j++)
		{
			printf("{%d,%d} ",f[j][0],f[j][1]);
		}
		printf("\n");
	}

	//printf("%d\n",ans);
}
