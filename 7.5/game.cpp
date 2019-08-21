#include<bits/stdc++.h>

using namespace std;

int t,n,k,a[2100000],b[2100000],T;

int main()
{
	scanf("%d",&T);
	int ca=0;
	while (T--)
	{
		ca++;
		scanf("%d%d",&n,&k);
		int i=1;
		t=1;
		a[1]=b[1]=1;
		while (a[i]<n)
		{
			i++;
			a[i]=b[i-1]+1;
			while (a[t+1]*k<a[i]) t++;
			b[i]=(a[t]*k<a[i])?a[i]+b[t]:a[i];
		}
		if (n==a[i]) printf("Case %d: lose\n",ca);
		else
		{
			int ans;
			for (int j=i;j>=1;j--)
				if (n-a[j]>=0) n-=a[j],ans=a[j];
			printf("Case %d: %d\n",ca,ans);
		}
	}
}
